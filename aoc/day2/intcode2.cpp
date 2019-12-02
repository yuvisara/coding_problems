#include<bits/stdc++.h>

using namespace std;

const int endOp = 99,
    addOp = 1,
    mulOp = 2,
    incrOp = 4;

int getResult(int noun, int verb, vector<int> input) {
    //changing the program to the 1202 program
    input[1] = noun;
    input[2] = verb;

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
            /*
            cout<<"Program exited"<<endl;
            for(int J=0; J<input.size(); J++) {
                cout<<J<<" "<<input[J]<<endl;
            }
            */
            break;
          }
          else {
            cout<<"Invalid Op code"<<endl;
          }
    }
    return input[0];
}

int main() {
    int num=0;
    char delim; //Non space delimiter(in this case comma
    vector<int> input;
    while(cin>>num) {
        cin>>delim;
        input.push_back(num);
        cout<<num<<endl;
    }
    
    int expResult = 19690720;
    for(int I=0; I<=99; I++) {
        for(int J=0; J<=99; J++) {
            if(getResult(I, J, input) == expResult) {
                cout<<"Found result: "<<I<<J<<endl;
                break;
            }
        }
    }

     
    return 0;
}
