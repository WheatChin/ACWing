#include<iostream>
using namespace std;
const int N=1e6+10;
int nums[N],n,k;

int quick_sort(int l,int r,int k){
    if(l>=r)    return nums[l];
    int x=nums[l+r>>1],i=l-1,j=r+1;
    while(i<j){
        while(nums[++i]<x);
        while(nums[--j]>x);
        if(i<j) swap(nums[i],nums[j]);
    }
    if((j-l+1)>=k) return quick_sort(l,j,k);
    else    return quick_sort(j+1,r,k-(j-l+1));
}

int main(){
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>nums[i];
    cout<<quick_sort(0,n-1,k)<<endl;
    return 0;
}