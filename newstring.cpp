#include "newstring.h"

int length(const char *str);

String::String():
    size(0), array(0)
{
};

String::String(int n):
    size(n), array(0)
{
    array=new char[size];
    for (int i=0; i<size; ++i)
        array[i]='\0';
};


String::String(const char *str):
    size(::length(str)), array(0)
{
    array=new char[size];
    for(int i=0; i<size; ++i)
        array[i]=str[i];
};


String::String(const String &original):
    size(original.size), array(0)
{
    array = new char[size];
    for(int i=0; i<size; ++i)
        array[i]=original.array[i];
};

String::~String()
{
    for(int i=0; i<size; ++i)
        array[i]=0;
    delete []array;
    array=0;
};

////////////////////////////////////////////////////////////

int length(const char *str)
{
    int length=0;
    for(int i=0; str[i]; ++i)
        ++length;
    return ++length;
}

int String::length()
{
    int length=size-1;
    return length;
}

String String::substr(int pos, int n)
{

    int length=0;
    if(pos+n<size)
        length=n+1;
    else
        length=size-pos;

    String substr(length);

    for(int i=0, j=pos; i<substr.size-1; ++i, ++j)
        substr.array[i]=array[j];
    return substr;
}

char* String::c_str()
{
    char *c_str = new char[size];
    for(int i=0; i<size; ++i)
        c_str[i]=array[i];
    return c_str;
}

////////////////////////////////////////////////////////////

String String::operator+(const String &x)
{

    String y(size+x.size-1);

    if (size>0)
    {
        for(int i=0; i<size; ++i)
            y.array[i]=array[i];
        for(int i=size-1, j=0; i<y.size; ++i, ++j)
            y.array[i]=x.array[j];
    }
    else
        for(int i=size, j=0; i<y.size; ++i, ++j)
            y.array[i]=x.array[j];

    return y;
};

String &String::operator=(const String &original)
{
    if( this == &original )
        return *this;

    if(size!=original.size)
    {
        delete []array;
        size=original.size;
        array= new char [size];
    }
    for(int i=0; i<size; ++i)
        array[i]=original.array[i];
    return *this;
};

bool String::operator==(String &x)
{
    if (size!=x.size)
        return false;
    else
    {
        for(int i=0; i<size; )
            if(array[i]==x.array[i])
                ++i;
            else return false;
        return true;
    }
};

////////////////////////////////

bool String::operator>=(String &x)
{
    int total=size>x.size?size:x.size;
    for(int i=0; i<total; )
    {
        if(array[i]>x.array[i])
            return true;
        if(array[i]==x.array[i])
            ++i;
        else if(array[i]<x.array[i])
            return false;
        else ++i;
    }
    return true;
};

bool String::operator<=(String &x)
{
    int total=size>x.size?size:x.size;
    for(int i=0; i<total; )
    {
        if(array[i]<x.array[i])
            return true;
        if(array[i]==x.array[i])
            ++i;
        else if(array[i]>x.array[i])
            return false;
    }
    return true;
};

bool String::operator>(String &x)
{
    int total=size>x.size?size:x.size;
    for(int i=0; i<total-1; )
    {
        if(array[i]>x.array[i])
            return true;
        if(array[i]==x.array[i])
            ++i;
        else if(array[i]<x.array[i])
            return false;
    }
    return !array[total]==x.array[total];
};

bool String::operator<(String &x)
{
    int total=size>x.size?size:x.size;
    for(int i=0; i<total; )
    {
        if(array[i]<x.array[i])
            return true;
        if(array[i]==x.array[i])
            ++i;
        else if(array[i]>x.array[i])
            return false;
    }
    return array[total]==x.array[total]?false:true;
};

std::ostream &operator<<(std::ostream &output, const String &x)
{
    for (int i=0; x.array[i]; ++i)
        output<<x.array[i];
    return output;
};

std::istream  &operator>>(std::istream &input, const String &x)
{
    for(int i=0; i<x.size-1; ++i)
        input>>x.array[i];
    return input;
};
