#include <bits/stdc++.h>
    #define ll long long int
    #define endl "\n"
    #define FIO ios_base::sync_with_stdio(false);   cin.tie(NULL);   cout.tie(NULL);
    #define F first
    #define S second
    #define pb push_back
    #define mp make_pair
    #define B begin()
    #define E end()
    using namespace std;
    ll M = 1000000007;
    const int N=1e5+5;
    class DSU{
        private:
        vector<int>parent,size;
        public: DSU(int n){
            for(int i=0;i<=n;i++){
                parent.push_back(i);
                size.push_back(1);
            }
        }
        public:int find_par(int node){
            if(parent[node]==node)return node;
            return parent[node]=find_par(parent[node]);
        }
        public:void union_size(int u,int v){
            int pu=find_par(u);
            int pv=find_par(v);
            if(size[pu]<size[pv]){
                parent[pu]=parent[pv];
                size[pv]+=size[pu];
            }else{
                parent[pv]=parent[pu];
                size[pu]+=size[pv];
            }
        }
    };
    struct node{
        int u,v,wt;
        node(int _u,int _v,int _wt){
            u=_u;
            v=_v;
            wt=_wt;
        }

    };
    int comp(node first,node second){
        if(first.wt<second.wt)return true;
        return false;
    }
    
    int minimum_spanning_tree(int n,vector<node>&edges){
        int c=0;
        DSU dsu(n);
        sort(edges.B,edges.E,comp);
        for(auto i:edges){
            int u=i.u;
            int v=i.v;
            int wt=i.wt;
            if(dsu.find_par(u)!=dsu.find_par(v)){
                dsu.union_size(u,v);
                c+=wt;
            }
        }
        return c;
    }
    // vector<int>vis(N,0),low(N),time(N);
    // int timer=0;
    // void bridges_in_graph(int node,int par){
    //     vis[node]=1;
    //     low[node]=time[node]=timer++;
    //     for(auto i:adj[node]){
    //         if(!vis[i]){
    //             dfs(i,node);
    //             low[node]=min(low[node],low[i]);
    //             if(low[i]>time[node]){
    //                 cout<<i<<" "<<node<<endl;
    //             }else{
    //                 low[node]=min(low[node],low[i]);
    //             }
    //         }
    //     }

    // } 
    int main(){
        int n,m;
        cin>>n>>m;
        vector<node>edges;
        for(int i=1;i<=m;i++){
            int u,v,wt;
            cin>>u>>v>>wt;
            edges.push_back(node(u,v,wt));
        }
        cout<<minimum_spanning_tree(n,edges);

        return 0;
    }



