#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+11;
int B[maxn],n,f;
int main(){
	while(cin>>n){
		if(n==0) break;
		while(1){
			f=0;
			for(int i = 1; i <= n; i++){
				cin>>B[i];
				if(i==1&&B[i]==0){
					cout<<endl;f=1;break;
				} 
			}
			if(f) break;
			int head=1,rear=1,flag=0;
			stack<int> s;
			while(rear<=n){
				if(B[rear]==head){
					head++;rear++;//直接驶入 
				}
				else if(!s.empty()&&B[rear]==s.top()){
					s.pop();rear++;
				} 
				else if(head<=n){//注意不要加s.empty 
					s.push(head);head++;
				}
				else{
					flag=1;break;
				}
			}
			if(flag) cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}
	}
	return 0;
} 