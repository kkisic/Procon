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

typedef tuple<string, string, string, string> tup;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    map<int, vector<pair<char, string>>> ms;

    rep(i, n){
        string s;
        cin >> s;
        int cnt = 0;
        char last;
        for(char c : s){
            if(c == 'a'){
                cnt++;
                last = c;
            }
            if(c == 'i'){
                cnt++;
                last = c;
            }
            if(c == 'u'){
                cnt++;
                last = c;
            }
            if(c == 'e'){
                cnt++;
                last = c;
            }
            if(c == 'o'){
                cnt++;
                last = c;
            }
        }
        if(ms.find(cnt) == ms.end()){
            ms[cnt] = vector<pair<char, string>>();
        }
        ms[cnt].emplace_back(last, s);
    }

    vector<pair<string, string>> same;
    vector<pair<string, string>> diff;
    for(pair<int, vector<pair<char, string>>> p : ms){
        vector<pair<char, string>> vs = p.second;
        sort(ALL(vs));
        vector<string> ex;
        for(int i = 0; i < SZ(vs); i++){
            if(i + 1 < SZ(vs)){
                if(vs[i].first == vs[i+1].first){
                    same.emplace_back(vs[i].second, vs[i+1].second);
                    i++;
                }else{
                    ex.push_back(vs[i].second);
                }
            }else{
                ex.push_back(vs[i].second);
            }
        }
        for(int i = 0; i + 1 < SZ(ex); i += 2){
            diff.emplace_back(ex[i], ex[i+1]);
        }
    }

    vector<tup> ans;
    int i = 0;
    int j = 0;
    while(i < SZ(same) && j < SZ(diff)){
        ans.emplace_back(diff[j].first, same[i].first, diff[j].second, same[i].second);
        i++;
        j++;
    }

    while(i + 1 < SZ(same)){
        ans.emplace_back(same[i+1].first, same[i].first, same[i+1].second, same[i].second);
        i += 2;
    }

    cout << SZ(ans) << endl;
    rep(i, SZ(ans)){
        string a, b, c, d;
        tie(a, b, c, d) = ans[i];
        cout << a << " " << b << endl;
        cout << c << " " << d << endl;
    }

    return 0;
}
