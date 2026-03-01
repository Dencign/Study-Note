#include<bits/stdc++.h>
using namespace std;

/*第一行 1个整数 T 表示样例数 (1≤T≤10)
  第一行 1个整数 n 			(1≤n≤1e5)
  第二行 n个整数 ai         (1≤ai≤1e5)
*/

int c[100010];

void solve(int T){
	while(T--){
		int n;cin>>n;
		int a[n+1];
		for(int i=1;i<=n;i++)
			cin>>a[i];
        for(int i=1;i<=n;i++)
            c[a[i]]=0;
		int i=1,j=0,lenth=0;
		while(i<=n && j<=n){
			if(j<n && !c[a[j+1]] ){
				c[a[j+1]]++;   //桶
				j++;	
                lenth=max(lenth,j-i+1);
			}	
			else{
				c[a[i]]--;
				i++;
			}
		}
		cout<<lenth<<'\n';
	}
}

void solve2(int T){
    while(T--){
		int n;cin>>n;
		int a[n+1];
		for(int i=1;i<=n;i++)	cin>>a[i];
		for(int i=1;i<=n;i++)	c[a[i]]=0;
		int lenth=0;
		for(int i=1,j=0;i<=n;i++){
			while(j<n && !c[a[j+1]] ){
				c[a[j+1]]++;
				j++;
			}
			lenth=max(lenth,j-i+1);
			c[a[i]]--;
		}
		cout<<lenth;
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
}