#include <bits/stdc++.h>
using namespace std;
using ll = long long ;

const int N = 3e5 + 10;
int n, q;
//差分数组
ll a[N], td[N], tid[N];

int lowbit(int x) {	return x & (-x); }

void update(int index, ll x){
	for (int i = index; i <= n; i+=lowbit(i)) 
		td[i] += x, tid[i] += index * x;
}

ll getsum(int r) {
	ll res = 0;
	for(int i = r; i > 0; i-=lowbit(i)) 
		res = res + (r + 1) * td[i] - tid[i];
	return res;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		update(i, a[i] - a[i-1]);
	}
	int op;
	while (q--) {
		cin >> op;
		if (op == 1) {
			int l, r ,v;
			cin >> l >> r >> v;
			update(l, v), update(r + 1 ,-v);
		}else {
			int l, r;
			cin >> l >> r;
			cout << getsum(r) - getsum(l-1) << '\n';
		}
	}
}