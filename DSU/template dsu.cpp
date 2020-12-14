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
