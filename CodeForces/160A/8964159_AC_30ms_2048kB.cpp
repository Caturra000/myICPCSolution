#include <iostream>  
#include<cstdio>  
#include<cstring>  
#include<cmath>  
using namespace std;  
//打死也过不了好奇怪啊，这份是网上的 (感觉和我的没差啊.. 
int main()  
{  
    int n,i,j;  
    int sum;  
    int a[101];  
    int temp;  
    int count;  
    int suma;  
    sum=0;  
    count=0;  
    suma=0;  
    scanf("%d",&n);  
    for(i=0;i<n;i++)  
    {  
        scanf("%d",&a[i]);  
        sum+=a[i];  
    }  
    for(i=0;i<n;i++)  
    {  
        for(j=i+1;j<n;j++)  
        {  
            if(a[i]<a[j])  
            {  
                temp=a[i];  
                a[i]=a[j];  
                a[j]=temp;  
            }  
        }  
    }  
  
    for(i=0;i<n;i++)  
    {  
        suma+=a[i];  
        count++;  
        if(2*suma>sum)  
        {  
            printf("%d\n",count);  
            break;  
        }  
  
    }  
    return 0;  
}  