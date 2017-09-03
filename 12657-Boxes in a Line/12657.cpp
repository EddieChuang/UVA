#include <iostream>
using namespace std;

struct node{
    
    int value;
    node *llink = NULL;
    node *rlink = NULL;
};

void insert_1(node*, node*);
void insert_2(node*, node*);
void swap(node*, node*);
void reverse(node*, node*);
node* find(node*, int);
void print(node*);
void print_reverse(node*);

int main(){
    
    int n, m;
    int c = 1;
    while(cin >> n >> m)
    {
        node *head = new node;
        node *tail = new node;
        node *curr = head;
        node *last = NULL;
        for(int i = 1; i <= n; ++i)
        {
            curr->rlink = new node;
            last = curr;
            curr = curr->rlink;
            curr->value = i;
            curr->llink = last;
        }
        curr->rlink = tail;
        tail->llink = curr;
        //cout << &head << endl;
        print(head);
        //print_reverse(tail->llink);
        int instruct, x, y;
        for(int i = 0; i < m; ++i)
        {
            cin >> instruct >> x >> y;
            
            node *node_x = find(head, x);
            node *node_y = find(head, y);
            
            //cout << "node_x: " << node_x << endl; 
            //cout << "head: " << &head << endl;
            //cout << "node_y: " << node_y << endl;
            
            switch(instruct)
            {
                case 1:
                    insert_1(node_x, node_y);
                    break;
                case 2:
                    insert_2(node_x, node_y);
                    break;
                case 3:
                    swap(node_x, node_y);
                    break;
                case 4:
                    cout << "a" << endl;
                    reverse(head, tail);
                    break;
            }
            
            //print(head->rlink);
            //print_reverse(tail->llink);
            //cout << head << endl;
        }   
    } 
}

void insert_1(node *x, node *y)
{    
    if(x->rlink == y)
        return;
    x->llink->rlink = x->rlink;
    x->rlink->llink = x->llink;
    
    x->rlink = y;
    x->llink = y->llink;
    
    y->llink->rlink = x;
    y->llink = x;
}

void insert_2(node *x, node *y)
{
    if(x->llink == y)
        return;

    x->llink->rlink = x->rlink;
    x->rlink->llink = x->llink;
    
    x->llink = y;
    x->rlink = y->rlink;
    
    y->rlink->llink = x;
    y->rlink = x;
}

void swap(node *x, node *y)
{
    node *temp = new node;
    temp->llink = x->llink;
    temp->rlink = x->rlink;
    
    x->llink = y->llink;
    x->rlink = y->rlink;
    x->llink->rlink = x;
    x->rlink->llink = x;
    
    y->llink = temp->llink;
    y->rlink = temp->rlink;
    y->llink->rlink = y;
    y->rlink->llink = y;
}

void reverse(node *head, node *tail)
{

   
    print(head);
}

node* find(node *head, int v)
{
    node *temp = head;
    while(temp != NULL)
    {
        if(temp->value == v)
            return temp;
        temp = temp->rlink;
    }
}

void print_reverse(node *tail)
{
    node *temp = tail;
    while(temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->llink;
    }
    cout << endl;
}

void print(node *head)
{
    node *temp = head;
    while(temp != NULL)
    {
        cout << temp << " ";
        temp = temp->rlink;
    }
    cout << endl;
}

