#include <bits/stdc++.h>
using namespace std;

int main() {
    //pow(9,13);
    int base = 9;
    int n = 13;
    long long res = 1;
    while (n) {
        bool flag = n & 1;
        if (flag) {
            res *= base; 
        }
        base *= base;
        n >>= 1;
    }
    cout << res ;
}
