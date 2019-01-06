inline int extMOD(int a, int m){
    return (a % m + m) % m;
}

tuple<int, int, int> extGCD(int a, int b){
    if(b == 0){
        return make_tuple(a, 1, 0);
    }

    // b * xx + (a % b) * yy = g
    tuple<int, int, int> res = extGCD(b, a % b);
    int g = get<0>(res);
    int xx = get<1>(res);
    int yy = get<2>(res);

    // a = (a / b) * b + (a % b)
    // a * x + b * y = g
    // ((a / b) * b + (a % b)) * x + b * y = g
    // b * ((a / b) * x + y) + (a % b) * x = g
    // xx = (a / b) * x + y
    // yy = x
    int x = yy;
    int y = xx - (a / b) * x;
    return make_tuple(g, x, y);
}

pair<int, int> CRT(const vector<int>& b, const vector<int>& m){
    int r = 0;
    int M = 1;

    for(int i = 0; i < (int)b.size(); i++){
        //r * p + m[i] * q = d
        tuple<int, int, int> euc = extGCD(M, m[i]);
        int d = get<0>(euc);
        int p = get<1>(euc);

        if((b[i] - r) % d != 0){
            return make_pair(0, -1);
        }
        int tmp = M * ((b[i] - r) / d) * p;
        M *= m[i] / d;
        r = extMOD(r + tmp, M);
    }
    return make_pair(r, M);
}
