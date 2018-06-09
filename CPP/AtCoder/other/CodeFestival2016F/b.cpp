#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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
    int n;
    cin >> n;

    vector<int> s(1e7+1);
    s[0] = 0;
    for(int i = 1; i <= 1e7; i++){
        s[i] = i + s[i-1];
    }

    int l = 0;
    int r = 1e7;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(s[mid] >= n){
            r = mid;
        }else{
            l = mid;
        }
    }
    int except = s[r] - n;

    for(int i = 1; i <= r; i++){
        if(i == except){
            continue;
        }
        cout << i << endl;
    }

    return 0;
}
