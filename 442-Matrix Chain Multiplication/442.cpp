#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

int main() {

	map<string, pair<int, int>> matrix;
	string str, nop;
	int n, row, col, count = 0;

	cin >> n;
	while(n--) 
	{
	
		cin >> str >> row >> col;
		matrix[str] = pair<int, int>(row, col);
	}
	cin.get();

	stack<string> s;
	char c;
	while ((c = getchar()) != -1) 
	{
		if (c == '\n') 
		{
			cout << count << endl;
			count = 0;
			//s = stack<string>();
			s.pop();
		}
		else if(c == ')' && s.size() > 1)
		{
			string matA = s.top(); s.pop();
			string matB = s.top(); s.pop();
			pair<int, int> p2 = matrix[matA];
			pair<int, int> p1 = matrix[matB];
			if (p1.second == p2.first) 
			{
				count += p1.first * p1.second * p2.second;
				matrix[matA + matB] = pair<int, int>(p1.first, p2.second);
				s.push(matA + matB);
			}
			else 
			{
				cout << "error" << endl;
				getline(cin, nop);   
			}
		}
		else if (isalpha(c)) 
			s.push(string(1, c));
	}
	return 0;
}