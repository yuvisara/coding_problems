#include<stdio.h>
#include<math.h>

using namespace std;
int main() {
	int num[] = {0,1,2,3,4,5,6,7,8,9};
	int flag[] = {1,1,1,1,1,1,1,1,1,1};
	long factNum[10];
	factNum[0] = 1;
	for(int I=1; I<=9; I++) {
		factNum[I] = factNum[I-1]*I;
	}
	
	long MaxNum = 1000000;
	for(int I=9; I>0 && MaxNum > 0; I--) {
		int currnetIndex = MaxNum/factNum[I];
		MaxNum = MaxNum%factNum[I];
		int tempSum = 0;
		printf("%d \n",currnetIndex);
	}
    
}
