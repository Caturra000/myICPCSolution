#include<iostream>
using namespace std;
bool flag = 0;
typedef unsigned long long ull;
ull g,a;
void fi(ull g,int step){
	if(flag== 1 || step==19) return;
	if(g%a==0 && flag == 0){
		flag = 1;
		cout << g << endl;
		return ;
	}
	else{
		fi(g*10,step+1);
		fi(g*10+1,step+1); 
	}
}
int main(){
	int cnt;
	while(cin>>a){
		g = 1;
		if(a==0) break;
		if(a==1) {cout << 1 << endl; continue;} 
			fi(g,0);
		if(flag = 1){
			flag = 0;
			continue;
		}
	}
	return 0;
}