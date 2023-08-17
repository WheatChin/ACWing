#include<iostream>
using namespace std;

double q(double x){
    return x*x*x;
}

int main(){
    double target,l,r,mid;
    scanf("%lf",&target);
    l=-100,r=100;
    while(r-l>1e-8){
        mid=(r+l)/2;
        if(q(mid)>target)   r=mid;
        else    l=mid;
    }
    printf("%.6lf\n",mid);
    return 0;
}