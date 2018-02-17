#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int

using namespace std;

typedef pair<int, int> P;

const int inf = 1e15;

signed main(){
    vector<string> vs;
    string s;
    while(true){
        cin >> s;
        if(cin.fail()){
            break;
        }
        vs.push_back(s);
    }

    vector<string> ans;
    for(string ss: vs){
        if(ss == "Left"){
            ans.push_back("<");
        }else if(ss == "Right"){
            ans.push_back(">");
        }else{
            ans.push_back("A");
        }
        ans.push_back(" ");
    }

    for(int i = 0; i < (int)ans.size()-1; i++){
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
