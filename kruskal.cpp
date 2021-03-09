int n, m,ans;//n代表点数，m代表边数
int fa[maxn];
struct node
{
   int x, y, z;
   bool friend operator<(const node &a,const node &b)
   {
      return a.z < b.z;
   }
} e[maxn];
int find(int x)
{
   return fa[x] == x ? x : fa[x] = find(fa[x]);
}
bool kruskal()
{
   for (int i = 1; i <= n;++i)
      fa[i] = i;
   sort(e, e + m);
   int cnt = 0;//用来存有多少条边
   ans = 0;//生成的最小的权值
   for (int i = 0;i<m;++i)
   {
      int fx = find(e[i].x), fy = find(e[i].y);
      if(fx==fy)
         continue;
      fa[fx] = fy;
      cnt++;
      ans += e[i].z;
      if(cnt==n-1)  return true;//如果能够构成最小生成树，直接退出
   }
	return false;//不能构成，则返回
}
