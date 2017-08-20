#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <string>
using namespace std;

vector<vector<string>> commandI(int, int);
void commandC(vector<vector<string>>&);
void commandL(vector<vector<string>>&, int, int, string);
void commandV(vector<vector<string>>&, int, int, int, string);
void commandH(vector<vector<string>>&, int, int, int, string);
void commandK(vector<vector<string>>&, int, int, int, int, string);
void commandF(vector<vector<string>>&, int, int, string);
void commandS(vector<vector<string>>, string);
void fill(vector<vector<string>>&, int, int, string, string);
void swap(int&, int&);

int main(){
    
    string command;
    vector< vector<string> > bmp;
    while(getline(cin, command)){
        
        vector<string> tokens;
        istringstream iss(command);
        copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));

        if(tokens[0] == "X")
            break;
        if(tokens[0] == "I")
            bmp = commandI(atoi(tokens[1].c_str()), atoi(tokens[2].c_str()));
        else if(tokens[0] == "C")
            commandC(bmp);
        else if(tokens[0] == "L")
            commandL(bmp, atoi(tokens[1].c_str()), atoi(tokens[2].c_str()), tokens[3]);
        else if(tokens[0] == "V")
            commandV(bmp, atoi(tokens[1].c_str()), atoi(tokens[2].c_str()), atoi(tokens[3].c_str()), tokens[4]);
        else if(tokens[0] == "H")
            commandH(bmp, atoi(tokens[1].c_str()), atoi(tokens[2].c_str()), atoi(tokens[3].c_str()), tokens[4]);
        else if(tokens[0] == "K")
            commandK(bmp, atoi(tokens[1].c_str()), atoi(tokens[2].c_str()), atoi(tokens[3].c_str()), atoi(tokens[4].c_str()), tokens[5]);
        else if(tokens[0] == "F")
            commandF(bmp, atoi(tokens[1].c_str()), atoi(tokens[2].c_str()), tokens[3]);
        else if(tokens[0] == "S")
            commandS(bmp, tokens[1]);
    }
}

vector<vector<string>> commandI(int m, int n)
{
    vector<vector<string>> bmp(n+1, vector<string>(m+1, "O"));
    return bmp;
}

void commandC(vector<vector<string>> &bmp)
{
    for(int i = 1; i < bmp.size(); ++i)
        for(int j = 1; j < bmp[i].size(); ++j)
            bmp[i][j] = "O";
}

void commandL(vector<vector<string>> &bmp, int x, int y, string color)
{
    bmp[y][x] = color;
}

void commandV(vector<vector<string>> &bmp, int x, int y1, int y2, string color)
{
    if(y1 > y2)
        swap(y1, y2);
    for(int i = y1; i <= y2; ++i)
        bmp[i][x] = color;
}

void commandH(vector<vector<string>> &bmp, int x1, int x2, int y, string color)
{
    if(x1 > x2)
        swap(x1, x2);
    for(int i = x1; i <= x2; ++i)
        bmp[y][i] = color;
}

void commandK(vector<vector<string>> &bmp, int x1, int y1, int x2, int y2, string color)
{
    if(x1 > x2)
        swap(x1, x2);
    if(y1 > y2)
        swap(y1, y2);
    
    for(int i = y1; i <= y2; ++i)
        for( int j = x1; j <= x2; ++j)
            bmp[i][j] = color;
}

void commandF(vector<vector<string>> &bmp, int x, int y, string color)
{
    if(bmp[y][x] != color)
        fill(bmp, x, y, bmp[y][x], color);
}

void fill(vector<vector<string>> &bmp, int x, int y, string src, string color)
{
    int m = bmp[0].size();
    int n = bmp.size();
    if(x < 1 || x >= m || y < 1 || y >= n || bmp[y][x] != src)
        return;

    bmp[y][x] = color;       
    fill(bmp, x, y-1, src, color);//up    
    fill(bmp, x+1, y, src, color);//right     
    fill(bmp, x, y+1, src, color);//right  
    fill(bmp, x-1, y, src, color);//left
    
}

void commandS(vector<vector<string>> bmp, string name)
{
    cout << name << endl;
    for(int i = 1; i < bmp.size(); ++i)
    {
        for(int j = 1; j < bmp[i].size(); ++j)
            cout << bmp[i][j];
        cout << endl;
    }
}

void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}