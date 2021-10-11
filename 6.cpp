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

ll power(ll a,ll b){
    if(b==0)return 1;
    ll x=power(a,b/2);
    if(b&1){
        return ((x%M)*(x%M)*(a%M))%M;
    }
    return ((x%M)*(x%M))%M;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>adj[n+1];
    for(ll i=1;i<=m;i++){
        ll a,b,w;
        cin>>a>>b>>w;
        adj[a].pb({b,w});
        adj[b].pb({a,w});
    }
    vector<ll>dis(n+1,INT_MAX);
    vector<ll>par(n+1,-1);
    par[1]=0;
    dis[1]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        ll d=pq.top().first;
        ll node=pq.top().second;
        pq.pop();
        for(auto i:adj[node]){
            ll wt=i.second;
            ll adjnode=i.first;
            if(wt+d<dis[adjnode]){
                dis[adjnode]=wt+d;
                par[adjnode]=node;
                pq.push({wt+d,adjnode});
            }
        }
    }
    //for(auto i:dis)cout<<i<<" ";
    vector<ll>ans;
    ans.push_back(n);
    ll f=n;
    while(par[f]!=1){
        f=par[f];
        if(f==-1){
            cout<<-1;
            return;
        }
        ans.push_back(f);
    }
    reverse(ans.B,ans.E);
    cout<<1<<" ";
    for(auto i:ans)cout<<i<<" ";
    

    








}





int main()
{
	FIO;
        solve();
        cout<<endl;	
    	
	return 0;
	
}
		

