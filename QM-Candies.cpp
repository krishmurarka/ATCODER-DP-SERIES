/******************************
     AUTHOR KRISH MURARKA
*******************************/
#include<bits/stdc++.h>
using namespace std;
#define ll                 long long int
#define mod                1000000007

ll dp[101][100005];
void solving()
{
  int n,k;
  cin>>n>>k;
  ll a[n];
  for(int i=0;i<n;i++)
  {
      cin>>a[i];
  }
  // dp[x][y] denontes xth index and y no of candies used
  // dp[x][0]=1; i.e. not giving candy to anyone

  // dp[first][0]=dp[first][1]=...=dp[first][a[0]]=1  i.e. there is only one to give chocolate to 1st person

  for(int i=0;i<=a[0];i++)
  {
     dp[0][i]=1;
  } 

  // dp[x][y]= dp[x-1][y]+ dp[x-1][y-1] + dp[x-1][y-2]...+ dp[x-1][y-a[x]];
  // so this is like a prefix sum as if we calulte this every time it will give tle.
  for(int i=1;i<n;i++)
  {
     vector<ll> prefix(k+1);
     prefix[0]=dp[i-1][0];
     for(int j=1;j<=k;j++)
     {
       prefix[j]=(prefix[j-1]+dp[i-1][j])%mod; // prefix sum
     }
     for(int j=0;j<=k;j++)
     {
        dp[i][j]=prefix[j];
        if(a[i]<j)
        {
          dp[i][j]=(dp[i][j]+mod-prefix[j-a[i]-1])%mod;
        }
     }
  }
  cout<<dp[n-1][k];
 
}
int main()
{
   solving();
    return 0;
}
