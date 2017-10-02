#include <iostream>
using namespace std;

int main() {

	int Case;
	cin >> Case;
	while (Case--)
	{
		int n;
		cin >> n;

		int *train = new int[n];
		for (int i = 0; i < n; ++i)
			cin >> train[i];

		int count = 0;
		for (int i = 0; i < n - 1; ++i)
			for (int j = i + 1; j < n; ++j)
				if (train[i] > train[j])
				{
					count++;
					swap(train[i], train[j]);
				}
		
		cout << "Optimal train swapping takes " << count << " swaps." << endl;
	}
	return 0;
}