//1. Recursive Approach (Brute Force)
//O(limit^3) (Try every value for x, y, z)
class Solution {
public:
    int countWays(int idx, int sum, int n, int limit) {
        if (idx == 3) {
            return sum == n ? 1 : 0;
        }

        int ways = 0;
        for (int i = 0; i <= limit; i++) {
            ways += countWays(idx + 1, sum + i, n, limit);
        }

        return ways;
    }

    int distributeCandies(int n, int limit) {
        return countWays(0, 0, n, limit);
    }
};
//2. Iterative Triple Loop (O(limit³))
//O(limit³)
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ways = 0;

        for (int x = 0; x <= limit; x++) {
            for (int y = 0; y <= limit; y++) {
                for (int z = 0; z <= limit; z++) {
                    if (x + y + z == n) {
                        ways++;
                    }
                }
            }
        }

        return ways;
    }
};
//3. Iterative with 2 Loops (O(limit²))
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ways = 0;

        for (int x = 0; x <= limit; x++) {
            for (int y = 0; y <= limit; y++) {
                int z = n - x - y;
                if (z >= 0 && z <= limit) {
                    ways++;
                }
            }
        }

        return ways;
    }
};
//4. Optimized Approach (O(limit))
//Approach - Using maths distribution
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0;

        //child1
        int minCh1 = max(0, n - 2*limit);
        int maxCh1 = min(n, limit);

        for(int i = minCh1; i <= maxCh1; i++) { //fixing child1 assignment of candies

            int N = n-i; //for ch2 and ch3

            int minCh2 = max(0, N - limit);
            int maxCh2 = min(N, limit);

            ways += maxCh2 - minCh2 + 1;
        }

        return ways;
    }
};

