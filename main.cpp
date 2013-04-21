#include <iostream>
#include "newstring.h"

using namespace std;

int main()
{
    String a("Hello ");
    cout<<"String class 'a': \""<<a<<"\" with length: "<<a.length()<<endl;

    String b("World!");
    cout<<"String class 'b': \""<<b<<"\" with length: "<<b.length()<<endl;

    String c;
    c=a+b;
    cout<<"String class 'c=a+b': \""<<c<<"\" with length: "<<c.length()<<endl<<endl;

    String g;
    g=c.substr(0,6);
    cout<<"Substring 'g' of String 'c' with position 0 & 6 elements after: "<<endl<<"\""<<g<<"\" with length: "<<g.length()<<endl;
    g=c.substr(6,15);
    cout<<"Substring 'g' of String 'c' with position 6 & 15 elements after: "<<endl<<"\""<<g<<"\" with length: "<<g.length()<<endl<<endl;


    cout<<"Some comparisons: "<<endl;
    if(a>=b)
        cout<<a<<" >= "<<b<<endl;
    else
        cout<<a<<" not >= "<<b<<endl;

    if(a<=b)
        cout<<a<<" <= "<<b<<endl;
    else
        cout<<a<<" not <= "<<b<<endl;

    if(a>b)
        cout<<a<<" > "<<b<<endl;
    else
        cout<<a<<" not > "<<b<<endl;

    if(a<b)
        cout<<a<<" < "<<b<<endl;
    else
        cout<<a<<" not < "<<b<<endl;

    if(a==b)
        cout<<a<<" == "<<b<<endl;
    else
        cout<<a<<" not == "<<b<<endl;
    cout<<endl;

    String l("lalka");
    cout<<"String class 'l': "<<l<<endl;;
    char *p;
    p=l.c_str();
    cout<<"Result of 'l.c_str' function: ";
    cout<<p<<endl<<endl;

    String f(5); // length include \0 symbol
    cout<<"Finaly actin: input strung with 4 symbols: ";
    cin>>f;
    cout<<"Your sting: "<<f<<endl;

    return 0;
}
