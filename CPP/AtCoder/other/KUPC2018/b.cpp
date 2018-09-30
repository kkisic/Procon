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

vector<char> com(10);

int h, w;

void dfs(int x, int row, const vector<vector<bool>>& a){
    if(row < 0){
        rep(i, h-1){
            cout << com[i];
        }
        cout << endl;
        exit(0);
    }

    if(not a[row][x]){
        return;
    }

    if(x+1 < w){
        com[h-1-row] = 'R';
        dfs(x+1, row-1, a);
    }

    if(x-1 >= 0){
        com[h-1-row] = 'L';
        dfs(x-1, row-1, a);
    }

    com[h-1-row] = 'S';
    dfs(x, row-1, a);
}

signed main(){
    cin >> h >> w;
    int s;
    vector<vector<bool>> area(h, vector<bool>(w, false));
    rep(i, h){
        rep(j, w){
            char c;
            cin >> c;

            if(c == 's'){
                s = j;
                area[i][j] = true;
                continue;
            }

            if(c == '.'){
                area[i][j] = true;
            }
        }
    }

    dfs(s, h-1, area);
    cout << "impossible" << endl;

    return 0;
}
