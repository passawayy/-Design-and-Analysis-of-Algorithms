#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
const int maxn=1e5+50;
priority_queue<int>q;
int a[maxn];
int main()
{
	int n,k; cin>>n>>k;//n表示物品的个数，k表示能够装载的容量 
	rep(i,1,n) cin>>a[i],q.push(a[i]);
	int ans=0;
	while(k>0&&q.size())
	{
		k-=q.top();
		q.pop();
		if(k<0) break;
		ans++;
		//cout<<k<<endl;
	}
	cout<<ans<<endl;
	return 0;
} 
/*
3 10
6 3 2
*/
