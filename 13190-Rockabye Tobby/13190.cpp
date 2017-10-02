#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct element{

	string name;
	int time, fequency, priority;
	element(string n, int t, int feq, int pri) : name(n), time(t), fequency(feq), priority(pri) {}

	bool operator<(const element &rhs) const
	{
		if (time < rhs.time)
			return false;
		else if (time == rhs.time && priority < rhs.priority)
			return false;
		return true;
	}
};

int main() {

	string name;
	int Case = 0, n, k, feq;
	cin >> Case;

	while (Case--)
	{
		cin >> n >> k;
		priority_queue<element> medicine;
		for (int i = 0; i < n; ++i)
		{
			cin >> name >> feq;
			medicine.push(element(name, feq, feq, i));
		}

		while (k)
		{
			for (int i = 0; i < medicine.size(); ++i)
			{
				element tmp = medicine.top();
				medicine.pop();
				cout << tmp.time << " " << tmp.name << endl;

				tmp.time += tmp.fequency;
				medicine.push(tmp);
				if (--k == 0)
					break;
			}
		}
	}
	return 0;
}