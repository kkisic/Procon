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

const double INF = 1e19;
const int MOD = 1e9+7;

signed main(){
    int n;
    cin >> n;

    vector<vector<double>> edge(2*n, vector<double>(2*n));

    map<int, string> toString;
    map<string, int> toInt;
    int c = 0;

    rep(i, n){
        string l, s;
        int m;
        cin >> l >> m >> s;

        if(toInt.find(l) == toInt.end()){
            toString.emplace(c, l);
            toInt.emplace(l, c++);
        }
        if(toInt.find(s) == toInt.end()){
            toString.emplace(c, s);
            toInt.emplace(s, c++);
        }

        edge[toInt[l]][toInt[s]] = m;
        edge[toInt[s]][toInt[l]] = 1.0 / m;
    }

    rep(k, c){
        rep(i, c){
            rep(j, c){
                if(edge[i][j] != 0){
                    continue;
                }
                if(edge[i][k] > 0 && edge[k][j] > 0){
                    edge[i][j] = edge[i][k] * edge[k][j];
                }
                if(edge[i][k] > 0 && edge[j][k] > 0){
                    edge[i][j] = edge[i][k] / edge[j][k];
                }
            }
        }
    }

    int first = 0;
    int last = 0;
    rep(i, c){
        rep(j, c){
            if(edge[i][j] > edge[first][last]){
                first = i;
                last = j;
            }
        }
    }
    cout << 1 << toString[first] << "=" << fixed << setprecision(0) << edge[first][last] + 0.1 << toString[last] << endl;

    return 0;
}
