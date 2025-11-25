#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n=100;//求100以内的素数 不包括100
    vector<bool> arr(n,1);//筛选谁不是素数
    for(int i=2;i<n;i++){
        if(arr[i]==1){
            for(int j=i*i;j<n;j+=i){
                arr[j]=0;
            }
        }
    }
    int count=0;
    //2开始自动忽略1
    for(int i=2;i<n;i++){
        if(arr[i]==1){
            cout<<i<<' ';
            count++;
        }
    }
    cout<<endl<<count;
}