#ifndef NEWSTRING_H_INCLUDED
#define NEWSTRING_H_INCLUDED

class String
{
public:
    String();
    String(int n);
    ~String();
    String(const String &original);

    String &operator=(String const &original)
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

    String operator+(String const&x)
    {
        String y(size+x.size);

        for(int i=0; i<size; ++i)
            y.array[i]=array[i];

        for(int i=size; i<x.size; ++i)
            y.array[i]=x.array[i];

        return y;
    };

    bool operator==(String const&x)
    {
        int total = size>x.size?size:x.size;

        for(int i=0; i<total; ++i)
            if(array[i]==x.array[i])
                ++i;
            else return false;
        return true;
    };
private:
    int size;
    char *array;
};


#endif // NEWSTRING_H_INCLUDED
