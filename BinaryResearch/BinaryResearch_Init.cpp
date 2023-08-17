#include<iostream>
using namespace std;
int q,n,k;
const int N=100010;
int a[N];

void binary_research(int k,int l,int r){
    int i=l,j=r;
    while(i<j){
        int mid=i+j>>1;
        if(a[mid]>=k)   j=mid;
        else i=mid+1;
    }
    if(a[i]!=k){
        cout<<"-1 -1"<<endl;
        return ;
    }
    printf("%d ",i);
    i=l;j=r;
    while(i<j){
        int mid=i+j+1>>1;
        if(a[mid]<=k)   i=mid;
        else    j=mid-1;
    }
    printf("%d\n",i);
}
int main(){
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;i++)    scanf("%d",&a[i]);
    while(q--){
        scanf("%d",&k);
        binary_research(k,0,n-1);
    }
    return 0;
}