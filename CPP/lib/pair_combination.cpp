class PairCombination{
    private:
        int n;
        vector<bool> used;
        vector<P> tmp;
        vector<vector<P>> pairs;

        void make(int p){
            if((int)tmp.size() == n / 2){
                pairs.push_back(tmp);
                return;
            }

            if(used[p]){
                return;
            }
            used[p] = true;

            for(int i = p+1; i < n; i++){
                if(used[i]){
                    continue;
                }
                used[i] = true;
                tmp.emplace_back(p, i);
                int next;
                for(next = 0; next < n; next++){
                    if(not used[next]){
                        break;
                    }
                }
                make(next);
                used[i] = false;
                tmp.pop_back();
            }
            used[p] = false;
        }

    public:
        PairCombination(int n)
            :n(n), used(n, false){
                if(n % 2 == 0){
                    make(0, 0);
                }else{
                    used[0] = true;
                    make(1);
                    used[0] = false;
                    for(int i = 1; i < n; i++){
                        used[i] = true;
                        make(0);
                        used[i] = false;
                    }
                }
            }

        vector<vector<P>> get_pairs(){
            return pairs;
        }
};
