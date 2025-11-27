#include<iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	while(n--){
		int x;cin>>x;
		int sum=0;
        if(x>0) sum++;
		while(x&(x-1)){
            x=x&(x-1);
			sum++;
		}
		cout<<sum<<' ';
	}
}