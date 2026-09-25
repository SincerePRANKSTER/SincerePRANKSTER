/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void backtrack(int* nums, int numsSize, int start,
               int* path, int pathSize,
               int** result, int* returnSize, int* returnColumnSizes) {

    result[*returnSize] = malloc(pathSize * sizeof(int));

    for (int i = 0; i < pathSize; i++) {
        result[*returnSize][i] = path[i];
    }

    returnColumnSizes[*returnSize] = pathSize;
    (*returnSize)++;

    for (int i = start; i < numsSize; i++) {
        path[pathSize] = nums[i];

        backtrack(nums, numsSize, i + 1,
                  path, pathSize + 1,
                  result, returnSize, returnColumnSizes);
    }
}

int** subsets(int* nums, int numsSize,
              int* returnSize, int** returnColumnSizes) {

    int total = 1 << numsSize;

    int** result = malloc(total * sizeof(int*));
    *returnColumnSizes = malloc(total * sizeof(int));

    int path[10];
    *returnSize = 0;

    backtrack(nums, numsSize, 0,
              path, 0,
              result, returnSize, *returnColumnSizes);

    return result;
}