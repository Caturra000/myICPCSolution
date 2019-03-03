#include<iostream>
using namespace std;

int main(){
    int k,w;
     long long n,tot;
    cin >> k >> n >> w;
    tot = ((w*(w+1))/2)*k;
    if(tot-n >= 0)
    	cout << tot-n;
	else
		cout << "0"; 
    return 0;
}