#include<cstdio>

int num[123];
int main(){
	int len,sum,flag=0; scanf("%d%d",&len,&sum);
	int i = len;
	if(len==1 && sum==0) {
		printf("0 0\n");
	}
	else if(sum && sum<=9*len){
		while(i!=1){
			if(sum>9){
				num[i] = 9;
				sum -= 9;
				i--;
			}
			else if(sum>1){
				num[i] = sum-1;
				sum = 1;
				i--;
			}
			else i--;
		}
		num[1] = sum;
		for(int i = 1;i <= len; i++){
			if(num[i]!=9){
				flag = i;
			}
			printf("%d",num[i]);
		}
		printf(" ");
		if(flag > 1){
			if(num[flag]+num[1] > 9){
				num[flag-1] = num[flag]+num[1]-9;
				num[flag] = 9;
				num[1] = 0;
			}
			else{
				num[flag] += num[1];
				num[1] = 0;
			}
		}
		for(int i = len;i >= 1; i--){
			printf("%d",num[i]);
		}
		printf("\n");
	}
	else{
		printf("-1 -1\n");
	}
	return 0;
}