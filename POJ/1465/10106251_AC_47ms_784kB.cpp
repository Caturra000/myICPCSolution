#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn= 5050;
struct List{
	int digit;
	int remainder;
	int pre;
};
List Q[maxn];
int n,m,d[11],vis[maxn];
int bfs(){
	int front = 0, tail = 1;
	Q[0].digit=Q[0].remainder=0;
	Q[0].pre = -1;
	while(front<tail){
		List t = Q[front];
		int r = t.remainder;
		for(int i = 0; i < m; i++){
			int nr = (10*r+d[i])%n;
			if(!vis[nr]&&(t.pre!=-1||d[i]!=0)){
				vis[nr] = 1;
				t.digit = d[i];
				t.remainder = nr;
				t.pre = front;
				Q[tail++] = t;
				if(nr==0) return tail-1;
			}
		}
		front++; 
	}
	return -1;
}
void print(int ans){
	if(ans>0){
		print(Q[ans].pre);
		printf("%d",Q[ans].digit); 
	}
}
int main(){
	while(~scanf("%d",&n)){
		memset(Q,0,sizeof Q);
		memset(vis,0,sizeof vis);
		scanf("%d",&m);
		for(int i = 0; i < m; i++){
			scanf("%d",&d[i]);
		} 
		sort(d,d+m);//NOTE
		if(!n) printf("0\n");
		else{
			int ans = bfs();
			if(ans==-1) printf("0\n");
			else{
				print(ans);printf("\n");
			}
		}
	}
	return 0;
} 