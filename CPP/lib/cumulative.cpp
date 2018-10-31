//a[s][t] = 0 <= i < s, 0 <= j < t

template <typename T>
class Cumulative{
    public:
        int h, w;
        vector<vector<T>> c, a;

        Cumulative(const vector<vector<T>>& c, int h, int w)
            : h(h), w(w), c(c), a(h+1, vector<T>(w+1)) {
                for(int i = 1; i <= h; i++){
                    for(int j = 1; j <= w; j++){
                        a[i][j] += c[i-1][j-1] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
                    }
                }
            }

        T query(int i, int j, int k, int l){
            return a[k][l] - a[k][j] - a[i][l] + a[i][j];
        }
};
