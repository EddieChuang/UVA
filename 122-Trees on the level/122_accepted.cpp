#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {

	int value;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : value(0), left(NULL), right(NULL) {}
};

void buildTree(TreeNode *root, int value, string path);
vector<int> isCompleted(TreeNode *root);

int main() {

	string node;
	TreeNode *root = new TreeNode;
	int count = 0;
	bool completed = true;
	while (cin >> node)
	{
		if (node != "()")
		{
			int index = node.find(",");
			int value = stoi(node.substr(1, index - 1));
			string path = index == node.size() - 1 ? "" : node.substr(index + 1, node.size() - index - 2); //when index==node.size()-1, the node is root. ex:(5,)

			buildTree(root, value, path);
			++count;
		}
		else
		{
			vector<int> print = isCompleted(root);
			if (print.size() == count)
			{
				cout << print[0];
				for (int i = 1; i < print.size(); ++i)
					cout << " " << print[i];
				cout << endl;
			}
			else
				cout << "not complete" << endl;

			// reset
			root = new TreeNode;
			count = 0;
			completed = true;
		}
	}
	return 0;
}

void buildTree(TreeNode *root, int value, string path)
{
	TreeNode *curr = root;
	for (int i = 0; i < path.size(); ++i)
	{
		if (path[i] == 'L')
		{
			if (!curr->left)
				curr->left = new TreeNode;
		}
		else if (path[i] == 'R')
		{
			if (!curr->right)
				curr->right = new TreeNode;
		}

		curr = path[i] == 'L' ? curr->left : curr->right;
	}
	curr->value = value;
}

vector<int> isCompleted(TreeNode *root)
{
	queue<TreeNode*> q;
	q.push(root);
	
	vector<int> print;
	while (!q.empty())
	{
		TreeNode *node = q.front();
		q.pop();

		if (node->value == 0)
			break;
		if (node->left)
			q.push(node->left);
		if (node->right)
			q.push(node->right);
		print.push_back(node->value);
	}
	return print;
}