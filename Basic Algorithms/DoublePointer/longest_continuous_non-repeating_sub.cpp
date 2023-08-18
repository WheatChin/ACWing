#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int nums[N],cnt[N];


int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    int res=0,i=0,j=0;
    for(;j<n;j++){
        //while(i<j && check(i,j))    i++;
        //check的方法：用一个cnt数组记录某个数字出现次数
        //如果>1，check失败
        cnt[nums[j]]++;
        while(i<j && cnt[nums[j]]>1){
            cnt[nums[i]]--;
            i++;
        }  
        res=max(res,j-i+1);
    }
    cout<<res<<endl;
    return 0;
    
}