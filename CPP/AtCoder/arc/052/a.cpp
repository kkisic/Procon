#include <cmath>
#include <iostream>
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

    int ans = 0;
    for(char c: s){
        if('0' <= c && c <= '9'){
            ans = ans * 10 + c - '0';
        }
    }
    cout << ans << endl;

    return 0;
}
