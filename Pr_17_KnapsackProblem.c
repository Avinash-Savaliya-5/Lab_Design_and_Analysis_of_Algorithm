#include <stdio.h>

int main() {
    int n = 5, W = 10;
    int wt[] = {2, 3, 5, 7, 1};
    int val[] = {10, 5, 15, 7, 6};
    int dp[6][11];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) dp[i][w] = 0;
            else if (wt[i-1] <= w) {
                int a = val[i-1] + dp[i-1][w - wt[i-1]];
                int b = dp[i-1][w];
                dp[i][w] = a > b ? a : b;
            } else dp[i][w] = dp[i-1][w];
        }
    }
    printf("Max value: %d\n", dp[n][W]);
    int w = W;
    int taken[5] = {0};
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            taken[i-1] = 1;
            w -= wt[i-1];
        }
    }
    printf("Items taken (index: weight,value):\n");
    for (int i = 0; i < n; i++) if (taken[i]) printf("%d: %d,%d\n", i, wt[i], val[i]);
    return 0;
}
