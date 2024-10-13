/*
Copyright (c) 2019 Michael Neill Hartman. All rights reserved.
mnh_license@proton.me
https://github.com/hartmanm
*/

#include <iostream>
#include <string>
#include <ctime>
using namespace std;
int main()
{
clock_t start;
double duration;
duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
int i=0;
int a,b,c = -1;
for(i=1; i < 101; i++)
{
a = i % 3;
b = i % 5;
c = a + b;
//cout << " index ";
cout << i;
cout  << " ";
if(a != 0 && b != 0)
{
cout << "fail"; // is a not a factor of either 5 or 3
cout << endl;
}
else
{
if(c == 0)
{
cout << "foo"; // is a factor of both
cout << endl;
}
if(a == 0 && b != 0)
{
cout << "bar"; // is a factor of 3 and not 5
cout << endl;
}
if(a != 0 && b == 0)
{
cout << "baz"; // is a factor of 5 and not 3
cout << endl;
}
}
}
cout << endl;
cout << duration;
cout << endl;
return 0;
};
