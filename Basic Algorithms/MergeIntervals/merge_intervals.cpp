#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
vector<PII> intervals;
const int INF=1e9+10;

int merge(const vector<PII>& intervals){
    int st=INF,ed=-INF;
    int ans=0;
    for(auto t:intervals){
        if(t.first>ed) {    // 没有交集
            if(st!=INF)    ans++;  //防止将第一个区间加入
            st=t.first;
            ed=t.second;
        }
        else{               //有交集，包含也算交集
            ed=max(ed,t.second);
        }
    }
    if(ed!=-INF)    ans++;
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int l,r;
        scanf("%d%d",&l,&r);
        intervals.push_back({l,r});
    }
    sort(intervals.begin(),intervals.end());
    cout<<merge(intervals);
    
    return 0;
}