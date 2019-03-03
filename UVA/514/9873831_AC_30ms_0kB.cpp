#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<stack> 
using namespace std; 
int B[1234];
stack<int> s;
int main(){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n&&n){
		while(1){
			memset(B,0,sizeof B);
			int f = 0;
			for(int i = 1; i <= n; i++){
				cin >> B[i];
				if(B[1] == 0){
					f = 1;
					break;
				}
			}
			if(f == 1){
				cout << endl;
				break;
			}
			while(!s.empty())
				s.pop();
			int a = 1,b = 1;
			bool flag = 0;
			while(b <= n){// B[n]满足则终止 
				if(a == B[b]){ 
					a++;b++;//直接驶入 
				}
				else if(!s.empty() && s.top() == B[b]){
					b++; s.pop();
				}//  NOTE:先写出最明显的两个条件，观察得出其余方向只能入栈再获得，然后再分析终止条件 
				//else if(a != B[b]){//
				else if(a <= n){ //a!=B[b] && (s.empty() || s.top() != B[b]) && a <= n 
					s.push(a); a++;
				}
				else{// a> n
					flag = 1;
					break;
				}
			}
			if(flag) cout << "No" << endl;
			else cout << "Yes" << endl; 
		}
	}
	return 0;
} 