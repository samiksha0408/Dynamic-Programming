#include "stdc++.h"

int dp[1000][1000];
using namespace std;

int mcm_memoised(int a[], int i, int j)
{

    if(i >= j ) return 0;
    int ans = INT_MAX;
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    else
     {
        for(int k = i; k< j;k++)
        {
        int tempans = mcm_memoised(a,i,k) + mcm_memoised(a,k+1,j)+ a[i-1]*a[k]*a[j];

        ans = min(tempans,ans);
               
        }
    return dp[i][j] = ans;    
    }

    
}


int main()
{
    memset(dp,-1,sizeof(dp));
    
    int n; cout << "enter size of array" << endl;
    cin >> n;
    int a[n];
    cout << "Enter dimensions" << endl;
    for(int i = 0; i<n;i++)
    {
        cin >> a[i];
    }
    
    int ans = mcm_memoised(a,1,n-1);
    cout << "Minimum number of multiplications is :" << ans << endl;



}