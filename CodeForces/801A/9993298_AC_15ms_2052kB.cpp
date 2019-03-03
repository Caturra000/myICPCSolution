#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int maxn = 1e4;
const int INF = 0x3f3f3f3f;

string vk;

int main(){
	cin >> vk;
	int len = vk.length();
	int ans = 0;
	for(int i = 1; i < len; i++){
		if(vk[i]=='K'&&vk[i-1]=='V') ans++;
	}
	string vk2 = vk;
	int mmax = 0,cnt = 0;
	for(int i = 0; i < len; i++){
		vk = vk2;
		if(vk[i]=='K') vk[i] = 'V';
		else vk[i] = 'K';
		for(int j = 1; j < len; j++){
			if(vk[j]=='K' && vk[j-1] == 'V') cnt++;
		}
		mmax = max(cnt,mmax);
		cnt = 0;
	}
	cout << max(mmax,ans) << endl;
	return 0;
}