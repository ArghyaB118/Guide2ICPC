'''
3.2 The Grandest Staircase Of Them All

With her LAMBCHOP doomsday device finished, Commander Lambda is preparing 
for her debut on the galactic stage - but in order to make a grand entrance, 
she needs a grand staircase! As her personal assistant, you've been tasked with 
figuring out how to build the best staircase EVER.

Lambda has given you an overview of the types of bricks available, plus a budget. 
You can buy different amounts of the different types of bricks (for example, 
3 little pink bricks, or 5 blue lace bricks). Commander Lambda wants to know 
how many different types of staircases can be built with each amount of bricks, 
so she can pick the one with the most options.

Each type of staircase should consist of 2 or more steps. No two steps are 
allowed to be at the same height - each step must be lower than the previous one. 
All steps must contain at least one brick. A step's height is classified as the 
total amount of bricks that make up that step. For example, when N = 3, 
you have only 1 choice of how to build the staircase, with the first step having 
a height of 2 and the second step having a height of 1: (# indicates a brick)

#
##

When N = 4, you still only have 1 staircase choice:

#
#
##

But when N = 5, there are two ways you can build a staircase from the given bricks. 
The two staircases can have heights (4, 1) or (3, 2), as shown below:

#
#
#
##

#
##
##

Write a function called answer(n) that takes a positive integer n and returns 
the number of different staircases that can be built from exactly n bricks. 
n will always be at least 3 (so you can have a staircase at all), but no more than 200, 
because Commander Lambda's not made of money!
'''

# Complexity = O(N^2)
def countStaircases(n): 
	memo = [[0 for x in range(0, n + 2)] for y in range(0, n + 2)] 	
	# Base case memo[sum][number of addends]
	memo[3][2] = memo[4][2] = 1
	for i in range (5, n + 1) : 
		for j in range (2, i + 1) : 
			# When step is equal to 2 
			if (j == 2) : 
				memo[i][j] = memo[i - j][j] + 1
			# When step is greater than 2 
			else : 
				memo[i][j] = (memo[i - j][j] + memo[i - j][j - 1]) 
	answer = 0
	print(memo)
	for i in range (1, n + 1): 
		answer = answer + memo[n][i] 
	return answer
		 
# Complexity = O(2^N)
def subsetSum(arr, n, i,sum, count): 
	# Finishing after checking all the subsets
	if (i == n): 
		if (sum == 0): 
			count += 1
		return count
	count = subsetSum(arr, N-1, i + 1, sum - arr[i], count) # If the element is counted, then the remaining sum is checked
	count = subsetSum(arr, N-1, i + 1, sum, count) # If the element is not included, then the total sum is checked
	return count 
# Complexity = O(2^N)
def count(height, left):
	if left == 0:
		return 1
	if left < height:
		return 0
	return count(height + 1, left - height) + count(height + 1, left)
# Driver Code 
if __name__ == "__main__": 
	N = 10
	print (countStaircases(N)) 
	#print(count(1,N) - 1)
	arr = [i for i in range(1,N)]
	#print(subsetSum(arr, N-1, 0, N, 0))