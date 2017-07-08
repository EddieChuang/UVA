#include <iostream>
using namespace std;

int main(){
    
    int n;
    while(cin >> n && n != 0)
    {
        int count[200001] = {0};
        int age, min=200001, max=-1;
        for(int i = 0; i < n; ++i)
        {   
            cin >> age;
            count[age]++;
            if(age < min)
                min = age;
            if(age > max)
                max = age;
        }
        
        count[min]--;
        cout << min;
        for(int i = min; i <= max; ++i)
            while(count[i]--)
                cout << " " << i ;
        cout << endl;
    }  
}