#include<iostream>
using namespace std;

const int N=1e6+10;
int nums[N],temp[N],n;

void merge_sort(int l,int r){
    if(l>=r)    return ;
    int mid=l+r>>1;
    int k=0,i=l,j=mid+1;
    merge_sort(i,mid);
    merge_sort(j,r);
    while(i<=mid && j<=r){
        if(nums[i]<nums[j]) temp[k++]=nums[i++];
        else    temp[k++]=nums[j++];
    }
    while(i<=mid)   temp[k++]=nums[i++];
    while(j<=r)     temp[k++]=nums[j++];
    for(i=l,j=0;i<=r;i++,j++)
        nums[i]=temp[j];
}


int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)    cin>>nums[i];
    merge_sort(0,n-1);
    for(int i=0;i<n;i++)    cout<<nums[i]<<' ';
    cout<<endl;
    return 0;
}