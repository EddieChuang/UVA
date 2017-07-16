#include <iostream>
#include <algorithm>
using namespace std;

int main(){
   
    int n, q, h;  
    cin >> n;
    int *chimps = new int[n];
    for( int i = 0 ; i < n ; ++i )
        cin >> chimps[i];

    cin >> q;    
    for( int i = 0 ; i < q ; ++i )
    {
        cin >> h;
        int *lower = lower_bound(chimps, chimps + n, h);
        int *upper = upper_bound(chimps, chimps + n, h);
        
        if((lower == chimps + n) || *lower >= h)
            --lower;
        if((lower - chimps) < 0)
            cout << "X ";
        else
            cout << *lower << " ";

        if((upper - chimps) >= n)
            cout << "X" << endl;
        else
            cout << *upper << endl;
    }
   return 0;
}