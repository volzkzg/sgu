#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double a,b,c,d,e,f,g,h,i;
    cin >> a >> c >> b >> d >> f >> e;
    g = (a*a+b*b-f*f)/2,h = (a*a+c*c-d*d)/2,i = (b*b+c*c-e*e)/2;

    cout << setiosflags(ios::fixed)
	 << setprecision(4)
	 << sqrt(a*a*b*b*c*c+2*g*h*i-g*c*g*c-h*b*h*b-i*a*i*a)/6
	 << endl;
    return 0;
}
