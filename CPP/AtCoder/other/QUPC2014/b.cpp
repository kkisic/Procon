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

signed main(){
    int n;
    cin >> n;

    vector<string> ans = {"ium"};
    int cnt = 0;
    while(n > 0){
        string next;
        switch(n % 10){
            case 0:
                next = "nil";
                break;
            case 1:
                next = "un";
                break;
            case 2:
                next = "bi";
                break;
            case 3:
                next = "tri";
                break;
            case 4:
                next = "quad";
                break;
            case 5:
                next = "pent";
                break;
            case 6:
                next = "hex";
                break;
            case 7:
                next = "sept";
                break;
            case 8:
                next = "oct";
                break;
            case 9:
                next = "enn";
                break;
        }

        if(cnt == 0 && (n % 10 == 2 || n % 10 == 3)){
            next.pop_back();
        }
        if(cnt >= 1 && n % 10 == 9 && ans[ans.size()-1] == "nil"){
            next.pop_back();
        }
        ans.push_back(next);
        n /= 10;
        cnt++;
    }
    reverse(ans.begin(), ans.end());
    ans[0][0] = toupper(ans[0][0]);
    for(string s : ans){
        cout << s;
    }
    cout << endl;

    return 0;
}
