#include<bits/stdc++.h>
using namespace std;
int max_userid=0;
int max_amount=0;

class Node
{
    public:
    int userid;
    int amount;
    Node *left;
    Node *right;
    int height;

};

int max(int a,int b)
{
    return (a>b)?a:b;

}

int height(Node* N)
{
    if(N==NULL) return 0;
    return N->height;

}
Node* newNode(int userid,int amount)
{
    Node* node =new Node();
    node->amount =amount;
    node->userid =userid;
    node->left =NULL;
    node->right=NULL;
    node->height =1;
    return(node);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

     y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;

     return x;

}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;


    y->left = x;
    x->right = T2;


    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;

    return y;
}

int getBalance(Node* N)
{
    if(N==NULL) return 0;
    return height(N->left)-height(N->right);

}

Node* insert(Node* node,int userid,int amount)
{
    if(node==NULL)
    {
        if(amount>max_amount)
        {
            max_amount=amount;
            max_userid=userid;
        }
        return newNode(userid,amount);

    }

    else if(userid<node->userid)
    {
        node->left=insert(node->left,userid,amount);

    }
    else if(userid>node->userid)
    {
        node->right=insert(node->right,userid,amount);

    }
    else
    {
        node->amount = node->amount + amount;
    }
    if(node->amount>max_amount)
    {
        max_amount=node->amount;
        max_userid=node->userid;
    }

    node->height=1+max(height(node->left),height(node->right));

    int balance =getBalance(node);

    if (balance > 1 && userid < node->left->userid)
        return rightRotate(node);

    if (balance < -1 && userid > node->right->userid)
        return leftRotate(node);

    if (balance > 1 && userid > node->left->userid)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && userid < node->right->userid)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;

}


int main()
{
    Node* root=NULL;
    int n;
    cin>>n;
    int q;
    cin>>q;
    while(q--)
    {
        int action;
        cin>>action;
        if(action==1)
        {
            int userid;
            int amount;
            cin>>userid>>amount;
            root=insert(root,userid,amount);
        }
        else if(action==2)
        {
            if(root==NULL)
            {
                cout<<"No Data Available"<<endl;
            }
            else cout<<max_userid<<endl;
        }
        else
        {
            cout<<"INVALID ACTION"<<endl;
        }

    }


}
























