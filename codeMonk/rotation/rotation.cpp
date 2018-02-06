#include<stdio.h>
#include<vector>

using namespace std;

int main(){
	
	int T=0;
	scanf("%d\n", &T);
	while(T--){
		int size, offset;
		scanf("%d %d\n", &size, &offset);
		if(offset> size) {
			offset = offset%size;
		}

		vector<int> input;
		int temp;
		for(int I=0; I<size; I++) {
			scanf("%d ", &temp);
			input.push_back(temp);
		}

		for(int I=(size-offset); I< size; I++) {
			printf("%d ", input[I]);
		}
		for(int I=0; I< size-offset; I++) {
			printf("%d ", input[I]);
		}
		printf("\n");
	}
	return 0;
}
