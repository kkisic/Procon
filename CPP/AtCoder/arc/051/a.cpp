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
const int BIAS = 100;

int dist(int x, int y){
    return x * x + y * y;
}

signed main(){
    double x1, y1, r, x2, y2, x3, y3;
    cin >> x1 >> y1 >> r >> x2 >> y2 >> x3 >> y3;

    if(dist(x2-x1, y2-y1)<=r*r && dist(x3-x1, y2-y1)<=r*r
            && dist(x2-x1, y3-y1)<=r*r && dist(x3-x1, y3-y1)<=r*r){
        cout << "YES" << endl;
        cout << "NO" << endl;
        return 0;
    }

    if(x2 <= x1-r && x1+r <= x3 && y2 <= y1-r && y1+r <= y3){
        cout << "NO" << endl;
        cout << "YES" << endl;
        return 0;
    }

    cout << "YES" << endl;
    cout << "YES" << endl;
    return 0;
}
