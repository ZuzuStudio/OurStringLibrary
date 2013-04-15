#ifndef NEWSTRING_H_INCLUDED
#define NEWSTRING_H_INCLUDED

#include <iostream>

class String
{

public:
    String();
    String(int n);
    String(const char *str);
    String(const String &original);
    ~String();

    int length();
    int length(const char *str);
    String substr(int first, int n);

    String &operator=(const String &original);
    String operator+(String x);

    bool operator==(String x);
    bool operator>=(String x);
    bool operator<=(String x);
    bool operator>(String x);
    bool operator<(String x);
    void operator<<(String x);
    friend std::ostream &operator<<(std::ostream &output, const String &a);
    friend std::istream &operator>>(std::istream &input, const String &a);

private:
    int size;
    char *array;
};

#endif // NEWSTRING_H_INCLUDED
