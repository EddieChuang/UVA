#include <iostream>
using namespace std;

int main(){

	int t, s, d;
	cin >> t;

	while (t-- && cin >> s >> d)
	{
		int x = (s + d) / 2;
		int y = (s - d) / 2;

		if (x > s || y > s || (s+d) % 2 != 0)
		{
			cout << "impossible" << endl;
			continue;
		}
		cout << x << " " << y << endl;
	}
	return 0;
}