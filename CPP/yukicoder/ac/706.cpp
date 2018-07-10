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
    int n;
    cin >> n;

    vector<int> len(1010);
    rep(i, n){
        string s;
        cin >> s;
        len[s.size()]++;
    }

    int max = 0;
    rep(i, 1011){
        if(len[max] <= len[i]){
            max = i;
        }
    }

    cout << max-2 << endl;

    return 0;
}
