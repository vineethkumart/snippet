int matrix_mul(int i, int j, int nums[], int dp[][], int N)
{
    assert(i, j > 0 && < N);

    if (i == j) return 0;


    int& ans = dp[i][j];
    if (ans) return ans;

    ans = INT_MAX;
    for (int k = i; k < j; k++) {
        ans = min(ans, matrix_mul(i, k) + matrix_mul(k + 1, j) + nums[i-1]* nums[k] * nums[k+1]);
    }

    return ans;
}


int main()
{
    int nums[N] = {};
    int dp[N][N];

    return matrix_mul(1, N-1, nums, dp, N);
}


void bottom_up()
{


}

/*
 * Bursting ballon same, push 1 and begin and end of nums and also return min instead of max 
 * */
