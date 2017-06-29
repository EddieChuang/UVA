#include <iostream>
#include <vector>
using namespace std;

int main(){

	vector<int> arr;
	int insert;

	while (cin >> insert)
	{
		for (int i = 0; i < arr.size(); ++i)
		{
			if (arr[i] > insert)
			{
				int tmp = arr[i];
				arr[i] = insert;
				insert = tmp;
			}
		}
		arr.push_back(insert);

		int size = arr.size();
		if (size % 2 == 1)
			cout << arr[size / 2] << endl;
		else
			cout << (arr[size / 2 - 1] + arr[size / 2]) / 2 << endl;
	}
}