#include<bits/stdc++.h>

using namespace std;

vector<string> getPath(map<string, string> &objs, string leaf) {
    auto itr = objs.find(leaf); 
    vector<string> path;
    while(itr != objs.end()){
        path.push_back(itr->second);
        itr = objs.find(itr->second);
    }
    return path;
}


int main() {
    string line;
    map<string, string> rObjs;
    while(getline(cin, line)) {
        string head = line.substr(0,3);
        string tail = line.substr(4,3);
        
        rObjs.insert(make_pair(tail, head));
    }
    
    vector<string> spath = getPath(rObjs, "SAN");
    vector<string> ypath = getPath(rObjs, "YOU");

    int I=spath.size()-1;
    int J=ypath.size()-1;
    while(I>=0 && J>=0) {
        cout<<spath[I]<<" "<<ypath[J]<<endl;
        if(spath[I] == ypath[J]) {
            I--;
            J--;
        }
        else {
            cout<<I<<" "<<J<<endl;
            break;
        }
    }

    cout<<"Result: "<<(I+J+2)<<endl;
    return 0;
}
