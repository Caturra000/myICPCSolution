#include<iostream>
using namespace std;
bool flag;
char wub[1<<8];
char iamx[1<<8];
int j;
int main(){
	cin >> wub;
	for(int i = 0; wub[i] != 0;i++){
		if(wub[i] == 'W' &&wub[i+1] == 'U' && wub[i+2] == 'B'){//空间至少大2 
			i += 2;
			if(flag && iamx[j-1] != ' ')
				iamx[j++] = ' ';
		}
		else{
			iamx[j++] = wub[i];
			flag = true;
		}
	}
	cout << iamx << endl;
	return 0;
}