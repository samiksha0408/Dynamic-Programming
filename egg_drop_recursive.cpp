#include "stdc++.h"
using namespace std;

int min_at_in_worst_case(int e, int f)
{
    if(f == 0 or f == 1 or e == 1) return f; // minimum attempts in the worst case 
    

    int ans = INT_MAX;
    for(int k = 1; k <= f; k++)
    {
        int tempans = 1 + max(min_at_in_worst_case(e-1,k-1), min_at_in_worst_case(e,f-k)); // max --> because worst case 
        ans = min(tempans,ans);
    }
    return ans; 
}
int main()
{
    int e,f;
    cout << "Enter the number of eggs and floors" << endl;
    cin >> e >> f;

    int ans = min_at_in_worst_case(e,f);
    cout << "Minimum attempts in worst case to find the threshold floor are :" << ans << endl;
}