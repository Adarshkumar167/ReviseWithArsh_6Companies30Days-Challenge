// 2933. High-Access Employees

class Solution
{
public:
    vector<string> findHighAccessEmployees(vector<vector<string>> &access_times)
    {
        int n = access_times.size();
        unordered_map<string, vector<int>> a;
        for (int i = 0; i < n; i++)
        {
            a[access_times[i][0]].push_back(stoi(access_times[i][1]));
        }
        for (auto &it : a)
        {
            sort(it.second.begin(), it.second.end());
        }
        vector<string> ans;
        for (auto &it : a)
        {
            int size = it.second.size();
            if (size >= 3)
            {
                for (int j = 2; j < size; j++)
                {
                    if ((it.second[j] - it.second[j - 2]) < 100)
                    {
                        ans.push_back(it.first);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};