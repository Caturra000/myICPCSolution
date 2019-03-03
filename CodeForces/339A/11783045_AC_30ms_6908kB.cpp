#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+11;
char str[maxn];
int a[maxn];
int n; 
int main(){
	while(scanf("%s",str)!=EOF){
		n=0;
		int x=0,len=strlen(str);
		for(int i = 0; i < len; i++){
			if(i==len-1){
				x=x*10+str[i]-'0';
				a[n++]=x;
				x=0;
				continue;
			}
			if(str[i]=='+'){
				a[n++]=x;
				x=0;
				continue;
			}
			x=x*10+str[i]-'0'; 
		}
		sort(a,a+n);
		for(int i = 0; i < n; i++){
			if(i==n-1) printf("%d\n",a[i]);
			else printf("%d+",a[i]);
		}
	}
	return 0;
} 