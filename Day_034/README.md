# 🧩 Day 34: String Compression using Run-Length Encoding

## 📚 Table of Contents
1. [Introduction to the Problem](#-introduction-to-the-problem)
2. [Prerequisites](#-prerequisites)
3. [Problem Understanding](#-problem-understanding)
4. [Approach & Intuition](#-approach--intuition)
5. [Solution Code](#-solution-code)
6. [Complexity Analysis](#-complexity-analysis)
7. [Visual Walkthrough](#-visual-walkthrough)
8. [Edge Cases & Handling](#-edge-cases--handling)
9. [Common Pitfalls & Mistakes](#-common-pitfalls--mistakes)
10. [Optimization Techniques](#-optimization-techniques)
11. [Real-world Applications](#-real-world-applications)
12. [Practice Problems](#-practice-problems)
13. [Frequently Asked Questions](#-frequently-asked-questions)
14. [Additional Resources](#-additional-resources)
15. [Conclusion](#-conclusion)

## 🎯 Learning Objectives

By the end of this day, you will master:
- **Run-Length Encoding (RLE)**: Understanding and implementing this fundamental compression technique
- **Two-Pointer Technique**: Efficient in-place array manipulation with O(1) space complexity
- **String/Character Processing**: Advanced techniques for working with character arrays
- **In-Place Algorithms**: Modifying data structures without extra space
- **Edge Case Handling**: Managing various input scenarios in string manipulation
- **Character to Digit Conversion**: Converting numbers to their character representations
- **Algorithm Optimization**: Techniques to improve both time and space efficiency
- **Problem Decomposition**: Breaking down complex problems into manageable components

## 🌟 Introduction to the Problem

### What is String Compression?
String compression is the process of reducing the size of a string by replacing consecutive repeated characters with the character followed by the count of repetitions. This is also known as Run-Length Encoding (RLE).

### Real-world Analogies
1. **Image Compression**: Used in formats like TIFF and BMP for simple image compression
2. **Fax Machines**: Used in Group 3 and 4 fax compression standards
3. **DNA Sequencing**: Compressing repetitive genetic sequences
4. **Video Compression**: Used in some video codecs for compressing frames

### Why is this Problem Important?
- Tests understanding of in-place array manipulation
- Demonstrates efficient string processing techniques
- Commonly asked in technical interviews
- Has practical applications in data compression
- Helps understand fundamental concepts of lossless data compression

## 🔍 Problem Understanding

### Problem Statement
Given an array of characters `chars`, compress it using the following algorithm:
- If the group's length is 1, append the character to the result.
- If the group's length is more than 1, append the character followed by the group's length.
- The compressed string should be stored in the input array.
- Return the new length of the array.

### Detailed Explanation
- A **group** is a sequence of consecutive identical characters
- **Compression** means replacing each group with the character followed by its count
- The modification must be done **in-place** (O(1) extra space)
- The first `k` elements of the array should contain the compressed string
- The remaining elements can be anything (they will be ignored)

### Example Walkthrough
Let's break down the first example:
```
Input: ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters should be: ["a","2","b","2","c","3"]
```

### Visual Representation
```
Input:  [a, a, b, b, c, c, c]
          |  |  |  |  |  |  |
          v  v  v  v  v  v  v
Groups:  [a,a] [b,b] [c,c,c]
           |     |      |
           v     v      v
Output: [a,2,  b,2,   c,3  ]
```

### Key Observations
1. We need to process the array in a single pass
2. We need to keep track of the current character and its count
3. When the character changes, we need to write the compressed version
4. We need to handle single-digit and multi-digit counts properly
5. The output length might be different from the input length

### Common Misconceptions
1. **Mistake**: Creating a new array to store the result
   - **Why it's wrong**: The problem requires in-place modification with O(1) extra space
   - **Better approach**: Use two pointers to read and write in the same array

2. **Mistake**: Not handling multi-digit counts correctly
   - **Example**: For 12 'a's, we need to write 'a', '1', '2' (three characters)
   - **Solution**: Convert the count to a string and write each digit separately

3. **Mistake**: Not updating the array length correctly
   - **Why it's important**: The function should return the new length of the compressed array
   - **Solution**: Keep track of the write position and return it as the new length

---

## 🧠 Approach & Intuition

### Understanding the Core Idea
The key insight is to use two pointers:
- A read pointer to traverse the array and count consecutive characters
- A write pointer to build the compressed string in-place

### Why Two Pointers?
- **In-Place Modification**: We need to modify the array without using extra space
- **Efficient Traversal**: We can process the array in a single pass
- **Controlled Writing**: The write pointer ensures we don't overwrite unprocessed characters

### Visualizing the Process
```
Input: ["a","a","b","b","c","c","c"]

Step 1: Read 'a', count=2 → Write 'a','2' at positions 0,1
Step 2: Read 'b', count=2 → Write 'b','2' at positions 2,3
Step 3: Read 'c', count=3 → Write 'c','3' at positions 4,5

Final Array: ["a","2","b","2","c","3","c"]
Return value: 6
```

### Step-by-Step Intuition
1. **Initialize Pointers**:
   - `write` to track where to write the compressed string
   - `read` to traverse the array
   - `count` to track consecutive characters

2. **Process Each Character**:
   - For each character, count its consecutive occurrences
   - When a different character is found, write the compressed version
   - Handle single and multi-digit counts properly

3. **Handle Edge Cases**:
   - Empty array
   - Single character
   - All unique characters
   - Large counts (10+ repetitions)

### Time and Space Complexity
- **Time Complexity**: O(n) where n is the length of the array
  - We make a single pass through the array
  - Each character is processed exactly once
- **Space Complexity**: O(1)
  - We use a constant amount of extra space
  - The modification is done in-place

## 💻 Solution Code

### C++ Implementation
```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if (n <= 1) return n;  // No compression needed for 0 or 1 characters
        
        int write = 0;  // Pointer to write compressed characters
        int count = 1;   // Count of current character sequence
        
        // Start from the second character
        for (int read = 1; read <= n; ++read) {
            // If current character is same as previous, increment count
            if (read < n && chars[read] == chars[read - 1]) {
                count++;
            } 
            // If characters differ or we've reached the end
            else {
                // Write the character
                chars[write++] = chars[read - 1];
                
                // Write the count if > 1
                if (count > 1) {
                    string countStr = to_string(count);
                    for (char c : countStr) {
                        chars[write++] = c;
                    }
                }
                
                // Reset count for new character
                count = 1;
            }
        }
        
        return write;  // New length of compressed array
    }
};
```

### Python Implementation
```python
class Solution:
    def compress(self, chars: List[str]) -> int:
        n = len(chars)
        if n <= 1:
            return n
            
        write = 0  # Pointer to write compressed characters
        count = 1   # Count of current character sequence
        
        # Start from the second character
        for read in range(1, n + 1):
            # If current character is same as previous, increment count
            if read < n and chars[read] == chars[read - 1]:
                count += 1
            # If characters differ or we've reached the end
            else:
                # Write the character
                chars[write] = chars[read - 1]
                write += 1
                
                # Write the count if > 1
                if count > 1:
                    for c in str(count):
                        chars[write] = c
                        write += 1
                
                # Reset count for new character
                count = 1
                
        return write  # New length of compressed array
```

## 🔍 Complexity Analysis

### Time Complexity: O(n)
- **Reading Characters**: O(n) for the single pass through the array
- **Writing Compressed String**: O(n) in total (each character is written at most twice)
- **Total**: O(n)

### Space Complexity: O(1)
- **Extra Space**: O(1) - only a few variables used
- **In-Place Modification**: The input array is modified in-place

## 🎨 Visual Walkthrough

Let's visualize with input `["a","a","b","b","c","c","c"]`:

```
Initial: [a, a, b, b, c, c, c]
         ^  ^  ^  ^  ^  ^  ^
         r  r  r  r  r  r  r  (read pointer)
         w                     (write pointer)
         count = 1

Step 1: read=1, same 'a' → count=2
Step 2: read=2, new char 'b' → write 'a','2'
        [a, 2, b, b, c, c, c]
            w  r
        count=1

Step 3: read=3, same 'b' → count=2
Step 4: read=4, new char 'c' → write 'b','2'
        [a, 2, b, 2, c, c, c]
               w     r
        count=1

Step 5: read=5, same 'c' → count=2
Step 6: read=6, same 'c' → count=3
Step 7: read=7 (end) → write 'c','3'
        [a, 2, b, 2, c, 3, c]
                     w

Final: Return write=6
```

## 🧪 Edge Cases & Handling

1. **Empty Array**:
   ```
   Input: []
   Output: 0
   ```

2. **Single Character**:
   ```
   Input: ["a"]
   Output: 1, ["a"]
   ```

3. **No Compression Needed**:
   ```
   Input: ["a","b","c"]
   Output: 3, ["a","b","c"]
   ```

4. **Large Counts**:
   ```
   Input: ["a","a",...,"a"] (12 'a's)
   Output: 4, ["a","1","2"]
   ```

## 🚀 Optimization Techniques

### 1. Early Return for Small Arrays
```cpp
if (n <= 1) return n;  // No compression needed for 0 or 1 characters
```

### 2. Efficient Digit Writing
```cpp
// Convert count to string and write each digit
string countStr = to_string(count);
for (char c : countStr) {
    chars[write++] = c;
}
```

### 3. Single Loop with Lookahead
```cpp
for (int read = 1; read <= n; ++read) {
    if (read < n && chars[read] == chars[read - 1]) {
        count++;
    } else {
        // Write character and count
    }
}
```

## 🌐 Real-world Applications

1. **File Compression**: Used in formats like ZIP and RAR
2. **Image Processing**: Used in formats like TIFF and BMP
3. **Data Transmission**: Reduces bandwidth usage
4. **Database Storage**: Compresses repetitive data
5. **Log File Compression**: Reduces storage for repetitive log entries

## 📚 Practice Problems

1. **LeetCode 443**: String Compression (this problem)
2. **LeetCode 38**: Count and Say
3. **LeetCode 271**: Encode and Decode Strings
4. **LeetCode 394**: Decode String
5. **LeetCode 186**: Reverse Words in a String II

## ❓ Frequently Asked Questions

### Q1: Why do we need to handle multi-digit counts separately?
**A**: Because counts ≥10 require multiple characters to represent (e.g., '1' and '2' for 12), we need to write each digit as a separate character in the array.

### Q2: Can we solve this with O(1) space complexity?
**A**: Yes, the solution uses O(1) extra space by modifying the input array in-place and only using a few variables for counting and indexing.

### Q3: What's the time complexity of string conversion for counts?
**A**: The string conversion of a number `n` takes O(log n) time, but since the maximum count is 2000 (as per problem constraints), it's effectively O(1) per group.

### Q4: How would you handle case-sensitive compression?
**A**: The problem assumes case-sensitive comparison. For case-insensitive, convert characters to the same case before comparison.

## 📚 Additional Resources

1. [Run-Length Encoding - Wikipedia](https://en.wikipedia.org/wiki/Run-length_encoding)
2. [In-Place Algorithm - GeeksforGeeks](https://www.geeksforgeeks.org/in-place-algorithm/)
3. [Two-Pointer Technique - LeetCode](https://leetcode.com/tag/two-pointers/)
4. [String Compression - LeetCode Discuss](https://leetcode.com/problems/string-compression/discuss/92559/Simple-Easy-to-Understand-Java-solution)

## 🎓 Interview Tips

1. **Clarify Requirements**:
   - Ask about character set (ASCII, Unicode, etc.)
   - Ask about case sensitivity
   - Ask about the maximum length of the input array

2. **Think Aloud**:
   - Explain your thought process as you develop the solution
   - Discuss trade-offs between different approaches

3. **Test Thoroughly**:
   - Test with edge cases (empty array, single character, etc.)
   - Verify with the given examples
   - Consider performance implications

4. **Optimize**:
   - Start with a brute force solution if needed
   - Then optimize using the two-pointer technique
   - Discuss time and space complexity

## 🏁 Conclusion

The two-pointer technique provides an optimal O(n) time and O(1) space solution for the string compression problem. This pattern is widely applicable to array and string manipulation problems where in-place modification is required. Understanding this technique is crucial for technical interviews and real-world string processing tasks.

### Key Takeaways:
1. **Two-Pointer Technique** is powerful for in-place array manipulation
2. **Run-Length Encoding** is a simple yet effective compression method
3. **Edge Cases** must be carefully considered in string manipulation problems
4. **Efficient Digit Handling** is crucial for multi-digit counts

Given an array of characters `chars`, compress it using the following algorithm:
- If the group's length is 1, append the character to the result.
- If the group's length is more than 1, append the character followed by the group's length.
- The compressed string should be stored in the input array.
- Return the new length of the array.

**Example 1:**
```
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
```

**Example 2:**
```
Input: chars = ["a"]
Output: Return 1, and the first character should be: ["a"]
Explanation: The only group is "a", which remains as "a".
```

### 🔍 Problem Analysis

**Key Insights**:
- We need to compress the string in-place without using extra space
- The compression should be done in a single pass
- We need to handle both single characters and groups of characters
- The result should be stored in the original array

**Pattern Recognition**:
```
Input: ["a","a","b","b","c","c","c"]

Step 1: Read 'a', count=2 → Write 'a','2'
Step 2: Read 'b', count=2 → Write 'b','2'
Step 3: Read 'c', count=3 → Write 'c','3'

Output: ["a","2","b","2","c","3"] (length=6)
```

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
