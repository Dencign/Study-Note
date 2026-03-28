#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 305;
ll dp[N][N];

int n, m;

void Floyed() {
	for (int i = 1; i <= n; i++) {
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= n; y++) {
				dp[x][y] = min(dp[x][i] + dp[i][y], dp[x][y]);
			}
		}
	}
}

int main() {
	int q; cin >> n >> m >> q;

	memset(dp, 0x3f, sizeof(dp));
	while (m--) {
        ll u, v, w; cin >> u >> v >> w;
		dp[u][v] = min(dp[u][v], w);
	}
    for (int i= 1; i <= n; i++) dp[i][i] = 0;

	Floyed();

	while (q--) {
		int u, v; cin >> u >> v;
		cout << (dp[u][v] == INF ? -1 : dp[u][v]) << '\n';
	}
}