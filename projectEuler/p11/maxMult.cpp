#include<stdio.h>
#include<math.h>

#define MAX(a , b) ((a)>(b)?(a):(b))
#define validIndex(a, b) ((((a)>=0) && ((a)<(b)))?true:false)
using namespace std;
int a[100][100];
int N=0;

int getMultNumber(int i1, int i2, int i3, int i4, int j1, int j2, int j3, int j4) {
	printf("checking %d %d %d %d %d %d %d %d", i1, j1, i2, j2, i3, j3, i4, j4);

	if(validIndex(j1, N) && validIndex(j2, N) &&  validIndex(j3, N) &&  validIndex(j4, N) &&
			validIndex(i1, N) && validIndex(i2, N) &&  validIndex(i3, N) &&  validIndex(i4, N)) {
		printf(" valid: %d %d %d %d %d %d %d %d\n", i1, j1, i2, j2, i3, j3, i4, j4);
		int testMax = (a[i1][j1]* a[i2][j2] * a[i3][j3]* a[i4][j4]);
		return testMax;	
	}
	return 0;  	
}

int main(){
	scanf("%d\n", &N);
	
	for(int I=0; I<N; I++) {
		for(int J=0; J<N; J++){
			scanf("%d ", &a[I][J]);
		}
		scanf("\n");	
	}
	
	
	for(int I=0; I<N; I++) {
		for(int J=0; J<N; J++){
			printf("%d ", a[I][J]);
		}
		printf("\n");	
	}
	
	//Horizontal scan
	int globalMax = 0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N;j++){
			// (i,j) (i, j+1), (i, j+2), (i, j+3)
			// (i,j) (i+1, j), (i+2, j), (i+3, j)
			// (i,j) (i+1, j+1), (i+2, j+2), (i+3, j+3)
			// (i,j) (i-1, j-1), (i-2, j-2), (i-3, j-3)
			
			globalMax = MAX(globalMax, getMultNumber(i, i, i, i, j,j+1, j+2, j+3));
			globalMax = MAX(globalMax, getMultNumber(i, i+1, i+2, i+3, j,j, j, j));
			globalMax = MAX(globalMax, getMultNumber(i, i+1, i+2, i+3, j,j+1, j+2, j+3));
			globalMax = MAX(globalMax, getMultNumber(i, i-1, i-2, i-3, j,j+1, j+2, j+3));
			globalMax = MAX(globalMax, getMultNumber(i, i-1, i-2, i-3, j,j-1, j-2, j-3));
			globalMax = MAX(globalMax, getMultNumber(i, i+1, i+2, i+3, j,j-1, j-2, j-3));
		}	
	}
	printf("Maximum: %d \n",  globalMax);
	return 0;
}
