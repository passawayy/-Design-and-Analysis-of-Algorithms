#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i <= b;++i)
#define dep(i, a, b) for (int i = a; i >= b;--i)
const int maxn = 1e3 + 50;
int n,t[maxn];//n����Ʒ��t����������ÿ��������Ҫ���ѵ�ʱ��
int path[maxn][maxn],vis[maxn],dp[maxn];//path������¼·��
int main()
{
   cin>>n;
   memset(dp, 0, sizeof dp);
   memset(path, 0, sizeof path);
   memset(vis, 0, sizeof vis);
   int sum = 0;//����Ҫ�����ܵ�ʱ��
   rep(i, 1, n) cin >> t[i],sum+=t[i];
   rep(i,1,n)
   {
      dep(j,sum/2,t[i])
      {
         if(dp[j]<dp[j-t[i]]+t[i])
         {
            path[i][j] = 1;
            dp[j] = dp[j - t[i]] + t[i];
         }
      }
   }
   int i = n, j = sum / 2;
   cout << "1��ѡ��Ĺ�����";
   while(i&&j)
   {
      if(path[i][j]==1)
      {
         cout << i << " ";
         j -= t[i];
         vis[i] = 1;
      }
      i--;
   }
   cout << "\n";
   cout << "2��ѡ��Ĺ�����";
   rep(i,1,n) 
   {
      if(!vis[i])
         cout << i << " ";
   }
   cout << endl;
   cout<<"��󻨷ѵ�ʱ�䣺"<<max(sum-dp[sum/2],dp[sum/2])<<endl; 
   return 0;
}
/*
5
1 5 2 10 3

*/ 
