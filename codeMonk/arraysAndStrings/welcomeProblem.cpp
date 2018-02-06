#include<stdio.h>
#include<vector>

using namespace std;

int main() {
	int size = 0;
	scanf("%d\n", &size);
	
	vector<int> A;
	int tempVar;
	for(int I=0; I<size; I++) {
		scanf("%d ", &tempVar);
		A.push_back(tempVar);
	}
	scanf("\n");

	for(int I=0; I<size; I++) {
		scanf("%d ", &tempVar);
		printf("%d ", (A[I]+ tempVar));
	}
	printf("\n");
	return 0;
}
