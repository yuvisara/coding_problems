#include<stdio.h>
#include<string>
#include<vector>

using namespace std;

bool compare(string A, string B) {
	int minSize = A.size();
	int returnCode = false;
	int I;

	if(B.size() < minSize) {
		minSize = B.size();
	}
	
	for(I=0; I< minSize; I++){
		if(A.at(I) > B.at(I)) {
			returnCode = true;
			break;
		}
		else if(A.at(I) < B.at(I)) {
			break;
		}
	}

	if(I == minSize) {
		if(A.size() > B.size()) 
			returnCode = true;
	}

	return returnCode;
}

void merge(vector<string> &testInput, int start, int mid, int end) {
	int firstIndex = start;
	int secondIndex = mid+1;
	
	vector<string> tempArray;
	
	for(int I=0; I< (end-start); I++) {
		if(firstIndex <= mid && secondIndex <= end) {
			if(compare(testInput[firstIndex], testInput[secondIndex])){
				tempArray.push_back(testInput[firstIndex]);
				firstIndex++;
			}
			else {
				tempArray.push_back(testInput[secondIndex]);
				secondIndex++;
			}
		}

		else if(firstIndex > mid) {
			tempArray.push_back(testInput[secondIndex]);
			secondIndex++;
		}
		else if(secondIndex > end) {
			tempArray.push_back(testInput[firstIndex]);
			firstIndex++;
		}
	}
	
	for(int I=start; I< end; I++) {
		testInput[I] = tempArray[I-start];
	}
	
}

void mergeSort(vector<string> &testInput, int start, int end) {
	if(start < end) {
		int mid = (start+end)/2;

		mergeSort(testInput, start, mid);
		mergeSort(testInput, mid+1, end);

		merge(testInput, start, mid, end);
	}
}


int main() {
	int N=0;
	vector<string> input;

	scanf("%d\n", &N);
	for(int I=0; I<N ; I++) {
		char testStr[20];
		scanf("%s\n", testStr);
		input.push_back(testStr);
	}
	
	vector<string> copyInput = input;
	mergeSort(copyInput, 0, copyInput.size()-1);
	
	for(int I=0; I<copyInput.size(); I++){
		printf("%s\n", copyInput[I].c_str());
	}
	

}
