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
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;
const int MAX = 120*360;
const int HR = 1;
const int MR = 12;
const int SR = 720;

signed main(){
    int h, m, s, c1, c2;
    cin >> h >> m >> s >> c1 >> c2;

    h = (h % 12) * 60 * 60 + m * 60 + s;
    m = (m * 60 + s) * MR;
    s *= SR;

    int d1, d2, count;
    d1 = d2 = count = 0;
    int first, last;
    first = last = 0;
    while(d1 <= c1 && d2 <= c2){
        if(m > s && m + MR <= s + SR){
            d1++;
        }
        if(h > m && h + HR <= m + MR){
            d2++;
        }

        count++;
        if(first == 0 && d1 == c1 && d2 == c2){
            first = count;
            if(h + HR == m + MR || m + MR == s + SR){
                first++;
            }
        }

        h = (h + HR) % MAX;
        m = (m + MR) % MAX;
        s = (s + SR) % MAX;
    }

    if(first == 0){
        cout << -1 << endl;
        return 0;
    }

    cout << first << " " << count - 1 << endl;

    return 0;
}
