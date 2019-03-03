#include<iostream>
#include<cstring>
using namespace std;
char s[123];
int counter = 0;
bool lucky = true;
int main(){
    cin >> s;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == '7' || s[i] == '4')
            counter++;
    }
    while(counter > 9){
        int last = counter%10;
        if(last != 4 && last != 7){
            lucky = false;
            break;
        }
        counter /= 10;
    }
    if(lucky && (counter != 7 && counter != 4))
        lucky = false;
    if(lucky)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}