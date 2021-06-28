template <class T>
struct knapsack{
    /*
    knansack<ll>knap;
    knap.c = w;
    knap.add_item(weight, value);
    ans = knap.solve();
    */
    T c; 
    struct item{
        T p, w; 
    };
    std::vector<item> is;
    void add_item(T p, T w) {
        is.push_back({p, w});
    }
    T det(T a, T b, T c, T d) {
        return a * d - b * c;
    }
    T z;
    void go(T p, T w, int s, int t){
        if (w <= c){
          if (p >= z) z = p;
          for (; t < is.size(); ++t) {
            if (det(p - z - 1, w - c, is[t].p, is[t].w) < 0) return;
            go(p + is[t].p, w + is[t].w, s, t + 1);
        }
    }
    else {
        for (; s >= 0; --s) {
            if (det(p - z - 1, w - c, is[s].p, is[s].w) < 0) return;
            go(p - is[s].p, w - is[s].w, s - 1, t);
          }
        }
    }

    T solve(){
        sort(all(is), [](const item &a, const item &b) { 
            return a.p * b.w > a.w * b.p;
        });
        T p = 0, w = 0;
        z = 0;
        int b = 0; 
        for (; b < is.size() && w <= c; ++b) {
            p += is[b].p;
            w += is[b].w;
        }
        go(p, w, b-1, b);
        return z;
    }
};
