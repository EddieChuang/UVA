#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int n;
    while(cin >> n && n != 0)
    {
        int *age = new int[n];
        for(int i = 0; i < n; ++i)
            cin >> age[i];
        
        sort(age, age + n);
        cout << age[0];
        for(int i = 1; i < n; ++i)
            cout << " " << age[i];
        cout << "\n";
    }
}