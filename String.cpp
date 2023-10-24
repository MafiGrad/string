#include "String.h"
#include <cstring>
#include <exception>
#include <iterator>
#include <iostream>

String::String() : m_length{0}, m_capacity{0}, m_data{nullptr}
{
}

String::String(const char *cstr)
{
    append(cstr);
}

String::String(String &&other) noexcept
{
    move(other);
}

String::~String()
{
    if (m_data != nullptr)
    {
        delete[] m_data;
    }
}

String &String::append(const char *cstr)
{
    if (cstr == nullptr)
    {
        throw std::logic_error("String: Invalig argument append(c_str)");
    }

    const size_t s_len = std::strlen(cstr);
    for (size_t i = 0; i < s_len; i++)
    {
        push_back(cstr[i]);
    }
    return *this;
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

char &String::at(const size_t pos) const
{
    if (pos > m_length)
    {
        throw std::out_of_range("String: at() out of range");
    }

    return m_data[pos];
}

const char *String::data() const noexcept
{
    return m_data;
}

char &String::operator[](const size_t pos) const
{
    return m_data[pos];
}

void String::move(String &other) noexcept
{
    m_data = other.m_data;
    m_capacity = other.m_capacity;
    m_length = other.m_length;
    other.m_data = nullptr;
    other.m_length = 0;
    other.m_capacity = 0;
}

String &String::operator=(String &&other) noexcept
{
    move(other);
    return *this;
}

String &String::operator+=(const char *cstr)
{
    append(cstr);
    return *this;
}

bool String::operator<(const String &other) const
{
    const size_t cmp_len = std::min(m_length, other.m_length);
    return (std::strncmp(m_data, other.m_data, cmp_len) < 0);
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

bool operator==(const String &lstr, const String &rstr)
{
    const size_t llen = lstr.length();
    const size_t rlen = rstr.length();

    if (llen == 0 and rlen == 0)
    {
        return true;
    }

    if ((lstr.m_data == nullptr) or (rstr.m_data == nullptr))
    {
        return false;
    }

    return !std::strncmp(lstr.m_data, rstr.m_data, std::min(llen, rlen));
}

bool operator!=(const String &lstr, const String &rstr)
{
    return !(lstr == rstr);
}

bool operator==(const String &lstr, const char *rstr)
{
    return (lstr == String(rstr));
}

const String operator+(const String &lstr, const String &rstr)
{
    String str;
    str.m_length = lstr.length() + rstr.length();
    str.m_capacity = str.m_length + 1;
    str.m_data = new char[str.m_capacity];
    std::memcpy(str.m_data, lstr.data(), lstr.length());
    std::memcpy(str.m_data + lstr.length(), rstr.data(), rstr.length());
    str.m_data[str.m_length] = '\0';
    return str;
}

const String operator+(const String &lstr, const char *rstr)
{
    return lstr + String(rstr);
}

const String operator+(const char *lstr, const String &rstr)
{
    return String(lstr) + rstr;
}
