#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1e3;
char a[maxn],c[maxn];
char b[maxn];
int flag = 0;
int main(){
	cin >> a >> c;int len = strlen(a);
	if(strlen(a)!=strlen(c)) flag = 1;
	for(int i = 0; i < len; i++){
        if(a[i] < c[i])
            flag = 1;
    }
	if(flag) cout << -1 << endl;
    else cout << c << endl;
	return 0;
} 