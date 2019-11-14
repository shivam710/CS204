#include<bits/stdc++.h>
using namespace std;
struct Node
{
    struct Node *left,*right;
    int key;

};

struct Node* CreateNew(int key)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->key=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
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
        root=CreateNew(key);
    }
    else if(root->key>key)
    {
        root->left=Insert(root->left,key);
    }
    else if(root->key<key)
    {
        root->right=Insert(root->right,key);
    }
    return root;
};

struct Node* Search(struct Node* root,int key)
{
    if(root==NULL)
    {
        cout<<"NOT FOUND"<<endl;
        return root;
    }
    else if(root->key==key)
    {
        return root;
    }
    else if(root->key>key)
    {
        return Search(root->left,key);
    }
    else if(root->key<key)
    {
       return Search(root->right,key);
    }
};

struct Node* succ(struct Node* root)
{
    if(root->left==NULL)
    {
        return root;
    }
    else return root->left;
};

struct Node* Delete(struct Node* root,int key)
{
    struct Node* root1=Search(root,key);
    if(root1==NULL)
    {

        return root1;
    }
    else if(root1->left==NULL&&root1->right==NULL)
    {
        free(root1);

    }
    else if(root->left==NULL)
    {
        struct Node* temp=root1;
        root1=root1->right;
        free(temp);
    }
     else if(root1->right==NULL)
    {
        struct Node* temp=root1;
        root1=root1->left;
        free(temp);
    }

    else
    {
        struct Node* temp1=succ(root->right);
        root->key=temp1->key;
        if(temp1->right!=NULL)
        {
            struct Node* temp2=temp1;
            temp1=root->right;
            free(temp2);
        }
        else free(temp1);

    }
    return root;
};

int main()
{
    struct Node* root=(struct Node*)malloc(sizeof(struct Node));
    root=NULL;
    root=Insert(root,15);
    root=Insert(root,10);
    root=Insert(root,22);
    root=Insert(root,4);
    root=Insert(root,11);
    root=Insert(root,17);
    root=Insert(root,45);
    root=Insert(root,16);
    if(Search(root,14))cout<<Search(root,14)->key<<endl;
    cout<<Delete(root,11)->key;

    Inorder(root);
}
