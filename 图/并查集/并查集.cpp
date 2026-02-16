#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int pre[N], sum[N];
//寻根 + 路径压缩
int root(int n) {
	if (pre[n] == n) return n;
	int temp = root(pre[n]);
	pre[n] = temp;
	return temp;
}
//并集
void merge(int x, int y) {
	pre[root(x)] = root(y);
}
//是否联通
bool isCon(int x, int y) {
	return root(x) == root(y);
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) pre[i] = i;
	while (m--){
		int u, v;
		cin >> u >> v;
		merge(u, v);
	}
	for(int i = 1; i <= n; i++) {
		sum[root(i)]++;
	}
	vector<int> res;
	for(int i = 1; i <= n; i++){
		if(sum[i] != 0)
			res.push_back(sum[i]);
	}
	sort(res.begin(),res.end());
	for(int &x : res) {
		cout << x << ' ';
	}
}