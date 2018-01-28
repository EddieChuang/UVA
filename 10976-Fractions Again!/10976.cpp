#include <iostream>
using namespace std;

int main(){

    int k;
    while(cin >> k){

        int count = 0;
        int x[100000], y[100000];
        for(int y_ = k+1; y_ <= 2*k; ++y_){
            if((y_*k) % (y_-k) == 0){
                x[count] = (y_*k) / (y_-k);
                y[count++] = y_;
            }
        }
        cout << count << endl;
        for(int i = 0; i < count; ++i)
            cout << "1/" << k << " = 1/" << x[i] << " + 1/" << y[i] << endl;
    }
    return 0;
}