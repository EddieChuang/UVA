#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

void reset(int[]);
void setNode(int[], int, string);
void traverse(int[]);

int max_length = 1;

int main(){
    
    string str;
    int tree[257];
    reset(tree);
    while(cin >> str)
    {
        if(str == "()")
        {
            traverse(tree);
            reset(tree);
            continue;
        }
        str = str.substr(1, str.length()-2);  //(5,LL)
        
        char *cstr = new char[str.length() + 1];
        strcpy(cstr, str.c_str());
        
        char *pch = strtok(cstr, ",");
        int v = atoi(pch);
        pch = strtok(NULL, ",");
        if(pch == NULL)
            tree[1] = v;
        else
        {
            str = pch;
            setNode(tree, v, str);
        }
        delete []cstr;
        delete pch;
    }
    return 0;
}

void setNode(int tree[], int v, string instruct)
{
    int index = 1;
    for(int i = 0; i < instruct.length(); ++i)
    {
        if(tree[index] == -1)
            tree[index] = 0;
        if(instruct[i] == 'L')
           index *= 2;
        else if(instruct[i] == 'R')
            index *= 2 + 1;    
    }
    
    tree[index] = v;
    if(index > max_length)
        max_length = index;
}

void reset(int tree[])
{
    max_length = 1;
    for(int i = 0; i < 257; ++i)
        tree[i] = -1;
}

void traverse(int tree[])
{
    for(int i = 1; i <= max_length; ++i)
    {
        if(tree[i] == 0)
        {
            cout << "not complete" << endl;
            return;
        }
    }
    for(int i = 1; i <= max_length; ++i)
        if(tree[i] != -1)
            cout << tree[i] << " ";
    cout << endl;
}
