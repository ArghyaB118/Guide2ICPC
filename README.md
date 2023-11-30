# Coding Practice
## This is where I practice solving interview questions
1. Implementation of Cuckoo Hashing with 2 tables and 2 hash functions
2. Implementation to test Secretary Problem
3. Implementation to check Happy Number

## How to run 
```bash
g++ -v
g++ -std=c++11 <program_name>.cpp
./a.out
```

###Interesting Links

Blind 75 problems on leetcode: https://leetcode.com/discuss/general-discussion/460599/blind-75-leetcode-questions

Leetcode patterns: https://seanprashad.com/leetcode-patterns/

## Topic-wise study

### Array problems
1. Buy and Sell stocks: from an array of prices, choose two days from buys and sell that maximizes the profit.
Solution: DP, where DP[i] = arr[i] - current_min
2. Currency Exchange: can you get the exact change with given denominations of coins and bills?
3. Count number of contiguous subarrays that follows a constraint.
4. Cutting Ribbons: Maximum length of k ribbons cut from a number of ribbons available of given lengths.
5. Heavy Hitters: Find top k most frequent elements.
Solution: Make a hashmap, keep counts, sort the hashmap by a priority queue based on counts as comparator. Return top k elements from the priority queue.
6. Find k Closest points in an 1D line and an 2D plane.
Solution: keep priority queue of length k based on the distance.
7. Largest Triple Product: 
Solution: keep a priority queue of length 3, and if the current elemnt is larger than the top element of the queue, pop the queue once, and push the current element.


### Graph problems
1. buildHouse.cpp
Problem: Choose the cell to build a house in a maze so that it has the least sum of distance from all other houses.
Solution: BFS from all the empty cells to the houses and select the cell with minimum sum of paths.
2. coursePrequisite.cpp



# Google Foobar Additional Problems
Source:https://github.com/oneshan/foobar

### Google Foobar Questions:
#### Level 1
1. Deduplicate a list from another larger list

#### Level 2
1. Ion flux Relabeling
Build a balanced binary tree
2. En Route Salute
String processing O(n^2), can we improve?

#### Level 3
1. Prepare the Bunnies' Escape
Solution involves doing BFS in a maze
2. Build the Grandest Staircase
3. Find the Access Codes
finding a lucky triple (x,y,z) where x divides y and y divides z.

#### Level 4
1. Bunnies Escape Distribute Keys

# Meta Careers Website Puzzles
Inlcuded in the folder MetaPuzzles and categorized level-wise.
