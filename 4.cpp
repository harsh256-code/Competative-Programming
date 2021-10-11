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
const int N=1e4;
vector<int>primes;
vector<bool>p(N,true);
void sieve(){
	for(int i=2;i*i<=N;i++){
		if(p[i]){
			for(int j=i*i;j<N;j+=i){
				p[j]=false;
			}
		}
	}
	for(int i=2;i<N;i++){
		if(p[i]){
			primes.pb(i);
		}
	}
}
int factor(int n){
	int c=0;
	for(auto i:primes){
		if(n<i) break;
		while(n%i==0){
			n/=i;
			c++;
		}
	}
	if(n>1)c++;
	return c;
}
void solve(){
	int a,b,k;
	cin>>a>>b>>k;
	if(k>60){
		cout<<"NO";
		return;
	}
	int minops=0;
	if(a==b) minops=2;
	else if(a%b==0 or b%a==0) minops=1;
	else minops=2;
	int g=__gcd(a,b);
	a=a/g;
	b=b/g;
	int maxops=0;
	maxops+=factor(a);
	maxops+=factor(b);
	maxops+=factor(g)*2;
	if(k>=minops and k<=maxops)cout<<"YES";
	else cout<<"NO";
	





	
}
int main()
{
	sieve();
	ll t;
	cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
	return 0;
}