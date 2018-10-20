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
    int n, m, q;
    cin >> n >> m >> q;

    map<char, P> dic;
    rep(i, n){
        rep(j, m){
            char c;
            cin >> c;

            if(c == '*'){
                continue;
            }
            dic[c] = make_pair(i+1, j+1);
        }
    }

    rep(i, q){
        char c;
        cin >> c;

        if(dic.find(c) == dic.end()){
            cout << "NA" << endl;
            continue;
        }
        cout << dic[c].first << " " << dic[c].second << endl;
    }

    return 0;
}
