#include<iostream>
using namespace std;
const int N=1e6+10;
int a[N],b[N];
int m,n,l,r,c;

void insert(int l,int r,int c){
    b[l]+=c;
    b[r+1]-=c;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i]-a[i-1];
    }
    while(m--){
        scanf("%d%d%d",&l,&r,&c);
        insert(l,r,c);
    }
    for(int i=1;i<=n;i++){
        b[i]+=b[i-1];
        printf("%d ",b[i]);
    }   
    return 0;
}