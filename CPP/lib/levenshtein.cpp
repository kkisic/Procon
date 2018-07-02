int levenshtein(string s, string t){
    int lenS = s.length();
    int lenT = t.length();
    vector<vector<int>> dp(lenS+1, vector<int>(lenT+1));
    rep(i, lenS+1){
        dp[i][0] = i;
    }
    rep(i, lenT+1){
        dp[0][i] = i;
    }

    rep(i, lenS){
        rep(j, lenT){
            dp[i+1][j+1] = min(dp[i+1][j]+1, dp[i][j+1]+1);
            int c = s[i] == t[j] ? 0 : 1;
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + c);
        }
    }

    return dp[lenS][lenT];
}
