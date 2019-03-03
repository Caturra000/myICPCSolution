#include<iostream>
#include<string>
using namespace std;
string hi = "helloX";
string typed;
int counter = 0;
int main(){
    cin >> typed;
    for(int i = 0; i < typed.length(); i++){
        if(counter != 5 && hi[counter] == typed[i]){
            counter++;
            continue;
        }
    }
    if(counter == 5)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}