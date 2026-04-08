#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(string s1, string s2) {
    if (s1.size() != s2.size()) return s1.size() > s2.size();
    for (int i = 0; i < s1.size(); i ++) {
        if (s1[i] != s2[i]) return s1[i] > s2[i];
    }
    return true;
}

void sub(string s1, string s2) {
    vector<int> v;
    int alen = s1.size();
    int blen = s2.size();
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    
    int t = 0;
    for (int i = 0; i < alen; ++ i) {
        t = s1[i] - '0' - t;
        if (i < blen) t -= s2[i] - '0';
        v.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }
    while (v.size() > 1 && v.back() == 0) v.pop_back();
    reverse(v.begin(), v.end());
    for (auto x: v) {
        cout << x ;
    } cout << '\n';
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (cmp(s1, s2)) {
        sub(s1, s2);
    }
    else {
        printf("-");
        sub(s2,s1);  
    }
}