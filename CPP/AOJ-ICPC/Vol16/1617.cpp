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
    string s;
    cin >> s;
    while(s != "."){
        string t;
        cin >> t;

        if(s == t){
            cout << "IDENTICAL" << endl;
            cin >> s;
            continue;
        }

        vector<string> xs;
        vector<string> xt;
        int i = 0;
        while(i < (int)s.length()){
            string tmp;
            if(s[i] == '\"'){
                i++;
                tmp = "";
                while(s[i] != '\"'){
                    tmp.push_back(s[i]);
                    i++;
                }
                i++;
                xs.push_back(tmp);
                continue;
            }

            tmp = "";
            while(s[i] != '\"' && i < (int)s.length()){
                tmp.push_back(s[i++]);
            }
            xt.push_back(tmp);
        }

        vector<string> ys;
        vector<string> yt;
        i = 0;
        while(i < (int)t.length()){
            string tmp;
            if(t[i] == '\"'){
                i++;
                tmp = "";
                while(t[i] != '\"'){
                    tmp.push_back(t[i]);
                    i++;
                }
                i++;
                ys.push_back(tmp);
                continue;
            }

            tmp = "";
            while(t[i] != '\"' && i < (int)t.length()){
                tmp.push_back(t[i++]);
            }
            yt.push_back(tmp);
        }

        if(xs.size() != ys.size() || xt.size() != yt.size()){
            cout << "DIFFERENT" << endl;
            cin >> s;
            continue;
        }

        int c = 0;
        rep(i, (int)xs.size()){
            if(xs[i] != ys[i]){
                c++;
            }
        }

        int d = 0;
        rep(i, (int)xt.size()){
            if(xt[i] != yt[i]){
                d++;
            }
        }

        if(d == 0 && c == 1){
            cout << "CLOSE" << endl;
            cin >> s;
            continue;
        }
        cout << "DIFFERENT" << endl;

        cin >> s;
    }

    return 0;
}
