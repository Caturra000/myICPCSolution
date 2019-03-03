#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#define lowbit(b) (b)&(-b)
const int maxn = 15005;
using namespace std;
int ft[32005];
int n,x,y;
int level[maxn];
int Scan()     //输入外挂
{
    int res=0,ch,flag=0;
    if((ch=getchar())=='-')
        flag=1;
    else if(ch>='0'&&ch<='9')
        res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')
        res=res*10+ch-'0';
    return flag?-res:res;
}
void init(){
	memset(ft,0,sizeof ft);
	memset(level,0,sizeof level);
}
int rsq(int b){
	int sum = 0;
	while(b){
		sum+=ft[b];
		b-=lowbit(b);
	}
	return sum;
}
void update(int k,int v){
	while(k<=32001){
		ft[k]+=v;
		k+=lowbit(k);
	}
}
int main(){
	while(scanf("%d",&n)!=EOF){
		init(); 
		for(int i = 0; i < n; i++){
			//scanf("%d%d",&x,&y); 
			x = Scan(); y = Scan(); x++;
			level[rsq(x)]++; //前面有几个星星 这颗星星就属于第几层 
			update(x,1);
		}
		for(int i = 0; i < n; i++)
			printf("%d\n",level[i]);
	}
	return 0;
}
