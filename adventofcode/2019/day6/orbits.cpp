#include<bits/stdc++.h>

using namespace std;

int main() {
    multimap<string, string> objs;
    map<string, int> numOrbits;


    string line;
    while(getline(cin, line)) {
        string head = line.substr(0,3);
        string tail = line.substr(4,3);
        
        objs.insert(make_pair(head, tail));
        numOrbits[head] = 0;
        numOrbits[tail] = 0;
    }

    //start with com
    string rootNode = "COM";
        
    queue<pair<string, int> > children;
    auto res = objs.equal_range(rootNode);
    for(auto itr = res.first; itr != res.second; itr++) {
        children.push(make_pair(itr->second, 1));
    }
    
    while(!children.empty()) {
        string node = children.front().first;
        int value = children.front().second;
        
        numOrbits[node] = value;
        children.pop();
        auto res = objs.equal_range(node);
        for(auto itr = res.first; itr != res.second; itr++) {
            children.push(make_pair(itr->second, value+1));
        }
    }

    int nOrb = 0;
    for(auto itr = numOrbits.begin(); itr != numOrbits.end(); itr++) {
        nOrb += itr->second;    
    }

    cout<<"Number of orbits"<<nOrb<<endl;
    return 0;
}
