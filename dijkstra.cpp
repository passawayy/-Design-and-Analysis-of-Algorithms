#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 50;
struct node
{
    int to, w;
    node(){};
    node(int to, int w) : to(to), w(w){};
};
vector<node> v[maxn];
int n, m,dis[maxn],vis[maxn];
struct mycmp
{
    bool operator()(int x,int y)
    {
        return dis[x] > dis[y];
    }
};
void dijkstra()
{
    memset(dis, inf, sizeof dis);
    memset(vis, 0, sizeof vis);
    dis[1] = 0;
    priority_queue<int, vector<int>, mycmp> q;
    q.push(1);
    while(!q.empty())
    {
        int now = q.top();
        q.pop();
        if(vis[now])
            continue;
        vis[now] = 1;
        for (int i = 0; i < v[now].size();++i)
        {
            int to = v[now][i].to, val = v[now][i].w;
            if(!vis[to]&&dis[to]>dis[now]+val)
            {
                dis[to] = dis[now] + val;
                q.push(to);
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for (int i = 1; i <= m;++i)
    {
        char x, y;
        int  z;
        cin >> x >> y >> z;
        v[x-'a'+1].push_back(node(y-'a'+1, z));
    }
    dijkstra();
    cout << dis[n] << endl;
    //    cout << endl;
    return 0;
}
/*
8 11
a b 1
b d 2
d c 1
c a 2
e d 2
d f 8
e g 2
f e 2
g f 3
h f 2
g h 3
*/
