#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 10;
ll a[N][N], p[N][N];

int main() {
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + a[i][j];
        }
    }
    
    for (int i = 1; i <= k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << p[x2][y2] + p[x1 - 1][y1 - 1] - p[x1 - 1][y2] - p[x2][y1 - 1] << '\n';
    }
}