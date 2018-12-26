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
        int h, w;
        cin >> h >> w;

        if(h % 2 == 0 && w % 2 == 0){
            cout << "Second" << endl;

            int x, y;
            cin >> x >> y;
            while(x != -1 && y != -1){
                cout << x << " " << w - y - 1 << endl;
                cin >> x >> y;
            }
            continue;
        }


        if(h * w % 2){
            cout << "First" << endl;
            cout << h - 1 << " " << w - 1 << endl;
        }else{
            cout << "Second" << endl;
        }
        bool trans = false;
        if(w % 2 == 0){
            swap(h, w);
            trans = true;
        }
        int x, y;
        cin >> x >> y;
        while(x != -1 && y != -1){
            if(trans){
                swap(x, y);
            }

            int tmp = x * w + y;
            if(tmp % 2){
                tmp--;
            }else{
                tmp++;
            }

            int nx = tmp / w;
            int ny = tmp % w;
            if(trans){
                cout << ny << " " << nx << endl;
            }else{
                cout << nx << " " << ny << endl;
            }
            cin >> x >> y;
        }
    }

    return 0;
}
