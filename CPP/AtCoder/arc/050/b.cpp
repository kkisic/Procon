#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int

using namespace std;

typedef pair<int, int> P;

const int inf = 1e15;

int solve(int r, int b, int x, int y, int m){
    if(r < m*x || b < m){
        return min(b / y, r);
    }

    int rr = r - m * x;
    int bb = b - m;

    return m + min(bb / y, rr);
}

signed main(){
    int r, b, x, y;
    cin >> r >> b >> x >> y;

    int allR = min(r / x, b);
    int allB = min(b / y, r);

    int left = 0;
    int right = allR;

    while(right - left > 1){
        int m1 = left + (right - left) / 3;
        int m2 = left + (right - left) * 2 / 3;
        int c1 = solve(r, b, x, y, m1);
        int c2 = solve(r, b, x, y, m2);
        if(c1 > c2){
            right = m2;
        }else{
            left = m2;
        }
    }
    int ans1 = max(solve(r, b, x, y, right), solve(r, b, x, y, left));

    left = 0;
    right = allB;

    while(right - left > 1){
        int m1 = left + (right - left) / 3;
        int m2 = left + (right - left) * 2 / 3;
        int c1 = solve(b, r, y, x, m1);
        int c2 = solve(b, r, y, x, m2);
        if(c1 > c2){
            right = m2;
        }else{
            left = m2;
        }
    }
    int ans2 = max(solve(b, r, y, x, right), solve(b, r, y, x, left));

    cout << max(ans1, ans2) << endl;

    return 0;
}
