#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	deque<int> dq;//储存下标
	
	for (int i = 1; i <= n; i++) {
		while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
		while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
		//等于很重要 两个元素相等时 出队才不会破坏队列元素的完整
		dq.push_back(i);
		if (i < k) continue;
		cout << a[dq.front()] << ' ';
	}

	cout << '\n';
	dq.clear();

	for (int i = 1; i <= n; i++) {
		while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
		while (!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
		
		dq.push_back(i);
		if (i < k) continue;
		cout << a[dq.front()] << ' ';
	}
}