#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> arr={20,60,30,10,50,40};
    int len=arr.size();
    for(int i=0;i<len-1;i++){
        bool flag=1;
        for(int j=0;j<len-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=0;
            }   
        }
        if(flag==1) break;
    }

    for(auto x:arr){
        cout<<x<<' ';
    }
}