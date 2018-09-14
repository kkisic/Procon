int n, k;
string s;
vector<int> rank_sa;

bool compare_sa(int i, int j){
    if(rank_sa[i] != rank_sa[j]){
        return rank_sa[i] < rank_sa[j];
    }

    int ri = i + k <= n ? rank_sa[i + k] : -1;
    int rj = j + k <= n ? rank_sa[j + k] : -1;
    return ri < rj;
}

void construct(string s, vector<int>& sa){
    n = s.length();
    rank_sa = vector<int>(n+1);
    vector<int> tmp = vector<int>(n+1);

    rep(i, n+1){
        sa[i] = i;
        rank_sa[i] = i < n ? s[i] : -1;
    }

    for(k = 1; k <= n; k *= 2){
        sort(sa.begin(), sa.end(), compare_sa);

        tmp[sa[0]] = 0;
        for(int i = 1; i <= n; i++){
            tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1], sa[i]) ? 1 : 0);
        }
        rep(i, n+1){
            rank_sa[i] = tmp[i];
        }
    }
}
