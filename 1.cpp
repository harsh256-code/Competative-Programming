#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define FIO ios_base::sync_with_stdio(false);   cin.tie(NULL);   cout.tie(NULL);
#define F first
#define S second
#define pb push_back
#define mp make_pair
using namespace std;
ll M = 1000000007;
ll fastpower(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1){
			res=((res%M)*(a%M))%M;
		}
		a=((a%M)*(a%M))%M;
		b=b>>1;
	}
	return res;
}
ll longestcommonsubstring(string a,string b,ll m,ll n){
    ll dp[m+1][n+1];
    ll lcs=0;
    for(ll i=0;i<=m;i++){
        for(ll j=0;j<=n;j++){
            if(i==0 or j==0){
                dp[i][j]=0;
            }
            else if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                lcs=max(lcs,dp[i][j]);
            }else dp[i][j]=0;
            

        }
    }
    return lcs;
}

bool isPrime(ll n){
	if(n==1){
		return false;
	}
	for(ll i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
bool ispalindrome(ll n){
	ll a=n,b,ans=0;
	while(n){
		b=n%10;
		ans=ans*10 +b;
		n=n/10;

	}
	if(ans==a){
		return true;

	}else{
		return false;
	}
}
ll finddivisor(ll n){
	for(ll i=3;i<n;i+=2){
		if(n%i==0){
			return i;
		}
	}
	return 1;
}
ll maxfact(ll g,ll n){
	ll maxf=0;
	for(ll i=n;i>=1;i--){
		if(g%i==0){
			if(i<=n){
				maxf=max(i,maxf);
			}
			if(g/i <=n){
				maxf=max(i,maxf);
			}
		}
	}
	return maxf;
}
ll setbitzero(ll n){
	if(n==0){
		return 1;
	}
	 ll c=0;
	while(n){
		if(0==(n&1)){
			c++;
		}
		n>>=1;
	}
	return c;
}
ll setbitone(ll n){
	if(n==0){
		return 0;
	}
	 ll c=0;
	while(n){
		if(n&1){
			c++;
		}
		n>>=1;
	}
	return c;
}
ll reversenumber(ll n){
	ll ans=0;
	while(n){
		ll a=n%10;
		ans=ans*10+a;
		n=n/10;

	}
	return ans;
}
void decimal_to_binary(ll n){
	vector<ll>v;
	while(n){
		v.pb(n%2);
		n=n/2;
	}
	reverse(v.begin(),v.end());
	for(auto i:v){
		cout<<i;
	}
}
int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
 
    int base = 1;
 
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}
int main()
{
	FIO;
	ll t;
	cin>>t;
	while (t--)
	{
		ll n;
		cin>>n;
	  	ll a[n];
	   	for(ll i=1;i<=n;i++){
		   cin>>a[i];
	   	}
		if(n&1){
			ll mid=(n/2)+1;
			if(a[mid] < a[mid-1] && a[mid] < a[mid+1]){
				a[mid]=max(a[mid-1],a[mid+1]);
			}
			if(a[mid] > a[mid-1] && a[mid] > a[mid+1]){
				a[mid]=max(a[mid-1],a[mid+1]);
			}
			else{
				for(ll i=1;i<=n;i++){
					if(a[mid] < a[mid-1] && a[mid] < a[mid+1]){
						a[mid]=max(a[mid-1],a[mid+1]){

					}
					}
					if(a[mid] > a[mid-1] && a[mid] > a[mid+1]){
						a[mid]=max(a[mid-1],a[mid+1]){

						}
					}
				}
			}
			
		}

		cout<<endl;
		
		 
	}


	
	return 0;
}