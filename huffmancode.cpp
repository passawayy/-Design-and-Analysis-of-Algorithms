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
struct Node
{
   char c;
   int f;
   Node *left, *right;
   Node(char c,int f,Node *l=NULL,Node *r=NULL):c(c),f(f),left(l),right(r){}
   bool  operator<(const Node &a)const 
   {
      return f > a.f;
   }
};
priority_queue<Node> q;
int n;
map<char, string> mp;
void huffman()
{
   while(q.size()!=1)
   {
      Node *l = new Node(q.top());
      q.pop();
      Node *r = new Node(q.top());
      q.pop();
      q.push(Node('R', l->f + r->f, l, r));
   }
}
void huffmancode(Node *rt,string &pre)
{
   string cnt = pre;
   if(rt->left==NULL)
      return;
   pre += "0";
   if(rt->left->left==NULL)
      mp[rt->left->c] = pre;
   else
      huffmancode(rt->left, pre);
   pre = cnt;
   pre += "1";
   if(rt->right->right==NULL)
      mp[rt->right->c] = pre;
   else
      huffmancode(rt->right, pre);
}
void print()
{
   map<char, string>::const_iterator it = mp.begin();
   while(it !=mp.end())
   {
      cout << it->first << " " << it->second << endl;
      ++it;
   }
}
void run()
{
   cin>>n;
   rep(i,0,n-1)
   {
      char c;
      int x;
      cin >> c >> x;
      q.push(Node(c, x));
   }
   
   huffman();
   Node rt = q.top();
   string cnt="";
   huffmancode(&rt, cnt);
   print();
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

