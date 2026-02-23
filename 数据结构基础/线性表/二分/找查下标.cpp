#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int arr[N];

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	while(q--){
		int x;cin>>x;
		int i=0,j=n;
		int mid;
		while(i+1!=j){
			mid=(i+j)/2;
			if(arr[mid] < x)
				i=mid;
			else
				j=mid;
		}
		if(arr[j] == x){
			cout<< j <<' ';
		}else
			cout<<-1<<' ';
	}
}

/*
测试用例
7 3
0 0 1 2 2 5 7
1 2 8
答案
3 4 -1
*/