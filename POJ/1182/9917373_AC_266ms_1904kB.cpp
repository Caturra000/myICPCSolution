#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
const int maxn = 150003;
int p[maxn],rank[maxn];
using namespace std;

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
void Out(int a)    //输出外挂
{
	if(a>9)
    Out(a/10);
	putchar(a%10+'0');
}
void init(){
	for(int i = 0; i < maxn; i++)
		p[i] = i;
	memset(rank,0,sizeof rank);
}
int find(int x){
	return p[x]==x?x:find(p[x]);
}
bool same(int x,int y){
	return find(x)==find(y);
}
bool link(int x,int y){
	x = find(x); y = find(y);
	if(x==y) return false;
	if(rank[x]<rank[y])
		p[x] = y;
	else{
		p[y] = x;
		if(rank[x]==rank[y])
			rank[x]++;
	}
}
int main(){
	//ios::sync_with_stdio(false);
	int num,n,k,a,b,fake=0; cin>>n>>k;
	init();
	for(int i = 0; i < k; i++){
		//cin >> num >> a >> b;
		scanf("%d%d%d",&num,&a,&b);
		
		if(a>n||b>n)
			fake++;
		else if(num==1){
			if(same(a,b+n)||same(a,b+2*n))
				fake++;
			else{
				link(a,b);
				link(a+n,b+n);
				link(a+2*n,b+2*n);
			}
		}
		else{
			if(same(a,b+2*n)||same(a,b))//....
				fake++;
			else{
				link(a,b+n);
				link(a+n,b+2*n);
				link(a+2*n,b);
			} 
		}
	}
	cout << fake << endl;
	return 0;
}
