#include<stdio.h>
#include<math.h>

#define MAX(A,B) ((A)>(B)?(A):(B))

using namespace std;

int main(){
	int input[100][100];
	int T=0; 	
	int size=0;
	scanf("%d %d\n", &T, &size);
	
	for(int I=0; I<size; I++) {
		for(int J=0; J<(I+1); J++){
			scanf("%d ", &input[I][J]);
		}
		scanf("\n");
	}
	
	
	for(int I=(size-2); I>=0; I--) {
		for(int J=0; J<=I; J++) {
			input[I][J] += MAX(input[I+1][J],input[I+1][J+1]);
		}
	}	
	
		
	for(int I=0; I<size; I++) {
		for(int J=0; J<(I+1); J++){
			printf("%d ", input[I][J]);
		}
		printf("\n");
	}
	
	
	return 0;
}
