#include <iostream>
#include <sstream>
#include <map>
#include <string>
using namespace std;

int main(){

	int n;
	cin >> n;
	cin.ignore();
	map<string, int> conquest;
	while (n--)
	{
		string str;
		getline(cin, str);

		stringstream ss(str);
		ss >> str;

		if (conquest.count(str) > 0)
			conquest[str]++;
		else
			conquest[str] = 1;
	}
	for (map<string, int>::iterator it = conquest.begin(); it != conquest.end(); it++)
		cout << it->first << " " << it->second << endl;

	system("pause");
}