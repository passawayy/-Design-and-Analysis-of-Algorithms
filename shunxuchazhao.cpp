#include<bits/stdc++.h>//假设有序序列是升序 
using namespace std;
const int maxn=1e5+50;
int n,a[maxn],target;
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	scanf("%d",&target);
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]==target)
		{
			ans=i;
			break;
		}
		if(a[i]>target)
		{
			break;
		}
	} 
	if(!ans) cout<<"未找到此数字！\n";
	else cout<<"此数字的下标是"<<ans<<endl;
	return 0;
 } 
 /*
 10
 1 2 5 6 7 8 9 10 11 12
 4
 
 10
 1 2 5 6 7 8 9 10 11 12
 5
 
 */
