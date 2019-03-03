#include<iostream>
#include<cstring>
using namespace std;
//bool beida[1234];
int counter;

int main(){
	//memset(beida,false,sizeof(beida));
    int k,l,m,n,d;
    cin >> k >> l >> m >> n >> d;
    for(int i = 1; i <= d; i++){
        /****failed**** 
		if(i%k == 0 || i%l == 0 || i%m == 0 || i%n == 0){
        	beida[i] == true;
		}
            //beida[i] == true;
        if(beida[i])
            counter++;
        *****/
        if(i%k == 0 || i%l == 0 || i%m == 0 || i%n == 0)
        	counter++;
    }
    cout << counter;
    return 0;
}