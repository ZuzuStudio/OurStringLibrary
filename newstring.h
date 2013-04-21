#ifndef NEWSTRING_H_INCLUDED
#define NEWSTRING_H_INCLUDED

#include <iostream>

class String
{

public:
    String();
    String(int n);
    explicit String(const char *str);
    String(const String &original);
    ~String();

    int length();
    String substr(int first, int n);
    char *c_str();

    String &operator=(const String &original);
    String operator+(const String &x);

    bool operator==(String &x);
    bool operator>=(String &x);
    bool operator<=(String &x);
    bool operator>(String &x);
    bool operator<(String &x);
    void operator<<(String &x);
    friend std::ostream &operator<<(std::ostream &output, const String &x);
    friend std::istream &operator>>(std::istream &input, const String &x);

private:
    int size;
    char *array;
};

#endif // NEWSTRING_H_INCLUDED
