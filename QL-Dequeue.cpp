/******************************
     AUTHOR KRISH MURARKA
*******************************/
#include<bits/stdc++.h>
using namespace std;
#define ll                 long long int
int n;
vector<ll> a(101);
ll dp[3005][3005];
ll fun(int first, int last) 
{
  if(first>last)return 0;
  if(dp[first][last]!=-1)return dp[first][last]; // memorisation
  
  // if player1 choose to remove 1st index then player 2 will give the minimum of the remaining sum to player 1
  ll firstElement=a[first]+min(fun(first+2,last),fun(first+1,last-1));
  //if player1 choose to remove lastindex then also player 2 will give the minimum of the remaining possoible to player1 
  ll lastElement=a[last]+min(fun(first+1,last-1),fun(first,last-2));
  // we will take the maximum of both the result as both players will play optimally.
  return dp[first][last]=max(firstElement,lastElement);
}
void solving()
{
  cin>>n;
  a.resize(n);
  mem1(dp);
  ll initial_sum=0;
  for(int i=0;i<n;i++)
  {
     cin>>a[i];
     initial_sum+=a[i];
  }
  ll x=fun(0,n-1); // sum by player 1 
  ll y=(initial_sum-x); // sum by player 2
  cout<<(x-y)<<"\n";
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
