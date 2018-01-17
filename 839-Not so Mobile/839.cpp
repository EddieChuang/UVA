#include <iostream>
using namespace std;

int buildMobile();

bool isBalance;

int main(){

    int Case;
    cin >> Case;
    
    while(Case--){
        
        isBalance = true;
        buildMobile();
        
        if(isBalance)
            cout << "YES" << endl;
        else
            cout << "NO"  << endl;
        if(Case)
            cout << endl;
    }
    return 0;
}

int buildMobile(){

    int w1, w2, d1, d2;
    cin >> w1 >> d1 >> w2 >> d2;

    w1 = w1 ? w1 : buildMobile();
    w2 = w2 ? w2 : buildMobile();
   
    isBalance &= (w1*d1==w2*d2);

    return w1 + w2;
}