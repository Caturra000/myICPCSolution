#include<iostream>
using namespace std;

int friends[5];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int f;
        cin >> f;
        if(f == 1)
            friends[1]++;
        else if(f == 2)
            friends[2]++;
        else if(f == 3)
            friends[3]++;
        else if(f == 4)
            friends[4]++;
    }
    int taxi = friends[4];
    taxi += friends[3];
    friends[1] -= friends[3];  //3+1
    friends[1] = (friends[1] < 0) ? 0 : friends[1];
    //2+2 2+1+1
    if(friends[2]%2 == 0)
        taxi += friends[2]/2;
    else{
        taxi += friends[2]/2+1;
        if(friends[1] >=2)
            friends[1] -= 2;
        else if(friends[1] == 1)
            friends[1] -= 1;
    }
    taxi += friends[1]/4;
    if(friends[1]%4)
        taxi += 1;
    cout << taxi;
    return 0;


}