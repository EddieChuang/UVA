#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

char table[26] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5',
                  '6', '6', '6', '7', '\0', '7', '7', '8', '8', '8', '9', '9', '9', '\0'};

string getPhoneNumber(string);    
int main(){

    int directory;
    cin >> directory;
    for(int j = 0; j < directory; ++j)
    {
        if(j != 0)
            cout << endl;
        
        int num;
        cin >> num;
        map<string, int> phones;
        string s;
        for(int i = 0; i < num; ++i)
        {
            cin >> s;
            string phone = getPhoneNumber(s);
            phones[phone]++;
        }
        
        bool duplicate = false;
        for(map<string, int>::iterator iter = phones.begin(); iter != phones.end(); iter++)
        {
            if(iter->second != 1)
            {
                duplicate = true;
                cout << iter->first << " " << iter->second << endl;
            }
        }
        if(duplicate == false)
            cout << "No duplicates.\n";
    }
}

string getPhoneNumber(string s)
{
    string phone = "";
    for(int i = 0; i < s.size(); ++i)
    {
        if(isalpha(s[i]))
            phone += table[s[i] - 'A'];
        else if(isdigit(s[i]))
            phone += s[i];
        if(phone.size() == 3)
            phone += '-';
    }
    return phone;
} 