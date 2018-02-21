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

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int a, b;
    cin >> a >> b;

    int ans1;
    if(a / 10 == 99){
        ans1 = 999 - b;
    }else if(a / 100 == 9){
        ans1 = 990 + a % 10 - b;
    }else{
        ans1 = 900 + a % 100 - b;
    }

    int ans2;
    if(b / 10 == 10){
        ans2 = a - 100;
    }else if(b / 100 == 1){
        ans2 = a - (100 + b % 10);
    }else{
        ans2 = a - (100 + b % 100);
    }

    cout << max(ans1, ans2) << endl;

    return 0;
}
