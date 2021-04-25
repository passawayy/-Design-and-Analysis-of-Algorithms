#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define dep(i,a,b) for(int i=a;i>=b;--i)
const int maxn=1e4+50;
int dp[maxn],a[maxn][maxn];
//dp[i]表示的是 在花费i的情况下所能获得的最大钱，a[i][j]代表的是花费i万元，第j分产品获得a[i][j]的钱 
int main()
{
	int n,m,w;//n代表有多少年，m有几种产品，w代表总共有多少钱 
	cin>>n>>m>>w;
	rep(i,1,n)
	{
		rep(j,1,m) cin>>a[i][j];
	}
//	rep(i,1,n)
//	{
//		rep(j,1,m) cout<<a[i][j]<<" ";
//		cout<<endl;
//	}
	rep(i,1,n)
	{
		rep(j,1,m)
		{
			rep(k,a[i][j],w)
			{
				dp[k]=max(dp[k],dp[k-i]+a[i][j]);
			}
		}
	}
	cout<<dp[w]<<endl;
	return 0;
}
/*
3 4 5
11 0 2 20
12 5 10 21
13 10 30 22
14 15 32 23
15 20 40 24
*/
