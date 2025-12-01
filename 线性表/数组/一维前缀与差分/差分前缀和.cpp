#include<iostream>
using namespace std;

const int N =1e5+10;
#define ll long long

ll a[N],profix[N],diff[N];

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	int n,p,q;
	cin>>n>>p>>q;

	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) diff[i]=a[i]-a[i-1];
    int l,r,x;
	while(p--){	
		cin>>l>>r>>x;
		diff[l]+=x;diff[r+1]-=x;
	}
	for(int i=1;i<=n;i++) a[i]=diff[i]+a[i-1];
	for(int i=1;i<=n;i++) profix[i]=a[i]+profix[i-1];

	while(q--){
		cin>>l>>r;
		cout<<profix[r]-profix[l-1]<<'\n';
	}
}