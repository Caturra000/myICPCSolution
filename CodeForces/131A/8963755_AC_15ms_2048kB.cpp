#include<iostream>
#include<string>
#include<cctype>
using namespace std;
string s;
bool case1 = false;
bool case2 = false;
int counter1 = 0;
int counter2 = 0;

int main(){
    cin >> s;
    if(s.length() == 1){
    	if(s[0] <= 'Z' && s[0] >= 'A'){
    		char t = tolower(s[0]);
        	cout << t;
        }
        else{
        	char t = toupper(s[0]);
        	cout << t;
        }
        return 0;
    }
    for(int i = 0; i < s.length(); i++){
        if(i == 0 && s[i] <= 'z' && s[i] >= 'a')
            case2 = true;
        if(!case2 && s[i] <= 'Z' && s[i] >= 'A')//UPPER ONLY
            counter1++;
        if(case2 && s[i] <= 'Z' && s[i] >= 'A')
            counter2++;
    }
    if(counter1 == s.length())
        case1 = true;
    if(case1){
    	//char t = toupper(s[0]);
    	//cout << t;
        for(int i = 0; i < s.length(); i++){
        	char t = tolower(s[i]);
            cout << t;
        }
    }
    else if(case2 && counter2 == s.length()-1){ // same situ
        char t = toupper(s[0]);
		cout << t;
        for(int i = 1; i < s.length(); i++){
        	char t = tolower(s[i]);
            cout << t;
        }
    }
    else
        cout << s;
    return 0;
}