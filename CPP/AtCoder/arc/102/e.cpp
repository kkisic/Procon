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
    int l;
    cin >> l;

    int maxBit = -1;
    vector<bool> onBit(20, false);
    int x = l;
    while(x > 0){
        onBit[++maxBit] = x % 2 == 1;
        x /= 2;
    }

    vector<tuple<int, int, int>> edge;
    rep(i, maxBit){
        edge.emplace_back(i+1, i+2, pow(2, maxBit - 1 - i));
        edge.emplace_back(i+1, i+2, 0);
    }

    int sum = pow(2, maxBit);
    for(int i = maxBit - 1; i >= 0; i--){
        if(not onBit[i]){
            continue;
        }
        edge.emplace_back(1, maxBit - i + 1, sum);
        sum += pow(2, i);
    }

    cout << maxBit + 1 << " " << edge.size() << endl;
    rep(i, (int)edge.size()){
        cout << get<0>(edge[i]) << " " << get<1>(edge[i]) << " " << get<2>(edge[i]) << endl;
    }

    return 0;
}
