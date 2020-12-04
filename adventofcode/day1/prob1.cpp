#include<bits/stdc++.h>

using namespace std;

int soln_hashing(vector<int> &nums) {
    for(int J=0; J<nums.size(); J++) {
        unordered_set<int> third;
        int currSum = 2020 - nums[J];

        for(int I=0; I<nums.size(); I++) {
            if(I!=J && (currSum > nums[I])) { 
                int second = currSum - nums[I];
                if(third.find(second) == third.end()) {
                    third.insert(nums[I]);
                }
                else {
                    return (nums[I] * second * nums[J]);
                }
            }
        }
    }
    return -1;
}

int soln_twoPointer(vector<int> &nums) {
    
    sort(nums.begin(), nums.end());
    int sum = 2020;
    for(int I=0; I<nums.size(); I++) {
        int begin = I+1, end = (nums.size()-1);
        while((begin < end)) {
            int currSum = nums[I] + nums[begin] + nums[end];
            if(sum == currSum) {
                return (nums[I] * nums[begin] * nums[end]);
            }
            else if(currSum < sum) {
                begin++;
            }
            else {
                end--;
            }
        }
    }
    return -1;
}


int main() {
    vector<int> nums;

    int num=0;
    while(cin>>num) {
        nums.push_back(num);
    }
    
    cout<<soln_hashing(nums)<<" "<<soln_twoPointer(nums)<<endl;

    return 0;
}
