#include<stdio.h>
#include<unordered_map>
#include<string>

using namespace std;

typedef long long ll;

ll pow(ll num, ll exp) {
	if(exp == 0)
		return 1;
	if(exp == 1) 
		return num;
	
	ll temp = pow(num, exp/2);
	temp *= temp;
	if(exp%2 == 0) {
		return temp; 
	}
	else {
		return temp*num;
	}
}

int main(){
	//a^b 2<a<100 2<b<100
	unordered_map<ll , int> countMap;
	for(int I=0; I<100; I++){
		for(int J=0; J<100; J++){
			printf("%d %d %ld\n", I, J, pow(I, J));
			countMap.insert(make_pair<ll, int>(pow(I, J), 1));
		}
	}

	printf("total size: %d\n", countMap.size());
	
	return 0;
}
