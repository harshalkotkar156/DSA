#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node{
    char data;
    Node *next;
    Node(char c){
        data=c;
        next =NULL;
    }
};
struct Stack
{
    Node *head;
    Stack(){
        head=NULL;
    }
    void push(char c)
    {
        Node *temp = new Node(c);
        temp->next =head;
        head=temp;
    }
    char pop(){
        if(head == NULL){
            return '\0';//INT_MAX;
        }
        char c= head->data;
        Node *temp =head;
        head=head->next;
        delete temp;
        return c;
    }
    bool isEmpty(){
        if(head==NULL){
            return true;
        }
        return false;
    }
    char top()
    {
        if(head ==NULL)
        {
            return '\0';
        }
        return head->data;
    }
};
int precedence(char c)
{
    if(c == '^'){
        return 3;
    }else if(c == '/' or c == '*' or c == '%'){
        return 2;
    }else if(c =='+' or c=='-'){
        return 1;
    }else{
        return 0;
    }
}
string postfix(string s)
{
    int n = s.length();
    Stack stack;
    string ans = "";
    for(int i=0;i<n;i++)
    {
        char c = s[i];
        if(isalpha(c)){
            ans += c;
        }else if(c == '('){
            stack.push('(');
        }else if(c == ')')
        {
            while(stack.top() != '(' and (!stack.isEmpty())){
                ans += stack.top();
                stack.pop();
            }
            stack.pop();

        }else{
            while(!stack.isEmpty() and precedence(c) <= precedence(stack.top())){
                ans += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }
    while(!stack.isEmpty()){
        ans+=stack.top();
        stack.pop();
    }
    return ans;
}
string prefix_postfix(string s)
{
    int n = s.length();
    Stack stack;
    string ans = "";
    for(int i=0;i<n;i++)
    {
        char c = s[i];
        if(isalpha(c)){
            ans += c;
        }else if(c == '('){
            stack.push('(');
        }else if(c == ')')
        {
            while(stack.top() != '(' and (!stack.isEmpty())){
                ans += stack.top();
                stack.pop();
            }
            stack.pop();

        }else{
            while(!stack.isEmpty() and precedence(c) < precedence(stack.top())){
                ans += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }
    while(!stack.isEmpty()){
        ans+=stack.top();
        stack.pop();
    }
    return ans;
}
string prefix(string s)
{
    int n=s.length();
    reverse(s.begin(),s.end());
    for(int i=0;i<n;i++)
    {
        if(s[i] ==')' or s[i] =='(')
        {
            if(s[i] ==')'){
                s[i]='(';
            }else{
                s[i] = ')';
            }
        }
    }
    
    string ans = prefix_postfix(s);
    reverse(ans.begin(),ans.end());
    return ans;
}
//evaluation
int postfix_Eva(string s)
{
    Stack st;
    int n=s.length();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        char c= s[i];
        if(int(c) >=48 and int(c)<=57)
        {
            st.push(c);
        }else{
            int b = st.top()-48 ;st.pop();
            int a = st.top()-48 ;st.pop();
            if(c== '^'){
                ans=pow(a,b);
            }else if(c == '+'){
                ans = ((a) + (b));
            }else if(c == '-')
            {
                ans = ((a)-(b));
            }else if(c =='/'){
                ans = ((a) / (b));
            }else if(c == '*'){
                ans = ((a) *(b));
            }else{
                ans = ((a) % (b));
            }
            st.push(ans+'0');
        }
    }
    return (st.top()-48);
}
int prefix_Eva(string s)
{
    Stack stc;
    int n=s.length();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        char c= s[i];
        if(int(c) >=48 and int(c)<=57)
        {
            stc.push(c);
        }else{
            int a = stc.top()-48 ;stc.pop();
            int b = stc.top()-48 ;stc.pop();
            if(c== '^'){
                ans=pow(a,b);
            }else if(c == '+'){
                ans = ((a) + (b));
            }else if(c == '-')
            {
                ans = ((a)-(b));
            }else if(c =='/'){
                ans = ((a) / (b));
            }else if(c == '*'){
                ans = ((a) *(b));
            }else{
                ans = ((a) % (b));
            }
            stc.push(ans+'0');
        }
    }
    return (stc.top()-48);
}
int main()
{
    cout<<"Start\n";
    string infix = "(a*b+c)/(d^e)-f";
    cout<<"Prefix Expression is : "<<prefix(infix)<<endl;
    cout<<"Postfix Expression is : "<<postfix(infix)<<endl;
    string postfix_num = "23+54-*";
    cout<<"Answer postfix evalution : "<<postfix_Eva(postfix_num)<<endl;
    cout<<"Prefix Sum : "<<prefix_Eva("45-32+*")<<endl;//provide reverse prefix expression
    return 0;
}