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
    const ll MAXN=1e5+5;
    ll power(ll a,ll b){
        if(b==0)return 1;
        ll x=power(a,b/2);
        if(b&1){
            return x*x*a;
        }
        
        return x*x;
    }
    void solve(){
        ll n;
        char c;
        cin>>n>>c;
        string s;
        cin>>s;
        ll cc=count(s.B,s.E,c);
        if(cc==n){
            cout<<0;
            return;
        }
        bool f=0;
        for(ll i=1;i<=n;i++){
            f=0;
            for(ll j=i;j<=n;j++){
                if(s[j-1]!=c)f=1;
                j+=i-1;
            }
            if(f==0){
                cout<<1<<endl;
                cout<<i+1;
                return;
            }

        }
        cout<<2<<endl;
        cout<<n-1<<" "<<n;
       
        // cin>>n>>x;
        // vector<ll>a(n);
        // vector<ll>temp(n);
        // for(ll i=0;i<n;i++){
        //     cin>>a[i];
        // }
        
        
// 1 2   3  4 5
// 13 11 4 2

//-5 -4 -3 -2 -1 0 1 2 3 4 5 6








    }





    int main()
    {
        FIO;
        ll t;
        cin>>t;
        while(t--){
            solve();
            cout<<endl;	
        }	
        return 0;
        
    }
            

