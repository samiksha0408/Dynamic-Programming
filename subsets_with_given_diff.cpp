#include "stdc++.h"

using namespace std;

int dp[102][102]; // depending on the problem constraints.  dp[n+1][w+1] = dp[n+1][sum+1] 



int count_subset_diff(int arr[],  int sum, int n)
{


    for(int i = 0; i< n+1; i++) 
    {
        for(int j = 0; j <sum+1;j++)
        {
            if(j == 0) dp[i][j] = 1;
            else if(j > 0 and i == 0) dp[i][j] = 0; 

            if(i > 0 and j > 0)
            {
                 if(arr[i-1] <=  j)
                 {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
                 }
                 else
                 {
                     dp[i][j] = dp[i-1][j];
                 }
            }
        }

    } 
    //change recursive function to iterative 
        
    
    return dp[n][sum];
    
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    int ans;
    printf("Enter number of elements");
    cin >> n;

    int arr[n];
   
    int sum = 0;  int diff;
    printf("Enter the array\n");
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }  

     
    printf("Enter difference\n");
    cin >> diff;
    sum = (sum + diff)/2;

    ans = count_subset_diff(arr,sum,n);
    cout << "The number of subsets with given difference are" << " "<< ans << endl;

     
    return 0;


}
