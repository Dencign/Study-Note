#include<bitset>
#include<iostream>
using namespace std;

//bitset<位数> 默认都为零 只有位运算无加减乘除 位运算操作速度快 O(n/w) w为计算机位数
    bitset<32> bs1;
//字符串构造    
    string s ="11001";
    bitset<32> bs2(s,0,1);//只能用string 从x位开始选y位
    bitset<32> bs3("100011",3);//从0位开始选3位
//数字构造
    bitset<7> b1(42);           // 42的二进制表示
    bitset<32> b2(0xFF);         // 十六进制

int main(){
    //接口
    cout<<b1<<'\n';
//flip() 翻转 
    b1[1].flip();   cout<<b1<<'\n';
    b1.flip(1);     cout<<b1<<'\n';
//set(x)设置为1 不填参数所有位数都设为1 x表示第几位设置为1
    b1.set();       cout<<b1<<'\n';
    //reset(x)设置为0 不填参数所有位数都设为0 x表示第几位设置为0
    b1.reset();     cout<<b1<<'\n';
// 测试位
    b1.test(0);             // 检查第0位是否为1（会检查越界）
    b1.all();               // 是否所有位都为1
    b1.any();               // 是否有任意位为1
    b1.none();              // 是否所有位都为0
//容量查询
    bitset<16> bs(1001);
    size_t size = bs.size();      // 16（总位数）
    size_t count = bs.count();    // 1的个数
//类型转换
    string t;
    t=bs.to_string(); 
    unsigned long a;
    //只能转换为无符号 long 或 long long
    a=bs.to_ulong();
}