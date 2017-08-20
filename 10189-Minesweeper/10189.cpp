#include <iostream>
using namespace std;

void sweeper(char **, int, int);
void print(char **, int, int, int);

int main(){
    
    int m, n, Case = 0;
    while(cin >> m >> n && m != 0 && n != 0)
    {
        if(Case != 0)
            cout << endl;
        
        char **mine = new char*[m+2];
        for(int i = 0; i < m+2; ++i)
            *(mine + i) = new char[n+2];
        
        for(int i = 0; i < m+2; ++i)
            for(int j = 0; j < n+2; ++j)
                *(*(mine+i)+j) = '0';

        char c;
        for(int i = 1; i <= m; ++i)
        {    
            for(int j = 1; j <= n; ++j)
            {
                cin >> c;
                if(c == '*')
                {
                    *(*(mine+i)+j) = c;
                    sweeper(mine, i, j); 
                }
            }
        }
        print(mine, m, n, ++Case);    
    }   
}

void sweeper(char **mine, int x, int y)
{
    for(int i = -1; i <= 1; ++i)
    {
        for(int j = -1; j <= 1; j++)
            if(*(*(mine + x+i) + y+j) != '*')
                (*(*(mine + x+i) + y+j))++;
    }        
}

void print(char **mine, int m, int n, int Case)
{
    cout << "Field #" << Case << ":" << endl;
    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= n; ++j)
            cout << *(*(mine + i) + j);
        cout << endl;
    }       
}