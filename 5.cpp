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
string printlcs(string s1,string s2){
    ll a=s1.length(),b=s2.length();
    ll dp[a+1][b+1];
    string ans="";
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            if(i==0 or j==0){
                dp[i][j]=0;
            }else if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                //ans+=s1[i-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    ll i=a,j=b;
    ll index=dp[a][b];
    while(i>0 and j>0){
        if(s1[i-1]==s2[j-1]){
            ans+=s1[i-1];
            j--;
            i--;
        }else if(dp[i][j-1]>dp[i-1][j]){
            j--;
        }else i--;
    }
    reverse(ans.B,ans.E);
    return ans;
    
}
string printlrs(string s1){
    ll n=s1.length();
    string ans="";
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0 or j==0){
                dp[i][j]=0;
            }else if(s1[i-1]==s1[j-1] and i!=j){
                dp[i][j]=1+dp[i-1][j-1];
                //ans+=s1[i-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
        ll i=n,j=n;
        while(i>0 and j>0){
            if(dp[i][j]==dp[i-1][j-1]+1){
                ans+=s1[i-1];
                j--;
                i--;
            }else if(dp[i][j]==dp[i-1][j]){
                i--;
            }else j--;
        }
        reverse(ans.B,ans.E);
    return ans;
    
}
void printsubsequence(string input,string output){
    if(input.empty()){
        cout<<output<<endl;
        return;
    }
    printsubsequence(input.substr(1),output+input[0]);
    printsubsequence(input.substr(1),output);
}
void solve(){
    string s1,s2="";
    cin>>s1;
    printsubsequence(s1,s2);
    
    
    

    


    



    
}
int main()
{
	FIO;
    solve();
	// ll t;
	// cin>>t;
	// while(t--){
    //     solve();
    //     cout<<endl;
    // }		
	return 0;
	
}
		

