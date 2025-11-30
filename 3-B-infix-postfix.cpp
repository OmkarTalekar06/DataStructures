#include<cctype>
#include<iostream>
using namespace std;

#define SIZE 100

class Stack{
    char arr[SIZE];
    int top;
    public:
    Stack(){
        top = -1;
    }

    void push(char x ){
        if (top >= SIZE - 1)
        {
            cout<<"Stack overflow";
        }
        else{
            arr[++top] = x;
        }
    }
    
    char pop(){
        if (top<0)
        {
            return'#';
        }
        return arr[top--];
    }

    char peek(){
        if (top<0)
        {
            return '#';
        }
        return arr[top];
    }

    bool isEmpty(){
        return top == -1;
    }

};

int precendence(char op){
    if(op == '^') return 3;
    if(op =='*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

string infixTopostfix(string infix){
    Stack s;
    string postfix = " ";

    for (char ch : infix)
    {
        if (isalnum(ch))
        {
            postfix += ch;
        }else if (ch == '(')
        {
            s.push(ch);
        }
        else if(ch == ')'){
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix += s.pop();
            }
            s.pop();
        }
        else{
            while (!s.isEmpty() && precendence(ch) <= precendence(s.peek())) 
            {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.isEmpty())
    {
        postfix += s.pop();
    }
    return postfix;
    
}

int main(){
    string infix;
    cout<<"Enter infix expression : ";
    cin>> infix;

    string postfix = infixTopostfix(infix);
    cout<<"Postfix expression : "<<postfix<<endl;
    return 0;
}