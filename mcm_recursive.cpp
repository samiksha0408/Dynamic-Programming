#include "stdc++.h"

using namespace std;

int solve(int b[], int i, int j)
{
    int ans = INT_MAX;

    if(i >= j)
        return 0;
    for(int k = i; k<=j-1;k++)
    {
        int tempans = solve(b,i,k) + solve(b,k+1,j)+ b[i-1]*b[k]*b[j];

        ans = min(tempans,ans);
                // if(tempans < ans)
        // {
        //     ans = tempans;
        // }
    }

    return ans;
}


int main()
{
    int n;
    cout << "Enter number of matrices" << endl;
    cin >> n;

    int a[n+1];
    cout << "Enter dimensions" << endl;
    for(int i = 0; i<= n;i++)
    {
        cin >> a[i];
    }
    

    int ans = solve(a,1,n);
    cout << "Minimum number of multiplications is :" <<ans << endl;


}