#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct node{
    
    int value;
    node *left = NULL;
    node *right = NULL;
    
};

void createTree(node**, vector<int>, vector<int>);
void DFS(node*, int);
void clearTree(node*);
int find(vector<int>, int);
int minimum;
int ans;

int main(){
    
    string order;
    int x;
    node *tree;
    while(getline(cin, order))
    {
        vector<int> inorder, postorder;
        ans = minimum = 99999;
        
        stringstream ss(order);
        while(ss >> x)
            inorder.push_back(x);
        
        ss.str("");
        ss.clear();
        
        getline(cin, order);
        ss << order;
        while(ss >> x)
            postorder.push_back(x);
        
        createTree(&tree, inorder, postorder);
        DFS(tree, 0);
        clearTree(tree);
        cout << ans << endl;
    }
    
    
}

void createTree(node **tree, vector<int> inorder, vector<int> postorder)
{
    if(postorder.size() == 0)
        return;
    
    int root = postorder.back();
    *tree = new node;
    (*tree)->value = postorder.back();
    
    if(postorder.size() == 1)
        return;
    
    int index = find(inorder, root);
    vector<int> inorder_left(inorder.begin(), inorder.begin()+index);
    vector<int> inorder_right(inorder.begin()+index+1, inorder.end());
    vector<int> postorder_left(postorder.begin(), postorder.begin()+inorder_left.size());
    vector<int> postorder_right(postorder.begin()+inorder_left.size(), postorder.end()-1);
    
    createTree(&(*tree)->left, inorder_left, postorder_left);
    createTree(&(*tree)->right, inorder_right, postorder_right);
}

void DFS(node *tree, int sum)
{
    sum += tree->value;
    if(tree->left != NULL)
        DFS(tree->left, sum);
    if(tree->right != NULL)
        DFS(tree->right, sum);
    if(tree->left == NULL && tree->right == NULL)
    {
        if(sum == minimum && tree->value < ans)
            ans = tree->value;
        else if(sum < minimum)
        {    
            ans = tree->value;
            minimum = sum;
        }
    }
}

void clearTree(node *tree)
{
    if(tree == NULL)
        return;
    clearTree(tree->left);
    clearTree(tree->right);
    delete tree;
}

int find(vector<int> vec, int x)
{
    for(int i = 0; i < vec.size(); ++i)
        if(vec[i] == x)
            return i;
}