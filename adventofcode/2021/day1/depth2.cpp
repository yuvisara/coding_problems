#include<bits/stdc++.h>

using namespace std;

int getSum (vector<int> & input) {
    int sum = 0;
    for(auto num : input) sum+=num;
    return sum;
}

int main() {
    int windowSize = 3;
    vector<int> data(windowSize, 1);

    int num = 0;
    for(int I=0; I<windowSize; I++) {
        cin>>data[I];
    }
    int currIndex = 0;
    int prevSum = getSum(data);
    int count =0;

    while(cin>>num) {
        data[currIndex] = num;
        currIndex++;
        currIndex %= windowSize;
        int sum = getSum(data);
        if(prevSum < sum) count++;
        prevSum = sum;
    }
    cout<<count<<endl;
    

    return 0;
}
