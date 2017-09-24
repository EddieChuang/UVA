#include <iostream>
using namespace std;

int largest(char**, int, int, int, int);

int main(){

	int Case, m, n, q, r, c;
	cin >> Case;

	while (Case--)
	{
		cin >> m >> n >> q;
		char **square = new char *[m];
		for (int i = 0; i < m; ++i)
		{
			square[i] = new char[n];
			for (int j = 0; j < n; ++j)
				cin >> square[i][j];
		}
		cout << m << " " <<  n << " " << q << endl;
		while (q--)
		{
			cin >> r >> c;
			cout << largest(square, r, c, m, n) << endl;
		}
	}
	return 0;
}

int largest(char** square, int r, int c, int m, int n)
{
	int len = 1;
	while (r - len >= 0 && c - len >= 0 && r + len < m && c + len < n)
	{
		for (int i = -len; i <= len; i += len)
			for (int j = -len; j <= len; j += len)
				if (square[r][c] != square[r + i][c + j])
					return (len - 1) * 2 + 1;
		len ++;
	}
	return (len - 1) * 2 + 1;
}