#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
using namespace std;

#define N 500005

priority_queue<int, vector<int>, greater<int> > Q;
int n, k;

main()
{
	int i, j, x;
	char s[5];
	while(scanf("%d %d",&n,&k)==2){
		while(!Q.empty()) Q.pop();
		while(n--){
			scanf("%s",s);
			if(s[0]=='I'){
				scanf("%d",&x);
				if(Q.size()<k) Q.push(x);
				else if(Q.top()<x){
					Q.pop();Q.push(x);
				}
			}
			else printf("%d\n",Q.top());
		}
		
	}
}