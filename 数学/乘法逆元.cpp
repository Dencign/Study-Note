#include <bits/stdc++.h>
using namespace std;
//模值
const long long mode = 998244353;
//快速幂
long long qmi(long long c,long long mi){
	long long res = 1;
	while (mi) {
		if(mi & 1){
			res = res * c % mode;
		}
		c = c * c % mode;
		mi >>= 1;
	}
	return res;
}
// 费马小定理求逆元 基数为整数 幂为质数 逆元存在条件 gcd(a, mode) == 1 
// pow(a,p-1) % p = 1
long long inv(long long num){
	return qmi(num, mode - 2);
}

// 函数 (a * x + b) / (c * x) & mode 求值
// 在模的情况下 (1 / c) % mode == x  x 称为逆元 -> (x * c) % mode = 1
// 例如 3 * 5 % 7 = 1  此时 5 是 1/3 在模7下的 逆元 
long long f(int a,int b,int c,int x){
	return ((a*x % mode + b)  * (inv(c * x) % mode))% mode;
}

int main() {
	int T; cin >> T;
	while (T--) {
		long long a, b, c, q;
		cin >> a >> b >> c >> q;
		while (q--) {
			int x; cin >> x;
			long long res = f(a, b, c, x) ;
			cout << res << '\n';
		}
	}
}