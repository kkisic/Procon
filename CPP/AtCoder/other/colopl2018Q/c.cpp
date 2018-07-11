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

bool judge(int a, int b, int s, const vector<int>& other){
    vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    vector<bool> mark(35, false);
    int otherN = other.size();

    rep(i, (int)prime.size()){
        if(a == 0){
            break;
        }
        if(a % prime[i] == 0){
            mark[prime[i]] = true;
        }
    }

    rep(i, (int)prime.size()){
        if(b == 0){
            break;
        }
        if(b % prime[i] == 0){
            if(mark[prime[i]]){
                return false;
            }
            mark[prime[i]] = true;
        }
    }

    rep(i, otherN){
        if((s >> i) % 2 == 0){
            continue;
        }
        rep(j, (int)prime.size()){
            if(other[i] % prime[j] == 0){
                if(mark[prime[j]]){
                    return false;
                }
                mark[prime[j]] = true;
            }
        }
    }
    return true;
}

signed main(){
    int a, b;
    cin >> a >> b;

    vector<int> mod2, mod3, other;
    mod2.push_back(0);
    mod3.push_back(0);
    for(int i = a; i <= b; i++){
        if(i % 2 == 0){
            mod2.push_back(i);
            continue;
        }
        if(i % 3 == 0){
            mod3.push_back(i);
            continue;
        }
        other.push_back(i);
    }

    int otherN = other.size();

    int ans = 0;
    rep(i, (int)mod2.size()){
        rep(j, (int)mod3.size()){
            rep(k, (1 << otherN)){
                if(judge(mod2[i], mod3[j], k, other)){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
