#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,b,a) for(int i=b;i>=a;i--)
#define m_p make_pair
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const int maxn = 1e5 + 50;
int  dis[maxn], n, m, ans, vis[maxn], tot;//dis[x]��ʾ��x��������̱ߵĳ���
//vis�������������Ƿ���ʹ���n��ʾ������m��ʾ���� 
int head[maxn << 1], ver[maxn << 1], val[maxn << 1], nxt[maxn << 1];
void add(int x,int y,int z)//��ʽǰ���� 
{
    ver[++tot] = y, val[tot] = z, nxt[tot] = head[x], head[x] = tot;
}
void prim()
{
    memset(dis, inf, sizeof dis);
    memset(vis, 0, sizeof vis);
    dis[1] = 0;
    ans = 0;//��ʾMST�Ĵ� 
    int cnt = 0;//ѡ�����ı���
    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push(m_p(0, 1));
    while(!q.empty()&&cnt<n)
    {
        int d = q.top().first, u = q.top().second;
        q.pop();
        if(vis[u])
            continue;
        ++cnt, ans += d, vis[u] = 1;
        for (int i = head[u]; i;i=nxt[i])
        {
            int to = ver[i], w = val[i];
            if(w<dis[to])
                dis[to] = w, q.push(m_p(w, to));
        }
    }
}
void init()//��ʼ�� 
{
    memset(head, 0, sizeof head);
    tot = 0;
}
int main()
{
    cin >> n >> m;
    init();
    for (int i = 1; i <= m; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z), add(y, x, z);
    }
    prim();
    cout << ans << endl;   
   return 0;
}

