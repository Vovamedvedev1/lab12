#include <iostream>
#include <cmath>
#include "lab12.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Complex a;
    Complex b;
    Complex c;
    cin >> a;
    cin >> b;
    cin >> c;
    Complex d;
    try
    {
        d=(a+b)*c/(a-b);
        cout << "d=(a+b)*c/(a-b)" << endl;
        cout << "d=" << d << endl;
    }
    catch(const char* ex)
    {
        cout << ex << endl;
    }
    d+=5;
    cout << "d+=5" << endl;
    cout << "d=" << d << endl;
    d*=a;
    cout << "d*=a" << endl;
    cout << "d=" <<d << endl;
    try
    {
        d/=b;
        cout << "d/=b" << endl;
        cout << "d=" << d << endl;
    }
    catch(const char* ex)
    {
        cout << ex << endl;
    }
    Complex h;
    Complex m;
    h = d++;
    m = ++d;
    cout << "h=" << h << endl;
    cout << "m=" << m << endl;
    cout << "d=" << d << endl;
    cout << "h > m     " << bool(h>m) << endl;
    cout << "h < m     " << bool(h<m) << endl;
    Complex c1(3,1);
    Complex c2(-1,3);
    cout << "c1 = " << c1 << "       c2 = " << c2 << endl;
    cout << "c1 == c2    " << bool(c1==c2) << endl;
    cout << "c1 != c2    " << bool(c1!=c2) << endl;
    cout << "c1 == (c2*2)    " << bool(c1==(c2*2)) << endl;
    cout << "c1 != (c2/4)    " << bool(c1!=(c2/4)) << endl;
    return 0;
}
