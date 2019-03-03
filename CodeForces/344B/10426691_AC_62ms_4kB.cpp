#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
int b1,b2,b3,l1,l2,l3,a,b,c,flag;
int main(){
	while(scanf("%d%d%d",&a,&b,&c)!=EOF){
		flag=0;
		for(int i = 0; i <= 1e7; i++){
			l1 = i; l3 = c-l1; l2 = b-l3;
			if(l1>=0&&l2>=0&&l3>=0&&a==l1+l2&&b==l2+l3&&c==l1+l3){
				printf("%d %d %d\n",l2,l3,l1);
				flag=1;
				break;
			}
		}
		if(flag==0) printf("Impossible\n");
	}
	return 0;
}