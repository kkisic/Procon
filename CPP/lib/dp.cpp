//Longest Increasing Subsequence
int lis(const vector<int>& a){
    int n = a.size();
    vector<int> dp(n+1, INF);
    dp[1] = a[0];
    for(int i = 1; i < n; i++){
        int l = 0;
        int r = n;
        while(r - l > 1){
            int m = (r + l) / 2;
            if(dp[m] < a[i]){
                l = m;
            }else{
                r = m;
            }
        }
        dp[l+1] = a[i];
    }
    int ans;
    for(int i = 1; i <= n; i++){
        if(dp[i] != INF){
            ans = i;
        }
    }
    return ans;
}


//Traveling Salesman Problem
//頂点番号: 0-Indexed(0 <= i < v)
int tsp(int v, const vector<vector<int>>& edge){
    vector<vector<int>> cost(1 << v, vector<int>(v, INF));
    //始点は0
    cost[1][0] = 0;
    for(int s = 0; s < (1 << v); s++){
        rep(i, v){
            if(s != 0 && (s >> i) % 2 == 0){
                continue;
            }
            rep(j, v){
                if((s >> j) % 2 == 1 || edge[i][j] == INF){
                    continue;
                }
                if(cost[s | (1 << j)][j] > cost[s][i] + edge[i][j]){
                    cost[s | (1 << j)][j] = cost[s][i] + edge[i][j];
                }
            }
        }
    }

    int ans = INF;
    rep(i, v){
        if(ans > cost[(1 << v) - 1][i] + edge[i][0]){
            ans = cost[(1 << v) - 1][i] + edge[i][0];
        }
    }
    //解なしの場合INF
    return ans;
}
