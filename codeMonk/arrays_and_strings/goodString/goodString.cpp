#include<stdio.h>

using namespace std;
int main() {
	char ch;
	int maxCount = 0;
	int count = 0;
	while((ch = getchar())!=EOF) {
		if((ch == 'a')||(ch == 'e')||(ch == 'i')||(ch == 'o')||(ch == 'u')) {
			count++;
		}
		else {
			if(count > maxCount) {
				maxCount = count;
			}
			count=0;
		}

	}

	if(count > maxCount) {
		maxCount = count;
	}

	printf("%d\n", maxCount);
	return 0;
}
