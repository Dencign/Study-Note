#include<list>
//双链表 头文件
#include<iostream>
using namespace std;

int main(){
    list <int> l; //泛型编程 list<数据类型>l(长度,默认值)
    /*常用操作
    增 尾插push_back() 头插push_front()
    删 pop_back pop_front()
    查 fornt() back() empty() size() 
    */
   //指针操作
   l.push_back(1);
   auto it=l.begin();
   advance(it,1);//操作指针向后移动1位
   l.insert(it,5);

   for(auto x : l){
    cout<<x<<' ';
   }
   cout<<endl;
   it=l.begin();
   l.erase(it);
   for(auto x : l){
    cout<<x<<' ';
   }
}