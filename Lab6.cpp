#include <iostream>
#include <cmath>

using namespace std;

float f(float x1, float x2)
{
	return x1*x1*x1*x1 + 24*x1*x1*x1 + 2*x1*x1*x2*x2 - 32*x1*x1*x2+344*x1*x1+24*x1*x2*x2-384*x1*x2+2396*x1+x2*x2*x2*x2-32*x2*x2*x2+456*x2*x2-3200*x2+9979;
}

float g1(float x1, float x2)
{
	return 4*x1*x1*x1+24*3*x1*x1+4*x1*x2*x2-64*x1*x2+688*x1+24*x2*x2-384*x2+2396;
}

float g2(float x1, float x2)
{
	return 4*x1*x1*x2-32*x1*x1+48*x1*x2-384*x1+4*x2*x2*x2-32*3*x2*x2+456*2*x2-3200;
}

void step(float &x1, float &x2, float h=0.001)
{
	float y1 = x1 - h*g1(x1, x2);
	float y2 = x2 - h*g2(x1, x2);
	x1 = y1; x2 = y2;
}

float dist(float x1, float x2, float y1, float y2)
{
	float d1 = x1-y1, d2 = x2-y2;
	return sqrtf(d1*d1 + d2*d2);
}

float EPS = 0.0001;

int main()
{
	float x1 = 6, x2 = -6, px1, px2, func = 0, pfunc = 0;
	float h = 0.001;
	
	do 
	{
		pfunc = func;
		px1 = x1; px2 = x2; 
		step(x1, x2);
		h *= 0.95; // drobim shag
		func = f(x1, x2);
		cout << "x1 = " << x1 << ", x2 = " << x2 << " f = " << func << endl;
	}
	while(dist(x1,x2, px1,px2) > EPS || fabs(func-pfunc) > EPS);
	
	cout << "X* = (" << x1 << ", " << x2 << ") f = " << func << endl;
}
