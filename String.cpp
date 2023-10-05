#include "String.h"
#include <cstring>
#include <exception>
#include <iterator>
#include <iostream>

String::String() : m_length{0}, m_capacity{0}, m_data{nullptr}
{
}

String::~String()
{
    if (m_data != nullptr)
    {
        delete[] m_data;
    }
}

void String::reserve(const size_t sz)
{
    if (m_capacity >= sz)
    {
        return;
    }

    m_capacity = sz;

    if (m_data == nullptr)
    {
        m_data = new char[m_capacity];
        return;
    }

    char *tmp = new char[m_capacity];
    std::memcpy(tmp, m_data, m_length + 1);
    delete[] m_data;
    m_data = tmp;
}

void String::push_back(const char c)
{
    if (m_length >= m_capacity)
    {
        const size_t new_sz = (m_length == 0) ? (m_length + 1) : (m_length * 2);
        reserve(new_sz);
    }

    m_data[m_length] = c;
    m_length++;
    m_data[m_length] = '\0';
}

void String::clear() noexcept
{
    m_capacity = 0;
    m_length = 0;

    if (m_data != nullptr)
    {
        delete[] m_data;
        m_data = nullptr;
    }
}

bool String::empty() const noexcept
{
    return !(static_cast<bool>(m_length));
}

size_t String::length() const noexcept
{
    return m_length;
}

size_t String::size() const noexcept
{
    return m_capacity;
}

char &String::operator[](const size_t pos) noexcept
{
    return m_data[pos];
}

std::ostream &operator<<(std::ostream &os, const String &str)
{
    std::copy(str.m_data, str.m_data + str.m_length, std::ostream_iterator<char>(os));
    return os;
}

std::istream &operator>>(std::istream &is, String &str)
{
    str.clear();
    do
    {
        const char c = is.get();
        if (not std::isgraph(c))
        {
            break;
        }
        str.push_back(c);
    } while (true);

    return is;
}
