#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5+10;

int n, q;
int a[N];
ll t[N];

int lowbit(int x) { return x & (-x); }
//单点修改
void update(int index, ll num) {
	for (int i = index; i <= n; i += lowbit(i)) t[i] += num;
}
//和
ll getsum(int index) {
	ll res = 0;
	for (int i = index ; i > 0; i -= lowbit(i)) res += t[i];
	return res;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> q;

	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) update(i,a[i]);

	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
            //加操作
			int k, v; cin >> k >> v;
			update(k, v);
		}else {
            //查询操作
			int l, r; cin >> l >> r;
			cout <<  getsum(r) - getsum(l-1) << '\n';
		}
	}
}