#include<iostream>
#include <string>
#include <vector>

using namespace std;

void rotate(vector<string>, int);

int main(){
	
	vector<string> sentences;
	string sentence;
	int maxlen = 0;
	while (getline(cin, sentence))
	{
		sentences.push_back(sentence);
		if (maxlen < sentence.size())
			maxlen = sentence.size();
	}
	rotate(sentences, maxlen);

	system("pause");
	return 0;
}

void rotate(vector<string> sentences, int maxlen)
{
	for (int i = 0; i < maxlen; ++i)
	{
		for (int j = sentences.size() - 1; j >= 0; --j)
		{
			if (i < sentences[j].size())
				cout << sentences[j][i];
			else
				cout << " ";
		}
		cout << endl;
	}
}