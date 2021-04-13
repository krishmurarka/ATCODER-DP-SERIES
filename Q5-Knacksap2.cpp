/******************************
     AUTHOR KRISH MURARKA
*******************************/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define deb(x) cout<<#x<<" "<<x<<"\n"

ll n,weight;
// instead of weight we are taking taking for dp as weight can be very large.
ll dp[101][100005];
ll w[105],p[105];
ll fun(int ind,int price)
{   
   if (ind == n) {
        if (price == 0)
            return 0;
        return inf;
    }
   if(dp[ind][price]!=-1)return dp[ind][price];
   ll pick=inf;
   if(p[ind]<=price)
   pick=w[ind]+fun(ind+1,price-p[ind]);
   ll nonpick=fun(ind+1,price);
   return dp[ind][price]=min(pick,nonpick);

}

void solving()
{
    cin>>n>>weight;
   memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)
      cin>>w[i]>>p[i];
  //For every Possible price we are checking if we would select that price 
  //with weight less than given weight.
  //As soon as we find that price we exist.
    for(int i=100000;i>=1;i--)
    {
      if(fun(0,i)<=weight)
      {
        cout<<i<<"\n";
        break;
      }
    }   
}
int main()
{
    fast;
    int t=1;
   // cin>>t;
    for(int i=1;i<=t;i++)
    {  
      solving();
    }
    return 0;
}
