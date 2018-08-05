#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    string s;
    cin >> s;

    if(s[0] != 'A' || not ('a' <= s[1] && s[1] <= 'z')){
        cout << "WA" << endl;
        return 0;
    }

    bool ans = true;
    int c = 0;
    for(int i = 2; i < (int)s.length(); i++){
        if(s[i] == 'C' && i != (int)s.length() - 1){
            c++;
            continue;
        }
        if('A' <= s[i] && s[i] <= 'Z'){
            ans = false;
        }
    }

    if(c == 1 && ans){
        cout << "AC" << endl;
        return 0;
    }
    cout << "WA" << endl;

    return 0;
}
