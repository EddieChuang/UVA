#include <iostream>
#include <cmath>
using namespace std;

int main(){
    
    int l, D, I;
    cin >> l;
    for(int i = 0; i < l; ++i)
    {        
        cin >> D >> I;
        I--;
        int x = 1 << (D-1);
        int y = 0;
        for(int j = D-2; j >= 0; --j)
        {
            y ^= (I%2) << j;
            I /= 2;
        }
        x ^= y;
        cout << x << endl;
    }
    return 0;
}
