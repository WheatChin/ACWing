/*
给定一个长度为N的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出 −1。
Q: 为什么要保持栈内元素大小的单调递增特性？
A: 由于栈内元素是递增的，所以比较次数一定是最少的，这就实现了优化。
Q: 如何保持栈内元素大小的递增性？
A: 在依次出栈比较栈顶元素和当前数组元素大小的时候，如果栈顶元素小，那么找到目标值，将当前数组元素入栈，这样保持了栈内元素大小的递增性；
如果栈顶元素大，那么栈顶指针左移，直到找到目标值，再将当前数组元素入栈，这样就保持了栈内元素大小的递增性。
我们不必在意这个过程破坏了栈的结构，因为之前的数已经找到之前数组元素对应的目标值了。
*/


#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> st;
    int n,x;
    cin>>n;
    while(n--){
        scanf("%d",&x);
        while(st.size() && st.top()>=x)  st.pop();
        if(st.size())   printf("%d ",st.top());
        else    printf("-1 ");
        st.push(x);
    }
    return 0;
}