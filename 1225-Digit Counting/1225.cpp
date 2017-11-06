#include <iostream>
#include <string>
using namespace std;

int main() {

	int Case, n;
	cin >> Case;
	while (Case--)
	{
		cin >> n;
		string seq = "";
		for (int i = 1; i <= n; ++i)
			seq += to_string(i);

		int count[10] = { 0 };
		for (int i = 0; i < seq.size(); ++i)
			count[seq[i] - '0']++;

		cout << count[0];
		for (int i = 1; i < 10; ++i)
			cout << " " << count[i];
		cout << endl;
	}
	return 0;
}