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
int n;
struct node
{
	double x,y;
	node(){};
	node(double x,double y):x(x),y(y){}
	bool friend operator<(const node &a,const node &b)
	{
			return a.x < b.x;
		//return a.y < b.y;
	}
} p[maxn],py[maxn];
double getdis(node a,node b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool cmp(node a,node b)
{
	return a.y < b.y;
}
double work(int s,int ed)
{
	if(s+1==ed)
		return getdis(p[s], p[ed]);
	if(s+2==ed)
		return min(getdis(p[s], p[s + 1]),min( getdis(p[s + 1], p[s + 2]),getdis(p[s],p[s+2])));
	int mid=s+ed>>1;
	double ans = min(work(s, mid), work(mid + 1, ed));
	int cnt=0;
	rep(i,s,ed)
	{
		if(p[i].x>=p[mid].x-ans&&p[i].x<=p[mid].x+ans)
		{
			py[++cnt] = p[i];
		}
	}
	sort(py + 1, py + cnt + 1, cmp);
	rep(i,1,cnt)
	{
		rep(j,i+1,cnt)
		{
			if(py[j].y-py[i].y>=ans)
				break;
			ans = min(ans, getdis(py[i], py[j]));
		}
	}
	return ans;
}
int main()
{
	IO;
	while (cin >> n)
	{
		if (n == 0)
			break;
		rep(i, 1, n)
		{
			cin >> p[i].x >> p[i].y;
		}
		sort(p + 1, p + 1 + n);
		printf("%.2lf\n", work(1, n));
   }
   return 0;
}
/* 
start time:
over time:

2
0 0
1 1
2
1 1
1 1
3
-1.5 0
0 0
0 1.5
0
*/

