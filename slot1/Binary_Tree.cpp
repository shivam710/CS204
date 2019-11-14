#include<bits/stdc++.h>
using namespace std;
struct Node
{
    struct Node* left , *right;
    int key;

};


struct Node* createNode(int key)
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
void Preorder(struct Node* root)
{
    if(root==NULL)return;
    cout<<root->key<<endl;
    Preorder(root->left);
    Preorder(root->right);

}
void Postorder(struct Node* root)
{
    if(root==NULL)return;
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->key<<endl;

}
int main()
{
    struct Node* root=(struct Node*)malloc(sizeof(struct Node));
    root->key=15;
    root->left=createNode(22);
    root->right=createNode(23);
    root->left->left=createNode(24);
    root->left->right=createNode(25);
    root->right->right=createNode(27);
    root->right->left=createNode(26);
    cout<<"Inorder Traversal is :"<<endl;
    Inorder(root);
    cout<<"Preorder Traversal is :"<<endl;
    Preorder(root);
    cout<<"Postorder Traversal is :"<<endl;
    Postorder(root);
}
