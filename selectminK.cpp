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
int a[maxn],n,k;
int split(int a[],int l,int r)
{
    int cnt= a[l];
    for (;;)
    {
        while(l<r&&cnt<=a[r])
            r--;
        if(l>=r)
            break;
        a[l++] = a[r];
        while(l<r&& a[l]<=cnt)
            l++;
        if(l>=r)
            break;
        a[r--] = a[l];
    }
    a[r] = cnt;
    return r;
}
int select(int *a,int l,int r,int k)
{
    for (;;)
    {
        int mid = split(a, l, r);
        if(mid==k)
            return a[k];
        else if(mid<k)
            l = mid + 1;
        else
            r = mid - 1;
    }
}
void run()
{
    n = rd();
    rep(i, 1, n) a[i] = rd();
    k = rd();
    int ans= select(a, 1, n, k);
    cout << ans << endl;
}

int main()
{
   run();
   return 0;
}
/* 
start time:
over time:
*/

