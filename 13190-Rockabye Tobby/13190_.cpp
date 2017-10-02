#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<string, int> Pair;

int main() {

	string name;
	int Case = 0, n, k, feq;
	cin >> Case;

	while (Case--)
	{
		cin >> n >> k;
		vector<Pair> medicine;
		vector<int> f;
		for (int i = 0; i < n; ++i)
		{
			cin >> name >> feq;
			f.push_back(feq);
			medicine.push_back(Pair(name, feq));
		}

		int now = 1;
		while (k)
		{
			for (int i = 0; i < medicine.size(); ++i)
			{
				if (now >= medicine[i].second)
				{
					cout << medicine[i].second << " " << medicine[i].first << endl;
					medicine[i].second += f[i];
					if (--k == 0)
						break;
				}
			}
			now++;
		}
	}

	system("pause");
	return 0;
}