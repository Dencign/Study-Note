#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void div(string s1, int s2) {
    vector<int> v;
    int t = 0;
    for (int i = 0; i < s1.size(); i ++) {
        t *= 10;
        t += s1[i] - '0';
        if (t < s2){
            if (!v.empty()) v.push_back(0);
        } else {
            v.push_back(t / s2);
        }
        t %= s2; 
    }
    if (v.empty()) {
        cout << 0 << '\n';
    }
    for (auto x: v) {
        cout << x;
    } cout << '\n' << t << '\n';
}

int main() {
    string s1;
    int s2;
    cin >> s1 >> s2;
    div(s1, s2);
}