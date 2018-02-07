#include<stdio.h>
#include<vector>

using namespace std;

//#define TEST 0

typedef long long var;
var K;
//compare function return true if true else false
bool compare(var a, var b) {
	if((a%K)>(b%K)) {	
		return true;
	}
	return false;
}

void merge(vector<var> &array, int start, int mid, int end) {
	int firstIndex = start;
	int secondIndex = mid+1;

	var tempArr[end-start+1];
	int tempIndex = 0;

	for(int I=start; I<=end; I++) {
		if(firstIndex > mid) {
			tempArr[tempIndex] = array[secondIndex];
			tempIndex++;
			secondIndex++;
		}

		else if(secondIndex > end) {
			tempArr[tempIndex] = array[firstIndex];
			firstIndex++;
			tempIndex++;
		}

		else if(compare(array[firstIndex], array[secondIndex])) {
			tempArr[tempIndex] = array[secondIndex];
			tempIndex++;
			secondIndex++;
		}
		else {
			tempArr[tempIndex] = array[firstIndex];
			firstIndex++;
			tempIndex++;
		}
	}

	for(int I=0; I<=(end-start); I++){
		array[start+I] = tempArr[I];
	}

}

void mergeSort(vector<var> &array, int start, int end) {
	if(start < end) {
		int mid = (start+end)/2;
		mergeSort(array, start, mid);
		mergeSort(array, mid+1, end);

		merge(array, start, mid, end);
	}
}


int main(){
	#ifdef TEST
		vector<var> array;
		array.push_back(1);
		array.push_back(9);
		array.push_back(8);
		array.push_back(7);
		array.push_back(6);
		array.push_back(5);
		array.push_back(4);
		array.push_back(3);
		array.push_back(10);

		int size = array.size();

		printf("Testing: array before: ");
		for(int I=0; I< size; I++) 
			printf("%d ", array[I]);

		printf("\n");

		mergeSort(array, 0, size-1);
		
		printf("Testing: array after: ");
		for(int I=0; I< size; I++) 
			printf("%d ", array[I]);

		printf("\n");

	#else
		int N;
		var temp;
		vector<var> array;

		scanf("%d %ld\n", &N, &K);
		for(int I=0; I<N; I++) {
			scanf("%ld ", &temp);
			array.push_back(temp);
		}

		mergeSort(array, 0, array.size()-1);
		for(int I=0; I< array.size(); I++) 
			printf("%d ", array[I]);

		printf("\n");
	#endif
	return 0;
}
