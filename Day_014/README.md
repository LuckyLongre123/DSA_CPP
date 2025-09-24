# 🔄 Reverse Integer - Complete Beginner's Guide

> **Master integer manipulation and overflow handling step by step!**

---

## 📖 What You'll Learn

By the end of this guide, you'll master:
- 🔢 **Integer Digit Manipulation** - How to extract and work with individual digits
- ⚠️ **Overflow Detection** - Preventing numbers from getting too big
- 🎯 **Boundary Handling** - Understanding number limits
- 🧮 **Mathematical Operations** - Using modulo and division like a pro

---

## 🎯 The Problem

### 📋 Problem Statement

**Given**: A signed 32-bit integer `x`  
**Task**: Return `x` with its digits reversed  
**Catch**: If the reversed number is too big/small, return `0`

**Important Rule**: You can't use 64-bit integers (no cheating with bigger numbers!)

### 🌟 Real-World Example

Think of it like reading a number backwards:
- **123** becomes **321** (like reading "one-two-three" as "three-two-one")
- **-456** becomes **-654** (negative sign stays at the front)
- **1200** becomes **21** (leading zeros disappear)

---

## 🔍 Understanding the Basics

### 🏗️ What Are 32-bit Integers?

```mermaid
graph LR
    A[32-bit Integer] --> B[INT_MIN<br/>-2,147,483,648]
    A --> C[INT_MAX<br/>+2,147,483,647]
    
    style A fill:#e1f5fe
    style B fill:#ffebee
    style C fill:#e8f5e8
```

**Think of it like a container:**
- It can only hold numbers from `-2,147,483,648` to `+2,147,483,647`
- If you try to put a bigger number, it "overflows" (breaks)

### 🎲 Digit Extraction Magic

Here's how we extract digits from a number:

```mermaid
flowchart TD
    A[Number: 1234] --> B[1234 % 10 = 4<br/>Extract last digit]
    B --> C[1234 ÷ 10 = 123<br/>Remove last digit]
    C --> D[123 % 10 = 3<br/>Extract next digit]
    D --> E[123 ÷ 10 = 12<br/>Remove digit]
    E --> F[Continue until 0]
    
    style A fill:#e3f2fd
    style B fill:#fff3e0
    style D fill:#fff3e0
```

**Key Operations:**
- `number % 10` → Gets the last digit
- `number ÷ 10` → Removes the last digit

---

## 📚 Step-by-Step Examples

### 🟢 Example 1: Simple Positive Number

**Input:** `x = 123`  
**Output:** `321`

```mermaid
graph TD
    A[Start: 123] --> B[Extract 3<br/>Result = 3]
    B --> C[Extract 2<br/>Result = 32]
    C --> D[Extract 1<br/>Result = 321]
    D --> E[Final: 321 ✅]
    
    style A fill:#e8f5e8
    style E fill:#c8e6c9
```

**Step-by-step breakdown:**
1. **Start:** `ans = 0, x = 123`
2. **Step 1:** Get last digit: `123 % 10 = 3`
   - Build result: `ans = 0 × 10 + 3 = 3`
   - Remove digit: `x = 123 ÷ 10 = 12`
3. **Step 2:** Get last digit: `12 % 10 = 2`
   - Build result: `ans = 3 × 10 + 2 = 32`
   - Remove digit: `x = 12 ÷ 10 = 1`
4. **Step 3:** Get last digit: `1 % 10 = 1`
   - Build result: `ans = 32 × 10 + 1 = 321`
   - Remove digit: `x = 1 ÷ 10 = 0`
5. **Done:** `x = 0`, return `321`

### 🔴 Example 2: Negative Number

**Input:** `x = -123`  
**Output:** `-321`

```mermaid
graph TD
    A[Start: -123] --> B[Extract -3<br/>Result = -3]
    B --> C[Extract -2<br/>Result = -32]
    C --> D[Extract -1<br/>Result = -321]
    D --> E[Final: -321 ✅]
    
    style A fill:#ffebee
    style E fill:#ffcdd2
```

**Magic of Negative Numbers:**
- In programming, `-123 % 10 = -3` (not `7`)
- The negative sign is preserved automatically!

### 🟡 Example 3: Trailing Zeros

**Input:** `x = 1200`  
**Output:** `21`

```mermaid
graph TD
    A[Start: 1200] --> B[Extract 0<br/>Result = 0]
    B --> C[Extract 0<br/>Result = 0]
    C --> D[Extract 2<br/>Result = 2]
    D --> E[Extract 1<br/>Result = 21]
    E --> F[Final: 21 ✅<br/>Leading zeros vanish!]
    
    style A fill:#fff8e1
    style F fill:#ffecb3
```

### 🚨 Example 4: Overflow Case

**Input:** `x = 1534236469`  
**Expected Reverse:** `9646324351`  
**Problem:** `9646324351 > 2,147,483,647` (too big!)  
**Output:** `0`

```mermaid
graph TD
    A[Start: 1534236469] --> B[Build: 964632435]
    B --> C[Next would be: 9646324351]
    C --> D{Check: > INT_MAX?}
    D -->|YES| E[Return 0 ❌]
    D -->|NO| F[Continue building]
    
    style A fill:#e1f5fe
    style E fill:#ffebee
```

---

## 🛠️ The Algorithm

### 🎯 Main Strategy: Build Backwards

```mermaid
flowchart TD
    A[Initialize result = 0] --> B{Is x = 0?}
    B -->|No| C[Check for overflow]
    C --> D[Get last digit: x % 10]
    D --> E[Build result: result × 10 + digit]
    E --> F[Remove digit: x ÷ 10]
    F --> B
    B -->|Yes| G[Return result]
    
    style A fill:#e8f5e8
    style C fill:#fff3e0
    style G fill:#c8e6c9
```

### 💻 The Code

```cpp
int reverse(int x) {
    int ans = 0;
    
    while(x != 0) {
        // 🚨 SAFETY CHECK: Will next operation overflow?
        if(ans < INT_MIN/10 || ans > INT_MAX/10) {
            return 0;  // Overflow detected!
        }
        
        // 🔧 BUILD: Add next digit to result
        ans = ans * 10 + x % 10;
        
        // ✂️ REMOVE: Delete last digit from x
        x = x / 10;
    }
    
    return ans;
}
```

### 🛡️ Overflow Protection Explained

**Why do we check `ans > INT_MAX/10`?**

```mermaid
graph TD
    A[ans = 214748365] --> B[INT_MAX/10 = 214748364]
    B --> C{ans > INT_MAX/10?}
    C -->|YES| D[Next: ans × 10 = 2147483650<br/>This exceeds INT_MAX!]
    C -->|NO| E[Safe to continue]
    
    style A fill:#ffebee
    style D fill:#ff5252
    style E fill:#4caf50
```

**The Math:**
- `INT_MAX = 2,147,483,647`
- `INT_MAX ÷ 10 = 214,748,364`
- If `ans > 214,748,364`, then `ans × 10` will definitely overflow!

---

## 🧪 Test Cases & Edge Cases

### ✅ Normal Cases

| Input | Output | Why |
|-------|--------|-----|
| `123` | `321` | Basic reversal |
| `-123` | `-321` | Negative preserved |
| `120` | `21` | Trailing zeros removed |

### ⚠️ Edge Cases

| Input | Output | Why |
|-------|--------|-----|
| `0` | `0` | Zero stays zero |
| `7` | `7` | Single digit unchanged |
| `1534236469` | `0` | Overflow detected |
| `-2147483648` | `0` | Negative overflow |

### 🎯 Boundary Testing

```mermaid
graph TD
    A[Test Categories] --> B[Normal Numbers<br/>✅ Should work]
    A --> C[Edge Cases<br/>⚠️ Special handling]
    A --> D[Overflow Cases<br/>❌ Return 0]
    
    B --> B1[Positive: 123 → 321]
    B --> B2[Negative: -456 → -654]
    B --> B3[Trailing zeros: 1200 → 21]
    
    C --> C1[Zero: 0 → 0]
    C --> C2[Single digit: 5 → 5]
    
    D --> D1[Too big: 1534236469 → 0]
    D --> D2[INT_MAX: 2147483647 → 0]
    
    style B fill:#e8f5e8
    style C fill:#fff3e0
    style D fill:#ffebee
```

---

## 🎓 Key Concepts Mastery

### 🔢 Digit Manipulation Techniques

**1. Extract Last Digit:**
```cpp
int lastDigit = number % 10;
// Example: 1234 % 10 = 4
```

**2. Remove Last Digit:**
```cpp
number = number / 10;
// Example: 1234 / 10 = 123
```

**3. Build Number from Digits:**
```cpp
result = result * 10 + digit;
// Example: 32 * 10 + 1 = 321
```

### ⚠️ Overflow Detection Patterns

```mermaid
graph LR
    A[Before Operation] --> B[Check Bounds]
    B --> C{Safe?}
    C -->|Yes| D[Perform Operation]
    C -->|No| E[Return Error/0]
    
    style A fill:#e3f2fd
    style B fill:#fff3e0
    style D fill:#e8f5e8
    style E fill:#ffebee
```

**Pattern to Remember:**
```cpp
// Always check BEFORE multiplying by 10
if (result > INT_MAX/10 || result < INT_MIN/10) {
    return 0;  // Prevent overflow
}
result = result * 10 + digit;  // Safe to proceed
```

### 🎯 Problem-Solving Framework

```mermaid
flowchart TD
    A[Read Problem] --> B[Identify Constraints]
    B --> C[Plan Algorithm]
    C --> D[Handle Edge Cases]
    D --> E[Implement Solution]
    E --> F[Test Thoroughly]
    
    style A fill:#e1f5fe
    style B fill:#f3e5f5
    style C fill:#e8f5e8
    style D fill:#fff3e0
    style E fill:#fce4ec
    style F fill:#e0f2f1
```

---

## 📊 Complexity Analysis

### ⏰ Time Complexity: O(log x)

**Why logarithmic?**
- We process each digit once
- Number of digits in `x` = ⌊log₁₀|x|⌋ + 1
- For 32-bit integers: maximum 10 digits

```mermaid
graph TD
    A[Input Size] --> B[1 digit: O(1)]
    A --> C[10 digits: O(1)]
    A --> D[1000 digits: O(1)]
    A --> E[Max 32-bit: 10 digits]
    
    style A fill:#e3f2fd
    style B fill:#e8f5e8
    style C fill:#e8f5e8
    style D fill:#e8f5e8
    style E fill:#fff3e0
```

### 💾 Space Complexity: O(1)

**Why constant space?**
- Only use a few variables: `ans`, `x`
- No arrays, lists, or recursive calls
- Memory usage doesn't grow with input size

---

## 🚀 Practice Problems

Once you master this, try these similar problems:

| Problem | Difficulty | Key Concept |
|---------|------------|-------------|
| 🔢 Palindrome Number | Easy | Digit extraction |
| 🧮 Plus One | Easy | Digit manipulation |
| 💫 Power of Three | Easy | Mathematical properties |
| 🔄 Add Digits | Easy | Digit processing |

---

## 🎯 Quick Reference

### 🔑 Essential Code Patterns

```cpp
// Extract digits from right to left
while (x != 0) {
    int digit = x % 10;  // Get last digit
    x = x / 10;          // Remove last digit
}

// Build number from digits
int result = 0;
result = result * 10 + digit;

// Check overflow before multiplication
if (result > INT_MAX/10 || result < INT_MIN/10) {
    return 0;
}
```

### 📝 Important Constants

```cpp
INT_MIN = -2,147,483,648  // Smallest 32-bit integer
INT_MAX =  2,147,483,647  // Largest 32-bit integer
```

### 🧠 Mental Model

```mermaid
graph TD
    A[Think of number as<br/>stack of digits] --> B[Pop digits one by one<br/>from right side]
    B --> C[Build new number<br/>adding digits to left]
    C --> D[Watch out for<br/>container overflow!]
    
    style A fill:#e1f5fe
    style B fill:#f3e5f5
    style C fill:#e8f5e8
    style D fill:#fff3e0
```

---

## 🏆 Mastery Checklist

- [ ] ✅ Understand digit extraction using `%` and `/`
- [ ] ✅ Know how to build numbers digit by digit
- [ ] ✅ Master overflow detection techniques
- [ ] ✅ Handle negative numbers correctly
- [ ] ✅ Deal with trailing zeros
- [ ] ✅ Solve the problem in O(log x) time
- [ ] ✅ Use O(1) space only
- [ ] ✅ Test all edge cases thoroughly

---

## 💡 Pro Tips

1. **🛡️ Safety First**: Always check for overflow BEFORE performing operations
2. **🔢 Practice Mental Math**: Understand what `123 % 10` and `123 / 10` do
3. **🧪 Test Edge Cases**: Zero, single digits, negative numbers, overflow cases
4. **📚 Learn the Pattern**: This digit manipulation technique appears in many problems
5. **🎯 Visualize**: Draw out the step-by-step process for complex examples

---

**🎉 Congratulations! You now have a complete understanding of integer reversal and overflow handling. Keep practicing and happy coding!**