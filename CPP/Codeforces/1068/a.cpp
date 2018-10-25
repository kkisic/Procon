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

template <typename T>
void debugv(vector<T>& vec){
    for(T t : vec){
        cout << t << endl;
    }
    cout << endl;
}

signed main(){
    int n, m, k, l;
    cin >> n >> m >> k >> l;

    int need = (k + l) / m;
    if((k + l) % m != 0){
        need++;
    }

    if(need * m > n){
        cout << -1 << endl;
        return 0;
    }
    cout << need << endl;

    return 0;
}
