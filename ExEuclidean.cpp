#include <bits/stdc++.h>
using namespace std;
int gcdExtended(int a, int b, int *x1, int *y1)
{
	if (a == 0)
	{
		*x1 = 0;
		*y1 = 1;
		return b;
	}
	int x2, y2; 
	int gcd = gcdExtended(b%a, a, &x2, &y2);	
	*x1 = y2 - (b/a) * x2;
	*y1 = x2;
	return gcd;
}
int main()
{
	int x1, y1, a = 30, b = 12;
	int g = gcdExtended(a, b, &x1, &y1);
	cout << "GCD(" << a << ", " << b
		<< ") = " << g << endl;
	return 0;
}
