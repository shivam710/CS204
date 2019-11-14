#include<bits/stdc++.h>
using namespace std;
struct Node
{
    struct Node *left,*right;
    int key;
    int height;
};
struct Node* createNode(int key)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->key=key;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=1;
    return temp;
};
int height(struct Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    else return root->height;
}
int balance(struct Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else return(height(root->left)-height(root->right));
}

struct Node* rightRotate(struct Node* x)
{
    struct Node* y=x->left;
    struct Node* temp= y->right;
    y->right=x;
    x->left=temp;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return y;

};

struct Node* leftRotate(struct Node* x)
{
    struct Node* y=x->right;
    struct Node* temp= y->left;
    y->left=x;
    x->right=temp;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return y;

};



struct Node* succ(struct Node* root)
{
    if(root->left==NULL)
    {
        return root;
    }
    else return root->left;
};

void Inorder(struct Node* root)
{
    if(root==NULL)return;
    Inorder(root->left);
    cout<<root->key<<endl;
    Inorder(root->right);

}

struct Node* Insert(struct Node* root,int key)
{
    if(root==NULL)
    {
        root=createNode(key);
    }
    else if(root->key>key)
    {
        root->left=Insert(root->left,key);
        root->height=1 + max(height(root->left),  height(root->right));
        if(balance(root)>1)
        {
            if(root->left->key>key)
            {
                root=rightRotate(root);

            }
            else if(root->left->key<key)
            {
                root->left=leftRotate(root->left);
                root=rightRotate(root);
            }
        }


    }
    else if(root->key<key)
    {
        root->right=Insert(root->right,key);
        root->height=1 + max(height(root->left), height(root->right));
         if(balance(root)<-1)
        {
            if(root->right->key<key)
            {
                root=leftRotate(root);
            }
            else if(root->right->key>key)
            {
                root->right=rightRotate(root->right);
                root=leftRotate(root);
            }
        }


    }
    root->height=1 + max(height(root->left), height(root->right));
    return root;


};

struct Node* Delete(struct Node* root, int key)
{
    if (root == NULL)
        return root;
    if ( key < root->key )
        root->left = Delete(root->left, key);
    else if( key > root->key )
        root->right = Delete(root->right, key);
    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct Node *temp = root->left ?
                         root->left :
                         root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else *root = *temp;
            free(temp);
        }
        else
        {
            Node* temp = succ(root->right);
            root->key = temp->key;
            root->right = Delete(root->right,temp->key);
        }
    }
    if (root == NULL)
    return root;
    root->height = 1 + max(height(root->left),  height(root->right));
    int gbalance = balance(root);
    if (gbalance > 1 &&
        balance(root->left) >= 0)
        return rightRotate(root);
    if (gbalance > 1 &&
        balance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (gbalance < -1 &&
        balance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (gbalance < -1 &&
        balance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main()
{
    struct Node* root=new Node;
    root=NULL;
    root=Insert(root,3);
    root=Insert(root,2);
    root=Insert(root,1);
    root=Insert(root,4);
    root=Insert(root,5);
    root=Insert(root,6);
    root=Insert(root,7);
    root=Delete(root,7);
    root=Delete(root,4);


    Inorder(root);
}










