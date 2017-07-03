#include <iostream>
using namespace std;

void mergeSort(int *, int, int, int&);
int merge(int *, int, int, int, int);

int main(){

    int num;
    while (cin >> num)
    {
		int count = 0;
        int *ary = new int[num];
        for(int i = 0; i < num; ++i)
            cin >> ary[i];

        mergeSort(ary, 0, num, count);
        cout << count << endl;
    }
    return 0;
}


void mergeSort(int *ary, int begin, int size, int &count)
{
    if(size == 1)
        return;

    int n1 = size / 2;
    int n2 = size - n1;
    int right = begin + n1;
    mergeSort(ary, begin, n1, count);
    mergeSort(ary, right, n2, count);
    count += merge(ary, begin, right, n1, n2);
}

int merge(int *ary, int left, int right, int n1, int n2)
{
    int *tmp = new int[n1 + n2];
	int count = 0;
    for(int i = 0, j = 0, k = 0; i < n1 || j < n2; ++k)
    {
        if(i == n1)
            tmp[k] = ary[right + (j++)];
        else if(j == n2)
            tmp[k] = ary[left + (i++)];
        else if(ary[left + i] < ary[right + j])
            tmp[k] = ary[left + (i++)];
        else
        {
            tmp[k] = ary[right + j];
            count += (right + j) - (left + k);
			j++;
        }
    }
    for(int i = 0; i < n1 + n2; ++i)
        ary[left + i] = tmp[i];
	return count;
}
