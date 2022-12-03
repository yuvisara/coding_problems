#include<bits/stdc++.h>

using namespace std;

int getMax(vector<long long> calories) {
	int max = 0;
	for(auto val : calories) {
		if(val > max) max = val;
	}
	return max;
}

int getTopThree(vector<long long> calories) {
	sort(calories.begin(), calories.end(), greater<int>());
	int sum = 0;
	for(int I=0; (I<3 && I<calories.size()); I++) {
		sum+=calories[I];
	}
	return sum;
		
}

int main() {
	vector<long long> calories;
	long long sum = 0;
	string str;
	while(getline(cin, str)) {
		if(str.length() == 0) {
			calories.push_back(sum);
			sum = 0;
		}
		else sum += stoll(str);
		
	}
	cout<< getMax(calories)<<endl;
	cout<< getTopThree(calories)<<endl;

	return 0;
}
