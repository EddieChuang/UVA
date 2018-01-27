#include <iostream>
#include <vector>
using namespace std;

void buildTree(vector<string>, int, int, int);
int main(){

    int t;
    cin >> t;
    cin.get();
    while(t--){

        vector<string> tree;
        string str;
        while(getline(cin, str) && str[0] != '#')
            tree.push_back(str);
        if(tree.size() != 0)
            buildTree(tree, 0, 0, tree[0].size()-1);
        else
            cout << "()";
        cout << endl;
    }
    return 0;
}

void buildTree(vector<string> tree, int row, int left, int right){

    cout << "(";
    for(int i = left; i <= right; ++i){
        if(tree[row][i] != ' ' && tree[row][i] != '#' && tree[row][i] != '-' && tree[row][i] != '|' && tree[row][i] != '\0'){
            cout << tree[row][i];
            if(row+1 < tree.size() && tree[row+1][i] == '|'){
                int L = i, R = i;
                while(L-1 >= 0 && tree[row+2][L-1]=='-')
                    --L;
                while(R+1<tree[row+2].size() && tree[row+2][R+1]=='-')
                    ++R;
                buildTree(tree, row+3, L, R);
            }
            else{
                cout << "()";
            }
        }
    }
    cout << ")";
}