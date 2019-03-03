#include <iostream>  
#include<string.h>  
using namespace std;  
int main()  
{  
    int n,k;  
    char c[101];  
    while(cin>>n)  
    {  
        while(n--)  
        {  
            cin>>c;  
            k=strlen(c);  
            if(k>10)  
                cout<<c[0]<<k-2<<c[k-1]<<endl;  
            else  
                cout<<c<<endl;  
        }  
    }  
    return 0;  
}  