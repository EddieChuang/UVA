#include <iostream>
#include <math.h>
using namespace std;

int main(){

	double v, t;
	while (cin >> v >> t)
	{
		double a = v / t;    //v = v0+at
		double s = 0.5 * a * pow(2 * t, 2);  //S = 1/2 * a * t^2
		
		if (v == 0 || t == 0)
			cout << 0 << endl;
		else
			cout << s  << " " << 2 * v * t << endl;

	}



	system("pause");
	return 0;
}