#include <bits/stdc++.h>
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
const ll N=1e7+2;
vector<bool>primes(N,true);
vector<ll>prefix(N);
void sieve(){
    primes[0]=primes[1]=0;
    ll i,j;
    for(i=2;i*i<N;i++){
        if(primes[i]){
            for(j=i*i;j<=N;j+=i){
                primes[j]=false;
            }
        }
    }
}
void prefixc(){
    ll i,c=0;
    for(i=1;i<=N;i++){
        if(primes[i]){
            c++;
        }
        prefix[i]=c;

    }
}
void solve(){
    ll n;
    cin>>n;
    if(n==2){
        cout<<1;
    }else if(n==3){
        cout<<2;
    }else{
        ll ans=prefix[n]-prefix[n/2];
        cout<<ans+1;
    }

    

}
int main()
{
	FIO;
    sieve();
    prefixc();
    ll t;
	cin>>t;
	while (t--)
	{
		solve();
        cout<<endl;
	
	}
		
		
		
	

}	


