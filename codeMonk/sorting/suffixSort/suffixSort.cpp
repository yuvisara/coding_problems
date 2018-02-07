#include<stdio.h>
#include<string>
#include<vector>

using namespace std;


bool compare(string A, string B){
	int index = 0;
	bool returnCode = false;

	int minSize = A.size();
	if(B.size() < minSize) {
		minSize = B.size();
	}
	for(index=0; index<minSize; index++){
		if(A.at(index) < B.at(index)) {
			returnCode = true;
			break;
		}
		else if(A.at(index) > B.at(index)) {
			break;
		}
	}
	if(index == minSize) {
		if(A.size() < B.size())
			returnCode = true;
	}
	return returnCode;
}

void testSort(vector<string> &input){
	int flag = 1;
	while(flag != 0){
		flag = 0;
		for(int I=0; I<(input.size()-1); I++) {
			if(compare(input[I+1], input[I])){
				string temp = input[I+1];
				input[I+1] = input[I];
				input[I] = temp;
				flag++;
			}
		}
	}
}


int main() {
	char inputStr[30];
	int position;
	int inputSize;
	scanf("%s %d\n", inputStr, &position);
	
	for(inputSize=0; inputStr[inputSize]!='\0'; inputSize++);
	
	vector<string> input;
	for(int I=0; I< inputSize; I++) {
		char testStr[30];
		int J=0;
		for(J=0; J<(inputSize-I); J++) {
			testStr[J]= inputStr[I+J];
		}
		testStr[J] = '\0';
		input.push_back(testStr);
	}
	
	testSort(input);
	position--;
	printf("%s\n", input[position].c_str());
	return 0;
}
