/******************************
     AUTHOR KRISH MURARKA
*******************************/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int n,m;
vector<vector<char>> a(1001,vector<char>(1001));
ll dp[1001][1001];
ll fun(int row,int col)
{
    if(row==(n-1) && col==(m-1))return 1;// if we reach destination
    
    if(row>=n || col>=m)return 0;  // we we move out of matrix
    if(a[row][col]=='#')return 0;  // if we encounter a wall
    if(dp[row][col]!=-1)return dp[row][col]%mod;    // Memorisation
    return dp[row][col]=(fun(row+1,col)+fun(row,col+1)%mod)%mod;  // we are taking total ways fom right + down
}
void solving()
{
  cin>>n>>m;
  a.resize(n,vector<char>(m));
  memset(dp,-1,sizeof dp);
  for(int i=0;i<n;i++)
  {
     for(int j=0;j<m;j++)
     {
        cin>>a[i][j];
     }
  }
  cout<<fun(0,0)<<"\n";
}
int main()
{
    
    int t=1;
     //cin>>t;
    for(int i=1;i<=t;i++)
    {  

      //cout<<"Case #"<<i<<": ";
      solving();
    }
    return 0;
}
