#include <stdio.h>
#include <limits.h>

int minCoins(int coins[], int m, int V) {
    int dp[V + 1];
    for (int i = 0; i <= V; i++) dp[i] = INT_MAX;
    dp[0] = 0;

    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < m; j++) {
            if (coins[j] <= i) {
                int sub_res = dp[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < dp[i])
                    dp[i] = sub_res + 1;
            }
        }
    }
    return dp[V] == INT_MAX ? -1 : dp[V];
}

int main() {
    int n, V;
    printf("Enter the number of coin denominations: ");
    scanf("%d", &n);

    int coins[n];
    for (int i = 0; i < n; i++) {
        printf("Enter denomination %d: ", i + 1);
        scanf("%d", &coins[i]);
    }

    printf("Enter the value to make change for: ");
    scanf("%d", &V);

    int result = minCoins(coins, n, V);
    if (result != -1)
        printf("Minimum coins required is %d\n", result);
    else
        printf("Not possible to make change for %d with given coins\n", V);

    return 0;
}
