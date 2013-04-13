#include "newstring.h"

String::String():
            size(0), array(0)
            {};

String::String(int n):
            size(n), array(0)
            {
                array=new char[size];
            };

String::~String()
{
    for(int i=0; i<size; ++i)
    array[i]=0;
    array=0;
}

