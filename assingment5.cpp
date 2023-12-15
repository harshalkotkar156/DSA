#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data=x;
        left=right=NULL;

    }
};

void mirror(Node *root)
{
    if(root==NULL){return ;}

    Node *temp=root->left;
    root->left=root->right;
    root->right=temp;
    mirror(root->left);
    mirror(root->right);

}
bool search(Node *root,int x)
{
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    if(root->data < x){
        return search(root->right,x);
    }else{
        return search(root->left,x);
    }
}


Node *insert(Node *root,int x)
{
    if(root==NULL)
    {
        return new Node(x);
    }
    if(root->data > x)
    {
        root->left = insert(root->left,x);
    }else if(root->data < x){
        root->right = insert(root->right,x);
    }
    return root;
}
void inorder(Node *root)
{
    if(root ==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right); 
}

void postorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


void lineTraversal(Node *root)
{
    if(root ==NULL){
        cout<<"EMPTY\n";
        return;
    }
    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        int count=q.size();

        for(int i=0;i<count;i++)
        {
            Node *curr=q.front();
            q.pop();
            cout<<curr->data<<" ";
            if(curr->left !=NULL){
                q.push(curr->left);
            }
            if(curr->right !=NULL)
            {
                q.push(curr->right);
            }

        }
        cout<<endl;
    }

}


Node *getSuccesor(Node *root)
{
    root=root->right;
    while(root !=NULL and root->left !=NULL)
    {
        root=root->left;
    }
    return root;
}



Node *delNode(Node *root,int x)
{
    if(root==NULL){
        return root;
    }
    if(root->data < x){
        root->right=delNode(root->right,x);
    }else if(root->data > x){
        root->left=delNode(root->left,x);
    }else{
        if(root->left==NULL){
            Node *temp=root->right;
            delete root;
            return temp;
        }else if(root->right ==NULL){
            Node *temp=root->left;
            delete root;
            return temp;
        }else{
            Node *succesor=getSuccesor(root);//getting the succesor on only right side
            root->data=succesor->data;
            root->right=delNode(root->right,succesor->data);

        }
        return root;
    }

}

int height(Node *root)
{
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}

void parentChild(Node *root)//showing the childs of every root
{
    if(root != NULL){

        parentChild(root->left);

        cout<<"Parent : "<<root->data<<"   ::   Left child : ";
        if(root->left!=NULL){
            cout<<root->left->data<<"   ::   Right child : ";
        }else{
            cout<<"NULL   ::   Right child : ";
        }
        if(root->right!=NULL){
            cout<<root->right->data<<endl;
        }else{
            cout<<"NULL"<<endl;
        }

        parentChild(root->right);
    }
}

void printLeaf(Node *root)

{
    if(root==NULL){
        return;
    }
    if(root->left==NULL and root->right ==NULL){
        cout<<root->data<<" ";
        return;
    }
    if(root->left != NULL){
        printLeaf(root->left);
    }
    if(root->right != NULL){
        printLeaf(root->right);
    }



}


Node *copyBst(Node *root)
{
    if(root==NULL){return NULL;}
    else{

        Node *copynode = new Node(root->data);
        copynode->left=copyBst(root->left);
        copynode->right=copyBst(root->right);
        return copynode;
    }
}



int main()
{
    cout<<"Start\n";
    Node *root=NULL;
    root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(7);
    root->left->left=new Node(2);
    root->left->right=new Node(4);
    root->right->left=new Node(6);
    root->right->right=new Node(8);
    bool flag=true;

    cout<<"Enter 1 for INSERT : \n";
    cout<<"Enter 2 for SEARCH : \n";
    cout<<"Enter 3 for DELETE : \n";
    cout<<"Enter 4 for DISPLAY : \n";
    cout<<"Enter 5 for HEIGHT : \n";
    cout<<"Enter 6 for MIRROR IMAGE : \n";
    cout<<"Enter 7 for CREATE COPY : \n";
    cout<<"Enter 8 for PARENT-Child : \n";
    cout<<"Enter 9 for Display Leaf Node : \n";
    cout<<"Enter 10 for LevelWise Traversal  : \n";
    cout<<"     *******     \n";
    int choice;
    int x;
    while(flag)
    {
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter Num : ";cin>>x;
            root=insert(root,x);
            break;
        case 2:
            cout<<"Enter Num to be search : ";
            cin>>x;
            if(search(root,x)){
                cout<<"Present\n";
            }else{
                cout<<"NOT Present \n";
            }
            break;
        case 3:
            cout<<"Enter Num to be Delete : ";
            cin>>x;
            root=delNode(root,x);
            break;
        case 4:
            cout<<"Preorder : ";preorder(root);
            cout<<"\nInorder : ";inorder(root);
            cout<<"Postorder : ";postorder(root);
            cout<<endl;
            break;
        case 5:
            cout<<"The Height of tree is : "<<height(root);
            break;
        case 6:
            mirror(root);
            cout<<"Displaying Mirror Image \nPreorder : ";preorder(root);
            cout<<"\nInorder : ";inorder(root);
            cout<<"Postorder : ";postorder(root);
            cout<<endl;
            mirror(root);
            break;
        case 7:{
                //Node* copytree=NULL;
                Node *copytree=copyBst(root);
                cout<<"Traversal of Copy Tree is : \n";
                cout<<"Preorder : ";preorder(copytree);
                cout<<"\nInorder : ";inorder(copytree);
                cout<<"Postorder : ";postorder(copytree);
                cout<<endl;
            }
            break;
        case 8:
            cout<<"Parent-Child traversal : \n";
            parentChild(root);
            cout<<endl;
            break;
        case 9:
            cout<<"Displaying Leaf Nodes of Tree : ";
            printLeaf(root);
            cout<<endl;
            break;
        case 10:
            cout<<"Level wise traversal is  : \n";
            lineTraversal(root);
            break;
        default:
            cout<<"DONE\n";
            {
                flag=false;
            }
            break;
        }
    }
    return 0;
}