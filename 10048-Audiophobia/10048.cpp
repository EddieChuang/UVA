#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

void Floyd_Warsharll(int[101][101], int);

int main() {

	int c, s, q, Case = 0;
	while (cin >> c >> s >> q && (c || s || q))
	{
		
		int d[101][101], c1, c2, db;
		for (int i = 0; i <= c; ++i)
			for (int j = 0; j <= c; ++j)
				d[i][j] = i == j ? 0 : numeric_limits<int>::max();
		
		for (int i = 0; i < s; ++i)
		{
			cin >> c1 >> c2 >> db;
			d[c1][c2] = d[c2][c1] = db;
		}
		Floyd_Warsharll(d, c);

		if (Case)
			cout << endl;
		cout << "Case #" << ++Case << endl;
		for (int i = 0; i < q; ++i)
		{
			cin >> c1 >> c2;
			if (d[c1][c2] == numeric_limits<int>::max())
				cout << "no path" << endl;
			else
				cout << d[c1][c2] << endl;
		}
		
	}
	return 0;
}

void Floyd_Warsharll(int d[101][101], int c)
{
	for (int k = 1; k <= c; ++k)
		for (int i = 1; i <= c; ++i)
			for (int j = 1; j <= c; ++j)
				d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
}