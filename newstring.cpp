class String
{
    public:
        String():
            size(0), array(0)
            {};
        String(int n):
            size(n), array(0)
            {
                array=new char[size];
            };

       String(const String &original);

       String &operator=(const String &original)
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

       String operator+(String x)
       {
           String y(size+x.size);

           for(int i=0; i<size; ++i)
            y.array[i]=array[i];

           for(int i=size; i<x.size; ++i)
            y.array[i]=x.array[i];

            return y;
       };

       String operator==(String x)
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

String::String(const String &original):
size(original.size), array(0)
{
    array = new char[size];
	for(int i=0; i<size; ++i)
	array[i]=original.array[i];
}
