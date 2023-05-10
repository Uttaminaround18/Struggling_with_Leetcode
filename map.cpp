#include <bits/stdc++.h>
using namespace std;

void print(vector<int> nums)
{
    int n = nums.size();
    map<int, int> mp; // only map means ordered_map

    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }

    // Traversing in Hashmaps

    // FOR EACH LOOP

    for (auto &it : mp)
    {
        cout << it.second << " ";
    }
}

int main()
{
    // Initiliasing the vector
    vector<int> nums({1, 2, 2, 4, 1, 3});

    print(nums);
    return 0;
}