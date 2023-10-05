#pragma once

#include <cstdlib>
#include <utility>
#include <ostream>

class String
{
public:
    String();

    virtual ~String();

    void reserve(const size_t sz);
    void push_back(const char c);
    void clear() noexcept;

    bool empty() const noexcept;
    size_t length() const noexcept;
    size_t size() const noexcept;

    char &operator[](const size_t pos) noexcept;

    friend std::ostream &operator<<(std::ostream &os, const String &str);
    friend std::istream &operator>>(std::istream &is, String &str);

private:
    size_t m_length = 0;
    size_t m_capacity = 0;
    char *m_data = nullptr;
};