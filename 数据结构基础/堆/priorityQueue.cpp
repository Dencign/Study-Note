#include<queue>//存在于这个头文件中

#include<vector>
#include<iostream>
using namespace std;
//设置优先级 这个是小的优先级高 重载(a<b)  
struct cmp{
    bool operator() (int a,int b){
        return a>b; //但是优先级(a>b) 所以小的优先级大
    }
};
//另一种设置优先级的办法 lambda表达式
auto cmp1=[](int a,int b){
    return a<b;
    };

int main(){
    priority_queue<int> p;
    //默认大的优先级高
    priority_queue<int,vector<int>,cmp> q;
    /*
    empty(): 检查队列是否为空。size(): 返回队列中的元素数量。top(): 返回队列顶部的元素（不删除它）。
    push(): 向队列添加一个元素。pop(): 移除队列顶部的元素
    */
    q.push(2),q.push(5),q.push(1);
    cout << q.top()<<endl;

    priority_queue<int,vector<int>,decltype(cmp1)> q1(cmp1);
    q1.push(1),q1.push(5),q1.push(2);
    cout << q1.top()<<endl;
    q1.pop();
    cout<<q1.top();


}