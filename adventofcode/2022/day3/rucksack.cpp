#include<bits/stdc++.h>

using namespace std;

int getVal(char ch) {
	if((int)ch >= (int)'a' && (int)ch <= (int)'z') {
		return ((int)ch-(int)'a' + 1);
	}
	else if((int)ch >= (int)'A' && (int)ch <= (int)'Z') {
		return ((int)ch-(int)'A' + 27);
	}
	return 0;
}

int findCommon(string str1, string str2) {
	unordered_set <int> charsSet;
	for(char ch: str1) {
		charsSet.insert(getVal(ch));
	}
	int result = 0;
	
	sort(str2.begin(), str2.end());
	char prevch='-';
	for(char ch: str2) {
		if(prevch!=ch) {
			if(charsSet.find(getVal(ch)) != charsSet.end()) {
				result += getVal(ch);		
			}
		}
		prevch = ch;	
	}	
	return result;
}


string findCommonStr(string str1, string str2) {
	unordered_set <int> charsSet;
	for(char ch: str1) {
		charsSet.insert(getVal(ch));
	}
	string result;
	
	sort(str2.begin(), str2.end());
	char prevch='-';
	for(char ch: str2) {
		if(prevch!=ch) {
			if(charsSet.find(getVal(ch)) != charsSet.end()) {
				result += ch;
			}
		}
		prevch = ch;	
	}	
	return result;
}

int main() {
	int result = 0;
	/*
	string inputstr;
	 firstPart
	while(cin>>inputstr) {
		string firstStr, secondStr;
		firstStr = inputstr.substr(0, inputstr.size()/2);
		secondStr = inputstr.substr(inputstr.size()/2, inputstr.size());
		result += findCommon(firstStr, secondStr);
		cout<<findCommon(firstStr, secondStr)<<endl;		
	}
	*/

	//secondPart
	string str1, str2, str3;
	while(cin>>str1>>str2>>str3) {
		string tempStr = findCommonStr(str1, str2);
		result+=findCommon(tempStr, str3);
	}

	cout<<result<<endl;
	return 0;
}
