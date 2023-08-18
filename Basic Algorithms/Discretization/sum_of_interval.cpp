#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int> PII;
const int N=3e5+10;
//a数组存储数字，s存储前缀和
int a[N],s[N];
//add存储加的过程，query存储查询
vector<PII> add,query;
//alls存储映射关系，例如，alls[0]=1代表原来1的位置映射成0
vector<int> alls;

int find(int x){
    int l=0,r=alls.size()-1;
    while(l<r){
        int mid=l+r>>1;
        if(alls[mid]>=x) r=mid;
        else if(alls[mid]<x)    l=mid+1;
    }
    return l+1;
}

//思路：将数组上离散的坐标集中起来，通过映射的方式放到一个数组中。

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int x,c;
    for(int i=0;i<n;i++){
        scanf("%d%d",&x,&c);
        add.push_back({x,c});
        alls.push_back(x);
    }
    int l,r;
    for(int i=0;i<m;i++){
        scanf("%d%d",&l,&r);
        alls.push_back(l);
        alls.push_back(r);
        query.push_back({l,r});
    }
    
    //对映射数组排序后去重
    //unique去掉重复，将不重复的放在开头，返回不重复部分之后的第一个元素
    //然后用erase去除不重复部分后面的内容
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    
    for(auto t:add){
        x=find(t.first);
        a[x]+=t.second;
    }
    
    for(int i=1;i<=alls.size();i++)  s[i]=a[i]+s[i-1];
    
    for(auto t:query){
        l=find(t.first);
        r=find(t.second);
        cout<<s[r]-s[l-1]<<endl;
    }
    return 0;
}