#include<iostream>
using namespace std;
const int N=1e6+10;
int a[N],s[N];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=a[i]+s[i-1];
    }
    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",s[r]-s[l-1]);
    }
    return 0;
}