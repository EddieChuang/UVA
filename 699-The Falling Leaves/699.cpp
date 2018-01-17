#include <iostream>
#include <map>
using namespace std;

void buildTree(int, int);

 map<int, int> col_weight;

int main(){

    int Case = 1, value;
    while(cin >> value && value != -1){

        col_weight.clear();

        buildTree(value, 0);

        map<int, int>::iterator it = col_weight.begin();

        cout << "Case " << Case++ << ":" << endl << it->second;
        for(++it; it != col_weight.end(); ++it)
            cout << " " << it->second;
        cout << endl << endl;
    }
    return 0;
}

void buildTree(int value, int col){

    if(value == -1)
        return;
    col_weight[col] += value;

    cin >> value;
    buildTree(value, col-1);

    cin >> value;
    buildTree(value, col+1);
}