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
// vector<int> findSimilar(vector<string>vec){
// 	int n=vec.size();
// 	map<string,int>mpp;
// 	for(auto it:vec){
// 		mpp[it]++;
// 	}
// 	vector<int>ans(n,0);
// 	for(int i=0;i<n;i++){
// 		if(mpp[vec[i]]!=0){
// 			ans[i]+=mpp[vec[i]]-1;
// 		}

// 		for(int j=0;j<vec[i].size();j++){
// 			if(vec[i][j]=='0')vec[i][j]='1';
// 			else vec[i][j]='0';

// 			if(mpp[vec[i][j]]){
// 				ans[i]+=mpp[vec[i][j]];
// 			}
// 			if(vec[i][j]=='0')vec[i][j]='1';
// 			else vec[i][j]='0';
// 		}
// 	}
// 	return ans;
// }
// int expand(string s,int i,int j){
// 	int c=0;
// 	int n=s.size();
// 	if(i==j){
// 		c++;
// 		i--;
// 		j++;
// 	}
// 	while(i>=0 and j<n and s[i]==s[j]){
// 		c+=2;
// 		i--;
// 		j++;
// 	}
// 	return c;
// }
// int getLongestString(string s){
// 	int n=s.size();
// 	int maxi=0;
// 	for(int i=0;i<n;i++){
// 		int len=expand(s,i,i);
// 		maxi=max(maxi,len);
// 		if(i<n-1){
// 			len=expand(s,i,i+1);
// 		}
// 		maxi=max(maxi,len);
// 	}
// 	return maxi;
// }
// ll min_distance(vector<ll>&a,ll n,vector<ll>&dp){
// 	if(dp[n]!=-1)return dp[n];
// 	if(n==1){
// 		return dp[n]=abs(a[n]-a[n-1]);
// 	}
// 	if(n==0){
// 		return dp[n]=0;
// 	}
// 	return dp[n]=min(min_distance(a,n-1,dp)+abs(a[n]-a[n-1]),min_distance(a,n-2,dp)+abs(a[n]-a[n-2]));
// }

// ll find_min_steps(vector<ll>&a,ll n,ll k,vector<ll>&dp){
// 	if(dp[n]!=-1)return dp[n];
// 	if(n==0)return dp[n]= 0;
// 	ll ans=1e9;
// 	for(ll i=1;i<=k;i++){
// 		if(n-i>=0){
// 			ans=min(ans,find_min_steps(a,n-i,k,dp)+abs(a[n]-a[n-i]));
// 		}
// 	}
// 	return dp[n]=ans;
// }
// ll knapsack(vector<ll>&weight,vector<ll>&value,ll n,ll w,vector<vector<ll>>&dp){
// 	if(dp[n][w]!=-1)return dp[n][w];
// 	if(w==0 or n==0)return dp[n][w]=0; 
// 	if(weight[n-1]>w){
// 		return dp[n][w]=knapsack(weight,value,n-1,w,dp);
// 	}
// 	return dp[n][w]=max(value[n-1]+knapsack(weight,value,n-1,w-weight[n-1],dp),knapsack(weight,value,n-1,w,dp));

// }

// ll LCS(string &s,string &t,ll n,ll m){
// 	if(n==0 or m==0)return 0;
// 	if(s[n-1]==t[m-1]){
// 		return 1+LCS(s,t,n-1,m-1);
// 	}
// 	return max(LCS(s,t,n-1,m),LCS(s,t,n,m-1));
// }
// vector<vector<ll>>G;
// vector<ll>dp;
// ll longest_path(ll node){
// 	if(dp[node]!=-1)return dp[node];
// 	ll best=0;
// 	for(auto child:G[node]){
// 		best=max(best,1+longest_path(child));
// 	}
// 	return dp[node]=best;
// }
vector<string>grid;
ll Grid1(ll n,ll m,vector<vector<ll>>&dp){
	
	if(n<0 or m<0)return 0;
	if(grid[n][m]=='#')return 0;
	if(n==0 and m==0)return dp[n][m]=1;
	if(dp[n][m]!=-1)return dp[n][m];
	return dp[n][m]= (Grid1(n-1,m,dp)%M+Grid1(n,m-1,dp)%M)%M;
}
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<ll>previous(m+1),current(m+1);
	for(ll i=1;i<=n;i++){
		string s;
		cin>>s;
		for(ll j=1;j<=m;j++){
			if(s[j-1]=='#')current[j]=0;
			else{
				if(i==1 and j==1)current[j]=1;
				else{
					current[j]=(previous[j]+current[j-1])%M;
				}
			}

			
		}
		previous=current;
	}
	cout<<current[m];


}





int main()
{
	FIO;
    solve();
    cout<<endl;		
	return 0;
	
}
		

