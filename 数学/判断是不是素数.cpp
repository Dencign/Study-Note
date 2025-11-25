#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n){
    //只需要算到根号n n如果不是素数肯定有一个不大于根号n的因子
    // a*b=n 假设(a<b) a*a<a*b  a*a<n  a<sqrt(n);   
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return false;
    }
    return true;
}

int main(){
    cout<<isPrime(100)<<endl;
    cout<<isPrime(97)<<endl;
}