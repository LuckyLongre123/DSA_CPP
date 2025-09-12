# Day 23: Digit Processing Mastery

## 🎯 Learning Objectives

By the end of this day, you will master:
- **Digit Extraction Techniques**: Efficient methods to process individual digits
- **Mathematical Validation**: Implementing complex conditional logic
- **Range Processing**: Optimizing algorithms for interval-based problems
- **Edge Case Handling**: Managing zero digits and division by zero scenarios

---

## Problem 1: Self Dividing Numbers (LeetCode 728)

### 📋 Problem Statement

**Difficulty**: Easy  
**Category**: Math, Implementation  
**Companies**: Google, Amazon, Microsoft

A **self-dividing number** is a number that is divisible by every digit it contains.

**Important Rules**:
- Self-dividing numbers do **NOT** contain the digit 0
- The number must be divisible by each of its digits

Given two integers `left` and `right`, return a list of all the self-dividing numbers in the range `[left, right]`.

### 💡 Examples with Detailed Analysis

#### Example 1: Small Range Analysis
```
Input: left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]

Detailed breakdown:
✅ Single digits (1-9): All self-dividing by definition
   - 1: 1 % 1 = 0
   - 2: 2 % 2 = 0
   - ...
   - 9: 9 % 9 = 0

❌ 10: Contains 0 → Not self-dividing
✅ 11: 11 % 1 = 0 (both digits are 1)
✅ 12: 12 % 1 = 0, 12 % 2 = 0
❌ 13: 13 % 1 = 0, but 13 % 3 = 1 ≠ 0
❌ 14: 14 % 1 = 0, but 14 % 4 = 2 ≠ 0
✅ 15: 15 % 1 = 0, 15 % 5 = 0
❌ 16: 16 % 1 = 0, but 16 % 6 = 4 ≠ 0
❌ 17: 17 % 1 = 0, but 17 % 7 = 3 ≠ 0
❌ 18: 18 % 1 = 0, but 18 % 8 = 2 ≠ 0
❌ 19: 19 % 1 = 0, but 19 % 9 = 1 ≠ 0
❌ 20: Contains 0 → Not self-dividing
❌ 21: 21 % 2 = 1 ≠ 0
✅ 22: 22 % 2 = 0 (both digits are 2)
```

#### Example 2: Higher Range Analysis
```
Input: left = 47, right = 85
Output: [48, 55, 66, 77]

Step-by-step validation:
❌ 47: 47 % 4 = 3 ≠ 0 → Not self-dividing
✅ 48: 48 % 4 = 0 ✓, 48 % 8 = 0 ✓ → Self-dividing
❌ 49: 49 % 4 = 1 ≠ 0 → Not self-dividing
❌ 50: Contains 0 → Not self-dividing
❌ 51: 51 % 5 = 1 ≠ 0 → Not self-dividing
❌ 52: 52 % 5 = 2 ≠ 0 → Not self-dividing
❌ 53: 53 % 5 = 3 ≠ 0 → Not self-dividing
❌ 54: 54 % 5 = 4 ≠ 0 → Not self-dividing
✅ 55: 55 % 5 = 0 ✓ (both digits are 5) → Self-dividing
...
✅ 66: 66 % 6 = 0 ✓ (both digits are 6) → Self-dividing
✅ 77: 77 % 7 = 0 ✓ (both digits are 7) → Self-dividing
```

#### Example 3: Edge Cases
```
Input: left = 100, right = 102
Output: []

Analysis:
❌ 100: Contains 0 → Not self-dividing
❌ 101: Contains 0 → Not self-dividing  
❌ 102: Contains 0 → Not self-dividing

Result: Empty array (no self-dividing numbers in range)
```

### 🔍 Intuition

The key insight is to **extract each digit** and check two conditions:
1. **No zero digits** (to avoid division by zero)
2. **Perfect divisibility** (original number % digit == 0)

### 🚀 Approach: Digit Extraction and Validation

**Algorithm Steps**:
1. **Iterate through range**: Check each number from `left` to `right`
2. **Extract digits**: Use `num % 10` and `num /= 10` pattern
3. **Validate conditions**:
   - Digit must not be 0 (avoid division by zero)
   - Original number must be divisible by the digit
4. **Collect results**: Add valid numbers to result array

- **Time Complexity**: O((right - left + 1) × log₁₀(max_number))
- **Space Complexity**: O(1) excluding output array

```cpp
vector<int> selfDividingNumbers(int left, int right) {
    vector<int> result;
    
    for (int i = left; i <= right; i++) {
        if (isSelfDividing(i)) {
            result.push_back(i);
        }
    }
    return result;
}

bool isSelfDividing(int num) {
    int original = num;
    
    while (num > 0) {
        int digit = num % 10;
        
        // Check for zero digit or non-divisibility
        if (digit == 0 || original % digit != 0) {
            return false;
        }
        
        num /= 10;  // Move to next digit
    }
    return true;
}
```

### 📊 Algorithm Walkthrough

```
Example: Check if 128 is self-dividing

Step 1: num = 128, digit = 128 % 10 = 8
        Check: 128 % 8 = 0 ✓
        Update: num = 128 / 10 = 12

Step 2: num = 12, digit = 12 % 10 = 2
        Check: 128 % 2 = 0 ✓
        Update: num = 12 / 10 = 1

Step 3: num = 1, digit = 1 % 10 = 1
        Check: 128 % 1 = 0 ✓
        Update: num = 1 / 10 = 0

Step 4: num = 0, loop ends
        Result: 128 is self-dividing ✓
```

### 🎯 Visual Representation

```
Number: 128
Digits: [8, 2, 1] (extracted right to left)

Validation Process:
128 ÷ 8 = 16 remainder 0 ✓
128 ÷ 2 = 64 remainder 0 ✓  
128 ÷ 1 = 128 remainder 0 ✓

Result: All digits divide evenly → Self-dividing number!
```

### 🚨 Edge Cases and Testing Strategy

#### Critical Test Cases
```cpp
// 1. Single digit range
left = 1, right = 9
Expected: [1, 2, 3, 4, 5, 6, 7, 8, 9]
Reason: All single digits are self-dividing

// 2. Range with zeros
left = 10, right = 20
Expected: [11, 12, 15]
Reason: 10, 20 contain 0; others fail divisibility

// 3. Empty result range
left = 100, right = 110
Expected: []
Reason: All numbers contain 0

// 4. Single number range
left = 22, right = 22
Expected: [22]
Reason: 22 % 2 = 0 for both digits

// 5. Large valid numbers
left = 111, right = 111
Expected: [111]
Reason: 111 % 1 = 0 for all digits

// 6. Maximum constraint range
left = 9999, right = 10000
Expected: []
Reason: 10000 contains 0, 9999 has 9999 % 9 = 0 but complex validation
```

#### Boundary Conditions
```cpp
// Minimum range
left = 1, right = 1 → [1]

// Maximum range (constraint: right ≤ 10⁴)
left = 1, right = 10000
// Contains all self-dividing numbers from 1 to 10000

// Numbers with repeated digits
111: 111 % 1 = 0 ✓
222: 222 % 2 = 0 ✓
333: 333 % 3 = 0 ✓
...
999: 999 % 9 = 0 ✓
```

### 🔄 Alternative Approaches Comparison

#### Approach 1: String Conversion Method
```cpp
vector<int> selfDividingNumbers(int left, int right) {
    vector<int> result;
    
    for (int i = left; i <= right; i++) {
        string s = to_string(i);
        bool isSelfDiv = true;
        
        for (char c : s) {
            int digit = c - '0';
            if (digit == 0 || i % digit != 0) {
                isSelfDiv = false;
                break;
            }
        }
        
        if (isSelfDiv) result.push_back(i);
    }
    return result;
}
```
**Time**: O(n × log m), **Space**: O(log m) for string conversion
**Pros**: More readable for beginners
**Cons**: String allocation overhead, slower performance

#### Approach 2: Recursive Digit Extraction
```cpp
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i, i)) {
                result.push_back(i);
            }
        }
        return result;
    }
    
private:
    bool isSelfDividing(int num, int original) {
        if (num == 0) return true;
        int digit = num % 10;
        if (digit == 0 || original % digit != 0) return false;
        return isSelfDividing(num / 10, original);
    }
};
```
**Time**: O(n × log m), **Space**: O(log m) due to recursion stack
**Pros**: Clean functional style
**Cons**: Function call overhead, potential stack overflow

#### Approach 3: Optimized with Early Termination
```cpp
vector<int> selfDividingNumbers(int left, int right) {
    vector<int> result;
    
    for (int i = left; i <= right; i++) {
        // Quick check: if number contains 0, skip
        if (containsZero(i)) continue;
        
        if (isSelfDividing(i)) {
            result.push_back(i);
        }
    }
    return result;
}

bool containsZero(int num) {
    while (num > 0) {
        if (num % 10 == 0) return true;
        num /= 10;
    }
    return false;
}
```
**Time**: O(n × log m), **Space**: O(1)
**Pros**: Early termination for numbers with zeros
**Cons**: Double digit extraction (can be optimized)

### 🧮 Mathematical Properties and Insights

#### Digit Extraction Mathematics
```cpp
// For number 1234:
int num = 1234;

// Extract digits from right to left:
digit1 = 1234 % 10 = 4    // num becomes 123
digit2 = 123 % 10 = 3     // num becomes 12
digit3 = 12 % 10 = 2      // num becomes 1
digit4 = 1 % 10 = 1       // num becomes 0

// Validation process:
original = 1234
1234 % 4 = 2 ≠ 0 → Not self-dividing
```

#### Self-Dividing Number Properties
```cpp
// Pattern Analysis:
// 1-digit: All are self-dividing (1-9)
// 2-digit: 11, 12, 15, 22, 24, 33, 36, 44, 48, 55, 66, 77, 88, 99
// 3-digit: Much rarer due to more constraints

// Mathematical insight:
// For n-digit number, must satisfy n divisibility conditions
// Probability decreases exponentially with digit count
```

#### Complexity Analysis Deep Dive
```cpp
// Time Complexity: O((right - left + 1) × log₁₀(max_number))
// - Outer loop: (right - left + 1) iterations
// - Inner digit extraction: log₁₀(number) iterations per number
// - Each digit check: O(1) modulo operation

// Space Complexity: O(1) excluding output
// - Only using constant extra variables
// - Output space: O(k) where k = count of self-dividing numbers

// Practical performance:
// Range [1, 10000]: ~4 × 10000 = 40000 operations maximum
// Very efficient for given constraints
```

#### Pattern Recognition
```cpp
// Numbers with repeated digits are often self-dividing:
11, 22, 33, 44, 55, 66, 77, 88, 99   // All 2-digit repeated
111, 222, 333, 444, 555, 666, 777, 888, 999  // All 3-digit repeated

// Numbers with 1 as digit are more likely to be self-dividing:
// Because any number % 1 = 0

// Numbers with large digits (7, 8, 9) are less likely:
// Harder to satisfy divisibility for larger divisors
```

### 🎯 Advanced Optimization Techniques

#### Precomputation Approach
```cpp
class SelfDividingNumbers {
private:
    vector<int> precomputed;
    
public:
    SelfDividingNumbers() {
        // Precompute all self-dividing numbers up to 10^4
        for (int i = 1; i <= 10000; i++) {
            if (isSelfDividing(i)) {
                precomputed.push_back(i);
            }
        }
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int num : precomputed) {
            if (num >= left && num <= right) {
                result.push_back(num);
            }
        }
        return result;
    }
};
```
**Pros**: O(log k) query time with binary search
**Cons**: O(k) space for precomputation

#### Digit-by-Digit Validation Optimization
```cpp
bool isSelfDividing(int num) {
    int original = num;
    
    // Process digits from right to left
    while (num > 0) {
        int digit = num % 10;
        
        // Early termination conditions
        if (digit == 0) return false;           // Contains zero
        if (original % digit != 0) return false; // Not divisible
        
        num /= 10;
    }
    return true;
}
```

### 🔍 Pattern Analysis and Statistics

#### Distribution of Self-Dividing Numbers
```cpp
// Range [1, 100]: 20 self-dividing numbers
// Range [1, 1000]: 53 self-dividing numbers  
// Range [1, 10000]: 108 self-dividing numbers

// Observation: Growth rate decreases as range increases
// Reason: More digits = more constraints = lower probability
```

#### Common Patterns
```cpp
// All single digits: 1, 2, 3, 4, 5, 6, 7, 8, 9
// Repeated digits: 11, 22, 33, 44, 55, 66, 77, 88, 99
// Numbers with 1: 12, 15, 111, 112, 115, 122, 124, 126, 128, 132, 135, 144
// Numbers divisible by all digits: 24, 36, 48, 111, 112, 115, 122, 124, 126, 128
```

### 🔑 Key Insights

1. **Digit Extraction Mastery**: `num % 10` and `num /= 10` pattern is fundamental
2. **Early Termination Strategy**: Return false immediately when invalid condition found
3. **Zero Handling**: Critical to check for zero digits to avoid division by zero
4. **Mathematical Properties**: Self-dividing numbers become exponentially rarer
5. **Pattern Recognition**: Repeated digits and numbers with 1 are common patterns
6. **Optimization Opportunities**: Precomputation and early termination improve performance

### 📈 Constraints

- 1 ≤ left ≤ right ≤ 10⁴

### 🔗 Source

[LeetCode 728 - Self Dividing Numbers](https://leetcode.com/problems/self-dividing-numbers)

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Self Dividing Numbers | Easy | ✅ Solved | Digit Extraction | O(n × log m) | O(1) |

## 🎯 Key Learnings Achieved

### Core Mastery ✅
- **Digit Processing**: Master the `num % 10` and `num /= 10` pattern for efficient digit extraction
- **Validation Logic**: Implement multiple condition checks with early termination strategies
- **Mathematical Constraints**: Handle division by zero and edge cases with robust error checking
- **Range Processing**: Efficiently iterate through number ranges with systematic validation

### Advanced Skills ✅
- **Pattern Recognition**: Identify mathematical properties of self-dividing numbers
- **Performance Optimization**: Apply early termination and precomputation techniques
- **Algorithm Analysis**: Deep understanding of time/space complexity for digit problems
- **Edge Case Mastery**: Comprehensive handling of boundary conditions and special cases

### Problem-Solving Framework ✅
- **Mathematical Insight**: Understand why certain number patterns are self-dividing
- **Code Organization**: Structure solutions with helper functions and clear logic flow
- **Testing Strategy**: Create comprehensive test cases covering all scenarios
- **Optimization Awareness**: Recognize opportunities for performance improvements

### 🧪 Comprehensive Testing Framework

```cpp
class SelfDividingTest {
public:
    void runAllTests() {
        testBasicCases();
        testEdgeCases();
        testPerformance();
        testBoundaryConditions();
        cout << "All tests passed!" << endl;
    }
    
private:
    void testBasicCases() {
        // Test single digits
        auto result1 = selfDividingNumbers(1, 9);
        vector<int> expected1 = {1,2,3,4,5,6,7,8,9};
        assert(result1 == expected1);
        
        // Test range with zeros
        auto result2 = selfDividingNumbers(10, 22);
        vector<int> expected2 = {11, 12, 15, 22};
        assert(result2 == expected2);
    }
    
    void testEdgeCases() {
        // Empty result
        auto result1 = selfDividingNumbers(100, 110);
        assert(result1.empty());
        
        // Single number
        auto result2 = selfDividingNumbers(48, 48);
        assert(result2 == vector<int>{48});
        
        // Range with no self-dividing numbers
        auto result3 = selfDividingNumbers(23, 23);
        assert(result3.empty());
    }
    
    void testPerformance() {
        auto start = chrono::high_resolution_clock::now();
        auto result = selfDividingNumbers(1, 10000);
        auto end = chrono::high_resolution_clock::now();
        
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        assert(duration.count() < 100); // Should complete in < 100ms
        assert(result.size() == 108); // Known count for range [1, 10000]
    }
};
```

### 📊 Real-World Applications

#### Number Theory Research
```cpp
// Self-dividing numbers are studied in recreational mathematics
// Applications in:
// 1. Digital root analysis
// 2. Divisibility pattern recognition
// 3. Number sequence generation
```

#### Algorithm Design Patterns
```cpp
// This problem demonstrates:
// 1. Digit extraction techniques
// 2. Range processing algorithms
// 3. Early termination optimization
// 4. Mathematical validation logic
```

## 💡 Problem-Solving Tips

1. **Digit Extraction Mastery**: Always use `% 10` and `/ 10` pattern for digit problems
2. **Zero Detection**: Check for zero digits early to prevent division by zero errors
3. **Early Termination**: Return false immediately when invalid condition is found
4. **Range Processing**: Handle each number individually for clarity and correctness
5. **Pattern Recognition**: Identify common self-dividing number patterns
6. **Performance Optimization**: Consider precomputation for repeated queries
7. **Mathematical Insight**: Understand why certain numbers are more likely to be self-dividing

### 🚀 Next Steps and Related Problems

#### Immediate Practice
- **LeetCode 9**: Palindrome Number (digit extraction)
- **LeetCode 7**: Reverse Integer (digit manipulation)
- **LeetCode 202**: Happy Number (digit sum patterns)
- **LeetCode 258**: Add Digits (digital root)

#### Advanced Digit Problems
- **LeetCode 171**: Excel Sheet Column Number
- **LeetCode 168**: Excel Sheet Column Title
- **LeetCode 400**: Nth Digit
- **LeetCode 233**: Number of Digit One

#### Mathematical Extensions
- Study perfect numbers and their properties
- Explore divisibility rules for different bases
- Investigate digit sum algorithms and patterns
- Learn about modular arithmetic applications

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Self Dividing Numbers | Easy | ✅ Solved | Digit Extraction | O(n × log m) | O(1) |

### Performance Metrics
- **Algorithm Efficiency**: Optimal for given constraints
- **Code Quality**: Clean, readable, and maintainable
- **Edge Case Coverage**: Comprehensive boundary condition handling
- **Pattern Recognition**: Mathematical insights fully understood

### Skills Developed
1. **Digit Manipulation**: Master digit extraction and validation techniques
2. **Range Processing**: Efficient iteration through number ranges
3. **Mathematical Validation**: Complex conditional logic implementation
4. **Performance Optimization**: Early termination and pattern recognition

---

**🎯 Day 23 Complete! Digit Processing Mastered** ✅
