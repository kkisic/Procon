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
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());

    deque<int> d;
    int head = 0;
    int tail = n-1;
    int cnt = 1;
    d.push_back(a[head++]);
    while(cnt < n){
        d.push_front(a[tail--]);
        cnt++;
        if(cnt == n){
            break;
        }

        d.push_back(a[tail--]);
        cnt++;
        if(cnt == n){
            break;
        }

        d.push_front(a[head++]);
        cnt++;
        if(cnt == n){
            break;
        }

        d.push_back(a[head++]);
        cnt++;
    }

    int ans1 = 0;
    rep(i, n-1){
        ans1 += abs(d[i] - d[i+1]);
    }

    reverse(a.begin(), a.end());

    d = deque<int>();
    head = 0;
    tail = n-1;
    cnt = 1;
    d.push_back(a[head++]);
    while(cnt < n){
        d.push_front(a[tail--]);
        cnt++;
        if(cnt == n){
            break;
        }

        d.push_back(a[tail--]);
        cnt++;
        if(cnt == n){
            break;
        }

        d.push_front(a[head++]);
        cnt++;
        if(cnt == n){
            break;
        }

        d.push_back(a[head++]);
        cnt++;
    }
    int ans2 = 0;
    rep(i, n-1){
        ans2 += abs(d[i] - d[i+1]);
    }
    cout << max(ans1, ans2) << endl;

    return 0;
}
