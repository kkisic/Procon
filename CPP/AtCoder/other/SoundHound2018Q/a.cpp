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

    if(a + b == 15){
        cout << "+" << endl;
        return 0;
    }

    if(a * b == 15){
        cout << "*" << endl;
        return 0;
    }

    cout << "x" << endl;

    return 0;
}
