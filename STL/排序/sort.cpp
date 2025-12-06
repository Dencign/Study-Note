#include<iostream>
#include<vector>

#include<algorithm>
using namespace std;

// true 不交换 false 交换 和 priority_queue 相反
auto cmp = [](int a,int b){
    return a < b;
};//升序

int main(){
    vector<int>arr={30,20,50,10,40,60};
    //sort(*开始地址，*结束地址后一位,排序方法cmp) 默认从小到大 内核是快排
    sort(arr.begin(),arr.end());
    //排序逻辑 "a 应该排在 b 前面吗？" 如果 a < b 为 true，回答"是"，就把 a 放前面
    for(auto x:arr){
        cout<<x<<' ';
    }
    cout<<endl;
    vector<int>arr1={30,20,50,10,40,60,60};
    //less “<”运算符；greater “>”运算符
    sort(arr1.begin(),arr1.end(),greater<int>());
    
    for(auto x:arr1){
        cout<<x<<' ';
    }
    cout<<'\n';
    //去重
    arr1.erase(unique(arr1.begin(),arr1.end()),arr1.end());
    for(auto x:arr1){
        cout<<x<<' ';
    }
}