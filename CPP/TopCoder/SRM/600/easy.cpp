#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <iomanip>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e13;

class ORSolitaire{
    public:
        int getMinimum(vector<int> numbers, int goal){
            vector<bool> a(30, false);
            vector<int> b(30);

            int n = goal;
            for(int i = 0; i < 30; i++){
                if(n % 2 == 1){
                    a[i] = true;
                }
                n /= 2;;
            }

            for(signed i = 0; i < numbers.size(); i++){
                int m = numbers[i];
                if((m | goal) != goal){
                    continue;
                }
                rep(j, 30){
                    if(m % 2 == 1 && a[j]){
                        b[j]++;
                    }
                    m /= 2;;
                }
            }

            int ans = INF;
            for(int i = 0; i < 30; i++){
                if(ans > b[i] && a[i]){
                    ans = b[i];
                }
            }
            return ans;
        }
};

signed main(){
    return 0;
}
