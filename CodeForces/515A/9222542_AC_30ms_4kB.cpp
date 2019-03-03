#include<iostream>
int main(){
	long long x,y,s,z; std::cin>>x>>y>>s;
	z = ((x<0)?-x:x)+((y<0)?-y:y);
	std::cout << ((s<z||(s-z)%2)?"NO\n":"YES\n");
	return 0;
}