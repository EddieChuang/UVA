#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

typedef pair<char, int> Pair;

bool sortByValue(const Pair  &lhs, const Pair &rhs){
	
	if (lhs.second > rhs.second)
		return true;
	else if (lhs.second < rhs.second)
		return false;
	else if (lhs.first < rhs.first)
		return true;
	return false;
}

//struct sortByValue{
//	bool operator()(const pair<char, int> lhs, const pair<char, int> &rhs){
//		return lhs.second > rhs.second;
//	}
//};

int main(){

	map<char, int> count_map;
	for (int i = 0; i < 26; ++i)
		count_map['A' + i] = 0;
	
	int n;
	cin >> n;
	cin.get();
	while (n--)
	{
		string line;
		getline(cin, line);
		for (int i = 0; i < line.size(); ++i)
			if (toupper(line[i]) >= 'A' && toupper(line[i]) <= 'Z')
				count_map[toupper(line[i])]++;
	}

	vector<pair<char, int>> vec(count_map.begin(), count_map.end());
	sort(vec.begin(), vec.end(), sortByValue);

	for (int i = 0; i < vec.size(); ++i)
		if (vec[i].second)
			cout << vec[i].first << " " << vec[i].second << endl;

	return 0;
}