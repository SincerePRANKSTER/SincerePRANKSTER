
int numSubarraysWithSum(int* nums, int numsSize, int goal)
{
    int count = 0;
    int sum = 0;
    int l = 0;
    int r = 0;
    int prefixZeros = 0;

    while(r < numsSize)
    {
        sum += nums[r];

        while(l < r && (nums[l] == 0 || sum > goal))
        {
            if(sum > goal)
            {
                sum -= nums[l];
                prefixZeros = 0;
            }
            else
            {
                prefixZeros++;
            }

            l++;
        }

        if(sum == goal)
        {
            count += 1 + prefixZeros;
        }

        r++;
    }

    return count;
}
