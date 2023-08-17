#include<iostream>
using namespace std;

const int N=1e5+10;
int nums[N],temp[N],n;
typedef long long LL;

LL merge_sort(int l,int r){
    if(l>=r)    return 0;
    int mid=l+r>>1;
    LL ans=merge_sort(l,mid)+merge_sort(mid+1,r);
    int k=0,i=l,j=mid+1;
    while(i<=mid && j<=r){
        if(nums[i]<=nums[j]) temp[k++]=nums[i++];
        else{
            ans+=(mid-i+1);
            temp[k++]=nums[j++];
        }
    }
    while(i<=mid)   temp[k++]=nums[i++];
    while(j<=r)     temp[k++]=nums[j++];
    for(i=l,j=0;i<=r;i++,j++)
        nums[i]=temp[j];
    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)    cin>>nums[i];
    cout<<merge_sort(0,n-1);
    
    return 0;
}
