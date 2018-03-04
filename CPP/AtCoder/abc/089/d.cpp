#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
    int h, w, d;
    cin >> h >> w >> d;

    vector<vector<int>> a(h+1, vector<int>(w+1));
    map<int, P> b;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> a[i][j];
            b.insert(make_pair(a[i][j], make_pair(i, j)));
        }
    }

    vector<int> dist(h*w+1);
    for(int i = 1; i <= h*w; i++){
        if(i <= d){
            continue;
        }
        P p1 = b.at(i);
        P p2 = b.at(i-d);
        dist[i] = dist[i-d] + abs(p1.first - p2.first) + abs(p1.second - p2.second);
    }

    int q;
    cin >> q;

    rep(i, q){
        int l, r;
        cin >> l >> r;

        if(l == r){
            cout << 0 << endl;
            continue;
        }
        cout << dist[r] - dist[l] << endl;
    }
    return 0;
}
