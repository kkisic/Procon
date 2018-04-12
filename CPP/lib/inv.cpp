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

int powM(int x, int n){
    if(n == 0){
        return 1;
    }
    if(n % 2 == 0){
        return powM(x * x % MOD, n / 2);
    }
    return powM(x, n-1) * x % MOD;
}

int factM(int n){
    static vector<int> t = {1};

    if((int)t.size() > n){
        return t[n];
    }

    for(int i = t.size(); i <= n; i++){
        t.push_back(t[i-1] * i % MOD);
    }
    return t[n];
}

int comb(const vector<int>& t, int cn, int n, int k){
    if(n < k){
        return 0;
    }
    return cn * t[k] % MOD * t[n-k] % MOD;
}

vector<int> makeTable(int n){
    vector<int> t(n+1);
    t[n] = powM(factM(n), MOD-2);

    for(int i = n-1; i >= 0; i--){
        t[i] = t[i+1] * (i+1) % MOD;
    }
    return t;
}

//表を作らない
int comb(int n, int k){
    if(n < k){
        return 0;
    }
    int kFactInv = powM(factM(k), MOD - 2);
    int x = 1;
    for(int i = n; i > n - k; i--){
        x = i % MOD * x % MOD;
    }
    return kFactInv * x % MOD;
}

signed main (){
    return 0;
}
