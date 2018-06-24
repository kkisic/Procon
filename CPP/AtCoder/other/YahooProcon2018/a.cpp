#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    string s;
    cin >> s;

    if(s[0] != 'y' || s[1] != 'a' || s[2] != 'h' || s[3] != s[4]){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    return 0;
}
