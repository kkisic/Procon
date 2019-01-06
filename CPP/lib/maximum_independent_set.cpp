int mis(const vector<vector<int>>& edge){
    int n = edge.size();
    int half = n / 2;

    //V1の部分集合sが独立か
    vector<bool> okV1(1LL << half, true);
    for(int i = 0; i < half; i++){
        for(int v : edge[i]){
            if(v >= half) continue;
            okV1[(1LL << i) | (1LL << v)] = false;
        }
    }

    for(int s = 0; s < (1LL << half); s++){
        if(okV1[s]) continue;
        for(int u = 0; u < half; u++){
            if((s >> u) % 2 == 1) continue;
            okV1[s|(1LL << u)] = false;
        }
    }

    //V2の部分集合Sが独立か
    vector<bool> okV2(1LL << (n - half), true);
    for(int i = half; i < n; i++){
        for(int v : edge[i]){
            if(v < half) continue;
            okV2[(1LL << (i - half)) | (1LL << (v - half))] = false;
        }
    }

    for(int s = 0; s < (1LL << (n - half)); s++){
        if(okV2[s]) continue;
        for(int u = 0; u < n - half; u++){
            if((s >> u) % 2 == 1) continue;
            okV2[s|(1LL << u)] = false;
        }
    }

    //V1の部分集合Sと繋がっていないV2の頂点集合
    vector<int> set(1LL << half, -1);
    set[0] = (1LL << (n - half)) - 1;
    for(int i = 0; i < half; i++){
        int mask = 0LL;
        for(int v : edge[i]){
            if(v < half) continue;
            mask |= (1LL << (v - half));
        }
        set[1LL << i] = set[0] & ~mask;
    }

    for(int s = 1; s < (1LL << half); s++){
        if(set[s] == -1) continue;
        for(int v = 0; v < half; v++){
            if((s >> v) % 2 == 1) continue;
            set[s|(1LL << v)] = set[s] & set[1LL << v];
        }
    }

    //V2の部分集合Sにおける最大独立点集合の大きさ
    vector<int> dp(1LL << (n - half));
    for(int s = 0; s < (1LL << (n - half)); s++){
        if(not okV2[s]) continue;
        dp[s] = bitset<20>(s).count();
    }

    for(int s = 0; s < (1LL << (n - half)); s++){
        for(int v = 0; v < n - half; v++){
            if((s >> v) % 2 == 1) continue;
            dp[s|(1LL << v)] = max(dp[s], dp[s|(1LL << v)]);
        }
    }

    int ans = 0;
    for(int s = 0; s < (1LL << half); s++){
        if(not okV1[s]) continue;
        ans = max(ans, (int)bitset<20>(s).count() + dp[set[s]]);
    }

    return ans;
}
