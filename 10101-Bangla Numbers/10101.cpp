#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
using namespace std;

#define kuti 10000000
#define lakh 100000
#define hajar 1000
#define shata 100

void bangla(long long int);

int main(){

	long long int number;
	for (int i = 1; cin >> number; i++)
	{
		cout << setw(4) << i << ".";
		if (number == 0)
			cout << " 0";
		else
			bangla(number);
		cout << endl;
	}
	return 0;
}

void bangla(long long int number)
{
	if (number / kuti)
	{
		bangla(number / kuti);
		number %= kuti;
		cout << " kuti";
	}
	if (number / lakh)
	{
		bangla(number / lakh);
		number %= lakh;
		cout << " lakh";
	}
	if (number / hajar)
	{
		bangla(number / hajar);
		number %= hajar;
		cout << " hajar";
	}
	if (number / shata)
	{
		bangla(number / shata);
		number %= shata;
		cout << " shata";
	}
	if (number)
		cout << " " << number;
}