/******************************
     AUTHOR KRISH MURARKA
*******************************/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,a,b)        for(int i=a;i<b;i++)

ll  frog(int n,vector<ll> &v,int index,vector<ll>& dp)
{
  if(index>=n-1)return dp[index]=0;
  
  
  ll x=INT_MAX,y=INT_MAX;
  
  
  if(dp[index]!=-1)return dp[index];  //Memorisation
  
  
   if(index+1<n)
   {
      x=abs(v[index]-v[index+1])+frog(n,v,index+1,dp);   // Trying to jump 1 step ahead
   }
   if(index+2<n)
   {
      y=abs(v[index]-v[index+2])+frog(n,v,index+2,dp);   // trying to jump 2 steps ahead
   }
  return dp[index]=min(x,y);                    // making the minimum of both
}
void solving()
{
      int n;
      cin>>n;
      vector<ll> a(n);
      vector<ll> dp(n+5);
      rep(i,0,n+2)dp[i]=-1;
      for(int i=0;i<n;i++)
        cin>>a[i];

      cout<<frog(n,a,0,dp);   
}
int main()
{
    fast;
    read_input();
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {  
      solving();
    }
    return 0;
}

