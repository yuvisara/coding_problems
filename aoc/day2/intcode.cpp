#include<bits/stdc++.h>

using namespace std;

int main() {
    int num=0;
    char delim; //Non space delimiter(in this case comma
    vector<int> input;
    while(cin>>num) {
        cin>>delim;
        input.push_back(num);
        cout<<num<<endl;
    }
    
    const int endOp = 99,
        addOp = 1,
        mulOp = 2,
        incrOp = 4;
    

    //changing the program to the 1202 program
    input[1] = 12;
    input[2] = 2;


    int vSize = input.size();
    for(int I=0; I<vSize; ) {
          if(input[I] == addOp) {
            if(input[I+1] < vSize &&
                input[I+2] < vSize &&
                input[I+3] < vSize) {
                    input[input[I+3]] = input[input[I+1]] + input[input[I+2]];
                }
                I+=4; 
          }
          else if(input[I] == mulOp) {
            if(input[I+1] < vSize &&
                input[I+2] < vSize &&
                input[I+3] < vSize) {
                    input[input[I+3]] = input[input[I+1]] * input[input[I+2]];
                }
                I+=4; 
          }
          else if(input[I] == endOp) {
            cout<<"Program exited"<<endl;
            for(int J=0; J<input.size(); J++) {
                cout<<J<<" "<<input[J]<<endl;
            }
            break;
          }
          else {
            cout<<"Invalid Op code"<<endl;
          }
    }
    

    return 0;
}
