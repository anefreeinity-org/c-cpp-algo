#include "./String.h"

ANEFreeInIty::String::String(const char *str)
{
    this->str = str;
}

const char *ANEFreeInIty::String::Get()
{
    return this->str;
}

ANEFreeInIty::String ANEFreeInIty::String::operator+(String const &obj)
{
    int len1 = 0;
    int len2 = 0;

    while (this->str[len1] != '\0')
    {
        len1++;
    }

    while (obj.str[len2] != '\0')
    {
        len2++;
    }

    char *concatStr = new char[len1 + len2 + 1];

    for (int i = 0; i < len1; i++)
    {
        concatStr[i] = this->str[i];
    }

    for (int i = 0; i < len2; i++)
    {
        concatStr[i + len1] = obj.str[i];
    }

    concatStr[len1 + len2] = '\0';

    ANEFreeInIty::String strObj(concatStr);
    return strObj;
}

std::ostream &ANEFreeInIty::operator<<(std::ostream &strm, String &str)
{
    return strm << str.Get();
}