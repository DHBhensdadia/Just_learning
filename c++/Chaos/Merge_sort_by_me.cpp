#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// Declaration of function which are going to be used
class Merge
{
public:
    int *sort(int *nums, int n);
    int *merge(int *nums1, int n1, int *nums2, int n2);
} algo;

int main()
{

    // geting inputs
    int n;
    cin >> n;

    int *nums = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // sorting
    int *ans = algo.sort(nums, n);

    // providing output
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }

    // deleting memory
    delete[] nums;
    delete[] ans;
    return 0;
}

int *Merge::sort(int *nums, int n)
{

    // edge case
    if (n == 1)
    {
        int *temp = new int[1];
        temp[0] = nums[0];
        return temp;
    }

    // recursive call
    int *ans;
    int mid = n / 2;
    if (n & 1)
    {
        int *nums1 = sort(nums, mid);
        int *nums2 = sort(nums + mid, mid + 1);
        ans = merge(nums1, mid, nums2, mid + 1);

        delete[] nums1;
        delete[] nums2;
    }
    else
    {
        int *nums1 = sort(nums, mid);
        int *nums2 = sort(nums + mid, mid);
        ans = merge(nums1, mid, nums2, mid);

        delete[] nums1;
        delete[] nums2;
    }

    // return
    return ans;
}

int *Merge::merge(int *nums1, int n1, int *nums2, int n2)
{

    int *ans = new int[n1 + n2];
    int count{0};
    int i{0}, j{0};

    // merging both srings
    while (i < n1 && j < n2)
    {
        if (nums1[i] <= nums2[j])
        {
            ans[count++] = nums1[i++];
        }
        else
        {
            ans[count++] = nums2[j++];
        }
    }

    // after we reach end of one of the strig
    if (i == n1)
    {
        while (j < n2)
        {
            *(ans + (count++)) = nums2[j++];
        }
    }
    else
    {
        while (i < n1)
        {
            *(ans + (count++)) = nums1[i++];
        }
    }

    // return
    return ans;
}
