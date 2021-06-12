#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
const int inf=0x3f3f3f3f;
const int maxn=1e3+50;
int p[maxn],a[maxn][maxn],b[maxn][maxn],n; 
void work()
{
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	for(int len=2;len<=n;++len)
	{
		for(int l=1;l+len-1<=n;++l)
		{
			int r=l+len-1;
			a[l][r]=inf;
			for(int i=l;i<=r-1;++i)
			{
				int cnt=a[l][i]+a[i+1][r]+p[l]*p[i+1]*p[r+1];
				//cout<<cnt<<endl;
				if(cnt<a[l][r])
				{
					a[l][r]=cnt;
					b[l][r]=i;
				}
			}
		}
	}
}
void print(int l,int r)
{
	if(l==r) 
	{
		cout<<"A"<<l;
		//if(l!=n-1) cout<<"*";	
	}
	else
	{
		cout<<"(";
		print(l,b[l][r]);
		cout<<"*";
		print(b[l][r]+1,r);
		cout<<")";
	}
}
int main()
{
	cin>>n;
	rep(i,1,n) cin>>p[i];
	work();
	cout<<a[1][n-1]<<endl;
	print(1,n-1);
	return 0;
 } 
 /*
 7 
 30 35 15 5 10 20 25
 
 5
 100 10 20 5 100
 */
