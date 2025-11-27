#include<iostream>
using namespace std;

const int N = 1e5+10;
long long a[N];
long long Profix[N];

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;cin>>T; //有T组数据

	while(T--){
		int n,q;cin>>n>>q;

		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) Profix[i]=Profix[i-1]+a[i];
		
		while(q--){
		int l,r;cin>>l>>r;
		cout<<Profix[r]-Profix[l-1]<<'\n';
		}
	}
}