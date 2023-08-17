#include<iostream>
using namespace std;
const int N=1e6+10;
int num[N];

void quick_sort(int l,int r){
    if(l>=r) return ;
    int x=num[(l+r)/2],i=l-1,j=r+1;
    while(i<j){
        while(num[++i]<x)   ;
        while(num[--j]>x)   ;
        if(i<j) swap(num[i],num[j]);
    }
    quick_sort(l,j);
    quick_sort(j+1,r);
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>num[i];
    quick_sort(0,n-1);
    for(int i=0;i<n;i++)
        cout<<num[i]<<' ';
    cout<<endl;
    return 0;
}