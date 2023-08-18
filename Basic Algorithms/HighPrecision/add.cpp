#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> A,B;

vector<int> add(const vector<int>& A, const vector<int>& B){
    int k=0;
    vector<int> C;
    for(int i=0;i<A.size() || i<B.size(); i++){
        if(i<A.size())  k+=A[i];
        if(i<B.size())  k+=B[i];
        C.push_back(k%10);
        k/=10;
    }
    if(k)   C.push_back(k);
    return C;
}

int main(){
    string a,b;
    cin>>a>>b;
    vector<int> A,B;
    for(int i=a.size()-1;i>=0;i--)  A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)  B.push_back(b[i]-'0');
    auto C=add(A,B);
    for(int i=C.size()-1;i>=0;i--)  cout<<C[i];
    cout<<endl;
}