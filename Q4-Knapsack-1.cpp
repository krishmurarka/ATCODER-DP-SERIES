/******************************
     AUTHOR KRISH MURARKA
*******************************/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll n,sum;
ll w[105],p[105];
ll dp[105][100005];
ll fun(int ind,int curr_sum)
{

    if(ind>=n || curr_sum >=sum)return 0;
   if(dp[ind][curr_sum]!=-1)return dp[ind][curr_sum];  //Memorisation

    ll pick=0;
    if(curr_sum+w[ind] <=sum)
    {
      // incrementing the index because we can pick one element only once.
      pick=p[ind]+fun(ind+1,curr_sum+w[ind]);   
    }
    ll nonpick=fun(ind+1,curr_sum); //Non Pick Condition

    return dp[ind][curr_sum]=max(pick,nonpick);  // taking the max value
}
void solving()
{
  
  // Taking input
    cin>>n>>sum;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
       cin>>w[i]>>p[i];
    }

    cout<<fun(0,0)<<"\n";
}

int main()
{
    int t=1;
   // cin>>t;
    for(int i=1;i<=t;i++)
    {  
      solving();
    }
    return 0;
}
