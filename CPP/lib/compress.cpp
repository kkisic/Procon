pair<map<int, int>, vector<int>> compress(const vector<int>& a){
    vector<int> b(a);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    map<int, int> zip;
    rep(i, (int)b.size()){
        zip[b[i]] = i;
    }
    return {zip, b};
}
