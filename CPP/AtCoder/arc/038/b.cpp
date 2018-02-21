#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

const int WIN = 1;
const int LOSE = 2;

int h, w;

int judge(const vector<vector<bool> >& area, int i, int j){
    static vector<vector<int> > memo(h, vector<int>(w));
    if(i < 0 || i >= h || j < 0 || j >= w || !area[i][j]){
        return WIN;
    }
    if(memo[i][j] != 0){
        return memo[i][j];
    }

    int result = LOSE;
    if(judge(area, i+1, j) == LOSE){
        result = WIN;
    }
    if(judge(area, i+1, j+1) == LOSE){
        result = WIN;
    }
    if(judge(area, i, j+1) == LOSE){
        result = WIN;
    }
    memo[i][j] = result;
    return memo[i][j];
}

signed main(){
    cin >> h >> w;

    vector<vector<bool> > area(h, vector<bool>(w, true));
    rep(i, h){
        rep(j, w){
            char c;
            cin >> c;
            if(c == '#'){
                area[i][j] = false;
            }
        }
    }

    if(judge(area, 0, 0) == WIN){
        cout << "First" << endl;
        return 0;
    }
    cout << "Second" << endl;

    return 0;
}
