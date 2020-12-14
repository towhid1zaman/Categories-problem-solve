#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define endl "\n"
const int maxn = 200005;
const int mod = 1000000007;


struct disjoint{
        int fa[maxn];
        void Build(int n){
            for(int i = 0; i<=n; i++) fa[i]=i;
        }
        int Find(int x){ 
            return x==fa[x]?x:fa[x]=Find(fa[x]);
        }
        void Union(int a, int b){ 
            fa[Find(a)]=Find(b);
        }
}dsu;

void task(){
        int n, m; cin >> n >> m;
        dsu.Build(n);
        int cnt = 0;
        std::vector<bool>vis(n,0);
        for(int i = 1; i<=n; i++){
            int k; cin >> k;
            if(!k){
                cnt++;
                continue;
            }
            int p; cin >> p;
            vis[p] = 1;
            for(int j = 2; j<=k; j++){
                int a; cin >> a;
                vis[a] = 1;
                dsu.Union(a,p);
            }

        }

        set<int>st;

        for(int i = 1; i<=m; i++){
            if(vis[i]){
                int p = dsu.Find(i);
                st.insert(p);
            }
        }

        if(st.size()) cnt+=st.size() - 1;

        cout << cnt << endl;
}

int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
#ifdef OJ
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif

        int T = 1; //cin >> T;
        for(int __ = 1; __ <= T; __++){
            //cout <<"Case "<<__<<": ";
            task();
        }
      
return 0;
}
