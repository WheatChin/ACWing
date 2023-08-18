#include<iostream>
using namespace std;
const int M=1e6+10;
int e[M],ne[M];
int m,head,idx;

void init(){
    head=-1;
    idx=0;
}

void add_head(int x){
    ne[idx]=head;
    e[idx]=x;
    head=idx++;
}

void insert(int k,int x){
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx;
    idx++;
}

void remove(int k){
    if(k==-1) head=ne[head];
    else ne[k]=ne[ne[k]];
}

void traverse(){
    for(int i=head;i!=-1;i=ne[i])
        cout<<e[i]<<' ';
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    init();
    cin>>m;
    int k,x;
    char op;
    while(m--){
        cin>>op;
        if(op=='H'){
            cin>>x;
            add_head(x);
        }
        else if(op=='D'){
            cin>>k;
            remove(k-1);
        }
        else{
            cin>>k>>x;
            insert(k-1,x);
        }
    }
    traverse();
    return 0;
}