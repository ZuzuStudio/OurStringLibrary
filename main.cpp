#include <iostream>
#include "newstring.h"

using namespace std;

int main()
{
    String a("hello");
    String b("world");
    String c;
    c=a+b;
    cout<<"First string: "<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<endl;

    String g("Hello World");
    cout<<g<<endl;
    cout<<"3 symbols after 2 element: "<<g.substr(2,15)<<endl;
    cout<<endl<<endl;

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
        cout<<a<<" not == "<<b<<endl<<endl<<endl;

    int len;
    cout<<"Length n: ";
    cin>>len;
    String ar(len);
    cout<<endl<<"Enter string (lenght n): ";
    cin>>ar;
    cout<<ar;


    return 0;
}
