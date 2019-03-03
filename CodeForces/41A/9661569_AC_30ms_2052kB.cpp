#include<bits/stdc++.h>
using namespace std;
string st,ts;
int main(){
	cin >> st;
	cin >> ts;
	reverse(st.begin(),st.end());
	if(st==ts) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}