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
const int maxn=1e4+50;
int mp[maxn][maxn], n, m;
void floyd()
{
    for (int k = 1;k<=n;++k)
    {
        for (int i = 1; i <= n;++i)
        {
            for (int j = 1;j<=n;++j)
            {
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1;i<=n;++i)
    {
        for (int j = 1;j<=n;++j)
        {
            if(i==j)
                mp[i][j] = 0;
            else
                mp[i][j] = inf;
        }

    }
    for (int i = 1; i <= m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        mp[u][v] = min(mp[u][v], w);
    }
    floyd();
    for (int i = 1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            printf("从%d到%d的距离是%d\n", i, j, mp[i][j]);
        }
    }
        return 0;
}
/*
4 8
1 2 2
1 3 6
2 3 3
3 1 7
1 4 4
4 1 5
4 3 12
3 4 1 
*/
