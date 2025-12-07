#include<bits/stdc++.h>
using namespace std;

const int M = 1e5;
int a[M];
int ma;

/*用了存在性dp的思想
int dpp[M];
void solvepro(int n){
    for(int i=1;i<=n;i++)   cin>>a[i];
    ma=a[1];
    for(int i=1;i<=n;i++){
        dpp[i]=a[i];
        for(int j=1;j<i;j++){
            dpp[j]+=a[i];
            ma=max(ma,dpp[j]);
        }
    }
    cout<<ma<<' ';
}
9
-2 1 -3 4 -1 2 1 -5 3
*/

int dp[M];
void solve(int n){
    for(int i=1;i<=n;i++)   cin>>a[i];
    dp[1]=ma=a[1]; 
    for(int i=2;i<=n;i++){
        dp[i]=max(dp[i-1]+a[i],a[i]);
        ma=max(dp[i],ma);
    }
    cout<<ma;
}

int main(){
    int n;cin>>n;
    solve(n);
}