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
    int k;
    cin >> k;

    int a = 1;
    int b = 0;
    for(int i = 0; i <= k; i++){
        int tmp = b;
        b = a;
        a = b + tmp;
    }
    cout << a << " " << b << endl;

    return 0;
}
