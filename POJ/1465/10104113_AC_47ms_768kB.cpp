#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
const int maxn = 5050;
using namespace std;
struct List{
	int digit;
	int remainder;
	int pre; 
};
List Q[maxn];
int d[11];
bool flag[maxn];
int N,M;
void print(int ans){
	if(ans>0){
		print(Q[ans].pre);
		printf("%d",Q[ans].digit); 
	}
}
int bfs(){
	memset(flag,0,sizeof flag);
	int front = 0, tail = 1;
	Q[front].digit = 0; Q[front].remainder = 0; Q[front].pre = -1;
	while(front<tail){
		List t = Q[front];
		int r = t.remainder;
		for(int i = 0; i < M; i++){
			int nr = (r*10+d[i])%N; //NOTE
			if(!flag[nr] && (t.pre!=-1 || d[i]!=0)){
				flag[nr] = 1;
				t.remainder = nr;
				t.digit = d[i];
				t.pre = front;
				Q[tail++] = t;
				if(nr==0) return tail-1;
			}
		}
		++front;
	}
	return -1;
}
int main(){
	while(~scanf("%d",&N)){
		scanf("%d",&M); 
		for(int i = 0; i < M; i++){
			scanf("%d",&d[i]);
		}
		sort(d,d+M);
		if(N==0){
			printf("0\n");
			continue;
		}
		int ans = bfs();
		if(ans == -1){
			printf("0\n");
		}
		else{
			print(ans);printf("\n");
		}
	}
	return 0;
}