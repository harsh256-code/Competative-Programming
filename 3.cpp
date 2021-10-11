#include <bits/stdc++.h>
#include<string.h>
#define ll long long int
#define lld long double
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
void dfs(int node,vector<ll>adj[],vector<ll> &vis,vector<ll> &ans){
	ans.pb(node);
	vis[node]=1;
	for(auto it:adj[node]){
		if(!vis[it]){
			dfs(it,adj,vis,ans);
		}
	}
}
vector<ll>dfsGraph(int V,vector<ll>adj[]){
	vector<ll>ans;
	vector<ll>vis(V+1,0);
	for(ll i=1;i<=V;i++){
		if(!vis[i]){
			dfs(i,adj,vis,ans);
		}
	}
	return ans;
}
void solve(){
    ll e,n,k;
    cin>>n>>e;
	vector<ll>g[n+1];
    for(ll i=1;i<=e;i++){
		ll u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<ll>ans=dfsGraph(n,g);
	for(auto i:ans) cout<<i<<" ";
	
	// vector<ll>visited(n+1,0);
	// vector<ll>bfs;
	// for(ll i=1;i<=n;i++){
	// 	if(!visited[i]){
	// 		queue<ll>q;
	// 		q.push(i);
	// 		visited[i]=1;
	// 		while(!q.empty()){
	// 			ll f=q.front();
	// 			bfs.pb(f);
	// 			q.pop();
	// 			for(auto j:g[f]){
	// 				if(!visited[j]){
	// 					visited[j]=1;
	// 					q.push(j);
	// 				}
	// 			}
	// 		}
			
	// 	}
		
	// }
	
    


    
    
}
int main()
{
	FIO;
    ll t;
	cin>>t;
	while (t--)
	{
		solve();
        cout<<endl;
	
	}
  
		
		
		
	

}	


