#include<bits/stdc++.h>
using namespace std;
int x,y,z;
int main(){
	int n,inp; cin >> n;
	for(int i = 1; i <= 3*n; i++){
		cin >> inp;
		switch(i%3){
			case 1:
				x+=inp;
				break;
			case 2:
				y+=inp;
				break;
			case 0:
				z+=inp;
				break;
			default:
				break;
		}
	}
	x==0&&y==0&&z==0?cout << "YES" <<endl : cout << "NO" << endl;
	return 0;
}