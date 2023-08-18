#include<iostream>
using namespace std;
const int N=1e5+10;
int nums[N];

int lowbit(int x){
    return x&-x;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)    scanf("%d",&nums[i]);
    for(int i=0;i<n;i++){
        int x=nums[i],ans=0;
        while(x){
            x-=lowbit(x);
            ans++;
        }
        printf("%d ",ans);
    }
    return 0;
}