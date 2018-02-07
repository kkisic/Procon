#include <iostream>

using namespace std;

int main(){
    long long int a, k, ans;
    cin >> a >> k;

    if (k == 0){
        ans = 2000000000000 - a;
    }else{
        while(a < 2000000000000){
            ans++;
            a = a * (k+1) + 1;
        }
    }
    cout << ans << endl;

    return 0;
}
