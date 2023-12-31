// 2343. Query Kth Smallest Trimmed Number

class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        int n = queries.size();
        int m = nums.size();
        int o = nums[0].size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            multiset<pair<string, int>> a;
            for (int j = 0; j < m; j++)
            {
                string temp = nums[j].substr(o - queries[i][1], queries[i][1]);
                a.insert({temp, j});
            }
            int cnt = 0;
            for (auto it : a)
            {
                cnt++;
                if (cnt == queries[i][0])
                {
                    ans.push_back(it.second);
                    break;
                }
            }
        }
        return ans;
    }
};