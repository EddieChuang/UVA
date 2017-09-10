#include <iostream>
using namespace std;

int DFS(string*, int, int);
int m, n;

int main(){
    
    while(cin >> m >> n && m && n)
    {
        cin.get();
        string *oil = new string[m];
        for(int i = 0; i < m; ++i)
            getline(cin, *(oil+i));
        
        int count = 0;
        for(int i = 0; i < m; ++i)  
            for(int j = 0; j < n; ++j)
                if(oil[i][j] == '@')
                    count += DFS(oil, i, j);
        cout << count<< endl;
    }
    return 0;
}

int DFS(string *oil, int row, int col)
{
    oil[row][col] = '*';
    for(int i = -1; i <= 1; ++i)
        for(int j = -1; j <= 1 && (row+i < m) && (row+i >=0); ++j)
            if(col+j < n && col+j >= 0 && oil[row+i][col+j] == '@')
                DFS(oil, row+i, col+j); 
    return 1;
}