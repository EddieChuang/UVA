#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include<map> 
using namespace std;

struct less_second{
    typedef pair<int, int> type;
    bool operator ()(type const& a, type const &b) const{
        return a.second < b.second;
    }
};

int main(){

    string input;
    int newLine = 0;
    while(getline(cin, input))
    {
        if(newLine++)
            cout << endl;
        
        map<int, int, greater<int>> frequency;
        for(int i = 0; i < input.length(); ++i)
            frequency[(int)input[i]] = frequency.count((int)input[i])?frequency[(int)input[i]]+1:1;
        
        vector<pair<int, int>> vec_map(frequency.begin(), frequency.end());
        sort(vec_map.begin(), vec_map.end(), less_second());
        for(vector<pair<int, int>>::iterator it = vec_map.begin(); it != vec_map.end(); it++)
            cout << it->first << " " << it->second << endl;  
    }
    return 0;
}