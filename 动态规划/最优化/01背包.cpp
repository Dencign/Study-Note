#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T, M;
/*
ll dp[2][1005];
while (cin >> T >> M) {
		if (T == 0 && M == 0) break;
		for (int i = 1; i <= M; i++) cin >> t[i] >> v[i];
		for (int i = 1; i <= T; i++) dp[0][i] = 0;
        for (int i = 1 ; i <= M; i++) {
                int y = i & 1, beh = y ^ 1; //滚动数组
                for (int j = 0; j <= T; j++) {
                    if (j < t[i]) dp[y][j] = dp[beh][j];
                    else dp[y][j] = max(dp[beh][j - t[i]] + v[i], dp[beh][j]);
                    //完全根据上一层更新
                }
		}
		cout << dp[M & 1][T] << '\n';
	}
*/
int t[105], v[105];
ll dp[1005];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while (cin >> T >> M) {
		if (T == 0 && M == 0) break;
		for (int i = 1; i <= M; i++) cin >> t[i] >> v[i];
		for (int i = 1; i <= T; i++) dp[i] = 0;
		for (int i = 1; i <= M; i++) {
            //一维优化
            for (int j = T; j >= 0; j--) {
                if (j >= t[i])
                dp[j] = max(dp[j],dp[j - t[i]] + v[i]);
            }
		}
		cout << dp[T] << '\n';
	}
}