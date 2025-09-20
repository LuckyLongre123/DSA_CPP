# Day 34: String Compression - Two-Pointer In-Place Manipulation

## 🎯 Learning Objectives

By the end of this day, you will master:
- **Two-Pointer Technique**: Efficient in-place array manipulation with read/write pointers
- **Run-Length Encoding (RLE)**: Understanding and implementing string compression
- **In-Place Algorithms**: Modifying arrays without extra space (O(1) space complexity)
- **Character Array Processing**: Advanced techniques for working with character arrays
- **Multi-Digit Number Handling**: Converting counts to individual character digits
- **Edge Case Management**: Handling various input scenarios in array manipulation

---

## Problem: String Compression (LeetCode 443)

### 📋 Problem Statement

**Difficulty**: Medium  
**Category**: Array, Two Pointers, String  
**Companies**: Amazon, Microsoft, Google, Meta

Given an array of characters `chars`, compress it using the following algorithm:
- If the group's length is 1, append the character to the result.
- If the group's length is more than 1, append the character followed by the group's length.
- The compressed string should be stored in the input array.
- Return the new length of the array.

**Important Note**: The modification must be done **in-place** with O(1) extra space.

### 🔍 Problem Analysis

**Key Insights**:
- We need to compress consecutive identical characters
- Each group is replaced with character + count (if count > 1)
- Must modify the array in-place without extra space
- Return the new length of the compressed array

**Pattern Recognition**:
```
["a","a","b","b","c","c","c"]
Step 1: Process 'a' group (count=2) → Write 'a','2'
Step 2: Process 'b' group (count=2) → Write 'b','2'
Step 3: Process 'c' group (count=3) → Write 'c','3'
Final: ["a","2","b","2","c","3"] (length=6)
```

### 📚 Examples with Detailed Analysis

#### Example 1: Basic Compression
```
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters should be: ["a","2","b","2","c","3"]

Step-by-step process:
Initial: ["a","a","b","b","c","c","c"]
Process 'a' group: count=2 → write 'a','2' at positions 0,1
Process 'b' group: count=2 → write 'b','2' at positions 2,3
Process 'c' group: count=3 → write 'c','3' at positions 4,5

Final result: ["a","2","b","2","c","3"] (length=6)
```

#### Example 2: Single Character
```
Input: chars = ["a"]
Output: Return 1, and the first character should be: ["a"]

Explanation: Single character remains unchanged.
```

#### Example 3: Large Count Handling
```
Input: chars = ["a","b","b",...,"b"] (12 b's total)
Output: Return 4, and the first 4 characters should be: ["a","b","1","2"]

Explanation: 'a' remains as is, 12 'b's become 'b','1','2'.
```

### 🔄 Solution Approach: Two-Pointer In-Place Compression

#### 💡 Core Idea
Use two pointers to efficiently compress the array in-place:
- `read`: Traverses the array to count consecutive characters
- `write`: Writes the compressed result back to the same array

#### 📊 Complexity Analysis
- **Time Complexity**: O(n)
  - Single pass through the array
  - Each character is processed exactly once
- **Space Complexity**: O(1) - in-place modification

#### 🔍 Algorithm Steps
1. **Initialize**: Set `read` and `write` pointers to 0
2. **Count Groups**: For each character, count consecutive occurrences
3. **Write Character**: Place the character at `write` position
4. **Write Count**: If count > 1, convert to string and write each digit
5. **Continue**: Move to next group until array is processed
6. **Return**: Final `write` position as new array length

```cpp
int compress(vector<char>& chars) {
    int write = 0, read = 0;
    while (read < chars.size()) {
        char current = chars[read];
        int count = 0;
        
        // Count consecutive characters
        while (read < chars.size() && chars[read] == current) {
            read++;
            count++;
        }
        
        // Write character
        chars[write++] = current;
        
        // Write count if > 1
        if (count > 1) {
            for (char c : to_string(count)) {
                chars[write++] = c;
            }
        }
    }
    return write;
}
```

---

## 📚 Complete Guide to Two-Pointer Technique

### 1. Read/Write Pointer Pattern 👆👇

**Purpose**: Efficiently modify arrays in-place without extra space.

**Key Concepts**:
- **Read Pointer**: Traverses the original data
- **Write Pointer**: Builds the result in the same array
- **Invariant**: Write pointer never overtakes unprocessed read data

**Detailed Example**:
```cpp
vector<char> chars = {'a','a','b','b','c','c','c'};
//                    r                              (read starts at 0)
//                    w                              (write starts at 0)

// Process first group 'a'
char current = 'a';
int count = 0;
while (read < size && chars[read] == 'a') {
    read++;  // read moves: 0 -> 1 -> 2
    count++; // count: 1 -> 2
}
// Now: read=2, count=2

// Write compressed version
chars[write++] = 'a';  // write 'a' at position 0, write becomes 1
chars[write++] = '2';  // write '2' at position 1, write becomes 2

// Array now: ['a','2','b','b','c','c','c']
//                     w   r
```

**Important Notes**:
- Read pointer can move multiple positions per iteration
- Write pointer moves exactly once per character/digit written
- Final write position equals the new array length
- Original array elements beyond write position are ignored

### 2. `to_string()` Method for Count Conversion 🔢

**Purpose**: Converts integer counts to individual character digits for array storage.

**Syntax**: 
```cpp
string to_string(int value);
```

**Usage in Compression**:
```cpp
int count = 12;
string countStr = to_string(count);  // "12"
for (char c : countStr) {
    chars[write++] = c;  // Write '1', then '2'
}
```

**Important Notes**:
- Each digit becomes a separate character in the array
- For count=12: writes '1' and '2' as two separate elements
- Time complexity: O(log count) per conversion
- Essential for handling counts ≥ 10

---

## 🔬 Algorithm Deep Dive

### Visual Step-by-Step Execution

Let's trace through `chars = ["a","a","b","b","c","c","c"]`:

```
Initial State:
chars = ["a","a","b","b","c","c","c"]
         0   1   2   3   4   5   6    (indices)
read = 0, write = 0

Step 1: Process 'a' group
current = 'a', count = 0
read=0: chars[0]='a' → count=1, read=1
read=1: chars[1]='a' → count=2, read=2
read=2: chars[2]='b' ≠ 'a' → exit loop

Write 'a' at position 0: chars[0] = 'a', write=1
Write '2' at position 1: chars[1] = '2', write=2
chars = ["a","2","b","b","c","c","c"]
         w       r

Step 2: Process 'b' group  
current = 'b', count = 0
read=2: chars[2]='b' → count=1, read=3
read=3: chars[3]='b' → count=2, read=4
read=4: chars[4]='c' ≠ 'b' → exit loop

Write 'b' at position 2: chars[2] = 'b', write=3
Write '2' at position 3: chars[3] = '2', write=4
chars = ["a","2","b","2","c","c","c"]
                     w   r

Step 3: Process 'c' group
current = 'c', count = 0
read=4: chars[4]='c' → count=1, read=5
read=5: chars[5]='c' → count=2, read=6
read=6: chars[6]='c' → count=3, read=7
read=7: out of bounds → exit loop

Write 'c' at position 4: chars[4] = 'c', write=5
Write '3' at position 5: chars[5] = '3', write=6
chars = ["a","2","b","2","c","3","c"]
                         w

Final: return write = 6
```

---

## 🧪 Comprehensive Testing

### Test Cases with Expected Results

```cpp
// Test Case 1: Basic compression
compress(["a","a","b","b","c","c","c"]) → 6, ["a","2","b","2","c","3"]

// Test Case 2: Single character
compress(["a"]) → 1, ["a"]

// Test Case 3: No compression needed
compress(["a","b","c"]) → 3, ["a","b","c"]

// Test Case 4: All same characters
compress(["a","a","a","a","a"]) → 2, ["a","5"]

// Test Case 5: Double-digit counts
compress(["a"] + ["b"]*12) → 4, ["a","b","1","2"]

// Test Case 6: Large counts
compress(["a"]*100) → 4, ["a","1","0","0"]

// Test Case 7: Mixed single and multiple
compress(["a","b","b","c"]) → 4, ["a","b","2","c"]

// Test Case 8: Empty array
compress([]) → 0, []
```

### Edge Cases Analysis

#### 1. **Empty and Single Element**
```cpp
compress([])     → 0     ✅ Handle empty array
compress(["a"])  → 1     ✅ Single character unchanged
```

#### 2. **Count Boundary Cases**
```cpp
// Single occurrence (no count written)
compress(["a","b","c"]) → 3, ["a","b","c"]

// Exactly 10 occurrences (two digits)
compress(["a"]*10) → 3, ["a","1","0"]

// Large counts
compress(["a"]*999) → 4, ["a","9","9","9"]
```

---

## 📊 Alternative Approaches

### Approach 1: String Building (Not In-Place)
```cpp
int compress(vector<char>& chars) {
    string result;
    int i = 0;
    
    while (i < chars.size()) {
        char current = chars[i];
        int count = 1;
        
        while (i + 1 < chars.size() && chars[i + 1] == current) {
            i++;
            count++;
        }
        
        result += current;
        if (count > 1) {
            result += to_string(count);
        }
        i++;
    }
    
    // Copy back to original array
    for (int j = 0; j < result.size(); j++) {
        chars[j] = result[j];
    }
    
    return result.size();
}
```

**Pros**: Cleaner logic, easier to understand  
**Cons**: Uses O(n) extra space, violates in-place requirement

---

## 🎯 Key Learning Points

### ✅ **Two-Pointer Mastery**

#### **Read/Write Pattern Best Practices**:
```cpp
// ✅ Good: Separate read and write logic
int write = 0, read = 0;
while (read < chars.size()) {
    // Process group starting at read
    // Write compressed result at write
}

// ❌ Avoid: Single pointer trying to do both
for (int i = 0; i < chars.size(); i++) {
    // Confusing logic mixing read and write
}
```

#### **Count Handling Best Practices**:
```cpp
// ✅ Good: Handle multi-digit counts properly
if (count > 1) {
    for (char c : to_string(count)) {
        chars[write++] = c;
    }
}

// ❌ Avoid: Treating count as single character
if (count > 1) {
    chars[write++] = count + '0';  // Only works for count < 10
}
```

---

## 📏 Constraints and Implications

**Given Constraints:**
- `1 ≤ chars.length ≤ 2000`
- `chars[i]` is a lowercase English letter, uppercase English letter, or digit
- The compressed string should not be longer than the original string

**Constraint Analysis:**
```
Small to Medium Arrays: up to 2000 characters
→ O(n) solution is efficient
→ In-place modification saves memory

Character Set: Letters and digits
→ Simple character comparison sufficient
→ No Unicode or special character concerns

Compression Guarantee:
→ Result never longer than original
→ Safe to modify array in-place
→ Write pointer never overtakes read pointer
```

---

## 🚀 Advanced Topics and Extensions

### 1. **Run-Length Encoding Variants**
- **Modified RLE**: Different encoding schemes for specific data types
- **Adaptive RLE**: Switches between RLE and raw data based on efficiency
- **Hierarchical RLE**: Multi-level compression for highly repetitive data

### 2. **Related Array Problems**
- **LeetCode 26**: Remove Duplicates from Sorted Array
- **LeetCode 80**: Remove Duplicates from Sorted Array II
- **LeetCode 283**: Move Zeroes

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| String Compression | Medium | ✅ Solved | Two-Pointer In-Place | O(n) | O(1) |

## 🎯 Key Learnings Achieved

### ✅ **Two-Pointer Technique Mastery**
- **Read/Write Pointers**: Efficient in-place array modification
- **Group Processing**: Counting consecutive elements in single pass
- **Multi-Digit Handling**: Converting numbers to individual characters
- **Space Optimization**: O(1) auxiliary space usage

### ✅ **Algorithm Design Principles**
- **In-Place Modification**: Memory-efficient array manipulation
- **Single Pass Processing**: Linear time complexity achievement
- **Edge Case Handling**: Comprehensive boundary condition management
- **Character Array Operations**: Advanced string processing techniques

---

**Total Problems Solved**: 26/∞

*Master two-pointers, master in-place algorithms! 🎯*

### 📚 Examples with Detailed Analysis

#### Example 1: Basic Compression
```
Input: ["a","a","b","b","c","c","c"]
Output: 6, ["a","2","b","2","c","3"]

Step-by-step process:
1. Initialize: read=0, write=0
2. Process 'a': count=2 → write 'a','2' → write=2
3. Process 'b': count=2 → write 'b','2' → write=4
4. Process 'c': count=3 → write 'c','3' → write=6
5. Return 6 (new length)
```

#### Example 2: Single Character
```
Input: ["a"]
Output: 1, ["a"]

Explanation: Single character remains as is.
```

#### Example 3: No Compression Needed
```
Input: ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: 4, ["a","b","1","2"]

Explanation: "a" remains as is, "b" is followed by "12" (12 b's).
```

### 🔄 Solution Approach: Two-Pointer Technique

#### 💡 Core Idea
Use two pointers:
- `read`: To read through the original array
- `write`: To write the compressed result

#### 📊 Complexity Analysis
- **Time Complexity**: O(n)
  - Single pass through the array
  - Each character is read exactly once
- **Space Complexity**: O(1)
  - Constant extra space (only a few variables)
  - In-place modification of input array

#### 🔍 Algorithm Steps
1. Initialize `read` and `write` pointers to 0
2. While `read` is less than array length:
   - Store current character and initialize count to 1
   - Count consecutive same characters
   - Write the character at `write` position
   - If count > 1, write each digit of the count
3. Return the `write` position as new length

```cpp
int compress(vector<char>& chars) {
    int write = 0, read = 0;
    while (read < chars.size()) {
        char current = chars[read];
        int count = 0;
        
        // Count consecutive characters
        while (read < chars.size() && chars[read] == current) {
            read++;
            count++;
        }
        
        // Write character
        chars[write++] = current;
        
        // Write count if > 1
        if (count > 1) {
            for (char c : to_string(count)) {
                chars[write++] = c;
            }
        }
    }
    return write;
}
```

---

## 📖 Complete Guide to Key Concepts

### 1. Run-Length Encoding (RLE) 🧵

**Purpose**: Simple form of data compression where consecutive data elements are stored as a single data value and count.

**Key Points**:
- Replaces sequences of the same data values with a count and the value
- Effective for data with many consecutive repeated values
- Simple to implement and understand
- Used in image compression (e.g., BMP, TIFF formats)

**Example**:
```
Input:  "AAAABBBCCDAA"
Output: "4A3B2C1D2A"
```

### 2. Two-Pointer Technique 👆👇

**Purpose**: Efficiently solve problems with O(1) space by using two pointers to traverse data.

**Common Patterns**:
1. **Read/Write Pointers**:
   - One pointer reads, one writes
   - Used for in-place modifications
   - Example: This problem, removing duplicates

2. **Fast/Slow Pointers**:
   - One moves faster than the other
   - Used for cycle detection, middle of list

3. **Left/Right Pointers**:
   - Start at opposite ends and move towards center
   - Used for two-sum, palindrome checks

**Visualization**:
```
Initial: [a, a, b, b, c, c, c]
         w  r

After first group: [a, 2, b, b, c, c, c]
                  w     r
```

---

## 🧪 Test Cases

### Basic Test Cases
```
// Test Case 1: Basic compression
Input: ["a","a","b","b","c","c","c"]
Output: 6, ["a","2","b","2","c","3"]

// Test Case 2: Single character
Input: ["a"]
Output: 1, ["a"]
```

### Edge Cases
```
// Test Case 3: All same characters
Input: ["a","a","a","a","a"]
Output: 2, ["a","5"]

// Test Case 4: No compression needed
Input: ["a","b","c"]
Output: 3, ["a","b","c"]

// Test Case 5: Double-digit counts
Input: ["a","b","b",...,"b"] (12 b's)
Output: 4, ["a","b","1","2"]
```

### Performance Test Case
```
// Test Case 6: Large input
Input: ["a"] * 1000 + ["b"] * 1000
Output: 8, ["a","1","0","0","0","b","1","0","0","0"]
```

---

## 🔍 Alternative Approaches

### 1. Using Extra Space (Not In-Place)
```cpp
int compress(vector<char>& chars) {
    string compressed;
    int n = chars.size();
    
    for (int i = 0; i < n; ) {
        char current = chars[i];
        int count = 0;
        
        while (i < n && chars[i] == current) {
            i++;
            count++;
        }
        
        compressed += current;
        if (count > 1) {
            compressed += to_string(count);
        }
    }
    
    // Copy back to original array
    for (int i = 0; i < compressed.size(); i++) {
        chars[i] = compressed[i];
    }
    
    return compressed.size();
}
```
**Complexity**: O(n) time, O(n) space
**Drawback**: Uses extra space for the compressed string

### 2. Using String Stream
```cpp
#include <sstream>

int compress(vector<char>& chars) {
    stringstream ss;
    int n = chars.size();
    
    for (int i = 0; i < n; ) {
        char current = chars[i];
        int count = 0;
        
        while (i < n && chars[i] == current) {
            i++;
            count++;
        }
        
        ss << current;
        if (count > 1) {
            ss << count;
        }
    }
    
    string compressed = ss.str();
    for (int i = 0; i < compressed.size(); i++) {
        chars[i] = compressed[i];
    }
    
    return compressed.size();
}
```
**Complexity**: O(n) time, O(n) space
**Note**: More readable but uses extra space

---

## 🚀 Optimizations

1. **Early Termination**:
   - If the compressed string would be longer than original, return original
   - However, problem requires in-place modification

2. **Direct Character Writing**:
   - Instead of using `to_string()`, manually convert count to characters
   - Slight performance improvement by avoiding string allocation

3. **Single Pass with Lookahead**:
   - Process groups in a single pass without nested loops
   - More complex but potentially more efficient for certain cases

---

## 🤔 Common Pitfalls

1. **Off-by-One Errors**:
   - Be careful with array indices when counting characters
   - Remember that string indices are 0-based

2. **Character vs Digit Handling**:
   - Ensure counts are converted to individual characters
   - Don't write multi-digit numbers as single characters

3. **Edge Cases**:
   - Single character arrays
   - Arrays where no compression is possible
   - Arrays with all identical characters

4. **In-Place Modification**:
   - The problem requires in-place modification
   - Don't use extra space unless necessary

---

## 📚 Related Problems

1. **LeetCode 38**: Count and Say
2. **LeetCode 271**: Encode and Decode Strings
3. **LeetCode 443**: String Compression (this problem)
4. **LeetCode 394**: Decode String
5. **LeetCode 186**: Reverse Words in a String II

---

## 🔗 Additional Resources

1. [Run-Length Encoding - Wikipedia](https://en.wikipedia.org/wiki/Run-length_encoding)
2. [In-Place Algorithm - GeeksforGeeks](https://www.geeksforgeeks.org/in-place-algorithm/)
3. [Two-Pointer Technique - LeetCode](https://leetcode.com/articles/two-pointer-technique/)

---

## 🎓 Interview Tips

1. **Clarify Requirements**:
   - Ask about character set (ASCII, Unicode, etc.)
   - Confirm if in-place modification is required
   - Ask about handling of empty arrays

2. **Think Aloud**:
   - Explain your thought process as you develop the solution
   - Discuss trade-offs between different approaches

3. **Test Thoroughly**:
   - Test with edge cases (empty array, single character, no compression needed)
   - Verify with the given examples
   - Consider performance implications

4. **Optimize**:
   - Start with a brute force solution if needed
   - Then optimize using the two-pointer technique
   - Discuss time and space complexity

---

## 📝 Conclusion

The two-pointer technique provides an optimal O(n) time and O(1) space solution for the string compression problem. This pattern is widely applicable to array and string manipulation problems where in-place modification is required. Understanding run-length encoding is also valuable for data compression scenarios.
