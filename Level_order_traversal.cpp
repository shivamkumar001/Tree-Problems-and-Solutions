#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
void lot(Node* root,vector<int>&vec)
{
    if(root==NULL) 
        return;
    queue<Node*> q;
    q.push(root);
    while(q.empty()==false)
    {
        Node* u = q.front();
        vec.push_back(u->data);
        q.pop();
        
        if(u->left!=NULL)
            q.push(u->left);
        if(u->right!=NULL)
            q.push(u->right);
    }
}
Node* newNode(int data)
{
    Node* tmp=new Node;
    tmp->data=data;
    tmp->left=tmp->right=NULL;
    return tmp;
}
int main()
{
    Node* root=newNode(9);
    root->left=newNode(8);
    root->left->left=newNode(5);
    root->left->right=newNode(10);
    root->left->left->right=newNode(5);
    root->left->left->right->left=newNode(6);
    root->left->right->left=newNode(6);
    vector<int> vec;
    lot(root,vec);
    for(auto elm:vec)
        cout<<elm<<" ";
    cout<<endl;
    return 0;
}