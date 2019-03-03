//String Task
#include<iostream>
#include<cstring>
using namespace std;

#define isL(x) ((x)-'z' <= 0 && (x)-'a' >=0) ? true : false
#define isU(x) ((x)-'Z' <= 0 && (x)-'A' >=0) ? true : false
#define isD(x) (isL(x) && isU(x)) ? true : false //没用
#define isV(x) ((x) == 'A' || (x) == 'O' || (x) == 'Y' || (x) == 'E' || (x) == 'U' || (x) == 'I' || \
(x) == 'a' || (x) == 'o' || (x) == 'y' || (x) == 'e' || (x) == 'u' || (x) == 'i' ) ? true : false
#define isC(x) (isV(x)) ? false : true

char s[234];
char s2[234];
int counter = 0;

int main(){
    cin >> s;
    for(int i = 0; i <strlen(s); i++){
        if(isV(s[i]))
            continue;
        else if(isC(s[i])){
            if(isU(s[i])){
                s2[counter] = '.';
                s2[counter+1] = s[i]+'a'-'A';
                counter += 2;
            }else{//isV
                s2[counter] = '.';
                s2[counter+1] = s[i];
                counter += 2;
            }
        }
    }
    cout << s2;
}