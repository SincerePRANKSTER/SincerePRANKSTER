int longestOnes(int* nums, int numsSize, int k) {
    int left = 0, zeros = 0, max = 0;

    for (int right = 0; right < numsSize; right++) {
        if (nums[right] == 0)
            zeros++;

        while (zeros > k) {
            if (nums[left] == 0)
                zeros--;
            left++;
        }

        int len = right - left + 1;
        if (len > max)
            max = len;
    }

    return max;
}