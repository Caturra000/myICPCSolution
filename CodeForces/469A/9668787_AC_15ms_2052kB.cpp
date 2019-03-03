#include<bits/stdc++.h>
using namespace std;
int tot,inp,n,a,b;
bool abc[123];
int main(){
	cin >> n;
	cin >> a;
	for(int i = 0; i < a; i++){
		cin >> inp;
		if(!abc[inp]){
			tot++;
		}
		abc[inp] = true;
	}
	cin >> b;
	for(int i = 0; i < b; i++){
		cin >> inp;
		if(!abc[inp]){
			tot++;
		}
		abc[inp] = true;
	}
	if(tot==n)
		cout << "I become the guy." << endl;
	else
		cout << "Oh, my keyboard!" << endl;
	return 0;
}