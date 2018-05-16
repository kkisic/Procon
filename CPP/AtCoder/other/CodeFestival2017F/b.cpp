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
    string s;
    cin >> s;
    vector<int> a(3);

    for(char c: s){
        switch(c){
            case 'a': a[0]++;
                      break;
            case 'b': a[1]++;
                      break;
            case 'c': a[2]++;
                      break;
            default: break;
        }
    }
    sort(a.begin(), a.end());
    if(a[2] - a[0] <= 1){
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;

    return 0;
}
