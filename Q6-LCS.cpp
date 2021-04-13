/******************************
     AUTHOR KRISH MURARKA
*******************************/
#include<bits/stdc++.h>
using namespace std;
#define ll                long long int
string s,t;
ll dp[3003][3003];
ll fun(int ind1,int ind2)
{
     if(ind1>=s.length() || ind2>=t.length()) return 0;

     if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
     if(s[ind1]==t[ind2])
        return dp[ind1][ind2]=1+fun(ind1+1,ind2+1);
      else
        return dp[ind1][ind2]=max(fun(ind1,ind2+1),fun(ind1+1,ind2));
}
void solving()
{
  cin>>s>>t;
  memset(dp,-1,sizeof dp);
  //We are calculating the max possible value of LCS
  fun(0,0);
  // After getting the max value 
  // we backtrack the values to get the longest sequence.
  int ind=0;
  string ans="";
  int i=0,j=0;
  while(i<s.length() && j<t.length())
  {
    // we character are same we we add into LCS
      if(s[i]==t[j])
      {
        ans+=s[i];
        i++;
        j++;
      }
    // else chosing which side is having the larger value
    else if(dp[i][j+1]>=dp[i+1][j])
      {
         j++;
      }
      else
          i++;
  }
  cout<<ans<<endl;
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
