#include <iostream>
#include<algorithm>
using namespace std;

int main(){

	int Case, r;
	cin >> Case;

	while (Case-- && cin >> r)
	{
		int *s = new int[r+1];
		for (int i = 1; i <= r; ++i)
			cin >> s[i];

		sort(s + 1, s + r + 1);
		int vito = (r % 2) ? s[r / 2 + 1] : (s[r / 2] + s[r / 2 + 1]) / 2;
		int sum = 0;
		for (int i = 1; i <= r; ++i)
			sum += abs(vito - s[i]);
		cout << sum << endl;
	}
	return 0;
}