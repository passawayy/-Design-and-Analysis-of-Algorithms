#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i <= b;++i)
#define dep(i, a, b) for (int i = a; i >= b;--i)
const int maxn = 1e3 + 50;
int n,t[maxn];//n个物品，t数组代表的是每个任务所要花费的时间
int path[maxn][maxn],vis[maxn],dp[maxn];//path用来记录路径
int main()
{
   cin>>n;
   memset(dp, 0, sizeof dp);
   memset(path, 0, sizeof path);
   memset(vis, 0, sizeof vis);
   int sum = 0;//所需要花费总的时间
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
   cout << "1号选择的工作：";
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
   cout << "2号选择的工作：";
   rep(i,1,n) 
   {
      if(!vis[i])
         cout << i << " ";
   }
   cout << endl;
   cout<<"最后花费的时间："<<max(sum-dp[sum/2],dp[sum/2])<<endl; 
   return 0;
}
/*
5
1 5 2 10 3

*/ 
