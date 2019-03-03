#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=110010;
char Ma[MAXN*2];
int Mp[MAXN*2];
void Manacher(char s[],int len) {
	int l=0;
	Ma[l++]='$';
	Ma[l++]='#';
	for(int i=0; i<len; i++) {
		Ma[l++]=s[i];
		Ma[l++]='#';
	}
	Ma[l]=0;
	int mx=0,id=0;
	for(int i=0; i<l; i++) {
		Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
		while(Ma[i+Mp[i]]==Ma[i-Mp[i]])Mp[i]++;
		if(i+Mp[i]>mx) {
			mx=i+Mp[i];
			id=i;
		}
	}
}
char s[MAXN<<1];
int main() {
	while(scanf("%s",s)==1) {
		int len=strlen(s);
		Manacher(s,len);
		int ans=0;
		for(int i=0; i<2*len+2; i++)
			ans=max(ans,Mp[i]-1);
		if(ans!=0) printf("%d\n",ans);
	}
	return 0;
}