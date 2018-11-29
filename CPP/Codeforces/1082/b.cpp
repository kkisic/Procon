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
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    int head = -1;
    vector<P> range;
    rep(i, n){
        if(s[i] == 'G' && head == -1){
            head = i;
        }
        if(s[i] == 'S' && head != -1){
            range.emplace_back(head, i - 1);
            head = -1;
        }
    }
    if(head != -1){
        range.emplace_back(head, n - 1);
    }

    int num = SZ(range);
    int len = 0;
    rep(i, num){
        int tmp = range[i].second - range[i].first + 1;
        len = max(len, tmp);
    }
    bool p = false;
    rep(i, num - 1){
        if(range[i].second + 2 != range[i+1].first){
            continue;
        }
        int tmp = range[i].second - range[i].first + 1;
        tmp += range[i+1].second - range[i+1].first + 1;
        len = max(len, tmp);
        p = true;
    }

    if(num == 1){
        len = range[0].second - range[0].first + 1;
    }

    if(num > 2 && p || num > 1 && not p){
        len++;
    }
    cout << len << endl;

    return 0;
}
