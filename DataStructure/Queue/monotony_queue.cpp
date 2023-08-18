#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+10;
int q[N],a[N];
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        
    int hh=0,tt=-1;
    for(int i=0;i<n;i++){
        //判断是否出列
        if(hh<=tt && q[hh]<i-k+1) hh++;
        //队尾加入一个元素，保证单调性
        while(hh<=tt && a[q[tt]]>=a[i])  tt--;
        q[++tt] =i;
        if(i>=k-1)  printf("%d ",a[q[hh]]);
    }
    puts("");
    hh=0,tt=-1;
    for(int i=0;i<n;i++){
        //判断是否出列
        if(hh<=tt && q[hh]<i-k+1) hh++;
        //队尾加入一个元素，保证单调性
        while(hh<=tt && a[q[tt]]<=a[i])  tt--;
        q[++tt] =i;
        if(i>=k-1)  printf("%d ",a[q[hh]]);
    }
    return 0;
}
