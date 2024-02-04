#pragma once
#include <iostream>

namespace ANEFreeInIty
{
    class String
    {
        const char *str;

    public:
        String(const char *);
        const char *Get();
        String operator+(String const &);
    };

    std::ostream &operator<<(std::ostream &, String &);
};