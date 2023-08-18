#include<iostream>
#include<string>
using namespace std;
int hh=0,tt=-1;
const int N=100010;
int queue[N];

void push(int x){
    queue[++tt]=x;
}

void pop(){
    hh++;
}

bool empty(){
    return !(hh<=tt);
}

int query(){
    return queue[hh];
}

int main(){
    ios::sync_with_stdio(false);
    int m;
    string op;
    cin>>m;
    while(m--){
        cin>>op;
        if(op=="push"){
            int x;
            cin>>x;
            push(x);
        }
        else if(op=="pop"){
            pop();
        }
        else if(op=="empty"){
            if(empty()) cout<<"YES"<<endl;
            else    cout<<"NO"<<endl;
        }
        else{
            cout<<query()<<endl;
        }
    }
    return 0;
}