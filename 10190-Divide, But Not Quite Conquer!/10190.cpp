#include <iostream>
#include <vector>

using namespace std;

int main(){

	int n, m;
	while (cin >> n >> m)
	{
		vector<int> seq;
		while (n && m > 1&& (n == 1 || n % m == 0))
		{
			seq.push_back(n);
			n /= m;
		}



		if (seq.size() <= 1 || seq[seq.size() - 1] != 1)
			cout << "Boring!" << endl;
		else
		{
			cout << seq[0];
			for (int i = 1; i < seq.size(); ++i)
				cout << " " << seq[i];
			cout << endl;
		}
	}
	return 0;
}