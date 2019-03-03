#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+111;
int arr[maxn];

bool increase(int l,int r)
{
	for(int i = l+1;i<r;i++)
	{
		if(arr[i]<arr[i-1]) return false;
	}
	return true;
}

bool judge(int n)
{
	int pos;
	bool flag = true;
	for(int i = 1;i<n;i++)
	{
		if(arr[i]<arr[i-1])
		{
			flag = false;
			pos = i;
			break;
		}
	}
	if(flag) return true;
	if(pos==n-1) return true;
	if(pos==1) return increase(1,n);
	bool flag1 = increase(0,pos-1);
	bool flag2 = increase(pos+1,n);
	if(flag1==false||flag2==false) return false;
	int a = arr[pos-2];
	int b = arr[pos-1];
	int c = arr[pos];
	int d = arr[pos+1];
	if(a<=b&&b<=d) return true;
	if(a<=c&&c<=d) return true;
	return false;
}

int main(){
	int kase;cin>>kase;
	for(int i = 0;i<kase;i++)
	{
		int n;cin>>n;
		for(int i = 0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		bool flag = judge(n);
		if(flag==false)
		{
			reverse(arr,arr+n);
			flag = judge(n);
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
} 