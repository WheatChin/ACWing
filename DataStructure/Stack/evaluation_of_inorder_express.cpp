#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<unordered_map>

using namespace std;

stack<int> num;
stack<char> op;

void eval(){
    int x;
    auto b=num.top();
    num.pop();
    auto a=num.top();
    num.pop();
    auto c=op.top();
    op.pop();
    if(c=='+')  x=a+b;
    else if(c=='-') x=a-b;
    else if(c=='*') x=a*b;
    else if(c=='/')   x=a/b;
    num.push(x);
}

int main(){
    unordered_map<char,int> prio{{'+',1},{'-',1},{'*',2},{'/',2}};
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++){
        auto c=str[i];
        if(isdigit(c)){     //遇到数字，将整个数字抠出来
            int x=0,j=i;
            while(j<str.size() && isdigit(str[j]))
                x=x*10+str[j++]-'0';
            i=j-1;  //读完数字更新i的位置
            num.push(x);
        }
        else if(c=='(') op.push(c);
        else if(c==')') {
            while(op.top()!='(')    eval(); //eval函数表示用末尾的操作符操作末尾的两个数（子树）
            op.pop();
        }
        else{
            while(op.size() && prio[op.top()]>=prio[c]) eval(); 
            //当栈顶元素（父节点）优先级大于子树优先级，说明子树录入完毕，可以进行子树的计算。
            op.push(c);
        }
       
    }
     while(op.size()) eval();
    cout<<num.top()<<endl;
    return 0;
}