#include <iostream>
#include <memory.h>
using namespace std;

void drawImage(int, int, int);

int image[32][32];
int count, pos;
string str;

int main(){

    int t;
    cin >> t;

    while(t--){

        memset(image, 0, sizeof(image));
        count = 0;
        
        for(int i = 1; i <= 2; ++i){
            cin >> str;
            pos = -1;
            drawImage(0, 0, 32);
        }
        cout << "There are " << count << " black pixels." << endl;
    }
    return 0;
}

void drawImage(int r, int c, int width){

    ++pos;
    int w = width / 2;
    if(str[pos] == 'p'){
        drawImage(r, c + w, w);
        drawImage(r, c, w);
        drawImage(r + w, c, w);
        drawImage(r + w, c + w, w);
    }
    else if(str[pos] == 'f'){
        for(int i = r; i < r + width; ++i)
            for(int j = c; j < c + width; ++j)
                if(!image[i][j]){
                    image[i][j] = 1;
                    ++count;
                }
    }
}