#include<iostream>
using namespace std;
const int N=1e5+10;
int A[N],B[N];
int main(){
    int n,m,x;
    scanf("%d%d%d",&n,&m,&x);
    for(int i=0;i<n;i++)    scanf("%d",&A[i]);
    for(int i=0;i<m;i++)    scanf("%d",&B[i]);
    int i=0,j=m-1;
    while(i<n){
        if(A[i]+B[j]<x) i++;
        else if(A[i]+B[j]>x)    j--;
        else{
            cout<<i<<' '<<j<<endl;
            return 0;
        }
    }
    return 0;
}