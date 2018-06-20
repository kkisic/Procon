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
                cin >> a[i][j];
            }
        }

        int ans = 0;
        for(int h = 3; h <= n; h++){
            for(int w = 3; w <= m; w++){
                rep(i, n-h+1){
                    rep(j, m-w+1){
                        int min = INF;
                        for(int k = i; k < i + h; k++){
                            for(int l = j; l < j + w; l++){
                                if(i < k && k < i+h-1 && j < l && l < j+w-1){
                                    continue;
                                }
                                if(min > a[k][l]){
                                    min = a[k][l];
                                }
                            }
                        }

                        int tmp = 0;
                        bool ok = true;
                        for(int k = i; k < i + h; k++){
                            for(int l = j; l < j + w; l++){
                                if(i == k || k == i+h-1 || j == l || l == j+w-1){
                                    continue;
                                }
                                if(min <= a[k][l]){
                                    ok = false;
                                }
                                tmp += min - a[k][l];
                            }
                        }

                        if(ok && ans < tmp){
                            ans = tmp;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
