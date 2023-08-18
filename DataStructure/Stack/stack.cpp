#include<iostream>
#include<string>
using namespace std;
const int N=1e6+10;
int idx,x,n;
int s[N];
string op;

void init(){
    idx=0;
}

void push(int x){
    s[idx++]=x;
}
void pop(){
    idx--;
}

int query(){
    return s[idx-1]; 
}

void empty(){
    if(idx==0)  cout<<"YES"<<endl;
    else    cout<<"NO"<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    init();
    cin>>n;
    while(n--){
        cin>>op;
        if(op=="push"){
            cin>>x;
            push(x);
        }
        else if(op=="pop"){
            pop();
        }
        else if(op=="query"){
            cout<<query()<<endl;
        }
        else{
            empty();
        }
    }
    return 0;
}