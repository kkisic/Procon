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

signed main(){
    vector<vector<int>> c(3, vector<int>(3));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> c[i][j];
        }
    }

    for(int i = 0; i < 2; i++){
        int x = c[0][i] - c[0][i+1];
        int y = c[1][i] - c[1][i+1];
        int z = c[2][i] - c[2][i+1];
        if(x != y || y != z){
            cout << "No" << endl;
            return 0;
        }
    }

    for(int i = 0; i < 2; i++){
        int x = c[i][0] - c[i+1][0];
        int y = c[i][1] - c[i+1][1];
        int z = c[i][2] - c[i+1][2];
        if(x != y || y != z){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
