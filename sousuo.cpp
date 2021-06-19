#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+50;
const int inf=0x3f3f3f3f;
int n,t[maxn],sum,l,r,ans;//l代表1号选择的，r代表2号选择的 
void dfs(int x)
{
	if(x>n)
	{
		ans=min(ans,max(l,r));
		return ;
	}
	l+=t[x];
	dfs(x+1);
	l-=t[x];
	r+=t[x];
	dfs(x+1);
	r-=t[x];
 } 
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i) cin>>t[i],sum+=t[i];
	ans=inf;
	dfs(1); 
	cout<<ans<<endl;
	return 0;
}
