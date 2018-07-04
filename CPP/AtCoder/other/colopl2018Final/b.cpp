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

string s;
int i = 0;

string expr();
string operand(char op);

string expr(){
    if('0' <= s[i] && s[i] <= '9'){
        string num;
        while('0' <= s[i] && s[i] <= '9'){
            num.push_back(s[i++]);
        }
        return num;
    }
    return operand(s[i]);
}

string operand(char op){
    i++;

    vector<string> es;
    while(s[i] != ')'){
        i++;
        es.push_back(expr());
    }
    i++;

    string e;
    e.push_back('(');
    rep(j, (int)es.size()-1){
        e.append(es[j]);
        e.push_back(op);
    }
    e.append(es[es.size()-1]);
    e.push_back(')');

    return e;
}

signed main(){
    cin >> s;

    cout << expr() << endl;

    return 0;
}
