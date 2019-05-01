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

template <typename T>
using vector2 = vector<vector<T>>;
template <typename T>
vector2<T> initVec2(size_t n0, size_t n1, T e = T()){
    return vector2<T>(n0, vector<T>(n1, e));
}

template <typename T>
using vector3 = vector<vector<vector<T>>>;
template <typename T>
vector3<T> initVec3(size_t n0, size_t n1, size_t n2, T e = T()){
    return vector3<T>(n0, vector2<T>(n1, vector<T>(n2, e)));
}

int cross(int a, int b, int c, int d){
    return a * d - b * c;
}

//Longest Common Subsequence
string lcs(string s, string t){
    vector<vector<int>> dp((int)s.size() + 1, vector<int>((int)t.size() + 1));
    for(int i = 0; i <= (int)s.size(); i++){
        for(int j = 0; j <= (int)t.size(); j++){
            if(i + 1 <= (int)s.size()){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            }
            if(j + 1 <= (int)t.size()){
                dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
            }
            if(i + 1 <= (int)s.size() && j + 1 <= (int)t.size()){
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + (s[i] == t[j]));
            }
        }
    }

    int x = (int)s.size();
    int y = (int)t.size();
    string ans;
    while(x > 0 && y > 0){
        if(s[x-1] == t[y-1]){
            ans.push_back(s[x-1]);
            x--;
            y--;
            continue;
        }
        if(dp[x][y] == dp[x-1][y]){
            x--;
            continue;
        }
        y--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    string st = lcs(s, t);
    cout << SZ(st) + 1 << endl;


    return 0;
}
