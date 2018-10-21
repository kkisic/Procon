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
    int h, w, a, b;
    cin >> h >> w >> a >> b;

    vector<vector<bool>> s(h, vector<bool>(w, false));
    int stone = 0;
    rep(i, h){
        rep(j, w){
            char c;
            cin >> c;
            if(c == 'S'){
                s[i][j] = true;
                stone++;
            }
        }
    }

    int hor, ver, hv;
    hor = ver = hv = 0;
    rep(i, h / 2){
        rep(j, w / 2){
            int x = 0, y = 0;
            if(s[i][j] && s[h-1-i][j]){
                x++;
            }
            if(s[i][w-1-j] && s[h-1-i][w-1-j]){
                x++;
            }
            if(s[i][j] && s[i][w-1-j]){
                y++;
            }
            if(s[h-1-i][j] && s[h-1-i][w-1-j]){
                y++;
            }
            if(x == 2){
                hv++;
                x = y = 0;
            }
            ver += x;
            hor += y;
        }
    }

    int ans1, ans2;
    ans1 = ans2 = 0;
    if(hv * 4 + ver * 2 != stone){
        ans1 += a;
    }
    ans1 += ver * a;
    if(hv * 4 != stone){
        ans1 += b;
    }
    ans1 += hv * (max(a, b) + a + b);

    if(hv * 4 + hor * 2 != stone){
        ans2 += b;
    }
    ans2 += hor * b;
    if(hv * 4 != stone){
        ans2 += a;
    }
    ans2 += hv * (max(a, b) + a + b);

    cout << max(ans1, ans2) << endl;

    return 0;
}
