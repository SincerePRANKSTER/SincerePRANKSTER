int characterReplacement(char* s, int k) 
{
    int l = 0, r = 0;
    int len = strlen(s);
    int max = 0;
    int freq[26] = {0};
    int maxFreq = 0;

    while (r < len)
    {
        freq[s[r] - 'A']++;

        if (freq[s[r] - 'A'] > maxFreq)
            maxFreq = freq[s[r] - 'A'];

        if ((r - l + 1) - maxFreq > k)
        {
            freq[s[l] - 'A']--;
            l++;
        }

        if (max < r - l + 1)
            max = r - l + 1;

        r++;
    }

    return max;
}