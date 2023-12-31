// 2513. Minimize the Maximum of Two Arrays
// TC -> O(LogN) N = INT_MAX
// SC -> O(1)

#define ll long long int
class Solution
{
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2)
    {
        ll high = INT_MAX, low = 2;
        while (low <= high)
        {
            ll mid = (low + high) / 2;
            ll a = mid - mid / divisor1;
            ll b = mid - mid / divisor2;
            ll g = gcd(divisor1, divisor2);
            ll l = (ll)(divisor1) * (ll)(divisor2) / g;
            ll temp = mid - mid / l;
            if (a >= uniqueCnt1 && b >= uniqueCnt2 && temp >= uniqueCnt1 + uniqueCnt2)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};