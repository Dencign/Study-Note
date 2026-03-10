#include <bits/stdc++.h>
using namespace std;

int main() {
    // 二进制 1101
    int a[10] = {1,0,1,1};
    int res = 0;
    // 进制
    int k = 2;
    for (int i = 3; i >= 0; i--) {
        res = res * k + a[i]; 
    }
    cout << res << '\n';

}