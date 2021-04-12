//#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<cstring>
#include<string>
#include<set>
//#include<unordered_map>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,b,a) for(int i=b;i>=a;i--)
#define m_p make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define pi acos(-1)
#define IO ios::sync_with_stdio(false);cin.tie(0)
#define io ios::sync_with_stdio(false)
typedef  long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const double  eps=1e-9;
inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int lcm(int a,int b){return a*b/gcd(a,b);}
inline int rd()
{
int x=0,f=1;
char ch=getchar();
while(ch<'0'||ch>'9') { if(ch=='-') f=-1; ch=getchar();}
while(ch>='0'&&ch<='9') { x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
return x*f;
}
const int maxn=1e5+50;
int a[maxn];
void Merge(int Lpos,int Rpos,int Rend)
{
	int Lend = Rpos - 1, len = Rend - Lpos + 1;
	int tmp[maxn],tmppos=Lpos;
	while(Lpos<=Lend&&Rpos<=Rend)
	{
		if(a[Lpos]<=a[Rpos])
			tmp[tmppos++] = a[Lpos++];
		else
			tmp[tmppos++] = a[Rpos++];
	}
	while(Lpos<=Lend)
		tmp[tmppos++] = a[Lpos++];
	while(Rpos<=Rend)
		tmp[tmppos++] = a[Rpos++];
	for (int i = 0; i < len;++i,Rend--)
		a[Rend] = tmp[Rend];
}
void MergeSort(int l,int r)
{
	if(l<r)
	{
		int mid = l + r >> 1;
		MergeSort(l, mid), MergeSort(mid + 1, r);
		Merge(l, mid + 1, r);
	}
}
int main()
{
	int n;
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	MergeSort(1, n);
	rep(i, 1, n) cout << a[i] << " ";
	cout << endl;
	return 0;
}
/* 
start time:
over time:
*/

