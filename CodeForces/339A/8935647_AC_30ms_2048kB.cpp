#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

char s[250];
int num[110];
int counter = 0;
int main(){
    cin >> s;
    for(int i = 0; i < strlen(s); i += 2){
        num[counter] = s[i] - '0';
        counter++;
    }
    sort(num,num+counter);
    cout << num[0];
    for(int j = 1; j < counter; j++){
        cout << "+" << num[j];
    }
    return 0;
}