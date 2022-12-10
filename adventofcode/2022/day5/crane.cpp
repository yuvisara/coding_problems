#include<bits/stdc++.h>

using namespace std;

int main() {
	string str;
	vector<string> input;
	getline(cin, str);
	//read first line
	input.push_back(str);
	int stackLength = (str.length() + 1)/4;
	//read until _1__2__3__...
	string str2;	
	while(getline(cin, str2)) {
		if(!str2.empty() && str2[0] == '[') {
			input.push_back(str2);
		}
		else {
			//read empty line and exit
			getline(cin, str2);
			break;
		}
	}
	
	vector<stack<char> > arr(stackLength);
	
	for(int I=0; I<stackLength; I++) {
		for(int J=(input.size()-1); J>=0; J--) {
			int index = (I*4) + 1;
			if(input[J][index] == ' ') break;
			arr[I].push(input[J][index]);
		}
	}

	int count, row1, row2;
	while(scanf("move %d from %d to %d\n", &count, &row1, &row2) != EOF) {
		row1--;
		row2--;
		
		stack <char> temp;
		for(int I=0; I<count; I++) {
			//arr[row2].push(arr[row1].top());
			temp.push(arr[row1].top());
			arr[row1].pop();
		}
		for(int I=0; I<count; I++) {
			arr[row2].push(temp.top());
			temp.pop();
		}
	}

	for(int I=0; I<arr.size(); I++) {
		cout<<arr[I].top();
	}
	cout<<endl;
	return 0;
}
