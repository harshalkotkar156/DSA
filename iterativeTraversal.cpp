#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }

};

void postorder(Node *root)
{
    if(root ==NULL)
    {
        cout<<"Empty"<<endl;
        return;
    }
    stack<Node*>st1,st2;
    st1.push(root);
    while(!st1.empty())
    {
        Node *curr = st1.top();
        st1.pop();
        st2.push(curr);
        if(curr->left != NULL)
        {
            st1.push(curr->left);
        }
        if(curr->right!=NULL)
        {
            st1.push(curr->right);
        }
    }
    while(st2.empty() !=true)
    {
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
    cout<<endl;
    
}


void inorder(Node *root)
{
    if(root==NULL){
        cout<<"Empty"<<endl;
    }

    stack<Node*>st;
    Node *curr=root;
    while(curr!=NULL or !(st.empty()))
    {
        while(curr !=NULL)
        {
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        cout<<curr->data<<" ";
        curr=curr->right;
    }
    cout<<endl;
}


void preorder(Node *root)
{
    if(root==NULL){cout<<"Empty"<<endl;return;}

    stack<Node*>st;
    st.push(root);
    while(st.empty()==false)
    {
        Node *curr=st.top();
        cout<<curr->data<<" ";
        st.pop();
        if(curr->right !=NULL)
        {
            st.push(curr->right);
        }
        if(curr->left !=NULL)
        {
            st.push(curr->left);
        }
        

    }
    cout<<endl;
}
int main()
{
    cout<<"Start\n";

    Node *root=NULL;
    root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->right=new Node(70);//40,50,7

    cout<<"Inorder traversal : ";
    inorder(root);
    cout<<"Preorder Traversal : ";
    preorder(root);
    cout<<"PostOrder Traversal : ";
    postorder(root);
    return 0;
}