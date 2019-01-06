class RollingHash{
    private:
        const static int mod1 = 999999937LL;
        const static int mod2 = 1000000007LL;
        const static int base = 9973;

    public:
        int n;
        string s;
        vector<int> hash1, hash2, pow1, pow2;

        RollingHash(string s)
            :n(s.length()), s(s), hash1(n+1), hash2(n+1), pow1(n+1, 1), pow2(n+1, 1){
                for(int i = 0; i < n; i++){
                    hash1[i+1] = (hash1[i] + s[i]) * base % mod1;
                    hash2[i+1] = (hash2[i] + s[i]) * base % mod2;
                    pow1[i+1] = pow1[i] * base % mod1;
                    pow2[i+1] = pow2[i] * base % mod2;
                }

            }

        //[l, r)
        P hash(int l, int r){
            int t1 = ((hash1[r] - hash1[l] * pow1[r-l]) % mod1 + mod1) % mod1;
            int t2 = ((hash2[r] - hash2[l] * pow2[r-l]) % mod2 + mod2) % mod2;
            return make_pair(t1, t2);
        }

        bool compare(int l1, int r1, int l2, int r2){
            return hash(l1, r1) == hash(l2, r2);
        }
};

