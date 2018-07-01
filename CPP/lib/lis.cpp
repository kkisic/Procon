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
