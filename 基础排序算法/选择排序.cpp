#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> arr={20,60,30,10,50,40};
    //每次排序一个位置 有序区域逐渐扩大
    for (int i = 0; i < arr.size()-1; i++) {
        int min = arr[i], index = i;
        for (int j = i; j < arr.size(); j++) {
            if(arr[j] < min){
                min = arr[j];
                index = j;
            }
        }
        swap(arr[i],arr[index]);
    }

    for (int x : arr)
        cout << x << ' ';
}