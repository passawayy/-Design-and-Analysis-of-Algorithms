#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define dep(i,a,b) for(int i=a;i>=b;--i)
const int maxn=1e4+50;
int dp[maxn],a[maxn][maxn];
//dp[i]��ʾ���� �ڻ���i����������ܻ�õ����Ǯ��a[i][j]������ǻ���i��Ԫ����j�ֲ�Ʒ���a[i][j]��Ǯ 
int main()
{
	int n,m,w;//n�����ж����꣬m�м��ֲ�Ʒ��w�����ܹ��ж���Ǯ 
	cin>>n>>m>>w;
	rep(i,1,n)
	{
		rep(j,1,m) cin>>a[i][j];
	}
    memset(dp, 0, sizeof dp);
    rep(i,1,n)
	{
		rep(j,1,m)
		{
            dep(k,w,i)
            {
				dp[k]=max(dp[k],dp[k-i]+a[i][j]);
			}
		}
	}
   // rep(i, 1, n) cout << dp[i] << endl;
    cout<<dp[w]<<endl;
	return 0;
}
/*
5 4 5
11 0 2 20
12 5 10 21
13 10 30 22
14 15 32 23
15 20 40 24
*/
