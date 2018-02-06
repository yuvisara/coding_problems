#include<stdio.h>

#define isEven(x) (((x%2)==0)?"ODD":"EVEN")
using namespace std;

int main(){
	int T=0;
	scanf("%d\n", &T);
	while(T--){
		char inputStr[100002];
		scanf("%s\n", inputStr);
		
		int length=0;
		for(length=0; inputStr[length]!='\0'; length++);
		
		char temp;
		length--;
		bool flag = true;
		int I;
		for(I=0; I< length && flag; I++) {
			if(inputStr[length-I] != inputStr[I]){
				flag = false;
			}
		}
		if(flag) {
			printf("YES %s\n", isEven(length));
		}
		else {
			printf("NO\n");
		}

	}
	return 0;
}
