#include <iostream>
using namespace std;

int main(){

    int cola, empty, ans;
    while(cin >> cola)
    {
        empty = ans = 0;
        while(cola)
        {
            ans += cola;
            empty += cola%3;
            cola = cola/3 + empty/3;
            empty %= 3;
        }
        
        if(empty == 2)
            ans++;
        cout << ans << endl;
    }
    return 0;
}