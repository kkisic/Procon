#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

bool comp(tuple<int, int, int>& x, tuple<int, int, int>& y){
    int x_i = get<0>(x);
    int y_i = get<0>(y);
    int x_a = get<1>(x);
    int y_a = get<1>(y);
    int x_t = get<2>(x);
    int y_t = get<2>(y);

    if(x_a != y_a){
        return x_a > y_a;
    }

    if(x_t != y_t){
        return x_t < y_t;
    }

    return x_i > y_i;
}

signed main(){
    while(true){
        int M, T, P, R;
        cin >> M >> T >> P >> R;

        if(M == 0 && T == 0 && P == 0 && R == 0){
            break;
        }

        vector<vector<int>> res(T+1, vector<int>(P+1));
        vector<vector<bool>> ac(T+1, vector<bool>(P+1, false));
        vector<int> time(T+1);

        rep(i, R){
            int m, t, p, j;
            cin >> m >> t >> p >> j;

            if(j == 0){
                ac[t][p] = true;
                time[t] += m;
                continue;
            }
            res[t][p]++;
        }

        vector<tuple<int, int, int>> rank;
        for(int i = 1; i <= T; i++){
            int pena = 0;
            int AC = 0;
            for(int j = 1; j <= P; j++){
                if(ac[i][j]){
                    pena += res[i][j];
                    AC++;
                }
            }
            pena *= 20;

            rank.emplace_back(i, AC, time[i] + pena);
        }
        sort(rank.begin(), rank.end(), comp);

        rep(i, T-1){
            int r = get<0>(rank[i]);
            int x_a = get<1>(rank[i]);
            int y_a = get<1>(rank[i+1]);
            int x_t = get<2>(rank[i]);
            int y_t = get<2>(rank[i+1]);

            if(x_a != y_a || x_t != y_t){
                cout << r << ",";
            }else{
                cout << r << "=";
            }
        }
        cout << get<0>(rank[T-1]) << endl;

    }

    return 0;
}
