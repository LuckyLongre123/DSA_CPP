
/**
 * ================================================================================
 * 🔄 LeetCode 1910: Remove All Occurrences of a Substring
 * ================================================================================
 * 
 * 🎯 Problem: Given two strings s and part, remove **all occurrences** of part 
 * from s and return the resulting string.
 * 
 * 📝 Examples:
 * Input:  s = "daabcbaabcbc", part = "abc" → Output: "dab"
 * Input:  s = "axxxxyyyyb", part = "xy"   → Output: "ab"
 * 
 * 📝 Approach: Iterative Search & Remove
 * 1. Use string::find() to locate the first occurrence of "part" in s
 * 2. If found, remove it using string::erase()
 * 3. Repeat until no more occurrences exist
 * 4. Return the modified string
 * 
 * ⚡ Time Complexity: O(n * m * k) where n=|s|, m=|part|, k=occurrences
 * 💾 Space Complexity: O(1) - In-place modification
 * 
 * 🧠 Key Insight: 
 *    - After each removal, we restart the search from the beginning
 *    - This handles cases where removal creates new occurrences
 * 
 * 🚀 Optimizations: 
 *    - In-place string modification
 *    - Early termination when no occurrences found
 * ================================================================================
 */

 class SolutionRemove {
    public:
        //! MAIN FUNCTION: Removes all occurrences of a substring
        //! @param s The main string to process
        //! @param part The substring to remove
        //! @return Modified string with all occurrences removed
        string removeOccurrences(string s, string part) {
            // Step 1: Find first occurrence of 'part' in s
            size_t pos = s.find(part);
    
            // Step 2: Loop until no more occurrences are found
            while (pos != string::npos) {
                //? Remove substring starting at 'pos' of length 'part.size()'
                s.erase(pos, part.size());
    
                //? Search again from beginning (handles cascading removals)
                pos = s.find(part);
            }
    
            // Step 3: Return the modified string
            return s;
        }
        
        //! ALTERNATIVE: Stack-based approach (more efficient for certain cases)
        //! Time: O(n), Space: O(n)
        string removeOccurrencesStack(string s, string part) {
            string result = "";
            
            for (char c : s) {
                result += c;
                //? Check if the end of result matches 'part'
                if (result.size() >= part.size() && 
                    result.substr(result.size() - part.size()) == part) {
                    result.erase(result.size() - part.size());
                }
            }
            
            return result;
        }
    };
    
    // ============================================================
    // 🧪 TESTING SUITE - Verifies solutions with various test cases
    // ============================================================
    
    //! Helper function to print test results for Peak Index problem
    void printPeakTestResult(const vector<int>& arr, int result, int expected) {
        cout << "\n🔍 Input: arr = [";
        for (size_t i = 0; i < arr.size(); i++) {
            cout << arr[i];
            if (i != arr.size() - 1) cout << ", ";
        }
        cout << "]\n";
        
        cout << "   Peak Index: " << result << " (Value: " << arr[result] << ")\n";
        cout << "   Expected:   " << expected << " (Value: " << arr[expected] << ")\n";
        cout << "   Status:     " << (result == expected ? "✅ PASS" : "❌ FAIL");
        if (result != expected) {
            cout << " (Expected: " << expected << ")";
        }
        cout << "\n";
        
        // Print visual representation
        int max_val = *max_element(arr.begin(), arr.end());
        for (int i = max_val; i > 0; i--) {
            for (int num : arr) {
                cout << (num >= i ? "▲ " : "  ");
            }
            cout << "\n";
        }
        
        // Print indices
        for (size_t i = 0; i < arr.size(); i++) {
            cout << i << " ";
        }
        cout << "\n";
    }
    
    //! Helper function to print test results for Remove Occurrences problem
    void printRemoveTestResult(const string& original, const string& part, 
                              const string& result, const string& expected) {
        cout << "\n🔍 Input: s = \"" << original << "\", part = \"" << part << "\"\n";
        cout << "   Result:   \"" << result << "\"\n";
        cout << "   Expected: \"" << expected << "\"\n";
        cout << "   Status:   " << (result == expected ? "✅ PASS" : "❌ FAIL") << "\n";
    }
    
    int main() {
        cout << "================================================================================\n";
        cout << "🧪 TESTING LEETCODE 852: Peak Index in a Mountain Array\n";
        cout << "================================================================================\n";
        
        Solution peakSolution;
        
        // Test Case 1: Smallest possible mountain array
        {
            vector<int> arr = {0, 1, 0};
            int result = peakSolution.peakIndexInMountainArray(arr);
            printPeakTestResult(arr, result, 1);
        }
        
        // Test Case 2: Mountain array with peak at index 1
        {
            vector<int> arr = {0, 2, 1, 0};
            int result = peakSolution.peakIndexInMountainArray(arr);
            printPeakTestResult(arr, result, 1);
        }
        
        // Test Case 3: Mountain array with peak at index 1 (steep increase)
        {
            vector<int> arr = {0, 10, 5, 2};
            int result = peakSolution.peakIndexInMountainArray(arr);
            printPeakTestResult(arr, result, 1);
        }
        
        // Test Case 4: Larger mountain array with peak in the middle
        {
            vector<int> arr = {1, 3, 5, 8, 10, 12, 15, 12, 10, 8, 5, 3, 1};
            int result = peakSolution.peakIndexInMountainArray(arr);
            printPeakTestResult(arr, result, 6);
        }
        
        cout << "\n================================================================================\n";
        cout << "🧪 TESTING LEETCODE 1910: Remove All Occurrences of a Substring\n";
        cout << "================================================================================\n";
        
        SolutionRemove removeSolution;
        
        // Test Case 1: Basic removal
        {
            string s = "daabcbaabcbc", part = "abc";
            string result = removeSolution.removeOccurrences(s, part);
            printRemoveTestResult("daabcbaabcbc", part, result, "dab");
        }
        
        // Test Case 2: Multiple overlapping removals
        {
            string s = "axxxxyyyyb", part = "xy";
            string result = removeSolution.removeOccurrences(s, part);
            printRemoveTestResult("axxxxyyyyb", part, result, "ab");
        }
        
        // Test Case 3: Cascading removals
        {
            string s = "aababaab", part = "ab";
            string result = removeSolution.removeOccurrences(s, part);
            printRemoveTestResult("aababaab", part, result, "a");
        }
        
        // Test Case 4: No occurrences
        {
            string s = "hello", part = "xyz";
            string result = removeSolution.removeOccurrences(s, part);
            printRemoveTestResult("hello", part, result, "hello");
        }
        
        return 0;
    }
    
    /*
     * ================================================================================
     * 📝 Additional Notes:
     * 
     * LeetCode 852 (Peak Index):
     * - The solution assumes valid mountain array input as per problem constraints
     * - Binary search approach is optimal: O(log n) vs O(n) linear search
     * - The visual representation in tests helps understand the mountain structure
     * 
     * LeetCode 1910 (Remove Occurrences):
     * - The iterative approach handles cascading removals correctly
     * - Stack-based alternative can be more efficient for certain input patterns
     * - Both approaches modify the string in-place for space efficiency
     * 
     * General Improvements Made:
     * - Consistent formatting and documentation style
     * - Better separation between problems
     * - Enhanced test suite with clearer output
     * - Added alternative solutions for comparison
     * - Improved comments with consistent emoji usage
     * ================================================================================
     */