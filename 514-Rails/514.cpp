#include <iostream>
#include <stack>
using namespace std;

int main(){

	int n = 0;
	while(cin >> n && n != 0)
	{
		while(true)
		{
			stack<int> B;
			int *C = new int[n];

			cin >> C[0];
			if(C[0] == 0)
				break;
			for(int i = 1; i < n; ++i)
				cin >> C[i];

			int i = 0, A = 1;
			while(A <= n)
			{
				B.push(A++);
				while(!B.empty() && C[i] == B.top())
				{
					B.pop();
					i++;
				}
			}
			if(i == n)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		cout << endl;
	}
	return 0;
}