#include <vector>
#include <algorithm>
#include <iostream>

#define int long long int

const int inf = 1e15;

using namespace std;

signed main(){
    int a, b, k, l;
    cin >> a >> b >> k >> l;

    if(a*l < b){
        cout << a*k << endl;
        return 0;
    }

    int s = k / l;
    int ans = b * s;
    if((k-s*l)*a < b){
        ans += (k-s*l)*a;
        cout << ans << endl;
        return 0;
    }

    ans += b;
    cout << ans << endl;

    return 0;
}
