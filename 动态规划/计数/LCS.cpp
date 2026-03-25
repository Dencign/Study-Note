// Longest Common Subsequence
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int a[N], b[N];

int dp[N][N];
// dp[i][j] 表示a以i结尾的子序列和b以j结尾的子序列的最长相同子序列

int main() {
    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[n][m];

    return 0;
}