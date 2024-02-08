class Solution {
public:
    int numSquares(int n) {
        if (n <= 0)
            return 0;

        int i = sqrt(n), ans = INT_MAX;

        while (i > 0) {
            int value = getAnswer(i, n, 0);
            ans = min(ans, value);
            i--;
        }

        return ans;
    }
    int getAnswer(int num, int target, int count) {
        if (target <= 0)
            return count;
            
        if (target < num * num) {
            return INT_MAX;
        }

        int ans = INT_MAX;

        while (num > 0) {
            int sq = num * num;
            int value = getAnswer(num, target - sq, count + 1);
            ans = min(ans, value);
            num--;
        }

        return ans;
    }
};