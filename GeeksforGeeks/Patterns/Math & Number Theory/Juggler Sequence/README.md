# 📝 Juggler Sequence (GeeksforGeeks)

🔗 [Problem Link](https://www.geeksforgeeks.org/problems/juggler-sequence3930/1)

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen) ![Language](https://img.shields.io/badge/Language-C++-blue)

### 💡 Tags
Mathematics, Recursion, series

### 🚀 Performance
- **Runtime:** Successfully Evaluated
- **Memory:** N/A

---

### 📜 Problem Description

Juggler Sequence is a series of integers in which the first term starts with a positive integer number  *a*  and the remaining terms are generated from the immediate previous term using the below recurrence relation:

 ![Juggler Formula](https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/705067/Web/Other/2220ffd2-353d-4b30-b2aa-68fe4047f959_1685087657.png) 

Given a number n, find the Juggler Sequence for this number as the first term of the sequence until it becomes 1.

**Examples:**

```
Input: n = 9
Output: 9 27 140 11 36 6 2 1
Explaination: We start with 9 and use 
above formula to get next terms.
```

```
Input: n = 6
Output: 6 2 1
Explaination: 
[61/2] = 2. 
[21/2] = 1.
```

**Constraints:** 
1 ≤ n ≤ 100