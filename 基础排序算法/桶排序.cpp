#include<iostream>
#include<vector>
using namespace std;

//对于数据不大的数排序
const int N=2e5;
int c[N];

int main(){
    vector<int>a={10,50,30,60,80,20};
    
    for(int i=0;i<(int)a.size();i++){
        c[a[i]]++;
    }
    //数值范围
    int M = 100;
    for(int i=0;i<=M;i++){
        for(int j=0;j<c[i];j++)
            cout<< i <<' ';
    }
}