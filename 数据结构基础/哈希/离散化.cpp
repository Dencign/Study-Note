#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
const int Len = 1e5+10;
//记录离散点
vector<int> X;
//记录数据
long long a[N];

class doublenum{
	public:
	int a, b;
	doublenum(){}
	doublenum(int x, int y) : a(x), b(y) {}
}add[Len],quer[Len];

//下标映射
int getidx(int value) {
	return lower_bound(X.begin(), X.end(), value) - X.begin() + 1;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, q; cin >> n >> q;
    //导入数据
	for	(int i = 1; i <= n; i++) {
		int x, y; cin >> x >> y;
		add[i] = doublenum(x, y);
		X.push_back(x);
	}
	for	(int i = 1; i <= q; i++) {
		int l, r; cin >> l >> r;
		quer[i] = doublenum(l, r);
		X.push_back(l), X.push_back(r);
	}
    //处理点
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());
    //导入数据
	for	(int i = 1; i <= n; i++) {
		auto[x, y] = pair<int,int>{add[i].a,add[i].b};
		x = getidx(x);
		a[x] += y;
	}
    //前缀和
	for (int i = 1; i <= X.size(); i++) {
		a[i] += a[i-1];
	}
    //
	for	(int i = 1; i <= q; i++) {
		auto[x, y] = pair<int,int>{quer[i].a,quer[i].b};
		x = getidx(x), y = getidx(y);
		cout << a[y] - a[x-1] << '\n';
	}
}