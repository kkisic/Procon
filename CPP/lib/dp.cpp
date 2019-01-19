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

//Longest Increasing Subsequence
//a:[begin, end), low <= a[i] <= high
int lis(const vector<int>& a, int begin, int end, int low, int high){
    int n = end - begin;
    vector<int> dp(n+1, INF);
    dp[0] = 0;
    int i = 0;
    for(int j = begin; j < end; j++){
        if(a[begin+i] > high || a[begin+i] < low){
            i++;
            continue;
        }
        int l = 0;
        int r = n;
        while(r - l > 1){
            int m = (r + l) / 2;
            if(dp[m] < a[begin+i]){
                l = m;
            }else{
                r = m;
            }
        }
        dp[l+1] = a[begin+i];
        i++;
    }
    int ans = 0;
    for(int i = 0; i <= n; i++){
        if(dp[i] != INF){
            ans = i;
        }
    }
    return ans;
}

//Longest Common Subsequence
string lcs(string s, string t){
    vector<vector<int>> dp((int)s.size() + 1, vector<int>((int)t.size() + 1));
    for(int i = 0; i <= (int)s.size();; i++){
        for(int j = 0; j <= (int)t.size(); j++){
            if(i + 1 <= (int)s.size()){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            }
            if(j + 1 <= (int)t.size()){
                dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
            }
            if(i + 1 <= (int)s.size() && j + 1 <= (int)t.size()){
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + (s[i] == t[j]));
            }
        }
    }

    int x = (int)s.size();
    int y = (int)t.size();
    string ans;
    while(x > 0 && y > 0){
        if(s[x-1] == t[y-1]){
            ans.push_back(s[x-1]);
            x--;
            y--;
            continue;
        }
        if(dp[x][y] == dp[x-1][y]){
            x--;
            continue;
        }
        y--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


//Traveling Salesman Problem
//頂点番号: 0-Indexed(0 <= i < v)
int tsp(int v, const vector<vector<int>>& edge){
    vector<vector<int>> cost(1 << v, vector<int>(v, INF));
    //始点は0
    cost[1][0] = 0;
    for(int s = 0; s < (1 << v); s++){
        for(int i = 0; i < v; i++){
            if(s != 0 && (s >> i) % 2 == 0){
                continue;
            }
            for(int j = 0; j < v; j++){
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
    for(int i = 0; i < v){
        if(ans > cost[(1 << v) - 1][i] + edge[i][0]){
            ans = cost[(1 << v) - 1][i] + edge[i][0];
        }
    }
    //解なしの場合INF
    return ans;
}

//bitDP等での部分集合全列挙
for(int t = s; t != 0; t = (t - 1) & s){
    //処理
}
