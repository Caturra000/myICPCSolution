#include<cstdio>
int main(){
	long long sum = 0,n; scanf("%lld",&n);
	char inp[123];
	for(int i = 0; i < n; i++){
		scanf("%s",inp);
		if(inp[0] == 'T'){
			sum += 4;
		}
		else if(inp[0] == 'C'){
			sum += 6;
		}
		else if(inp[0] == 'O'){
			sum += 8;
		}
		else if(inp[0] == 'D'){
			sum += 12;
		}
		else if(inp[0] == 'I'){
			sum += 20;
		}
	}
	printf("%lld\n",sum);
	return 0;
} 