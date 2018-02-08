#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int

using namespace std;

typedef pair<int, int> P;

const int inf = 1e15;

signed main(){
    string s;
    cin >> s;

    vector<int> c('z'+1, 0);
    for(const auto& i: s){
        c[i]++;
    }

    int odd = 0;
    for(int i = 'a'; i <= 'z'; i++){
        if(c[i] % 2 == 1){
            odd++;
        }
    }

    if(odd <= 1){
        cout << s.length() << endl;
        return 0;
    }

    int even = (s.length() - odd) / 2;
    int ans = even / odd * 2 + 1;

    cout << ans << endl;

    return 0;
}
