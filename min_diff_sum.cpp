#include "stdc++.h"

using namespace std;

bool dp[102][102]; // depending on the problem constraints.  dp[n+1][w+1] = dp[n+1][sum+1] 



int  min_diff_sum(int arr[], int n)
{

int sum = 0;
for(int i = 0; i < n;i++)
{
    sum += arr[i];
}
vector<int> possible_subset_sums;
    for(int i = 0; i< n+1; i++) 
    {
        for(int j = 0; j <sum+1;j++)
        {
            if(j == 0) dp[i][j] = true;
            else if(j > 0 and i == 0) dp[i][j] = false; 

            if(i > 0 and j > 0)
            {
                 if(arr[i-1] <=  j)
                 {
                    dp[i][j] = dp[i-1][j] or dp[i-1][j - arr[i-1]];
                 }
                 else
                 {
                     dp[i][j] = dp[i-1][j];
                 }
            }
        }

    } 

    int i = n;
    for(int j = 0; j <sum+1;j++)
    {
        if(dp[i][j] == true)
        {
            possible_subset_sums.push_back(j);
        }
    }

int mn = INT_MAX;
    for(int i = 0; i < possible_subset_sums.size()/2; i++) 
    {
        mn = min(mn, sum - 2*possible_subset_sums[i]);
        //mn = max(0,mn);
    }
        
    
    return mn;
    
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    int ans; 
    printf("Enter number of elements");
    cin >> n;

    int arr[n];
   
   
    printf("Enter the array\n");
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];

    }  

    ans = min_diff_sum(arr,n);
    cout << "Minimum difference  is" << " " << ans << endl;
    
     
    return 0;


}
