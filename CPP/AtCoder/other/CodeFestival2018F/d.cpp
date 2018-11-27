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

int f(char c){
    if('A' <= c && c <= 'Z'){
        return c - 'A';
    }
    return c - 'a' + 26;
}

char g(int x){
    if(x < 26){
        return 'A' + x;
    }
    return 'a' + x - 26;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<vector<int>>> cnt(52, vector<vector<int>>(52, vector<int>(52)));

    rep(i, n){
        string s;
        cin >> s;

        vector<P> paired;
        bool used1[52] = {};
        bool used2[52][52] = {};
        bool used3[52][52][52] = {};

        for(char c : s){
            int x = f(c);

            for(P p : paired){
                if(used3[p.first][p.second][x]){
                    continue;
                }
                used3[p.first][p.second][x] = true;
                cnt[p.first][p.second][x]++;
            }

            rep(j, 52){
                if(not used1[j]){
                    continue;
                }
                if(not used2[j][x]){
                    used2[j][x] = true;
                    paired.emplace_back(j, x);
                }
            }
            used1[x] = true;
        }
    }

    int a, b, c;
    a = b = c = 0;
    rep(i, 52){
        rep(j, 52){
            rep(k, 52){
                if(cnt[a][b][c] < cnt[i][j][k]){
                    a = i;
                    b = j;
                    c = k;
                }
            }
        }
    }
    cout << g(a) << g(b) << g(c) << endl;

    return 0;
}
