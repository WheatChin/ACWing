#include<iostream>
#include<string>
using namespace std;
const int N=1e6+10;
int e[N],l[N],r[N];
int n,x,k,idx;
string op;

void init(){
    idx=2;
    r[0]=1;
    l[1]=0;
}

void insertK(int k,int x){
    e[idx]=x;
    r[idx]=r[k];
    l[r[k]]=idx;
    r[k]=idx;
    l[idx]=k;
    idx++;
}

void remove(int k){
    l[r[k]]=l[k];
    r[l[k]]=r[k];
}

void traverse(){
    for(int i=r[0];i!=1;i=r[i])    cout<<e[i]<<' ';
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    init();
    cin>>n;
    while(n--){
        cin>>op;
        if(op=="L"){
            cin>>x;
            insertK(0,x);
        }
        else if(op=="R"){
            cin>>x;
            insertK(l[1],x);
        }
        else if(op=="D"){
            cin>>k;
            remove(k+1);
        }
        else if(op=="IL"){
            cin>>k>>x;
            insertK(l[k+1],x);
        }
        else{
            cin>>k>>x;
            insertK(k+1,x);
        }
    }
    traverse();
    return 0;
}