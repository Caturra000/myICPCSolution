#include<iostream>
#include<string> 
using namespace std;
string s;
int ans = 0;
int n;

int main(){
    cin >> n >> s;
    string::iterator it;
    for(it = s.begin(); it != s.end(); it++){
        while(*it == *(it+1)){
            s.erase(it);
            ans++;
            continue;
        }
    }
    cout << ans;
    return 0;
}