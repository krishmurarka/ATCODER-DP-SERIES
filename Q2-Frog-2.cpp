/******************************
     AUTHOR KRISH MURARKA
*******************************/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
ll  frog(int n,vector<ll> &v,int index,vector<ll>& dp,int k)
{
  if(index>=n-1)return dp[index]=0;  // Base Case
  

  if(dp[index]!=-1)return dp[index];  // Memorisation
  
    ll ans=INT_MAX;
   for(int i=index+1;i<=min(index+k,n-1);i++)           // since we only need to move to n-1 as after that jump we will reach our destination
   { 
         ans=min(ans,abs(v[index]-v[i])+frog(n,v,i,dp,k));  // calcultating the minimum among all K possible steps
   }
  return dp[index]=ans;
}
void solving()
{
  // Taking INPUT
      int n,k;
      cin>>n>>k;
      vector<ll> a(n);
      vector<ll> dp(n+5);
      // Initaialising DP array -1
      rep(i,0,n+2)dp[i]=-1;
      for(int i=0;i<n;i++)
        cin>>a[i];
      // caling the frog fucntion 
      cout<<frog(n,a,0,dp,k);
}
int main()
{
    fast;
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {  
      solving();
    }
    return 0;
}

