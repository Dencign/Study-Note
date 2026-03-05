//给定n个整数，问由这些整数通过“加法”操作，可以组成多少种数字？

#include<iostream>
#include<bitset>
using namespace std;

const int N = 5e3 + 10,M= 5e5 + 10; 
int a[N];
bool dp[M];
/*
const int N = 5e3 + 10;
int a[N];
bool dp[N][N];

void solve(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }   

    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<N;j++){
            dp[i+1][j]=dp[i][j];
        }
        for(int j=0;j<N;j++){
            dp[i+1][j+a[i+1]]=dp[i][j];
        }
    }
    int count=0;
    for(int i=0;i<=N;i++){
        if(dp[n][i])
            count++;
    }
    cout<<count;
}

void solve(int n){
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }   

    dp[0]= true;
    for(int i = 1;i <= n;i++){
        for(int j=5e5;j >= a[i];j--){
            dp[j] |= dp[j-a[i]];
        }
    }
    long long count=0;
    for(int i=0;i<=5e5;i++){
        if(dp[i])
            count++;
    }
    cout<<count<<'\n';
}
*/
bitset<M> dpp;
//用bitset优化计算效率 O(n/w)w是机器位数
void solve(int n){
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }   
    dpp[0]=1;
    for(int i = 1;i <= n;i++){
            dpp |= (dpp<<a[i]);
    }
    cout<<dpp.count()<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    solve(n);
}