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
    string s;
    cin >> n >> s;

    int head = 0;
    rep(i, (int)s.length()){
        if(s[i] == 'B'){
            break;
        }
        head++;
    }

    if(head == (int)s.length()){
        cout << (1 + head * n) * head * n / 2 << endl;
        return 0;
    }

    int sum = 0;
    int cnt = 0;
    rep(i, (int)s.length()){
        if(s[i] == 'B'){
            cnt = 0;
            continue;
        }
        cnt++;
        sum += cnt;
    }

    if(s[0] == 'B'){
        cnt = 0;
    }

    sum = sum + (sum + cnt * head) * (n - 1);
    cout << sum << endl;

    return 0;
}
