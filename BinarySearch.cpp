#include<bits/stdc++.h>//假设有序序列是升序 
using namespace std;
const int maxn=1e5+50;
int n,a[maxn],target;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	scanf("%d",&target);
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid]==target) 
		{
			r=l=mid; 
			break;	
		}
		if(a[mid]>target) r=mid-1;
		else l=mid+1;	
	}
	if(a[l]!=target) cout<<"未找到此数！\n";
	else cout<<"该数的位置是"<<l<<endl; 
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
