

int cmp(const void *a, const void *b)
{
    int **x = (int **)a;
    int **y = (int **)b;
    return (*x)[1] - (*y)[1];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize)
{
    qsort(intervals, intervalsSize, sizeof(int *), cmp);

    int count = 0;
    int lastEnd = intervals[0][1];

    for(int i = 1; i < intervalsSize; i++)
    {
        if(intervals[i][0] < lastEnd)
            count++;
        else
            lastEnd = intervals[i][1];
    }

    return count;
}