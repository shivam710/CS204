#include<bits/stdc++.h>
using namespace std;

struct treapnode
{
    int priority;
    int key;
    treapnode *left,*right;
};

treapnode* rightrotate(treapnode* x)
{
    treapnode* y=x->left;
    treapnode* temp =y->right;
    y->right=x;
    x->left=temp;
    return y;

}
treapnode* leftrotate(treapnode* x)
{
    treapnode* y=x->right;
    treapnode* temp =y->left;
    y->left=x;
    x->right=temp;
    return y;

}

treapnode* newNode(int key)
{
    treapnode* temp =new treapnode;
    temp->key=key;
    temp->priority=rand()%100;
    temp->left=temp->right=NULL;
    return temp;

}



treapnode* Search(treapnode* root ,int key)
{
    if(root==NULL||root->key==key)
    {
        return root;
    }
    else if(root->key<key)
    {
        Search(root->right,key);
    }
    else if(root->key>key)
    {
        Search(root->left,key);
    }
}

treapnode* Insert(treapnode* root,int key)
{

    if(root==NULL||root->key==key)
    {
        treapnode* temp=newNode(key);
        return temp;
    }
    else if(root->key<key)
    {
        root->right=Insert(root->right,key);

        if(root->right->priority>root->priority)
        {
           root=leftrotate(root);
        }
    }
     else if(root->key>key)
    {
        root->left=Insert(root->left,key);

        if(root->left->priority > root->priority)
        {
            root=rightrotate(root);
        }
    }
    return root;
}

treapnode* Delete(treapnode* root,int key)
{
    if(root==NULL)
    {
        return root;
    }
    else if(root->key<key)
    {
        root->right=Delete(root->right,key);

    }
    else if(root->key>key)
    {
        root->left=Delete(root->left,key);
    }
    else if(root->left==NULL)
    {
        treapnode* temp=root->right;
        delete(root);
        root=temp;

    }
    else if(root->right==NULL)
    {
        treapnode* temp=root->left;
        delete(root);
        root=temp;

    }
    else if(root->right->priority > root->left->priority)
    {
        root=leftrotate(root);
        root->left=Delete(root->left,key);

    }
     else if(root->right->priority < root->left->priority)
    {
        root=rightrotate(root);
        root->left=Delete(root->left,key);

    }
    return root;

}
void inorder(treapnode* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<"key is "<<root->key<<" | priority is " <<root->priority;
        if(root->left)
        {
            cout<< " | left child is "<<root->left->key;
        }
        if(root->right)
        {
            cout<< " | right child is "<<root->right->key;
        }
        cout<<endl<<endl;
        inorder(root->right);
    }

}
int main()
{
    srand(time(NULL));

    struct treapnode *root = NULL;
    root = Insert(root, 100);
    root = Insert(root, 130);
    root = Insert(root, 210);
    root = Insert(root, 430);
    root = Insert(root, 90);
    root = Insert(root, 20);
    root = Insert(root, 10);

    inorder(root);

    root = Delete(root, 20);
    cout<<endl<<"After Deleting 20"<<endl<<endl;

    inorder(root);

    treapnode *temp = Search(root, 50);
    (temp == NULL)? cout <<endl<< "50 Not Found ":  cout << endl<<"50 found";


    return 0;
}
