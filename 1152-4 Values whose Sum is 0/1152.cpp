#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	int t, n, number;
	cin >> t;

	while (t--)
	{
		cin >> n;

		vector<vector<int>> vec2d;
		vector<int> ab, cd;
		for (int i = 0; i < n; ++i)
		{
			vector<int> vec;
			for (int j = 0; j < 4; ++j)
			{
				cin >> number;
				vec.push_back(number);
			}
			vec2d.push_back(vec);
		}

		for (int i = 0; i < vec2d.size(); ++i)
		{
			for (int j = 0; j < vec2d.size(); ++j)
			{
				ab.push_back(vec2d[i][0] + vec2d[j][1]);
				cd.push_back(vec2d[i][2] + vec2d[j][3]);
			}
		}
		
		sort(cd.begin(), cd.end());

		int ans = 0;
		for (int i = 0; i < ab.size(); ++i)
			ans += upper_bound(cd.begin(), cd.end(), -ab[i]) - lower_bound(cd.begin(), cd.end(), -ab[i]); //binary search
		

		cout << ans << endl;
		if (t)
			cout << endl;
	}
	system("pause");
}
/*
int lower_bound(vector<int> vec, int x, int y, int v)
{
	int m;
	while (x < y)
	{
		m = x + (y - x) / 2;
		if (vec[m] >= v)
			y = m;
		else
			x = m + 1;
	}
	return x;
}

int upper_bound(vector<int> vec, int x, int y, int v)
{
	int m;
	while (x < y)
	{
		m = x + (y - x) / 2;
		if (vec[m] <= v)
			x = m + 1;
		else
			y = m;
	}
	return x;
}*/