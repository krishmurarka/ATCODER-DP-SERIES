/******************************
     AUTHOR KRISH MURARKA
*******************************/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int n;
double dp[301][301][301];
// here dp[x][y][z]= x is no of 3s , y no of 2s , z no of 1s  , no of zero=(n-(x+y+z)); we did this because 4D DP will exceed memory 
// dp[x][y][z]=1+ p3*dp[x-1][y+1][z] + p2*dp[x][y-1][z+1] + p1*dp[x][y][z-1]+ p0*dp[x][y][z];
/* but the term in p0 is same as LHS so we cant apply this eqaution like this

  so we bring that part to LHS and take common

  dp[x][y][z]*(1-p0)=1+ p3*dp[x-1][y+1][z] + p2*dp[x][y-1][z+1] + p1*dp[x][y][z-1];

  

  now dividing we get:

  dp[x][y][z]=(1+ p3*dp[x-1][y+1][z] + p2*dp[x][y-1][z+1] + p1*dp[x][y][z-1])/(1-p0);
  now the equation is good to go.
*/
void solving()
{

 cin>>n;
 ll cnt[4]={0};
 for(int i=0;i<n;i++)
 {
    int x;
    cin>>x;
    cnt[x]++;
 }
 dp[0][0][0]=0;
 for(int three=0;three<=n;three++)
 {
   for(int two=0;two<=n;two++)
   {
      for(int one=0;one<=n;one++)
      {
         int zero=(n-(one+two+three));
         if(zero==n)continue;
         if(three+two+one > n)continue;

         double val=1;
         // probality of picking plate having 3 sushi
         if(three>0)
         val+=(1.0 * three/n)*dp[three-1][two+1][one];

         // probality of picking plate having 2 sushi
         if(two>0)
         val+=(1.0 * two/n)*dp[three][two-1][one+1];


         // probality of picking plate having 1 sushi
         if(one>0)
         val+=(1.0 * one/n)*dp[three][two][one-1];

        val=val/(1- 1.0* zero/n);
        
        dp[three][two][one]=val;
      }
     
   }
 }
 cout<<setprecision(10)<<dp[cnt[3]][cnt[2]][cnt[1]]<<"\n";
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
