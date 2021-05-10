#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
const int maxn=1e4+50;
int dp[maxn][maxn];
char a[maxn],b[maxn];
int main()
{
	cin>>a+1;
	cin>>b+1;
	int len1=strlen(a+1),len2=strlen(b+1);
	memset(dp,0,sizeof dp);
	rep(i,1,len1)
	{
		rep(j,1,len2)
		{
			if(a[i]==b[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
  		}
	}
	cout<<dp[len1][len2]<<endl;
	return 0;
}
