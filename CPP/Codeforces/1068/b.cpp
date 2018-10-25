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
    int b;
    cin >> b;

    int ans = 0;
    for(int i = 1; i <= sqrt(b); i++){
        if(b % i == 0){
            ans += 2;
            if(i * i == b){
                ans--;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
