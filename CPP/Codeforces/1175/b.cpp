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

int l;
int x;

const int MAX = (1LL << 32) - 1;
void solve(vector<int>& r){
    int y = 1;
    for(int a : r){
        if(MAX / y < a){
            cout << "OVERFLOW!!!" << endl;
            exit(0);
        }
        y *= a;
    }

    if(MAX - x < y){
        cout << "OVERFLOW!!!" << endl;
        exit(0);
    }
    x += y;
}

void f(vector<int>& r){
    if(l <= 0){
        return;
    }
    l--;
    string s;
    cin >> s;

    if(s == "add"){
        solve(r);
    }
    if(s == "for"){
        int a;
        cin >> a;
        r.push_back(a);
        f(r);
    }
    if(s == "end"){
        r.pop_back();
        return;
    }

    f(r);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> l;
    x = 0;

    vector<int> r;
    f(r);
    cout << x << endl;

    return 0;
}
