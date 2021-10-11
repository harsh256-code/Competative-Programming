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

    class DSU{
        private:
        vector<int>size,parent;
        public:
        DSU(int n){
            for(int i=0;i<=n;i++){
                parent.pb(i);
                size.pb(1);
            }
        }
        

       public:int find_par(int node){
            if(parent[node]==node){
                return node;
            }
            return parent[node]=find_par(parent[node]);
        }
        public:
        void unionsize(int u,int v){
            int pu=find_par(u);
            int pv=find_par(v);
            if(pu==pv)return;
            if(size[pu]<size[pv]){
                parent[pu]=pv;
                size[pv]+=size[pu];
            }else{
                parent[pv]=parent[pu];
                size[pu]+=size[pv];
            }
        }
        
    };
    map<string,int>m;
    int c=0;
    int get_string(string s){
        if(m.find(s)==m.end())m[s]=c++;
        return m[s];
    }
    int main(){
        int n;
        cin>>n;
        DSU dsu(n);
        while(n--){
            string u,v;
            cin>>u>>v;
            if(dsu.find_par(get_string(u))==dsu.find_par(get_string(v))){
                cout<<"Found in friend list";
            }else{
                dsu.unionsize(get_string(u),get_string(v));
                cout<<"Found by random";
            }
            cout<<endl;
        }
        return 0;
    }