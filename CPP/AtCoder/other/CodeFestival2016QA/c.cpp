#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
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
    int k;
    cin >> s >> k;

    for(int i = 0; i < (int)s.length(); i++){
        if(s[i] == 'a'){
            continue;
        }
        int diff = 'z' - s[i] + 1;
        if(diff <= k){
            s[i] = 'a';
            k -= diff;
        }
    }

    int c = s[(int)s.size()-1];
    c = (c - 'a' + k) % 26 + 'a';
    s[(int)s.size()-1] = c;

    cout << s << endl;

    return 0;
}
