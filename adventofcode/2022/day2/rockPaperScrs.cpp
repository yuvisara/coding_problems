#include<bits/stdc++.h>

using namespace std;

#define WIN 6
#define DRAW 3
#define LOSS 0

string disp(int v1) {
	if(v1 == 1) return " rock ";
	if(v1 == 2) return " paper ";
	if(v1 == 3) return " siccor ";
	return "";
}

int getResult(char val1, char val2) {
	int v1 = (int)val1 - (int)'A';
       	int v2 = (int)val2 - (int)'X';
		
	v1++;
	v2++;
	
	if((v1==1 && v2==2) 
			|| (v1==3 && v2==1)
			|| (v1==2 && v2==3)) {
		return WIN + v2;
	}
	else if(v1 == v2) {
		return DRAW + v2;
	}
	return LOSS + v2;
}

int getResult2(char val1, char val2) {
	int v1 = (int)val1 - (int)'A';
       	int v2 = (int)val2 - (int)'X';
		
	v1++;
	v2++;
	
	if(v2 == 1) {
		//lose
		if(v1 == 1) return 3;
		if(v1 == 2) return 1;
		return 2;
	}

	else if(v2 == 2) {
		//draw
		if(v1 == 1) return 4;
		if(v1 == 2) return 5;
		return 6;
	
	}
	//win
	if(v1 == 1) return 8;
	if(v1 == 2) return 3;
	return 7;

}

void getResultTest() {
	cout<<getResult2('A', 'Y')<<" 4"<<endl;
	cout<<getResult2('B', 'X')<<" 1"<<endl;
	cout<<getResult2('C', 'Z')<<" 7"<<endl;
}
int main() {
	char val1, val2;
	int result = 0;

	getResultTest();	
	
	
	while(cin>>val1>>val2) {
		//cout<<val1<<" "<<val2<<" "<<getResult(val1, val2)<<endl;
		//result += getResult(val1, val2);
		result += getResult2(val1, val2);
	}
		
	cout<<result<<endl;
	return 0;	
}
