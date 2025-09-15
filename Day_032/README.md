# Day 32: String Manipulation - Substring Removal

## 🎯 Learning Objectives

By the end of this day, you will master:
- **String Searching**: Using `find()` method for substring location
- **String Deletion**: Using `erase()` method for character removal
- **Iterative String Processing**: Repeatedly modifying strings until condition met
- **String Constants**: Understanding `string::npos` and its significance
- **Pattern Recognition**: Identifying overlapping substring removal scenarios

---

## Problem: Remove All Occurrences of a Substring (LeetCode 1910)

### 📋 Problem Statement

**Difficulty**: Medium  
**Category**: String, Simulation  
**Companies**: Amazon, Microsoft, Google, Meta

Given two strings `s` and `part`, repeatedly remove all occurrences of `part` from `s` until no more occurrences of `part` exist.

**Task**: Return the final string after all such removals have been made.

**Important Note**: After each removal, the remaining parts of the string are concatenated, which might create new occurrences of `part`.

### 🔍 Problem Analysis

**Key Insights**:
- We need to remove ALL occurrences of a substring
- Each removal might create new occurrences (overlapping patterns)
- We must continue until no more occurrences exist
- Order of removal doesn't matter - we always get the same result

**Pattern Recognition**:
```
"daabcbaabcbc" with part = "abc"
Step 1: Remove first "abc" → "dabaabcbc"
Step 2: Remove "abc" → "dababc" 
Step 3: Remove "abc" → "dab"
Final: "dab"
```

### 📚 Examples with Detailed Analysis

#### Example 1: Simple Removal
```
Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"

Step-by-step process:
Initial: "daabcbaabcbc"
Find "abc" at position 2: "da[abc]baabcbc"
After removal: "dabaabcbc"
Find "abc" at position 4: "daba[abc]bc"  
After removal: "dababc"
Find "abc" at position 3: "dab[abc]"
After removal: "dab"
No more "abc" found.

Final result: "dab"
```

#### Example 2: Overlapping Pattern Creation
```
Input: s = "axxxxxa", part = "xx"
Output: "a"

Step-by-step process:
Initial: "axxxxxa"
Find "xx" at position 1: "a[xx]xxxa"
After removal: "axxxa"
Find "xx" at position 1: "a[xx]xa"
After removal: "axa"
No more "xx" found.

Final result: "axa"

Wait, let's trace this more carefully:
Initial: "axxxxxa"
Find "xx" at position 1: "a[xx]xxxa"
After removal: "axxxa"
Find "xx" at position 1: "a[xx]xa"  
After removal: "axa"
No more "xx" patterns exist.

Final result: "axa"
```

#### Example 3: Complete Removal
```
Input: s = "abcabc", part = "abc"
Output: ""

Step-by-step process:
Initial: "abcabc"
Find "abc" at position 0: "[abc]abc"
After removal: "abc"
Find "abc" at position 0: "[abc]"
After removal: ""
No more "abc" found.

Final result: ""
```

### 🔄 Solution Approach: Iterative Search and Remove

#### 💡 Core Idea
Use string's built-in `find()` and `erase()` methods to repeatedly locate and remove occurrences until none remain.

#### 📊 Complexity Analysis
- **Time Complexity**: O(n × m × k)
  - n = length of string s
  - m = length of part
  - k = number of occurrences to remove
- **Space Complexity**: O(1) - in-place modification

#### 🔍 Algorithm Steps
1. **Search**: Use `find()` to locate first occurrence of `part`
2. **Check**: If found (position != `string::npos`), proceed to remove
3. **Remove**: Use `erase()` to delete the found occurrence
4. **Repeat**: Continue searching from beginning until no more occurrences
5. **Return**: Final modified string

```cpp
string removeOccurrences(string s, string part) {
    size_t pos = s.find(part);
    while (pos != string::npos) {
        s.erase(pos, part.size());
        pos = s.find(part);
    }
    return s;
}
```

---

## 📖 Complete Guide to String Methods Used

### 1. `string.find(substring)` Method 🔍

**Purpose**: Searches for the first occurrence of a substring within a string.

**Syntax**: 
```cpp
size_t find(const string& str, size_t pos = 0) const;
```

**Parameters**:
- `str`: The substring to search for
- `pos`: Starting position for search (default: 0)

**Return Value**:
- Returns the **index** of the first character of the first match
- Returns `string::npos` if substring is not found

**Detailed Examples**:
```cpp
string s = "Hello World Hello";
string part = "Hello";

// Basic usage
size_t pos1 = s.find("Hello");        // Returns: 0
size_t pos2 = s.find("World");        // Returns: 6  
size_t pos3 = s.find("xyz");          // Returns: string::npos

// Starting from specific position
size_t pos4 = s.find("Hello", 1);     // Returns: 12 (second "Hello")
size_t pos5 = s.find("Hello", 13);    // Returns: string::npos

// Finding characters
size_t pos6 = s.find('o');            // Returns: 4 (first 'o')
size_t pos7 = s.find('o', 5);         // Returns: 7 (second 'o')
```

**Important Notes**:
- `find()` is **case-sensitive**: "Hello" ≠ "hello"
- Returns position of **first character** of the match
- Search is **left-to-right** (finds leftmost occurrence first)
- Time complexity: O(n×m) in worst case

### 2. `string.erase(pos, length)` Method ✂️

**Purpose**: Removes characters from a string starting at specified position.

**Syntax**:
```cpp
string& erase(size_t pos = 0, size_t len = npos);
```

**Parameters**:
- `pos`: Starting position to erase from
- `len`: Number of characters to erase

**Return Value**: Reference to the modified string

**Detailed Examples**:
```cpp
string s = "Hello World Programming";

// Remove specific range
s.erase(6, 5);           // Remove "World" → "Hello  Programming"
                         // pos=6, len=5

// Remove from position to end
string s2 = "Hello World";
s2.erase(5);             // Remove from pos 5 to end → "Hello"

// Remove single character
string s3 = "Programming";
s3.erase(4, 1);          // Remove 'r' at position 4 → "Progamming"

// Remove all characters
string s4 = "Test";
s4.erase(0);             // Remove all → ""
```

**Important Notes**:
- **Modifies original string** (not a copy)
- Automatically **shifts remaining characters** left to fill gap
- If `pos` is beyond string length, throws `out_of_range` exception
- If `len` exceeds remaining characters, erases to end of string

### 3. `string::npos` Constant 🚫

**Purpose**: Special value indicating "no position" or "not found".

**Definition**:
```cpp
static const size_t npos = -1;  // Usually largest possible size_t value
```

**Usage Patterns**:
```cpp
string s = "Hello World";

// Check if substring exists
if (s.find("xyz") == string::npos) {
    cout << "Substring not found!" << endl;
}

// Check if substring exists (alternative)
if (s.find("Hello") != string::npos) {
    cout << "Substring found!" << endl;
}

// Store position and check
size_t pos = s.find("World");
if (pos != string::npos) {
    cout << "Found at position: " << pos << endl;
}
```

**Important Notes**:
- `npos` is typically the **largest possible value** for `size_t`
- On most systems: `npos = 18446744073709551615` (64-bit)
- **Always compare with `!=`** when checking if found
- **Never use `== -1`** for comparison (type mismatch)

### 4. `size_t` Data Type 📏

**Purpose**: Unsigned integer type used for sizes and indices.

**Characteristics**:
- **Unsigned**: Can only hold non-negative values (0 and positive)
- **Size**: Usually 64-bit on modern systems
- **Range**: 0 to 18,446,744,073,709,551,615 (on 64-bit systems)

**Why use `size_t` for string positions?**
```cpp
// Correct usage
size_t pos = s.find("substring");

// Avoid using int (can cause issues with large strings)
int pos = s.find("substring");  // ⚠️ Potential problems
```

**Important Notes**:
- String indices and sizes are always `size_t`
- Prevents negative index errors
- Can handle very large strings efficiently
- Standard type for STL containers

---

## 🔬 Algorithm Deep Dive

### Visual Step-by-Step Execution

Let's trace through `s = "abcabcabc"`, `part = "abc"`:

```
Initial State:
s = "abcabcabc"
     0123456789  (indices)

Step 1: Find "abc"
pos = s.find("abc") = 0
s = "[abc]abcabc"  ← Found at position 0

Step 2: Erase "abc" 
s.erase(0, 3)
s = "abcabc"       ← Removed first 3 characters
     012345        (new indices)

Step 3: Find "abc" again
pos = s.find("abc") = 0  
s = "[abc]abc"     ← Found at position 0 again

Step 4: Erase "abc"
s.erase(0, 3)
s = "abc"          ← Removed first 3 characters
     012           (new indices)

Step 5: Find "abc" again
pos = s.find("abc") = 0
s = "[abc]"        ← Found at position 0 again

Step 6: Erase "abc"
s.erase(0, 3)
s = ""             ← String is now empty

Step 7: Find "abc" again
pos = s.find("abc") = string::npos  ← Not found!

Loop terminates. Final result: ""
```

### Memory and Performance Analysis

#### Memory Usage:
```cpp
string s = "very long string...";  // Original string in memory
size_t pos = s.find(part);         // pos: 8 bytes (size_t)
s.erase(pos, part.size());         // Modifies original string in-place
```

**Memory Efficiency**:
- ✅ **In-place modification**: No extra string copies
- ✅ **Automatic memory management**: String handles resizing
- ✅ **Minimal overhead**: Only one `size_t` variable needed

#### Performance Characteristics:
```
For string of length n, part of length m, k occurrences:

Time per find(): O(n × m)     [worst case]
Time per erase(): O(n)       [shifting characters]
Total iterations: k
Overall: O(k × n × m)

Space: O(1) auxiliary space
```

---

## 🧪 Comprehensive Testing

### Test Cases with Expected Results

```cpp
// Test Case 1: Basic removal
removeOccurrences("daabcbaabcbc", "abc") → "dab"

// Test Case 2: Complete removal  
removeOccurrences("abcabc", "abc") → ""

// Test Case 3: No occurrences
removeOccurrences("hello", "xyz") → "hello"

// Test Case 4: Single character part
removeOccurrences("aaaaaa", "a") → ""

// Test Case 5: Part longer than string
removeOccurrences("hi", "hello") → "hi"

// Test Case 6: Overlapping patterns
removeOccurrences("aaaa", "aa") → ""

// Test Case 7: Part at end
removeOccurrences("helloabc", "abc") → "hello"

// Test Case 8: Part at beginning
removeOccurrences("abchello", "abc") → "hello"

// Test Case 9: Multiple scattered occurrences
removeOccurrences("xabcyabcz", "abc") → "xyz"

// Test Case 10: Empty string
removeOccurrences("", "abc") → ""
```

### Edge Cases Analysis

#### 1. **Empty Inputs**
```cpp
removeOccurrences("", "abc")     → ""     ✅ Handle empty string
removeOccurrences("hello", "")  → "hello" ✅ Handle empty part
```

#### 2. **Size Relationships**
```cpp
// Part longer than string
removeOccurrences("hi", "hello") → "hi"   ✅ No match possible

// Part same as string  
removeOccurrences("abc", "abc") → ""      ✅ Complete removal

// Single character scenarios
removeOccurrences("a", "a") → ""          ✅ Single char removal
removeOccurrences("a", "b") → "a"         ✅ No match
```

#### 3. **Overlapping Patterns**
```cpp
// Consecutive overlapping
removeOccurrences("aaaa", "aa") → ""
Trace: "aaaa" → "aa" → ""

// Complex overlapping
removeOccurrences("ababa", "aba") → "ba"  
Trace: "ababa" → "ba" (removes first "aba")
```

---

## 📊 Alternative Approaches

### Approach 1: Stack-Based Solution
```cpp
string removeOccurrences(string s, string part) {
    string result;
    for (char c : s) {
        result += c;
        if (result.size() >= part.size() && 
            result.substr(result.size() - part.size()) == part) {
            result.erase(result.size() - part.size());
        }
    }
    return result;
}
```

**Pros**: Single pass through string  
**Cons**: More complex logic, substring comparisons

### Approach 2: Recursive Solution
```cpp
string removeOccurrences(string s, string part) {
    size_t pos = s.find(part);
    if (pos == string::npos) return s;
    
    s.erase(pos, part.size());
    return removeOccurrences(s, part);
}
```

**Pros**: Clean recursive logic  
**Cons**: Stack overhead, potential stack overflow

### Approach 3: Two-Pointer with Rebuilding
```cpp
string removeOccurrences(string s, string part) {
    string result;
    int i = 0;
    while (i < s.length()) {
        if (s.substr(i, part.length()) == part) {
            i += part.length();
        } else {
            result += s[i];
            i++;
        }
    }
    // Need to handle newly formed patterns
    if (result.find(part) != string::npos) {
        return removeOccurrences(result, part);
    }
    return result;
}
```

**Analysis**: More complex due to pattern reformation

---

## 🎯 Key Learning Points

### ✅ **String Method Mastery**

#### **find() Method Best Practices**:
```cpp
// ✅ Good: Check return value
size_t pos = s.find(part);
if (pos != string::npos) {
    // Found at position 'pos'
}

// ❌ Avoid: Direct comparison with -1
if (s.find(part) != -1) {  // Type mismatch warning
```

#### **erase() Method Best Practices**:
```cpp
// ✅ Good: Specify exact length
s.erase(pos, part.size());

// ✅ Good: Erase to end
s.erase(pos);

// ⚠️ Careful: Check bounds
if (pos < s.length()) {
    s.erase(pos, len);
}
```

### ✅ **Algorithm Design Patterns**

#### **When to Use This Approach**:
- ✅ Simple substring removal problems
- ✅ When overlapping patterns need handling
- ✅ When in-place modification is acceptable
- ✅ For moderate-sized strings

#### **When to Consider Alternatives**:
- ❌ Very large strings (performance concerns)
- ❌ When original string must be preserved
- ❌ Complex pattern matching requirements
- ❌ When single-pass solution is critical

---

## 📏 Constraints and Implications

**Given Constraints:**
- `1 ≤ s.length ≤ 1000`
- `1 ≤ part.length ≤ 1000`
- `s` and `part` consist of lowercase English letters only

**Constraint Analysis:**
```
Small to Medium Strings: up to 1000 characters
→ O(n × m × k) solution is acceptable
→ No need for advanced optimization

Lowercase Letters Only:
→ Simple string comparison sufficient
→ No case sensitivity or Unicode concerns
→ ASCII values 'a' to 'z' only

Memory Considerations:
→ In-place modification keeps memory usage low
→ Maximum iterations bounded by string length
→ No risk of memory explosion
```

---

## 🚀 Advanced Topics and Extensions

### 1. **Pattern Matching Algorithms**
- **KMP Algorithm**: For efficient substring searching
- **Boyer-Moore**: For large alphabet substring search
- **Rabin-Karp**: For multiple pattern matching

### 2. **String Processing Optimizations**
- **StringBuilder Pattern**: For multiple concatenations
- **String Interning**: For repeated string operations
- **Memory Pool**: For frequent allocations/deallocations

### 3. **Related Problems**
- **LeetCode 1047**: Remove All Adjacent Duplicates In String
- **LeetCode 1209**: Remove All Adjacent Duplicates in String II
- **LeetCode 316**: Remove Duplicate Letters

---

## 📊 Progress Summary

| Problem | Difficulty | Status | Approach | Time Complexity | Space Complexity |
|---------|------------|--------|----------|-----------------|------------------|
| Remove All Occurrences | Medium | ✅ Solved | Iterative Search & Remove | O(n×m×k) | O(1) |

## 🎯 Key Learnings Achieved

### ✅ **String Manipulation Mastery**
- **find() Method**: Efficient substring searching with position return
- **erase() Method**: In-place character removal with automatic shifting
- **string::npos**: Special constant for "not found" conditions
- **size_t Type**: Proper unsigned integer type for string operations

### ✅ **Algorithm Design Principles**
- **Iterative Processing**: Repeating operations until condition met
- **Pattern Recognition**: Identifying when removals create new patterns
- **In-Place Modification**: Memory-efficient string manipulation
- **Edge Case Handling**: Comprehensive testing for boundary conditions

---

**Total Problems Solved**: 25/∞

*Master string methods, master text processing! 🔤*
