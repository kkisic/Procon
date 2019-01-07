//Mat[0] : 第0行ベクトル
typedef vector<int> Vec;
typedef vector<Vec> Mat;

Mat multi(Mat a, Mat b){
    Mat c(a.size(), Vec(b[0].size()));

    for(int i = 0; i < (int)a.size(); i++){
        for(int j = 0; j < (int)b[0].size(); j++){
            for(int k = 0; k < (int)b.size(); k++){
                c[i][j] = (c[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
            }
        }
    }
    return c;
}

Vec multi(Mat a, Vec b){
    Vec c(a.size());

    for(int i = 0; i < (int)a.size(); i++){
        for(int j = 0; j < (int)b.size(); j++){
            c[i] = (c[i] + a[i][j] * b[j] % MOD) % MOD;
        }
    }
    return c;
}

Mat powMat(Mat a, int n){
    Mat b(a.size(), Vec(a[0].size()));;
    for(int i = 0; i < (int)a.size(); i++){
        for(int j = 0; j < (int)a[0].size(); j++){
            if(i == j){
                b[i][j] = 1;
            }
        }
    }

    while(n != 0){
        if(n % 2 == 1){
            b = multi(b, a);
        }

        n /= 2;
        a = multi(a, a);
    }
    return b;
}

//int型で2値ベクトルを表現してる場合の掃き出し法
//a: 行列, k: 次元数
vector<int> gaussian_bit(vector<int> a, int k){
    int n = a.size();
    set<int> as;

    for(int i = 0; i < k; i++){
        int axis = -1;
        for(int j = 0; j < n; j++){
            if((a[j] >> i) % 2 == 1 && as.find(j) == as.end()){
                axis = j;
                as.insert(j);
                break;
            }
        }

        if(axis == -1){
            continue;
        }

        for(int j = 0; j < n; j++){
            if(j == axis){
                continue;
            }
            if((a[j] >> i) % 2 == 1){
                a[j] ^= a[axis];
            }
        }
    }
    sort(a.begin(), a.end());

    return a;
}
