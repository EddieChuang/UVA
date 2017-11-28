#include <iostream>
#include <map>
#include <string>
using namespace std;

void Floyd_Warshall(bool[][100], int);
void print(bool[][100], map<int, string>);

int main(){

	int n, m, Case = 1;
	while (cin >> n >> m && n && m)
	{
		bool call[100][100] = { false };
		map<int, string> id_people;
		map<string, int> people_id;
		string caller, callee;
		
		int id = 0;
		while (m--)
		{
			cin >> caller >> callee;
			if (people_id.find(caller) == people_id.end())
			{
				people_id[caller] = id;
				id_people[id++] = caller;
			}
			if (people_id.find(callee) == people_id.end())
			{
				people_id[callee] = id;
				id_people[id++] = callee;
			}
			call[people_id[caller]][people_id[callee]] = true;
		}

		cout << "Calling circles for data set " << Case++ << ":" << endl;
		Floyd_Warshall(call, n);
		print(call, id_people);

	}
	return 0;
}

void Floyd_Warshall(bool call[][100], int n)
{
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				call[i][j] = call[i][j] || (call[i][k] && call[k][j]);
}

void print(bool call[][100], map<int, string> id_people)
{
	int n = id_people.size();
	bool check[100] = { false };
	for (int i = 0; i < n; ++i)
	{
		if (check[i])
			continue;

		cout << id_people[i];
		check[i] = true;
		for (int j = 0; j < n; ++j)
		{
			if (call[i][j] && call[j][i] && !check[j])
			{
				cout << ", " << id_people[j];
				check[j] = true;
			}
		}
		cout << endl;
	}
}
