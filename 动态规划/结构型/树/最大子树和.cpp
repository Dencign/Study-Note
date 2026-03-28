#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
ll a[N], dp[N];
vector<int> g[N];

void dfs(int x, int pre) {
	dp[x] = a[x];
	for (auto &y : g[x]) {
		if (y == pre) continue;
		dfs(y, x);
		if (dp[y] > 0) dp[x] += dp[y];
	}
}

int main(){
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) {
			g[i].clear(), dp[i] = 0;
		}
		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			g[u].push_back(v), g[v].push_back(u);
		}
		dfs(1,0);

		cout << *max_element(dp + 1, dp + n + 1) << '\n';
	}
}