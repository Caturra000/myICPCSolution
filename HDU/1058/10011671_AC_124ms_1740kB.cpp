#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 5900;
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n; a[1] = 1;
	int p2 = 1, p3 = 1, p5 = 1, p7 = 1;
	for(int i = 2; i <= 5842; i++){
		while(a[p2]*2<=a[i-1]) p2++;//确保p2---p7下一位就对应于i 
		while(a[p3]*3<=a[i-1]) p3++;
		while(a[p5]*5<=a[i-1]) p5++;
		while(a[p7]*7<=a[i-1]) p7++;
		a[i] = a[p2]*2;//p2---p7中选最小 
		if(a[p3]*3<a[i]) a[i] = a[p3]*3;
		if(a[p5]*5<a[i]) a[i] = a[p5]*5;
		if(a[p7]*7<a[i]) a[i] = a[p7]*7;
	}
	while(cin>>n&&n){
		cout << "The " << n;
		if (n % 10 == 1 && n % 100 != 11) cout << "st";
		else if (n % 10 == 2 && n % 100 != 12) cout << "nd";
		else if (n % 10 == 3 && n % 100 != 13) cout << "rd";
		else cout << "th";
		cout << " humble number is ";
		cout << a[n] << ".\n";
	}
	return 0;
} 