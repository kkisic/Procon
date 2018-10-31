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

template<typename T>
class ConvexHullTrick{
    typedef pair<T, T> PT;
    private:
        //傾き降順
        deque<PT> lines;
        //getするxが単調か
        bool isMonotonicX;
        //最小
        function<bool(T, T)> comp;

    public:
        ConvexHullTrick(bool x = true, function<bool(T, T)> f = [](T l, T r) {return l >= r;})
            : isMonotonicX(x), comp(f) {}

        //no need : true
        bool check(PT l1, PT l2, PT l3){
            if(l1 < l3){
                swap(l1, l3);
            }
            return (l2.second - l1.second) * (l2.first - l3.first) >= (l1.first - l2.first) * (l3.second - l2.second);
        }

        void add(T a, T b){
            PT line = {a, b};
            while(lines.size() >= 2 && check(*(lines.end() - 2), lines.back(), line)){
                lines.pop_back();
            }
            lines.push_back(line);
        }

        T func(int id, T x){
            return lines[id].first * x + lines[id].second;
        }

        T get(T x){
            if(isMonotonicX){
                while(lines.size() >= 2 && comp(func(0, x), func(1, x))){
                    lines.pop_front();
                }
                return func(0, x);
            }

            int lo = -1;
            int hi = lines.size() - 1;
            while(hi - lo > 1){
                int mid = (hi + lo) / 2;
                if(comp(func(mid, x), func(mid+1, x))){
                    lo = mid;
                }else{
                    hi = mid;
                }
            }
            return func(hi, x);
        }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    ConvexHullTrick<int> cht;
    rep(i, n){
        cht.add(-2 * (i+1), a[i] + lround(pow(i + 1, 2)));
    }

    rep(i, n){
        cout << cht.get(i+1) + lround(pow(i + 1, 2)) << endl;
    }

    return 0;
}
