/* LC#339

You are given a nested list of integers nestedList. 
Each element is either an integer or a list 
whose elements may also be integers or other lists.

The depth of an integer is the number of lists 
that it is inside of. 
For example, the nested list [1,[2,2],[[3],2],1] 
has each integer's value set to its depth.

Return the sum of each integer in nestedList multiplied by its depth.

Input: nestedList = [[1,1],2,[1,1]]
Output: 10
Explanation: Four 1's at depth 2, one 2 at depth 1. 
1*2 + 1*2 + 2*1 + 1*2 + 1*2 = 10.
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

int nestedVectorUtil (vector<NestedInteger>& nestedList, int curr_depth) {
	int sum = 0;
	for (NestedInteger& i : nestedList) {
		if (i.isInteger())
			sum += i.getInteger() * curr_depth;
		else
			sum += nestedVectorUtil(i.getList(), curr_depth + 1);
	}
	return sum;
}

int depthSum(vector<NestedInteger>& nestedList) {
	int sum = 0;
	for (NestedInteger& i : nestedList) {
		if (i.isInteger())
			sum += i.getInteger();
		else
			sum += nestedVectorUtil(i.getList(), 2);
	}
	return sum;
}