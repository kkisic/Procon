template<typename T>
class ConvexHullTrick{
    typedef pair<T, T> PT;
    private:
        //傾き降順
        deque<PT> lines;
        //getするxが単調か
        bool isMonotonicX;
        //最小
        function<bool(T, T)> comp;

    public:
        ConvexHullTrick(bool x = true, function<bool(T, T)> f = [](T l, T r) {return l >= r;})
            : isMonotonicX(x), comp(f) {}

        //no need : true
        bool check(PT l1, PT l2, PT l3){
            if(l1 < l3){
                swap(l1, l3);
            }
            return (l2.second - l1.second) * (l2.first - l3.first) >= (l1.first - l2.first) * (l3.second - l2.second);
        }

        void add(T a, T b){
            PT line = {a, b};
            while(lines.size() >= 2 && check(*(lines.end() - 2), lines.back(), line)){
                lines.pop_back();
            }
            lines.push_back(line);
        }

        T func(int id, T x){
            return lines[id].first * x + lines[id].second;
        }

        T get(T x){
            if(isMonotonicX){
                while(lines.size() >= 2 && comp(func(0, x), func(1, x))){
                    lines.pop_front();
                }
                return func(0, x);
            }

            int lo = -1;
            int hi = lines.size() - 1;
            while(hi - lo > 1){
                int mid = (hi + lo) / 2;
                if(comp(func(mid, x), func(mid+1, x))){
                    lo = mid;
                }else{
                    hi = mid;
                }
            }
            return func(hi, x);
        }
};
