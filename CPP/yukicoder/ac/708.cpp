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

int i = 0;
string s;

int expr();
int ope(int x);
int num();

int expr(){
    int x = num();
    while(i < (int)s.length() && s[i] != ')'){
        x = ope(x);
    }
    i++;
    return x;
}

int ope(int x){
    if(s[i++] == '+'){
        return x + num();
    }
    return x - num();
}

int num(){
    if(s[i] == '('){
        i++;
        return expr();
    }
    return s[i++] - '0';
}

signed main(){
    cin >> s;

    cout << expr() << endl;

    return 0;
}
