# Day 12: Digit Manipulation and Array Indexing Mastery

## 🎯 Learning Objectives

By the end of this day, you will master:
- **Digit Extraction Techniques**: Using modulo and division for digit processing
- **Array Index Relationships**: Understanding index-value correlations
- **Mathematical Problem Solving**: Converting real-world constraints into code
- **Early Termination Optimization**: Returning immediately when conditions are met

---

## Problem 1: Find the Smallest Index Where Index Equals Sum of Digits (LeetCode 3550)

### 📋 Problem Statement

**Difficulty**: Easy  
**Category**: Array, Math, Digit Manipulation  
**Companies**: Various coding platforms

Given an array of integers `nums`, find the **smallest index** `i` such that `i` equals the sum of digits of `nums[i]`. Return the smallest such index, or `-1` if no such index exists.

### 🔍 Problem Analysis

**Core Requirement**: Find index `i` where `i == digitSum(nums[i])`

**Key Insights**:
- We need to check **index-value relationship**, not value-value
- **Digit sum** means adding all individual digits of a number
- Return the **smallest** such index (first occurrence)
- Return `-1` if no such relationship exists

### 📚 Examples with Detailed Analysis

#### Example 1: Finding Valid Index
```
Input: nums = [10, 1, 2, 3, 4, 5]
Output: 1

Step-by-step analysis:
Index 0: nums[0] = 10, digitSum(10) = 1+0 = 1, 0 ≠ 1 
Index 1: nums[1] = 1,  digitSum(1) = 1,     1 == 1 
Index 2: nums[2] = 2,  digitSum(2) = 2,     2 == 2 
Index 3: nums[3] = 3,  digitSum(3) = 3,     3 == 3 
Index 4: nums[4] = 4,  digitSum(4) = 4,     4 == 4 
Index 5: nums[5] = 5,  digitSum(5) = 5,     5 == 5 

Wait! Let me recalculate correctly:
Index 1: 1 == digitSum(1) = 1 → This should be the answer!

Actual Output: 1 (smallest valid index)
```

#### Example 2: Multi-digit Numbers
```
Input: nums = [12, 34, 5, 67]
Output: 2

Step-by-step analysis:
Index 0: nums[0] = 12, digitSum(12) = 1+2 = 3,  0 ≠ 3 
Index 1: nums[1] = 34, digitSum(34) = 3+4 = 7,  1 ≠ 7 
Index 2: nums[2] = 5,  digitSum(5) = 5,         2 ≠ 5 
Index 3: nums[3] = 67, digitSum(67) = 6+7 = 13, 3 ≠ 13 

Actual Output: -1 (no valid index found)
```

#### Example 3: No Valid Index
```
Input: nums = [99, 77, 33]
Output: -1

Step-by-step analysis:
Index 0: nums[0] = 99, digitSum(99) = 9+9 = 18, 0 ≠ 18 
Index 1: nums[1] = 77, digitSum(77) = 7+7 = 14, 1 ≠ 14 
Index 2: nums[2] = 33, digitSum(33) = 3+3 = 6,  2 ≠ 6 

Result: No index satisfies the condition
```

#### Example 4: Edge Cases
```
Input: nums = [0, 1, 2, 3]
Output: 1

Analysis:
Index 0: nums[0] = 0, digitSum(0) = 0, 0 == 0 
Index 1: nums[1] = 1, digitSum(1) = 1, 1 == 1 

Return: 0 (smallest valid index)
```

### 🔄 Solution Approach

#### Linear Search with Digit Sum Calculation

**💡 Core Idea**: Check each index sequentially and calculate digit sum for comparison

**📊 Complexity Analysis**:
- **Time Complexity**: O(n × d) where n = array length, d = average digits per number
- **Space Complexity**: O(1) - only using variables for calculation

**🔍 Algorithm Steps**:
1. **Iterate**: Loop through each index `i` from 0 to n-1
2. **Extract Digits**: Calculate sum of digits of `nums[i]`
3. **Compare**: Check if `i == digitSum(nums[i])`
4. **Early Return**: Return `i` immediately if condition met (ensures smallest index)
5. **No Match**: Return -1 if loop completes without finding match

**🎯 Why Linear Search?**
- **Sequential Check**: Must check from index 0 to ensure "smallest" index
- **Early Termination**: Can return immediately when first match found
- **Simple Logic**: Straightforward implementation without complex data structures

```cpp
int smallestIndex(vector<int>& nums) {
    // Iterate through each index to find the smallest valid one
    for(int i = 0; i < nums.size(); i++){
        int temp = nums[i];  // Copy value to avoid modifying original
        int sum = 0;         // Initialize digit sum
        
        // Calculate sum of digits using digit extraction
        while(temp != 0){
            sum += temp % 10;  // Extract and add last digit
            temp /= 10;        // Remove last digit by integer division
        }
        
        // Check if current index equals digit sum
        if(i == sum) {
            return i;  // Found! Return immediately (smallest index)
        }
    }
    
    return -1;  // No valid index found
}
```

### 🔬 Digit Extraction Deep Dive

**How Digit Extraction Works**:
```cpp
// Example: Extract digits from 1234
int num = 1234;
int digitSum = 0;

// Step 1: num = 1234
digitSum += num % 10;  // 1234 % 10 = 4, sum = 4
num /= 10;             // 1234 / 10 = 123

// Step 2: num = 123  
digitSum += num % 10;  // 123 % 10 = 3, sum = 7
num /= 10;             // 123 / 10 = 12

// Step 3: num = 12
digitSum += num % 10;  // 12 % 10 = 2, sum = 9
num /= 10;             // 12 / 10 = 1

// Step 4: num = 1
digitSum += num % 10;  // 1 % 10 = 1, sum = 10
num /= 10;             // 1 / 10 = 0 (loop ends)

// Final: digitSum = 4+3+2+1 = 10
```

**Visual Representation**:
```
Number: 1234
        ↓
   ┌────┴────┐
   │ Extract │
   │ Digits  │
   └────┬────┘
        ↓
   1 + 2 + 3 + 4 = 10
```

### 🎯 Key Learning Points

#### 1. **Digit Extraction Mastery** 🔢

**The Modulo-Division Pattern**:
```cpp
// Universal digit extraction template
while(number > 0) {
    int digit = number % 10;    // Extract rightmost digit
    // Process digit here (sum, product, check, etc.)
    number /= 10;               // Remove rightmost digit
}
```

**Applications**:
- Digit sum (this problem)
- Digit product
- Reverse number
- Check palindrome
- Count specific digits

#### 2. **Index-Value Relationships** 📊

**Pattern Recognition**:
```cpp
// General template for index-value problems
for(int i = 0; i < array.size(); i++) {
    if(i == someFunction(array[i])) {
        return i;  // Found relationship
    }
}
return -1;  // No relationship found
```

**Similar Problems**:
- Find index where index equals value
- Find index where index equals sum of digits
- Find index where index equals number of factors

#### 3. **Early Termination Strategy** ⚡

**Why It Matters**:
```cpp
// Efficient: O(k) where k is position of first match
for(int i = 0; i < n; i++) {
    if(condition) return i;
}

// Inefficient: Always O(n)
vector<int> results;
for(int i = 0; i < n; i++) {
    if(condition) results.push_back(i);
}
return results.empty() ? -1 : results[0];
```

#### 4. **Mathematical Properties** 🧮

**Digit Sum Bounds**:
```cpp
For k-digit number:
- Minimum digit sum: 1 (e.g., 1000...0)
- Maximum digit sum: 9×k (e.g., 999...9)

For array indices 0 to n-1:
- Only numbers with digit sum ≤ n-1 can possibly match
- This creates natural pruning opportunities
```

### 📊 Comprehensive Digit Sum Examples

#### Basic Examples:
```
Number: 123 → Process: 3+2+1 → Sum: 6
Number: 45  → Process: 5+4   → Sum: 9  
Number: 7   → Process: 7     → Sum: 7
Number: 100 → Process: 0+0+1 → Sum: 1
```

#### Step-by-Step Breakdown:
```
Calculating digitSum(456):

Step 1: num=456, digit=456%10=6, sum=0+6=6,  num=456/10=45
Step 2: num=45,  digit=45%10=5,  sum=6+5=11, num=45/10=4  
Step 3: num=4,   digit=4%10=4,   sum=11+4=15, num=4/10=0
Step 4: num=0 → Stop

Final: digitSum(456) = 15
```

#### Edge Cases:
```
digitSum(0)    = 0     // Special: while loop never executes
digitSum(1)    = 1     // Single digit
digitSum(10)   = 1     // Trailing zeros
digitSum(999)  = 27    // All same digits
digitSum(1001) = 2     // Mixed zeros
```

### 📏 Constraints and Implications

**Given Constraints:**
- `1 ≤ nums.length ≤ 100`
- `0 ≤ nums[i] ≤ 1000`

**Constraint Analysis:**
```
Array Length: 1-100
→ Maximum possible index: 99
→ Need digit sum ≤ 99 for any match

Number Range: 0-1000  
→ Maximum digit sum: digitSum(999) = 27
→ All numbers in range can potentially match some index

Digit Count: 1-4 digits per number
→ Very fast digit extraction (at most 4 iterations)
```

**Performance Implications:**
```
Worst Case: 100 elements × 4 digits = 400 operations
→ Extremely fast execution
→ No need for advanced optimizations
→ Simple approach is perfectly efficient
```

### 🔗 Source

[LeetCode 3550 - Find the Smallest Index Where Index Equals Sum of Digits](https://leetcode.com/problems/find-the-smallest-index-where-index-equals-sum-of-digits)

---

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Find Smallest Index | Easy | Solved | Linear Search + Digit Sum | O(n × d) | O(1) |

## 🎯 Key Learnings

1. **Digit Manipulation**: Extracting and summing digits using modulo and division operations
2. **Array Indexing**: Matching array indices with calculated values
3. **Early Return**: Returning immediately when condition is met to find smallest index
4. **Mathematical Operations**: Understanding how to break down numbers into individual digits

## 🚀 Next Steps

- Practice more digit manipulation problems
- Explore problems involving number properties and array indexing
- Learn about more efficient digit sum calculation methods
- Focus on mathematical problem-solving patterns

## 💡 Problem-Solving Tips

1. **Break Down Numbers**: Use `% 10` and `/ 10` to process digits
2. **Index Awareness**: Remember that array indices start from 0
3. **Early Termination**: Return as soon as the first valid condition is met
4. **Edge Case Testing**: Test with single digits, multi-digits, and edge values

### 📊 Detailed Complexity Analysis

#### Time Complexity: O(n × d)
**Breakdown**:
- **n**: Length of input array (number of elements to check)
- **d**: Average number of digits per number
- **Per Element**: O(d) time to extract and sum digits
- **Total**: O(n) elements × O(d) digits = O(n × d)

**Digit Count Analysis**:
```cpp
Number Range | Digits | Time per Element
    1-9      |   1    |      O(1)
   10-99     |   2    |      O(2)
  100-999    |   3    |      O(3)
 1000-9999   |   4    |      O(4)
```

**Real-world Performance**:
```cpp
Array Size | Max Number | Time Complexity
   100     |    999     |   O(100 × 3) = O(300)
  1000     |   9999     |   O(1000 × 4) = O(4000)
 10000     |  99999     |   O(10000 × 5) = O(50000)
```

#### Space Complexity: O(1)
**Space Usage**:
- **Variables**: `i`, `temp`, `sum` - constant space
- **No Arrays**: No additional data structures needed
- **In-place**: Only reading from input array, not modifying

### 🔄 Alternative Approaches

#### Approach 1: String Conversion Method

**💡 Core Idea**: Convert number to string and process each character

```cpp
int smallestIndex(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++) {
        string numStr = to_string(nums[i]);
        int digitSum = 0;
        
        // Sum digits by converting chars back to integers
        for(char c : numStr) {
            digitSum += (c - '0');  // Convert char to digit
        }
        
        if(i == digitSum) return i;
    }
    return -1;
}
```

**📊 Complexity**: O(n × d) time, O(d) space per number
**Pros**: More readable for beginners
**Cons**: Extra string allocation overhead

#### Approach 2: Recursive Digit Extraction

**💡 Core Idea**: Use recursion for digit sum calculation

```cpp
class Solution {
public:
    int digitSum(int num) {
        if(num == 0) return 0;
        return (num % 10) + digitSum(num / 10);
    }
    
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(i == digitSum(nums[i])) {
                return i;
            }
        }
        return -1;
    }
};
```

**📊 Complexity**: O(n × d) time, O(d) space (recursion stack)
**Pros**: Clean separation of concerns
**Cons**: Function call overhead, stack space usage

#### Approach 3: Mathematical Formula (Advanced)

**💡 Core Idea**: Use mathematical properties to calculate digit sum

```cpp
int digitSum(int num) {
    if(num == 0) return 0;
    return 1 + (num - 1) % 9;  // Mathematical digit sum property
}
```

**⚠️ Note**: This gives digital root, not actual digit sum - different problem!

**Why This Works**:
- **Modulo 10**: Always gives the last digit (1234 % 10 = 4)
- **Integer Division by 10**: Removes last digit (1234 / 10 = 123)
- **Termination**: Continues until number becomes 0

### 🎓 Learning Objectives Achieved

#### ✅ **Digit Manipulation Mastery**
- **Modulo Operation**: Extract individual digits efficiently
- **Integer Division**: Remove digits systematically  
- **Loop Patterns**: Process all digits until number becomes 0
- **Edge Cases**: Handle zero and single-digit numbers correctly

#### ✅ **Array-Index Problem Solving**
- **Relationship Identification**: Understand index-value correlations
- **Sequential Processing**: Check indices in order for "smallest" requirement
- **Early Termination**: Return immediately when condition met
- **Boundary Handling**: Manage array bounds and invalid cases

#### ✅ **Algorithm Optimization**
- **Time Complexity**: Analyze nested operations (array × digits)
- **Space Efficiency**: Achieve O(1) space with careful variable usage
- **Performance Awareness**: Understand when different approaches are better

#### ✅ **Problem Analysis Skills**
- **Requirement Parsing**: Break down complex problem statements
- **Example Tracing**: Manually verify algorithm correctness
- **Edge Case Identification**: Anticipate boundary conditions
- **Testing Strategy**: Design comprehensive test cases

### 🧪 Edge Cases and Testing

#### Critical Test Cases:

**1. Zero Handling**:
```cpp
nums = [0, 1, 2]  
// Index 0: 0 == digitSum(0) = 0 → Return 0
```

**2. Single Element**:
```cpp
nums = [5]
// Index 0: 0 == digitSum(5) = 5 → Return -1

nums = [0] 
// Index 0: 0 == digitSum(0) = 0 → Return 0
```

**3. All Invalid**:
```cpp
nums = [99, 88, 77]
// All digit sums > indices → Return -1
```

**4. Multiple Valid (Return Smallest)**:
```cpp
nums = [10, 1, 2, 3]
// Index 1: 1 == digitSum(1) = 1 
// Index 2: 2 == digitSum(2) = 2  
// Index 3: 3 == digitSum(3) = 3 
// Return 1 (smallest)
```

**5. Large Numbers**:
```cpp
nums = [123456, 78910, 15]  // Index 2: 2 ≠ digitSum(15) = 6
```

#### Boundary Conditions:
```cpp
// Minimum array size
nums = [0] → Expected: 0

// Maximum reasonable index
nums = [0,1,2,3,4,5,6,7,8,9,55] → Expected: 0
//      Index 10: 10 ≠ digitSum(55) = 10... wait!
//      Actually: 10 == 10 → But need to check from start
