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

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

class topological_sort{
    public:
        int n;
        vector<vector<int>> edge;
        vector<int> sorted;
        vector<int> mark;

        topological_sort(int n, vector<vector<int>>edge)
            : n(n), edge(edge), sorted(), mark(n) {}

        bool sort(){
            rep(i, n+1){
                if(mark[i] != 0){
                    continue;
                }
                if(not dfs(i)){
                    return false;
                }
            }
            return true;
        }

        bool kahn_sort(){
            priority_queue<int, vector<int>, greater<int>> s;
            vector<int> in(n);

            rep(v, n){
                for(int u : edge[v]) in[u]++;
            }

            rep(v, n){
                if(in[v] == 0) s.push(v);
            }

            while(not s.empty()){
                int v = s.top();
                sorted.push_back(v);
                s.pop();

                for(int u : edge[v]){
                    in[u]--;
                    if(in[u] == 0){
                        s.push(u);
                    }
                }
            }

            rep(i, n){
                if(in[i] > 0){
                    return false;
                }
            }
            return true;
        }

    private:
        bool dfs(int v){
            if(mark[v] == -1){
                return false;
            }
            if(mark[v] == 1){
                return true;
            }
            mark[v] = -1;

            for(int u : edge[v]){
                if(not dfs(u)){
                    return false;
                }
            }

            mark[v] = 1;
            sorted.push_back(v);
            return true;
        }
};

signed main(){
    int n;
    cin >> n;

    vector<vector<int>> edge(26, vector<int>());
    rep(i, n){
        string a, b;
        cin >> a >> b;

        int len = min(a.length(), b.length());
        int diff = -1;
        rep(j, len){
            if(a[j] == b[j]){
                continue;
            }
            diff = j;
            break;
        }

        if(diff != -1){
            edge[a[diff]-'a'].push_back(b[diff]-'a');
            continue;
        }

        if(a.length() > b.length()){
            cout << -1 << endl;
            return 0;
        }
    }

    topological_sort tp(26, edge);
    bool ok = tp.kahn_sort();

    if(not ok){
        cout << -1 << endl;
        return 0;
    }

    rep(i, 26){
        cout << (char)(tp.sorted[i] + 'a');
    }
    cout << endl;

    return 0;
}
