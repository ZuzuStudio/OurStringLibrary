#include <iostream>
#include "newstring.h"

using namespace std;

int main()
{
    String a("Hello ");
    cout<<"String class 'a': "<<a<<endl;

    String b("World!");
    cout<<"String class 'b': "<<b<<endl;

    String c;
    c=a+b;
    cout<<"String class 'c=a+b': "<<c<<endl<<endl;;
    cout<<"Length of string 'c' "<<c.length()<<endl;
    String g("Hello World!");
    cout<<"String class 'g': "<<g<<endl;
    cout<<"Substring with position 6 & 15 elements after: "<<g.substr(6,15)<<endl<<endl;

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

    String f(5);
    cout<<"Finaly actin: input strung with 5 symbols: ";
    cin>>f;
    cout<<"Your sting: "<<f<<endl;

    return 0;
}
