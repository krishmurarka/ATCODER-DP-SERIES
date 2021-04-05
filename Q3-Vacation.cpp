/******************************
     AUTHOR KRISH MURARKA
*******************************/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int n,k;
ll a[100005][3];
ll dp[100005][3];
ll  frog(int ind, int day)
{
  if(ind==n)return dp[ind][day]=0;  //base case
  if(dp[ind][day]!=-1)return dp[ind][day];   // memorisation
  
  ll swim=0,bug=0,homework=0;   // Three choices the person is having 
   if(day!=1)                     // if prev day was not swimming task then perform this
   {
        swim=a[ind][0]+frog(ind+1,1);
   } 
   if(day!=2)               // if prev day was not the bug fixing task then perform this
   {
      bug=a[ind][1]+frog(ind+1,2);
   }
   if(day!=3)            // if prev day was not the homework task then perform this
   {
      homework=a[ind][2]+frog(ind+1,3);
   }
   return dp[ind][day]=max(swim,max(bug,homework));     // Take the max out of all.
}
void solving()
{
      //Taking Input
      cin>>n;
      memset(dp,-1,sizeof(dp));
      memset(a,0,sizeof(a));
      for(int i=0;i<n;i++)
        {
          for(int j=0;j<3;j++)
          {
              cin>>a[i][j];
          }
        }
      cout<<frog(0,0);
}
int main()
{
   
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {  
      solving();
    }
    return 0;
}

