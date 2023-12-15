#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node*left;
    Node *right;
    Node(char x){
        data=x; 
        left=NULL;
        right=NULL;
    }
};
bool isOperator(char c){
    if(c=='+' or c=='-' or c=='*' or c=='/' or c=='%' or c=='^'){
        return true;
    }
    return false;
}
Node *ETpostfix(string s){

    int n=s.length();
    Node *rt;Node *lt;
    stack<Node*>st;
    for(int i=0;i<n;i++)
    {
        char c=s[i];
        Node *temp=new Node(c);
        if((isOperator(c))){
            
            rt=st.top();st.pop();
            lt=st.top();
            st.pop();
            Node *root=new Node(c);
            root->left=lt;
            root->right=rt;
            st.push(root);
        }else{
            st.push(temp);
        }
    }
    return st.top();
}

void inOrder(Node *root)
{
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
void preOrder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void iterativeInorder(Node *root)
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


void iteraticePreorder(Node *root)
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

void iterativePostorder(Node* root)
{
	if (root == NULL)
		return;
	stack<Node *> st1, st2;

	st1.push(root);
	Node* node;

	while (!st1.empty()) {

		node = st1.top();
		st1.pop();
		st2.push(node);


		if (node->left)
			st1.push(node->left);
		if (node->right)
			st1.push(node->right);
	}
	while (!st2.empty()) {
		node = st2.top();
		st2.pop();
		cout << node->data << " ";
	}
}
Node *ETprefix(string s)
{
    int n=s.length();
    reverse(s.begin(),s.end());
    Node *rt;Node *lt;
    stack<Node*>st;
    for(int i=0;i<n;i++)
    {
        char c=s[i];
        Node *temp=new Node(c);
        if((isOperator(c))){
            
            lt=st.top();st.pop();
            rt=st.top();
            st.pop();
            Node *root=new Node(c);
            root->left=lt;
            root->right=rt;
            st.push(root);
        }else{
            st.push(temp);
        }
    }
    return st.top();
}
int main()
{
    cout<<"Start\n";
    cout<<"Enter 1 for Expression tree of postfix\n";
    cout<<"Enter 2 for Expression tree of prefix\n";
    int choice;cin>>choice;
    if(choice==1){
        string s="hcdarzowkk--/*^*+*/";
        Node *root =ETpostfix(s);
        cout<<"Postfix to infix : ";
        inOrder(root);
        cout<<"\nPreorder(Prefix) Traversal : ";
        preOrder(root);
        cout<<"\nPostfix Traversal : ";
        postOrder(root);
        cout<<endl;
    }else{
        string s1="+ab";//"*+ab-cd";    
        Node *root1=ETprefix(s1);
        cout<<"Prefix to infix : ";
        inOrder(root1);
        cout<<"\nPreorder Traversal : ";//same
        preOrder(root1);
        cout<<"\nPrefix to Postfix : ";
        postOrder(root1);
        cout<<endl;
    }
    return 0;
}