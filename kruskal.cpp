int n, m,ans;//n���������m�������
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
   int cnt = 0;//�������ж�������
   ans = 0;//���ɵ���С��Ȩֵ
   for (int i = 0;i<m;++i)
   {
      int fx = find(e[i].x), fy = find(e[i].y);
      if(fx==fy)
         continue;
      fa[fx] = fy;
      cnt++;
      ans += e[i].z;
      if(cnt==n-1)  return true;//����ܹ�������С��������ֱ���˳�
   }
	return false;//���ܹ��ɣ��򷵻�
}
