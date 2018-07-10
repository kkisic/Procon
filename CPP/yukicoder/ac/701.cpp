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

    int i = 0;
    while(i+1 < n){
        int x = i;
        cout << 'a';
        while(x > 0){
            cout << (char)(x % 26 + 'a');
            x /= 26;
        }
        cout << 'a' << endl;
        i++;
    }
    cout << "an" << endl;

    return 0;
}
