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
    int a, b;
    cin >> a >> b;

    int k = 0;
    for(int i = 1; i < 100000; i++){
        if(i * (i + 1) / 2 <= a + b){
            k = i;
        }
    }

    vector<int> used(k + 1, false);
    int t = a;
    int n = 0;
    vector<int> nn;
    for(int i = k; i >= 1; i--){
        if(t >= i){
            used[i] = true;
            t -= i;
            n++;
            nn.push_back(i);
        }
    }

    t = b;
    int m = 0;
    vector<int> mm;
    for(int i = k; i >= 1; i--){
        if(used[i]){
            continue;
        }
        if(t >= i){
            t -= i;
            m++;
            mm.push_back(i);
        }
    }

    cout << n << endl;
    rep(i, n-1){
        cout << nn[i] << " ";
    }
    if(n >= 1){
        cout << nn[n-1] << endl;
    }else{
        cout << endl;
    }

    cout << m << endl;
    rep(i, m-1){
        cout << mm[i] << " ";
    }
    if(m >= 1){
        cout << mm[m-1] << endl;
    }else{
        cout << endl;
    }

    return 0;
}
