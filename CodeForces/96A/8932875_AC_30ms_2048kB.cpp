#include<iostream>
using namespace std;
string foot;
char record;
int num = 0;
int main(){
    cin >> foot;
    for(int i = 0; i < foot.length(); i++){
        if(i == 0){
            record = foot[i];
            num = 1;
        }
        else if(record == foot[i])
            num++;
        else{
            record = foot[i];
            num = 1;
        }
        if(num >= 7){
        	cout << "YES";
        	return 0;
        }
    }
    cout << "NO";
    return 0;
}