#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m; cin >> n >> m;
	//kill最小木棍？完整证明？ 
	(min(n,m)%2) ? cout << "Akshat" << endl : cout << "Malvika" << endl;
	return 0;
}