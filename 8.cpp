    #include <bits/stdc++.h>
    #include<stdio.h>
    #define ll long long int
    #define endl "\n"
    #define FIO ios_base::sync_with_stdio(false);   cin.tie(NULL);   cout.tie(NULL);
    #define F first
    #define S second
    #define pb push_back
    #define mp make_pair
    #define B begin()
    #define E end()
    ll M=1e9+7;
    ll N=1e5;
    using namespace std;
    struct cmp{
        bool operator()(const pair<ll,ll>&a,const pair<ll,ll>&b){
            if(a.F!=b.F)return a.F<b.F;
            else return a.S>b.S;
        }

    };
   
    ll computeXOR(ll n){
        if (n % 4 == 0)return n;
        if (n % 4 == 1)return 1;
        if (n % 4 == 2)return n + 1;
        return 0;
    }
    bool comp(ll a,ll b){
        return a%2>b%2;
    }
    void solve(){
        // ll a,b,c,m;
        // cin>>a>>b>>c>>m;
        // ll count=(a/2)+(b/2)+(c/2);
          // if(count>=m)cout<<"YES";
        // else cout<<"NO";
           
        


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
            
 