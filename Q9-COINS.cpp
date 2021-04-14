/******************************
     AUTHOR KRISH MURARKA
*******************************/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

double dp[3000][3000];
int n;
vector<double> head(3000),tail(3000);
double probablity(int ind,int count)
{
    // If we reach the end and count of heads is less than tail we return 0 else 1
    if(ind==n && count<=n/2)return 0;
    if(ind==n)return 1;
    //memorisation step
    if(dp[ind][count]!=-1)return dp[ind][count];
      //include= we are taking head for that index
   double include=head[ind]*probablity(ind+1,count+1);
     //exclude= we are taking tail for that index
   double exclude=tail[ind]*probablity(ind+1,count);
    //we need to return the sum of all probality where no of head > no of tail
   return dp[ind][count]=(include+exclude);

}
void solving()
{

 cin>>n;
 head.resize(n);
 tail.resize(n);
 
 // Initialising DP array as -1
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<n;j++)
    dp[i][j]=-1;
 }
  // Taking probablity of head as input 
  // so 1-p(head)=p(tail).
 for(int i=0;i<n;i++)
 {
   cin>>head[i];
   tail[i]=1-head[i];
 }
  // seting precision to print 10 decimal digits.
 cout<<fixed<<setprecision(10)<<probablity(0,0)<<"\n";
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
