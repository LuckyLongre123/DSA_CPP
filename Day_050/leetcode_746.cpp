/**
 * ================================================================================
 * LeetCode 746: Min Cost Climbing Stairs
 * ================================================================================
 * 
 * ! Problem: You are given an integer array `cost` where cost[i] is the cost of 
 * ! ith step on a staircase. Once you pay the cost, you can either climb one or 
 * ! two steps. You can either start from the step with index 0, or the step with 
 * ! index 1. Return the minimum cost to reach the top of the floor.
 * 
 * * Approach:
 * * 1. Initialize two variables to track costs at previous positions
 * * 2. Start from index 0 and 1 (we can begin at either step)
 * * 3. For each subsequent step, calculate minimum cost to reach it
 * * 4. At each step, we can arrive from either 1 or 2 steps back
 * * 5. Choose the path with minimum cost and add current step cost
 * * 6. Return minimum of last two positions (top is beyond last step)
 * 
 * ? Time Complexity: O(n) - Single pass through the array
 * ? Space Complexity: O(1) - Only two variables used (space-optimized DP)
 * 
 * TODO Key Insight: 
 * *    - This is a classic DP problem optimized for space
 * *    - We only need to track the last two steps, not the entire history
 * *    - The "top" is one step beyond the last index, reachable from either of last two steps
 * *    - Space optimization reduces O(n) space to O(1) without changing logic
 * 
 * * Optimizations: 
 * *    - Space-optimized DP using only two variables instead of an array
 * *    - Single forward pass eliminates need for recursion or backtracking
 * ================================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * Calculates minimum cost to climb stairs with variable step costs
     * @param cost Array where cost[i] is the cost of the ith step
     * @return Minimum cost to reach the top of the staircase
     */
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        // * Base cases: cost to reach step 0 and step 1
        int one = cost[0];  // * Minimum cost to reach step 0
        int two = cost[1];  // * Minimum cost to reach step 1
        
        // * Build up solution from step 2 onwards
        for (int i = 2; i < n; i++) {
            // ? Current step cost = cost[i] + minimum of (one step back OR two steps back)
            // ! This represents the optimal substructure of dynamic programming
            int current = cost[i] + min(one, two);
            
            // * Slide the window forward
            one = two;      // * What was "two steps back" is now "one step back"
            two = current;  // * Current position becomes "two steps back" for next iteration
        }
        
        // ! The top is one step beyond the last index
        // ? We can reach it from either the last step or second-to-last step
        return min(one, two);
    }
};

// ============================================================
// * TESTING SUITE - Verifies solution with various test cases
// ============================================================

/**
 * Helper function to print test result
 */
void printTestResult(vector<int>& cost, int result, int expected, int testNum) {
    cout << "\n=== Test Case " << testNum << " ===\n";
    cout << "Cost array: [";
    for (int i = 0; i < cost.size(); i++) {
        cout << cost[i];
        if (i < cost.size() - 1) cout << ", ";
    }
    cout << "]\n";
    cout << "   Result:   " << result << "\n";
    cout << "   Expected: " << expected << "\n";
    cout << "   Status:   " << (result == expected ? "✅ PASS" : "❌ FAIL");
    if (result != expected) {
        cout << " (Expected: " << expected << ")";
    }
    cout << "\n";
}

int main() {
    Solution solution;
    int testNum = 1;
    
    // * Test Case 1: Example from problem statement
    {
        vector<int> cost = {10, 15, 20};
        int result = solution.minCostClimbingStairs(cost);
        printTestResult(cost, result, 15, testNum++);
        // ? Explanation: Start at index 1, pay 15, climb two steps to top
    }
    
    // * Test Case 2: Longer staircase
    {
        vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
        int result = solution.minCostClimbingStairs(cost);
        printTestResult(cost, result, 6, testNum++);
        // ? Optimal path: 0→2→3→4→6→7→9→top (costs: 1+1+1+1+1+1=6)
    }
    
    // * Test Case 3: Two steps only
    {
        vector<int> cost = {1, 2};
        int result = solution.minCostClimbingStairs(cost);
        printTestResult(cost, result, 1, testNum++);
        // ? Start at index 0, climb two steps to top (cost: 1)
    }
    
    // * Test Case 4: All same costs
    {
        vector<int> cost = {5, 5, 5, 5, 5};
        int result = solution.minCostClimbingStairs(cost);
        printTestResult(cost, result, 10, testNum++);
        // ? Taking 2-step jumps is optimal: 0→2→4→top (costs: 5+5=10)
    }
    
    // * Test Case 5: Increasing costs
    {
        vector<int> cost = {1, 2, 3, 4, 5};
        int result = solution.minCostClimbingStairs(cost);
        printTestResult(cost, result, 6, testNum++);
        // ? Path: 0→2→4→top (costs: 1+3+2=6) OR 1→3→top (costs: 2+4=6)
    }
    
    // ! Test Case 6: High cost at start
    {
        vector<int> cost = {100, 1, 1, 1};
        int result = solution.minCostClimbingStairs(cost);
        printTestResult(cost, result, 2, testNum++);
        // ? Start at index 1 to avoid high initial cost: 1→2→3→top (1+1=2)
    }
    
    // * Test Case 7: Alternating high-low costs
    {
        vector<int> cost = {10, 1, 10, 1, 10, 1, 10};
        int result = solution.minCostClimbingStairs(cost);
        printTestResult(cost, result, 4, testNum++);
        // ? Take all low-cost steps: 1→3→5→top (costs: 1+1+1+1=4)
    }
    
    // * Test Case 8: Single high cost in middle
    {
        vector<int> cost = {1, 1, 100, 1, 1};
        int result = solution.minCostClimbingStairs(cost);
        printTestResult(cost, result, 3, testNum++);
        // ? Skip the expensive middle step: 0→1→3→4→top (1+1+1=3)
    }
    
    return 0;
}

/*
 * ================================================================================
 * TODO Additional Notes:
 * * - This solution uses space-optimized dynamic programming (O(1) space)
 * ! - The key insight is that we only need the last two values, not entire DP array
 * * - Starting position choice (index 0 or 1) is handled implicitly in the algorithm
 * ? - For larger inputs, this space optimization is crucial for memory efficiency
 * * - The sliding window technique (one, two variables) is a common DP optimization
 * ! - "Top of floor" means one position beyond the last index of the array
 * ================================================================================
 */