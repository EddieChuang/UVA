#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    
    int Case ;
    cin >> Case;
    cin.get();
    for(int j = 0; j < Case; ++j)
    {
        cin.get();
        if(j != 0)
            cout << endl;
        
        vector<int> p;        
        int index;        
        string str;
        
        getline(cin, str);
        stringstream ss(str);
        while(ss >> index)
            p.push_back(index);
        ss.clear();
            
        vector<string> arr(p.size() + 1);
        getline(cin, str);
        ss.str(str);
        for(int i = 0 ; i < p.size(); ++i)
            ss >> arr[p[i]];              
        for(int i = 1; i < arr.size(); ++i)
            cout << arr[i] << endl;
    }
}