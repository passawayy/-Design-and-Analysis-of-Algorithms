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
int n, m,tot,k,ans;
int head[maxn << 2], nxt[maxn << 2], ver[maxn << 2], col[maxn];
void add(int x,int y)
{
   ver[++tot] = y, nxt[tot] = head[x], head[x] = tot;
}
bool check(int x)
{
   for (int i = head[x];i;i=nxt[i])
   {
      int to = ver[i];
      if(col[to]==col[x])
         return false;
   }
   return true;
}
void dfs(int x)
{
   if(x>n)
   {
      rep(i, 1, n) cout << col[i] << " ";
      cout << '\n';
      ans++;
   }   
   else
   {
      rep(i,1,m)
      {
         col[x] = i;
         if(check(x))
         {
            dfs(x+ 1);
         }
         col[x] = 0;
      }
   }
}
void run()
{
   cin >> n >> m >> k;
   rep(i,1,k)
   {
      int x, y;
      cin >> x >> y;
      add(x, y);
      add(y, x);
   }
   dfs(1);
	if(ans>0)
 	  cout << "Total :" << ans << '\n';
	else cout<<"NO\n";
}

int main()
{
   run();
   return 0;
}
/* 
start time:
over time:
5 1 8
1 3
1 2
1 4
2 3
2 4
2 5
3 4
4 5
*/

