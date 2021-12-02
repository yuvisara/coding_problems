#include<bits/stdc++.h>

using namespace std;

int main() {
   string command;
   int value;
   int pos = 0, depth = 0; 
   
   int aim=0;
   while(cin>>command>>value) {
       if(command == "forward") {
            pos += value;
            depth += aim*value; 
            }
       if(command == "up") {
            aim -= value;
            }
       if(command == "down") {
            aim += value;
        }
    }

    cout<<depth*pos<<endl;
        
    return 0;
}
