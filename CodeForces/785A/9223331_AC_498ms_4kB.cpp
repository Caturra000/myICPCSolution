#include<iostream>
#include<cstring> 
using namespace std;
int main(){
	long long sum = 0,n; cin >> n;
	char inp[123];
	for(int i = 0; i < n; i++){
		cin >> inp;
		if(!strcmp(inp,"Tetrahedron")){
			sum += 4;
		}
		else if(!strcmp(inp,"Cube")){
			sum += 6;
		}
		else if(!strcmp(inp,"Octahedron")){
			sum += 8;
		}
		else if(!strcmp(inp,"Dodecahedron")){
			sum += 12;
		}
		else if(!strcmp(inp,"Icosahedron")){
			sum += 20;
		}
	}
	cout << sum << endl;
	return 0;
} 