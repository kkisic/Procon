#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <regex>
#include <algorithm>
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

    regex re("A?KIHA?BA?RA?");
    if(regex_match(s, re)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
