int lengthOfLongestSubstring(char* s) {
    int r[128] = {0};
    int max = 0;
    int left = 0;
    int temp = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        int p = (unsigned char)s[i];

        while (r[p] > 0) {
            r[(unsigned char)s[left]]--;
            left++;
        }

        r[p]++;

        temp = i - left + 1;

        if (max < temp)
            max = temp;
    }

    return max;
}
  