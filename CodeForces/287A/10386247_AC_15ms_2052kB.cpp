#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
char g[7][7];
int black,white,flag;
int main(){
	while(cin>>g[0]){
		black=0;white=0;flag=0;
		for(int i = 1; i < 4; i++) cin>>g[i];

		for(int i = 0; i < 3;i++){
			black=0;white=0;
			for(int j = 0; j < 3; j++){
				if(g[i][j]=='#') black++;
				else white++;
				if(g[i+1][j]=='#') black++;
				else white++;
				if(g[i][j+1]=='#') black++;
				else white++;
				if(g[i+1][j+1]=='#') black++;
				else white++;
//				cout<<black<<" "<<white<<endl;
				if((black==4&&white==0)||(white==4&&black==0)) flag=1;
				else if((black==3&&white==1)||(white==3&&black==1)) flag=1;
				black=0;white=0;
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}