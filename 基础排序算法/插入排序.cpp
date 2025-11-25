#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> arr={20,60,30,10,50,40};
    int len=arr.size();
    for(int i=1;i<len;i++){ //无序区域
        int key=arr[i];
        int j=i;
        while(j>0 && key<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
        arr[j]=key; 
    }

    for(auto x:arr){
        cout<<x<<' ';
    }
}