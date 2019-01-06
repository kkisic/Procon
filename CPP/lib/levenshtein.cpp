int levenshtein(string s, string t){
    int lenS = s.length();
    int lenT = t.length();
    vector<vector<int>> dp(lenS+1, vector<int>(lenT+1));
    for(int i = 0; i <= lenS; i++){
        dp[i][0] = i;
    }
    for(int i = 0; i <= lenT; i++){
        dp[0][i] = i;
    }

    for(int i = 0; i < lenS; i++){
        for(int j = 0; j < lenT; j++){
            dp[i+1][j+1] = min(dp[i+1][j]+1, dp[i][j+1]+1);
            int c = s[i] == t[j] ? 0 : 1;
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + c);
        }
    }

    return dp[lenS][lenT];
}
