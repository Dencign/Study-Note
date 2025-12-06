#include<queue>//存在于这个头文件中

#include<vector>
#include<iostream>
using namespace std;
// true 交换 false 不交换 和 sort 相反
//结构体内重载 < 号
typedef struct ListNode{
    int data;
    ListNode *next;

    bool operator < (const ListNode &p) const{
        return data > p.data; //小的优先级高 
        //parent > child 时返回 ，表示违反堆性质，需要调整
    }
}*List;
//这个在定义时只用 priority_queue<ListNode> pq;

//声明一个比较类设置优先级 这个是小的优先级高 重载()运算符  
struct cmp{
    bool operator () (int a,int b){
        return a > b; //但是优先级(a>b) 所以小的优先级大 构造小顶堆
    }
};
//另一种设置比较类的办法 lambda表达式 构造大顶堆
auto cmp1=[](int a,int b){
    return a < b;   // 父节点 < 子节点 时返回 true 交换 
    };
/*比较逻辑
比较函数回答："第一个参数是否应该比第二个参数在堆的更低位置？" (优先级更低)
如果 a < b 为 true，回答"是"，a 就在 b 的下面*/
int main(){
    priority_queue<int> p;
    //默认大的优先级高 大顶堆
    priority_queue<int,vector<int>,cmp> q;
    /*
    empty(): 检查队列是否为空。size(): 返回队列中的元素数量。top(): 返回队列顶部的元素（不删除它）。
    push(): 向队列添加一个元素。pop(): 移除队列顶部的元素
    */

    //小顶堆
    q.push(2),q.push(5),q.push(1);
    cout << q.top()<<endl;
    //大顶堆
    priority_queue<int,vector<int>,decltype(cmp1)> q1(cmp1);

    q1.push(1),q1.push(5),q1.push(2);
    cout << q1.top()<<endl;
    q1.pop();
    cout<<q1.top();


}