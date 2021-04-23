/******************************
     AUTHOR KRISH MURARKA
*******************************/
#include<bits/stdc++.h>
using namespace std;
#define ll                 long long int
int n,k;
vector<ll> a(101);
ll dp[100005][2];
ll fun(int stone ,int flag)
{
    if(dp[stone][flag]!=-1)return dp[stone][flag];
    int ans=flag;
    // Initially our ans is equal to the flag i.e. i will loose the game
    for(int i=0;i<n;i++)
    {
        // we can only pick a stone if total is less than k
        if(stone+a[i]<=k)
        {
            // if we can place a stone , the turns come to next person
            // so we change the flag. 
            int x=fun(stone+a[i],1-flag);
            // if flag !=x means if i choose this element then opponent will loose or i will win
            if(x!=flag)
            {
              ans=x;
            }
          // else I am only loosing 
        }
    }
    return dp[stone][flag]=ans;
}
void solving()
{
  cin>>n>>k;
  a.resize(n);
  mem1(dp);
  for(int i=0;i<n;i++)
  {
     cin>>a[i];
  }
  if(!fun(0,1)) //if i am wining
  {
     cout<<"First\n";
  }
  else // if opponent is winning
  {
     cout<<"Second\n";
  }
}
int main()
{
    int t=1;
    for(int i=1;i<=t;i++)
    { 
     solving();

    }
    return 0;
}
