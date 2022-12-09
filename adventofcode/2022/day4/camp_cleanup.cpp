#include<bits/stdc++.h>

using namespace std;

int main() {
	int start1, end1, start2, end2;
	int total = 0;
	int total_part2=0;
	while(scanf("%d-%d,%d-%d", &start1, &end1, &start2, &end2) != EOF) {
		if((start1>= start2 && end1 <= end2) ||
			(start2>= start1 && end2<=end1)) {
			total++;
		}
		if(!((start1<start2 && end1<start2) || (start1>end2 && end1>end2))) {
			total_part2++;
		}

	}
	cout<<total<<endl<<total_part2<<endl;
	return 0;
}
