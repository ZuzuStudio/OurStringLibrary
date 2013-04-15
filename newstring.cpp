#include "newstring.h"

String::String():
    size(0), array(0)
{
};

String::String(int n):
    size(n), array(0)
{
    array=new char[size];
};

//
String::String(const char *str):
    size(length(str)), array(0)
{
    array=new char[size];
    for(int i=0; i<size; ++i)
        array[i]=str[i];
};
//

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
    array=0;
};

////////////////////////////////////////////////////////////

int String::length(const char *str)
{
    int length=0;
    for(int i=0; str[i]; ++i)
        ++length;
    return length;
}

int String::length()
{
    return size;
}

String String::substr(int pos, int n)
{
    String substr(n);
    for(int i=0, j=pos; i<substr.size && j<size; ++i, ++j)
    substr.array[i]=array[j];
    return substr;

}

////////////////////////////////////////////////////////////

String String::operator+(String x)
{
    String y(size+x.size);

    for(int i=0; i<size; ++i)
        y.array[i]=array[i];

    for(int i=size, j=0; i<size+x.size; ++i, ++j)
    {
        y.array[i]=x.array[j];
    }
    return y;
};

String &String::operator=(const String &original)
{
    if( this == &original )
        return *this;
    delete []array;
    size=original.size;
    array= new char [size];
    for(int i=0; i<size; ++i)
        array[i]=original.array[i];
    return *this;

};

bool String::operator==(String x)
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
bool String::operator>=(String x)
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

bool String::operator<=(String x)
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

bool String::operator>(String x)
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
    return array[total]==x.array[total]?false:true;
};

bool String::operator<(String x)
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

std::ostream &operator<<(std::ostream &output, const String &a)
{
    for (int i=0; i<a.size; ++i)
        output<<a.array[i];
    return output;
};

std::istream  &operator>>(std::istream &input, const String &a)
{
    for(int i=0; i<a.size; ++i)
        input>>a.array[i];
    return input;
};
