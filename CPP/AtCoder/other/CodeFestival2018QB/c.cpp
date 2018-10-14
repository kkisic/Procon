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
    int n;
    cin >> n;

    vector<vector<bool>> ans(n, vector<bool>(n, false));
    vector<vector<bool>> s(n, vector<bool>(n, false));
    vector<int> d = {1, 0, -1, 0};
    int cnt = 0;

    stack<P> st;
    st.emplace(0, 0);
    vector<int> dx = {-2, -1, 2, 1};
    vector<int> dy = {-1, 2, 1, -2};

    while(not st.empty()){
        int x = st.top().first;
        int y = st.top().second;
        st.pop();

        if(ans[x][y]){
            continue;
        }

        ans[x][y] = true;
        s[x][y] = true;
        cnt++;
        rep(k, 4){
            int nx = x + d[k];
            int ny = y + d[k^1];
            if(0 <= nx && nx < n && 0 <= ny && ny < n){
                s[nx][ny] = true;
            }
        }

        rep(k, 4){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || n <= nx || ny < 0 || n <= ny || ans[nx][ny]){
                continue;
            }
            st.emplace(nx, ny);
        }
    }

    rep(i, n){
        rep(j, n){
            if(s[i][j]){
                continue;
            }
            ans[i][j] = true;
            s[i][j] = true;
            cnt++;
            rep(k, 4){
                int nx = i + d[k];
                int ny = j + d[k^1];
                if(0 <= nx && nx < n && 0 <= ny && ny < n){
                    s[nx][ny] = true;
                }
            }
        }
    }

    rep(i, n){
        rep(j, n){
            if(ans[i][j]){
                cout << 'X';
            }else{
                cout << '.';
            }
        }
        cout << endl;
    }
    return 0;
}
