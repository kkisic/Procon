#include <cmath>
#include <cstring>
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

class Trie{
    private:
        int char_size;
        class Node{
            public:
                int *nxt;
                int exist;
                vector<int> accept;
                Node(int size):exist(0){
                    nxt = new int[size];
                    memset(nxt, -1, sizeof(*nxt) * size);
                }
        };
        int margin;
        vector<Node> nodes;

        void update_direct(int node, int id){
            nodes[node].accept.push_back(id);
        }
        void update_child(int node){
            nodes[node].exist++;
        }

    public:
        Trie(int char_size = 26, int margin = 'a') :
            char_size(char_size), margin(margin){
                nodes.push_back(Node(char_size));
            }

        void add(const string &s, int s_idx, int n_idx, int id){
            if(s_idx == (int)s.size()){
                update_direct(n_idx, id);
            }else{
                const int c = s[s_idx] - margin;
                if(nodes[n_idx].nxt[c] == -1){
                    nodes[n_idx].nxt[c] = (int)nodes.size();
                    nodes.push_back(Node(char_size));
                }
                add(s, s_idx + 1, nodes[n_idx].nxt[c], id);
                update_child(n_idx);
            }
        }
        void add(const string &s, int id){
            add(s, 0, 0, id);
        }
        void add(const string &s){
            add(s, nodes[0].exist);
        }
        void query(const string &s, const function<void(int)> &f, int s_idx, int n_idx){
            for(auto &idx : nodes[n_idx].accept) f(idx);
            if(s_idx == (int)s.size()){
                return;
            }
            const int c = s[s_idx] - margin;
            if(nodes[n_idx].nxt[c] == -1) return;
            query(s, f, s_idx + 1, nodes[n_idx].nxt[c]);
        }
        void query(const string &s, const function<void(int)> &f){
            query(s, f, 0, 0);
        }
        int size() const{
            return nodes[0].exist;
        }
        int node_size() const{
            return nodes.size();
        }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    int m;
    cin >> s >> m;

    Trie trie;
    vector<string> p(m);
    rep(i, m){
        cin >> p[i];
        trie.add(p[i]);
    }
    vector<int> w(m);
    rep(i, m) cin >> w[i];

    vector<int> dp(SZ(s) + 1);
    rep(i, SZ(s)){
        auto f = [&](int id){
            dp[i+SZ(p[id])] = max(dp[i+SZ(p[id])], dp[i] + w[id]);
        };
        trie.query(s, f, i, 0);
        dp[i+1] = max(dp[i+1], dp[i]);
    }

    cout << dp[SZ(s)] << endl;

    return 0;
}
