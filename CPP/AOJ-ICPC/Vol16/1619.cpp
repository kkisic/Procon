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
    while(true){
        int n, m;
        cin >> n >> m;

        if(n == 0 && m == 0){
            break;
        }

        vector<vector<int>> a(n, vector<int>(m));
        rep(i, n){
            rep(j, m){
                char c;
                cin >> c;
                a[i][j] = c - '0';
            }
        }

        if(n < m){
            int ans = 0;
            rep(s, (1 << n)){
                int c = 0;
                vector<int> tmp(m);
                rep(i, n){
                    if((s >> i) % 2 == 1){
                        c++;
                        rep(j, m){
                            tmp[j] ^= a[i][j];
                        }
                    }
                }

                bool ok = true;
                rep(i, m){
                    if(tmp[i] != 0){
                        ok = false;
                    }
                }
                if(ok && ans < c){
                    ans = c;
                }
            }
            cout << ans << endl;

            continue;
        }

        vector<int> x(n);
        rep(i, n){
            rep(j, m){
                x[i] *= 2;
                x[i] += a[i][j];
            }
        }

        vector<int> dp1((1 << m), -1);
        dp1[0] = 0;

        int ans = 0;
        for(int i = 0; i < n; i++){
            vector<int> dp2((1 << m), -1);
            rep(s, (1 << m)){
                if(dp1[s^x[i]] != -1){
                    dp2[s] = max(dp2[s], max(dp1[s], dp1[s^x[i]] + 1));
                }
                dp2[s] = max(dp2[s], dp1[s]);
            }
            dp1 = dp2;
        }
        cout << dp1[0] << endl;
    }

    return 0;
}
