#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int T; cin >> T;
	while(T--){
		int n,temp,flag; cin>>n;
		set<vector<int> > sv;
		vector<int> tuple;
		sv.clear(); tuple.clear();
		for(int i = 0; i < n; i++){
			cin >> temp;
			tuple.push_back(temp);
		}
		vector<int> zerot(n,0);
		sv.insert(tuple);
		while(1){
			vector<int> fake(tuple);
			for(int i = 0; i < n-1; i++){
				tuple[i] = abs(fake[i]-fake[i+1]);
			}
			tuple[n-1] = abs(fake[n-1]-fake[0]);
			if(sv.count(zerot)){
				flag = 1;
				break;
			}
			if(sv.count(tuple) ){
				flag = 2;
				break;
			}
			else{
				sv.insert(tuple);
			}	
		}
		cout << (flag==1?"ZERO\n":"LOOP\n");
	}
	return 0; 
} 