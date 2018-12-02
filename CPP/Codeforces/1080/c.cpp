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
#include <functional>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    rep(i, t){
        int n, m;
        cin >> n >> m;

        int x1, x2, x3, x4, y1, y2, y3, y4;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x3 >> y3 >> x4 >> y4;

        int s1 = max(x1, x3);
        int s2 = min(x2, x4);
        int t1 = max(y1, y3);
        int t2 = min(y2, y4);

        int w, b, mw, mb, ww, bb, mul;
        w = b = mw = mb = ww = bb = mul = 0;
        if(s1 <= s2 && t1 <= t2){
            bool isW = (s1 + t1) % 2 == 0;
            int width = s2 - s1 + 1;
            int hight = t2 - t1 + 1;
            mul = width * hight;
            mw += mul / 2;
            mb += mul / 2;
            if(mul % 2 == 1){
                if(isW){
                    mw++;
                }else{
                    mb++;
                }
            }
        }
        bool isW = (x1 + y1) % 2 == 0;
        int width = x2 - x1 + 1;
        int hight = y2 - y1 + 1;
        ww = width * hight;
        w += ww / 2;
        b += ww / 2;
        if(ww % 2 == 1){
            if(isW){
                w++;
            }else{
                b++;
            }
        }
        ww -= mul;

        isW = (x3 + y3) % 2 == 0;
        width = x4 - x3 + 1;
        hight = y4 - y3 + 1;
        bb = width * hight;
        w += bb / 2;
        b += bb / 2;
        if(bb % 2 == 1){
            if(isW){
                w++;
            }else{
                b++;
            }
        }
        b -= mb;
        w -= mw;

        int ab, aw;
        ab = aw = 0;
        isW = true;
        width = n;
        hight = m;
        aw += width * hight / 2;
        ab += width * hight / 2;
        if(width * hight % 2 == 1){
            if(isW){
                aw++;
            }else{
                ab++;
            }
        }

        cout << aw - w + ww << " " << ab - b + bb << endl;
    }

    return 0;
}
