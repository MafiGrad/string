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

char &String::operator[](const size_t pos) noexcept
{
    return m_data[pos];
}
