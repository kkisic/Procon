#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

pair<P, P> cut(P cake, int s){
    int w = cake.first;
    int d = cake.second;
    s %= (w * 2 + d * 2);

    if((0 < s && s < w) || (w + d < s && s < 2 * w + d)){
        int nw1 = s % (w + d);
        int nw2 = w - nw1;
        return make_pair(make_pair(min(nw1, nw2), d), make_pair(max(nw1, nw2), d));
    }

    int nd1 = (s - w) % (w + d);
    int nd2 = d - nd1;
    return make_pair(make_pair(w, min(nd1, nd2)), make_pair(w, max(nd1, nd2)));
}

signed main(){
    while(true){
        int n, w, d;
        cin >> n >> w >> d;

        if(n == 0 && w == 0 && d == 0){
            break;
        }

        vector<P> cake;
        cake.emplace_back(w, d);
        rep(i, n){
            int p, s;
            cin >> p >> s;

            P c = cake[p-1];
            cake.erase(cake.begin() + p - 1);

            pair<P, P> newCake = cut(c, s);
            cake.push_back(newCake.first);
            cake.push_back(newCake.second);
        }

        vector<int> area;
        rep(i, (int)cake.size()){
            area.push_back(cake[i].first * cake[i].second);
        }
        sort(area.begin(), area.end());
        rep(i, (int)area.size() - 1){
            cout << area[i] << " ";
        }
        cout << area[(int)area.size()-1] << endl;
    }

    return 0;
}
