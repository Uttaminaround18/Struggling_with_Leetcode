#include <bits/stdc++.h>
using namespace std;

#define ll long long int

vector<int> bfs()
{

    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // for (auto it : adj)
    // {

    //     for (auto a : it)
    //     {
    //         cout << a << " ";
    //     }

    //     cout << "\n";
    // }

    int vis[n + 1] = {0};
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    vector<int> ans;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return ans;
}

void bsf_solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (auto it : adj)
    {

        for (auto a : it)
        {
            cout << a << " ";
        }

        cout << "\n";
    }
}

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int ind = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ind = i;
            break;
        }
    }
    if (ind == -1)
        reverse(nums.begin(), nums.end());
    else
    {

        for (int i = n - 1; i > ind; i--)
        {
            if (nums[i] > nums[ind])
            {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        reverse(nums.begin() + ind + 1, nums.end());
    }
}

int permutation(string a, string b)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < b.size(); i++)
    {
        mp[b[i]]++;
    }

    int j = 0, r = 0;
    int n = a.size();
    int ans = 0;
    int cnt = mp.size();

    while (j < n)
    {
        while (cnt > 0 && j <= r)
        {
            if (r == n)
                break;

            if (mp.find(a[r]) != mp.end())
            {
                mp[a[r]]--;
                if (mp[a[r]] == 0)
                    cnt -= 1;
            }
            r++;
        }

        if (cnt > 0)
            break;

        ans += n - r + 1;
        if (mp.find(a[j]) != mp.end())
        {
            mp[a[j]]++;
            if (mp[a[j]] > 0)
                cnt++;
        }
        j++;
    }

    return ans;
}

void rotate_array(vector<int> &nums, int k)
{
    k %= nums.size();
    int n = nums.size();
    reverse(nums.begin(), nums.end());
    // reverse(nums.begin(), nums.begin() + k + 1);
    reverse(nums.begin() + n - k, nums.end());

    for (auto it : nums)
        cout << it << " ";
}

string removeStars(string s)
{
    int n = s.size();
    stack<char> st;

    for (int i = 0; i < n; i++)
    {
        if (s[i] != '*')
            st.push(s[i]);
        else
        {
            if (!st.empty())
            {
                st.pop();
            }
            else
                break;
        }
    }

    string ans = "";

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int finLength(int n, vector<int> color, vector<int> radius)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!st.empty())
        {
            int top = st.top();
            if (color[top] == color[i] && radius[top] == radius[i])
                st.pop();
            else
                st.push(i);
        }
        else
        {
            st.push(i);
        }
    }

    return st.size();
}

bool isPossible(int diff, vector<int> prefix_sum)
{
    int n = prefix_sum.size();
    for (int i = 0; i < n; i++)
    {
        int other_parition = (prefix_sum[n - 1] - prefix_sum[i]);
        if (diff == abs(prefix_sum[i] - other_parition))
            return true;
    }

    return false;
}

int parition(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int total_sum = nums[0];
    vector<int> prefix_Sum(n);
    prefix_Sum[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        total_sum += nums[i];
        prefix_Sum[i] = prefix_Sum[i - 1] + nums[i];
    }

    for (auto it : prefix_Sum)
        cout << it << " ";

    int low = 0;
    int ans = -1;
    int high = total_sum;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(mid, prefix_Sum))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ans;
}

int f(int ind, vector<vector<int>> &piles, int k)
{

    int choice = piles[ind][ind] + f(ind + 1, piles, k - 1);

    int choice2 = piles[0][ind] + f(ind + 1, piles, k - 1);
}

int maxValueOfCoins(vector<vector<int>> &piles, int k)
{
    int n = piles.size();
    int m = piles[0].size();
}

// void findPrefixScore(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> maxi;
//     maxi.push_back(nums[0]);

//     int a = nums[0];
//     for (int i = 1; i < nums.size(); i++)
//     {
//         if (a > nums[i])
//         {
//             maxi.push_back(a);
//         }
//         else
//         {
//             a = nums[i];
//             maxi.push_back(nums[i]);
//         }
//     }

//     vector<int> conver;
//     for (int i = 0; i < n; i++)
//     {
//         int b = nums[i] + maxi[i];
//         conver.push_back(b);
//     }

//     vector<long long> ans(n, 0);
//     ans[0] = conver[0];
//     for (int i = 1; i < n; i++)
//     {
//         ans[i] = ans[i - 1] + conver[i];
//     }

//     for (auto it : ans)
//         cout << it << " ";

//     return ans;
// }

vector<int> findColumnWidth(vector<vector<int>> grid)
{

    int n = grid.size();
    int m = grid[0].size();
    vector<int> op;
    for (int i = 0; i < m; i++)
    {
        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            int count = 0, neg = 0;
            int a = grid[j][i];
            if (a < 0)
            {
                neg = 1;
                a *= -1;
            }

            while (a > 0)
            {
                a = a / 10;
                count++;
            }

            if (neg == 1)
                count += 1;

            ans = max(ans, count);
        }

        op.push_back(ans);
    }

    return op;
}

vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int ans = 0;
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        int count_ones = 0;
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1)
                count_ones += 1;
        }
        if (count_ones > ans)
        {
            ans = count_ones;
            index = i;
        }
    }

    return {index, ans};
}

// int maxDivScore(vector<int> &nums, vector<int> &divisors)
// {
//     int n = divisors.size();
//     vector<int> v;
//     map<int, int> mp;

//     // int ans = 0;
//     int index = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int cnt = 0;
//         for (int j = 0; j < nums.size(); j++)
//         {
//             if (nums[j] % divisors[i] == 0)
//                 cnt += 1;
//         }

//         mp[nums[i]] = cnt

//             if (cnt > ans)
//         {
//             // ans = cnt;
//             index = nums[i];
//         }
//     }

//     sort(v.begin(), v.end());
//     int flag = 0;
//     for (int i = 1; i < v.size(); i++)
//     {

//         if (v[i] == v[i - 1])
//         {
//             flag = 1;
//             break;
//         }
//     }
//     int ans = 0;
//     if (flag == 1)
//         ans = *min_element(v.begin(), v.end());
//     else
//         ans = *max_element(v.begin(), v.end());

//     return ans;
// }

int addMinimum(string word)
{
    int n = word.size();
    unordered_map<char, int> mp;

    int maxi = 0;

    mp['a'] = 0;
    mp['b'] = 0;
    mp['c'] = 0;

    for (int i = 0; i < n; i++)
    {
        mp[word[i]]++;
        if (mp[word[i]] > maxi)
            maxi = mp[word[i]];
    }
    int ans = 0;
    for (auto it : mp)
    {
        if (it.second == maxi)
            continue;
        else
        {
            ans += maxi - it.second;
        }
    }

    return ans;
}

int dominantPairs(int n, vector<int> &arr)
{
    sort(arr.begin(), arr.begin() + n / 2);
    sort(arr.begin() + n / 2, arr.end());

    int res = 0;

    int i = 0, j = n / 2;
    while (i < n / 2 && j < n)
    {
        if (arr[i] >= arr[j] * 5)
        {
            res += n / 2 - i;
            j++;
        }
        else
            i++;
    }

    return res;
}

int maxOperations(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    int ans = 0;

    int j = 0;
    while (j < n)
    {
        int num = k - nums[j];
        if (mp.find(num) != mp.end())
        {
            ans += 1;
            mp[num]--;
            if (mp[num] == 0)
                mp.erase(num);
        }
        else
        {
            mp[num]++;
        }
    }

    return ans;
}

vector<int> pivotArray(vector<int> &nums, int pivot)
{
    int n = nums.size();
    vector<int> before;
    vector<int> after;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] < pivot)
            before.push_back(nums[i]);
        else if (nums[i] == pivot)
            cnt += 1;
        else
            after.push_back(nums[i]);
    }

    while (cnt--)
    {
        before.push_back(pivot);
    }

    for (int i = 0; i < after.size(); i++)
        before.push_back(after[i]);

    return before;
}

vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
    int n = candies.size();
    int maxi = 0;
    int ind = 0;
    for (int i = 0; i < n; i++)
    {
        if (candies[i] > maxi)
        {
            maxi = candies[i];
        }
    }
    vector<bool> res;
    for (auto it : candies)
    {
        it += extraCandies;
        if (it >= maxi)
            res.push_back(1);
        else
            res.push_back(0);
    }

    return res;
}

int subarray_sum(vector<int> nums, int k)
{
    int n = nums.size();
    int i = 0;
    int j = 0;
    int sum = 0;
    int ans = 0;

    while (j < n)
    {
        sum += nums[j];
        int len = j - i + 1;

        while (sum * len >= k)
        {
            sum -= nums[i];
            i++;
            len--;
        }

        ans += j - i + 1;
        j++;
    }

    return ans;
}

int solve(vector<int> &nums, int k)
{
    int n = nums.size();
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i] / k;
        nums[i] = nums[i] % k;
    }

    sort(nums.begin(), nums.end());
    int i = 0, j = n - 1;

    while (i < j)
    {
        if (nums[i] + nums[j] >= k)
        {
            sum += 1;
            i++;
            j--;
        }
        else
            i++;
    }

    return sum;
}

int wiggleMaxLength(int ind, int pos, vector<int> &nums, vector<vector<int>> &dp)
{
    int n = nums.size();
    if (ind == n - 1)
        return 0;

    if (dp[ind][pos] != -1)
        return dp[ind][pos];

    int take = 0, not_take = 0;
    if (pos == 1)
    {
        if (nums[ind + 1] - nums[ind] > 0)
            take = 1 + wiggleMaxLength(ind + 1, 0, nums, dp);
        else
            not_take = 0 + wiggleMaxLength(ind + 1, pos, nums, dp);
    }
    else
    {
        if (nums[ind + 1] - nums[ind] < 0)
            take = 1 + wiggleMaxLength(ind + 1, 1, nums, dp);
        else
            not_take = 0 + wiggleMaxLength(ind + 1, pos, nums, dp);
    }

    return dp[ind][pos] = not_take + take;
}

int minDiffSubArray(vector<int> nums)
{
    int n = nums.size();
    vector<int> prefix(n, 0);
    prefix[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + nums[i];
    }

    int ans = INT_MAX;
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int part1 = prefix[mid];
        int part2 = prefix[n - 1] - prefix[mid];
        ans = min(ans, abs(part1 - part2));

        if (part1 > part2)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return ans;
}

int largest_subarray(vector<int> nums)
{
    int n = nums.size();
    int j = 0, i = 0;
    unordered_map<int, int> mp;
    int ans = 0;

    while (j < n)
    {
        mp[nums[j]]++;

        while (mp.size() < j - i + 1)
        {
            mp[nums[i]]--;
            if (mp[nums[i]] == 0)
                mp.erase(nums[i]);
            i++;
        }

        ans = max(ans, j - i + 1);
        j++;
    }

    return ans;
}

int waysToSplitArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> prefix(n, 0);
    prefix[0] = nums[0];
    int cnt = 0;

    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + nums[i];

    for (int i = 0; i < n - 1; i++)
    {
        if (prefix[i] >= (prefix[n - 1] - prefix[i]))
            cnt += 1;
    }

    return cnt;
}

void longest_subarray(vector<int> nums)
{
    int n = nums.size();
    int i = 0, j = 1;
    int ans = INT_MIN;
    int l = 0, r = 0;

    while (j < n)
    {
        if (nums[j] >= nums[j - 1])
            j++;
        else
        {
            if (j - i > ans)
            {
                ans = j - i;
                l = i + 1;
                r = j;
            }
            i = j;
            j++;
        }
    }
    cout << l << " " << r << "\n";
}

int f(int ind, int num, int minProfit, vector<int> &group, vector<int> &profit)
{
    int n = profit.size();
    if (num == 0)
    {
        if (minProfit <= 0)
            return 1;
        else
            return 0;
    }
    if (ind == n)
    {
        if (minProfit <= 0)
            return 1;
        else
            return 0;
    }

    int take = 0;
    if (num >= group[ind])
        take = f(ind + 1, num - group[ind], minProfit - profit[ind], group, profit);

    int not_take = f(ind + 1, num, minProfit, group, profit);

    return not_take + take;
}

int f1(int ind, int num, vector<vector<int>> &players, vector<vector<int>> &dp)
{
    int n = players.size();
    if (ind == n)
    {
        return 0;
    }

    if (dp[ind][num + 1] != -1)
        return dp[ind][num + 1];

    int take = 0;
    if (num == -1 || players[ind][1] >= players[num][1])
    {
        take = players[ind][0] + f1(ind + 1, ind, players, dp);
    }

    int not_take = 0 + f1(ind + 1, num, players, dp);

    return dp[ind][num + 1] = max(take, not_take);
}

int f2(int ind, vector<int> nums)
{
    int n = nums.size();
    if (ind == 0)
        return nums[0];

    if (ind < 0)
        return 0;

    int choice1 = nums[ind] + f2(ind - 2, nums);

    int choice2 = 0 + f2(ind - 1, nums);

    return max(choice1, choice2);
}

int antiqueItems(vector<int> &items, vector<int> &price)
{
    vector<pair<int, int>> shops;
    int n = items.size();

    for (int i = 0; i < n; i++)
        shops.push_back({price[i], items[i]});

    sort(shops.begin(), shops.end());
    unordered_set<int> st;
    int ans = 0;

    for (auto it : shops)
    {
        if (st.find(it.second) == st.end())
        {
            ans += it.first;
            st.insert(it.second);
        }
    }

    return ans;
}

int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
{

    vector<pair<int, int>> jobs;
    int n = profit.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        jobs.push_back({difficulty[i], profit[i]});
    }

    sort(jobs.begin(), jobs.end());

    int mx = INT_MIN;
    vector<int> pre;
    for (auto i : jobs)
        pre.push_back(mx = max(i.second, mx));

    sort(worker.begin(), worker.end());
    int sum = 0;
    for (auto i : worker)
    {

        // int ind = lower_bound(jobs.begin(), jo)

        ans += sum;
    }

    return ans;
}

int get_smallest(map<int, int> &mp, int x)
{
    int smallest = 0;
    for (auto it : mp)
    {
        if (it.first < 0)
        {
            smallest += it.second;
        }
        else
            return 0;

        if (smallest >= x)
            return it.first;
    }

    return 0;
}

vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x)
{
    int n = nums.size();
    int i = 0;
    int j = 0;
    map<int, int> mp;
    vector<int> ans;

    while (j < n)
    {
        mp[nums[j]]++;

        if (j - i + 1 < k)
            j++;
        else
        {
            int a = get_smallest(mp, x);
            ans.push_back(a);

            if (mp.find(nums[i]) != mp.end())
            {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
                j++;
            }
        }
    }

    return ans;
}

void removeDuplicates(string s, int k)
{
    int n = s.size();
    stack<char> st;
    vector<int> count(26, 0);
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        count[s[i] - 'a']++;

        if (mp.find(s[i]) == mp.end())
            mp[s[i]] = i;

        if (count[s[i] - 'a'] == k && i - mp[s[i]] >= k - 1)
        {
            count[s[i] - 'a'] -= k;
            int a = k - 1;
            while (a--)
            {
                st.pop();
            }

            if (count[s[i] - 'a'] == 0)
                mp.erase(s[i]);
        }
        else
        {
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int maxSubaray(vector<int> nums, int k)
{
    int n = nums.size();
    int i = 0;
    int j = 0;
    int sum = 0;
    int maxi = INT_MIN;

    while (j < n)
    {
        sum += nums[j];

        while (j - i + 1 > k && i <= j)
        {
            sum -= nums[i];
            i++;
        }

        maxi = max(maxi, sum);
        j++;
    }

    return maxi;
}

int takeCharacters(string s, int k)
{
    vector<int> count(3, 0);
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        count[s[i] - 'a']++;
    }

    for (int i = 0; i < 3; i++)
    {
        count[i] -= k;
    }

    if (count[0] < 0 || count[1] < 0 || count[2] < 0)
        return -1;

    int i = 0;
    int j = 0;
    int res = 0;

    while (j < n)
    {
        count[s[j] - 'a']--;

        while (count[s[j] - 'a'] < 0 && i <= j)
        {
            count[s[i] - 'a']++;
            i++;
        }

        res = max(res, j - i + 1);
        j++;
    }

    return n - res;
}

long long countSubarrays(vector<int> &nums, long long k)
{

    int i = 0;
    int j = 0;
    int n = nums.size();
    long long ans = 0;

    long long score = 0;

    while (j < n)
    {
        score += nums[j];

        while (score * (j - i + 1) >= k && i <= j)
        {
            score -= nums[i];
            // score /= (j - i + 1);
            i++;
        }

        ans += j - i + 1;
        j++;
    }

    return ans;
}

int maxFrequency(vector<int> &nums, int k)
{
    int i = 0;
    int j = 0;
    int n = nums.size();
    int sum = 0;
    int ans = 0;

    sort(nums.begin(), nums.end());

    while (j < n)
    {
        sum += nums[j];

        while ((j - i + 1) * nums[j] - sum > k)
        {
            sum -= nums[i];
            i++;
        }

        ans = max(ans, j - i + 1);
        j++;
    }

    return ans;
}

vector<long long> minOperations(vector<int> &nums, vector<int> &queries)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<int> prefix(n, 0);
    prefix[0] = nums[0];

    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + nums[i];

    vector<ll> ans;

    for (auto it : queries)
    {
        ll a = 0;
        ll ind = lower_bound(nums.begin(), nums.end(), it) - nums.begin();
        if (ind != 0)
            ind -= 1;
        ll ind2 = upper_bound(nums.begin(), nums.end(), it) - nums.begin();

        a += it * (ind + 1) - prefix[ind];

        if (ind != n)
            a += prefix[n - 1] - prefix[ind2 - 1] - (n - ind2) * it;

        ans.push_back(a);
    }

    return ans;
}

vector<int> findLonely(vector<int> &nums)
{
    unordered_map<int, int> mp;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }

    vector<int> ans;
    for (auto it : mp)
    {
        if (it.second == 1)
        {
            if (mp.find(it.first - 1) == mp.end() && mp.find(it.first + 1) == mp.end())
            {
                ans.push_back(it.first);
            }
        }
    }

    return ans;
}

int maximum_salary(int ind, int prev, vector<vector<int>> &nums, vector<vector<int>> &dp)
{
    int n = nums.size();
    if (ind == n)
        return 0;

    if (dp[ind][prev] != -1)
        return dp[ind][prev];

    int choice2 = 0;
    if (prev == 0)
        choice2 = nums[ind][1] + maximum_salary(ind + 1, 2, nums, dp);
    int choice = 0 + maximum_salary(ind + 1, 0, nums, dp);
    int choice1 = nums[ind][0] + maximum_salary(ind + 1, 1, nums, dp);

    return dp[ind][prev] = max(choice2, max(choice, choice1));
}

int longestSubstring(string s, int k)
{
    int n = s.size();
    int j = 0;
    int i = 0;
    unordered_map<char, int> mp;
    int cnt = 0;
    int r = 0;
    int ans = 0;

    while (j < n)
    {
        mp[s[j]]++;
        if (mp[s[j]] >= k)
            cnt += 1;

        if (cnt == mp.size())
        {
            ans = max(ans, j - i + 1);
        }

        while (cnt == mp.size())
        {
        }
    }
}

int maximizeSum(vector<int> &nums, int k)
{

    int maxi = *max_element(nums.begin(), nums.end());

    int num = maxi;
    for (int i = 1; i < k; i++)
    {
        num += 1;
        maxi += maxi;
    }

    return maxi;
}

vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    vector<int> ans(n, 0);

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[A[i]] = i;
    }

    if (A[0] == B[0])
        ans[0] = 1;
    else
        ans[0] = 0;

    for (int i = 1; i < n - 1; i++)
    {
        int cnt = 0;
        for (int j = 0; j <= i; j++)
        {
            if (mp[B[j]] <= i)
                cnt += 1;
        }
        ans[i] = cnt;
    }
    ans[n - 1] = n;
    return ans;
}

int isWinner(vector<int> &player1, vector<int> &player2)
{

    int n = player1.size();
    int ind1 = -1, ind2 = -1;
    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (ind1 != -1 && i - ind1 <= 2)
        {
            sum1 += 2 * player1[i];
        }
        else
            sum1 += player1[i];

        if (ind2 != -1 && i - ind2 <= 2)
        {
            sum2 += 2 * player2[i];
        }
        else
            sum2 += player2[i];

        if (player1[i] == 10)
            ind1 = i;
        if (player2[i] == 10)
            ind2 = i;
    }

    if (sum1 > sum2)
        return 1;
    else if (sum1 < sum2)
        return 2;
    else
        return 0;
}

int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]] = i;
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int ind = -1;
        for (int j = 0; j < m; j++)
        {
            if (mp[mat[i][j]] > ind)
                ind = mp[mat[i][j]];
        }

        ans = min(ans, ind);
    }

    for (int i = 0; i < n; i++)
    {
        int ind = -1;
        for (int j = 0; j < m; j++)
        {
            if (mp[mat[j][i]] > ind)
                ind = mp[mat[j][i]];
        }

        ans = min(ans, ind);
    }

    return ans;
}

long long minCost(vector<int> &nums, vector<int> &cost)
{
    int n = nums.size();
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        v.push_back({nums[i], cost[i]});
    }

    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.first <= b.first; });
    vector<int> num, cst;
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        num.push_back(v[i].first);
        cst.push_back(v[i].second);
        sum += v[i].second;
    }

    // cout << sum << "\n";
    long long target = sum / 2;
    long long y = 0;
    int ind = -1;

    for (int i = 0; i < n; i++)
    {
        y += cst[i];
        if (y >= target)
        {
            ind = num[i];
            break;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs((long long)(ind - num[i])) * (long long)cst[i];
    }

    return ans;
}

bool isSweetness(int mid, int n, int k, vector<int> nums)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum >= mid)
        {
            k--;
            sum = 0;
        }
    }

    if (k <= -1)
        return true;
    else
        return false;
}

int maxSweetness(vector<int> &sweetness, int n, int k)
{
    int low = 0;
    int high = 0;

    for (int i = 0; i < n; i++)
    {
        high += sweetness[i];
    }

    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isSweetness(mid, n, k, sweetness) == true)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return ans;
}

int halveArray(vector<int> &nums)
{
    int sum = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(nums[i]);
    }
    int cnt = 0;
    int total = sum;
    while (sum >= total / 2)
    {
        int top = pq.top();
        int num = top / 2;

        pq.pop();
        pq.push(num);
        sum -= (top - num);
        cnt += 1;
    }

    return cnt;
}

int solve(int ind, vector<vector<int>> &ranges, int rem)
{
    int n = ranges.size();

    if (rem == 0 || ind == n)
    {
        return 0;
    }

    int not_take = solve(ind + 1, ranges, rem);
    int take = ranges[ind][2];

    int low = 0;
    int high = n - 1;
    int index = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (ranges[ind][1] <= ranges[mid][0])
        {
            index = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    take += solve(index, ranges, rem - 1);

    return max(take, not_take);
}

int maxCoins(int n, vector<vector<int>> &ranges)
{
    sort(ranges.begin(), ranges.end(), [](vector<int> a, vector<int> b)
         {
        
        if(a[0] == b[0])
            return a[1] <= b[1];
        return a[0] <= b[0]; });

    return solve(0, ranges, 2);
}

int minOperations(vector<int> &nums, int x)
{
    int n = nums.size();
    int target = 0;

    for (int i = 0; i < n; i++)
    {
        target += nums[i];
    }

    target -= x;
    unordered_map<int, int> mp;
    int j = 0;
    int prefix_sum = 0;
    int ans = INT_MIN;

    while (j < n)
    {
        prefix_sum += nums[j];
        if (prefix_sum == target)
            ans = max(ans, j + 1);

        if (mp.find(prefix_sum - target) != mp.end())

        {
            ans = max(ans, j - mp[prefix_sum - target]);
        }
        // if (mp.find(prefix_sum) == mp.end())
        mp[prefix_sum] = j;
        j++;
    }

    // if (ans != INT_MIN)
    //     return n - ans;
    // else
    //     return -1;
    //  hello
    return ans;
}

int minSetSize(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }

    vector<int> freq;
    for (auto it : mp)
    {
        freq.push_back(it.second);
    }

    sort(freq.begin(), freq.end(), greater<int>());
    int remove = 0;
    int size = n / 2;
    int i = 0;
    int cnt = 0;

    while (remove < size && i < n)
    {
        remove += freq[i++];
        cnt += 1;
    }

    return cnt;
}

int helper(int ind, int k, int target, vector<int> &coins, vector<vector<int>> &dp)
{
    int n = coins.size();
    if (target == 0 && k == 0)
        return 1;

    if (ind == n)
    {
        if (target == 0 && k == 0)
            return 1;
        else
            return 0;
    }

    if (dp[k][target] != -1)
        return dp[k][target];

    int take = 0;
    if (coins[ind] <= target)
    {
        take = helper(ind, k - 1, target - coins[ind], coins, dp);
    }

    // if (take == 1)
    //     return dp[k][target] = 1;

    int not_take = helper(ind + 1, k, target, coins, dp);

    return dp[k][target] = take || not_take;
}

bool makeChanges(int n, int k, int target, vector<int> &coins)
{
    sort(coins.begin(), coins.end(), [](int &a, int &b)
         { return a > b; });
    // vector<vector<int>> dp(n,vector<int>())

    vector<vector<int>> dp(k + 1, vector<int>(target + 1, -1));

    int ans = helper(0, k, target, coins, dp);
    if (ans)
        return true;
    else
        return false;
}

vector<int> distinctDifferenceArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> mark(50, 0);
    vector<int> prefix(n, 0);
    vector<int> suffix(n, 0);
    prefix[0] = 1;
    mark[nums[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        if (mark[nums[i]] == 0)
        {
            prefix[i] = 1 + prefix[i - 1];
            mark[nums[i]] = 1;
        }
        else
            prefix[i] = prefix[i - 1];
    }

    vector<int> mark1(50, 0);
    mark1[nums[n - 1]] = 1;
    suffix[n - 1] = 1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (mark1[nums[i]] == 0)
        {
            suffix[i] = 1 + suffix[i + 1];
            mark1[nums[i]] = 1;
        }
        else
            suffix[i] = suffix[i + 1];
    }

    // for (auto it : suffix)
    //     cout << it << " ";

    vector<int> ans;

    for (int i = 0; i < n - 1; i++)
    {
        int diff = prefix[i] - suffix[i + 1];
        ans.push_back(diff);
    }
    ans.push_back(prefix[n - 1]);

    return ans;
}

vector<int> colorTheArray(int n, vector<vector<int>> &queries)
{
    int m = queries.size();
    int count = 0;

    vector<int> nums(n, 0);
    vector<int> ans(m, 0);
    int i = 0;

    for (auto &q : queries)
    {
        int ind = q[0];
        int color = q[1];

        if (ind == 0)
        {
            if (nums[ind] == nums[ind + 1])
            {
                if (nums[ind] != 0)
                    count -= 1;
            }

            nums[ind] = color;
            if (nums[ind] == nums[ind + 1])
            {
                count += 1;
            }
            ans[i] = count;
        }

        else if (ind == m - 1)
        {
            if (nums[ind] == nums[ind - 1])
            {
                if (nums[ind] != 0)
                {
                    count -= 1;
                }
            }

            nums[ind] = color;
            if (nums[ind] == nums[ind - 1])
            {
                count += 1;
            }

            ans[i] = count;
        }

        else
        {
            int value = (nums[ind] == nums[ind + 1]) + (nums[ind] == nums[ind - 1]);
            if (nums[ind] != 0)
                count -= value;

            nums[ind] = color;
            int nvalue = (nums[ind] == nums[ind + 1]) + (nums[ind] == nums[ind - 1]);
            count += nvalue;

            ans[i] = count;
        }

        i++;
    }

    return ans;
}

bool occurence(string s)
{
    int n = s.size();
    int b = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'b')
            b = 1;

        if (b == 1 && s[i] == 'a')
            return false;
    }

    return true;
}

int maxDistance(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int num = nums1[i];
        int low = 0;
        int high = nums2.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums2[mid] >= num)
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        ans = max(ans, i - low);
    }

    return ans;
}

int totalCuts(int n, int k, vector<int> &nums)
{
    vector<int> max_prefix(n, 0);
    vector<int> min_suffix(n, 0);

    max_prefix[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > max_prefix[i - 1])
            max_prefix[i] = nums[i];
        else
            max_prefix[i] = max_prefix[i - 1];
    }

    // for (auto it : max_prefix)
    //     cout << it << " ";

    min_suffix[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < min_suffix[i + 1])
            min_suffix[i] = nums[i];
        else
            min_suffix[i] = min_suffix[i + 1];
    }

    // cout << "\n";

    // for (auto it : min_suffix)
    //     cout << it << " ";

    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (max_prefix[i] + min_suffix[i + 1] >= k)
            cnt += 1;
    }

    return cnt;
}

int main()
{
    vector<int> v({2, 6, 10, 2, 8});
    vector<int> v1({4, 2, 8, 1, 3});
    vector<int> q({8, 9, 12});
    vector<vector<int>> nums({{0, 100000}});

    // for (int i = 0; i < v.size(); i++)
    // {
    //     players.push_back({v[i], v1[i]});
    // }
    // vector<int> ans;
    // ans = colorTheArray(1, nums);

    // for (auto it : ans)
    //     cout << it << " ";

    cout << totalCuts(5, 6, v) << "\n";

    // sort(players.begin(), players.end());
    // int n = players.size();
    // vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    // string s = "abcd";
    // string s2 = "pq";

    // cout << antiqueItems(v, v1) << "\n";

    // for (auto it : ans)
    //     cout << it << " ";

    // cout << maxFrequency(v, 5) << "\n";

    // cout << solve(v, 1) << "\n";
    // int n = v.size();
    // vector<vector<int>> dp(n, vector<int>(2, -1));
    // cout << wiggleMaxLength(0, 1, v, dp) << "\n";

    // cout << largest_subarray(v) << "\n";

    // cout << f(0, 10, 5, v1, v) << "\n";
    // vector<int> ans = rearrangeArray(v);
    // for (auto it : ans)
    //     cout << it << " ";

    return 0;
}
