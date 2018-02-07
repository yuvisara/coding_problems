#include<stdio.h>
#include<vector>

#define getIndex(I, J, N) ((I*N) + J)
using namespace std;

int main() {
	int T=0;
	scanf("%d\n", &T);
	while(T--){
		vector<int> input;
		int size = 0;
		int temp;
		scanf("%d\n", &size);
		for(int I=0; I<size; I++){
			for(int J=0; J<size; J++){
				scanf("%d ", &temp);
				input.push_back(temp);
			}
			scanf("\n");
		}
		
		int count = 0;
		for(int I=0; I<size; I++) {
			for(int J=0; J<size; J++) {
				for(int K=I; K<size; K++) {
					for(int M=J; M<size; M++) {
						if(input[getIndex(K, M, size)] < input[getIndex(I, J, size)])
							count++;
					}
				}
			}
		}
		
		printf("%d\n", count);
	}
	
	return 0;
}

