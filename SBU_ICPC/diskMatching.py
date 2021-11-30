import numpy as np
#stack1 = [20, 15, 10, 15, 25, 20, 15]
#stack2 = [15, 25, 10, 20, 15, 20]

stack2 = [10, 20, 20, 10, 20, 10, 20, 10]
stack1 = [20, 10, 20, 10, 10, 20, 10, 10, 20]

dp = np.zeros((len(stack1), len(stack2)))

if (stack1[0] == stack2[0]):
	dp[0][0] = 1

for i in range(1, len(stack2)):
	if (stack2[i] == stack1[0]):
		dp[0][i] = 1
	else:
		dp[0][i] = dp[0][i-1]
for i in range(1, len(stack1)):
	if (stack1[i] == stack2[0]):
		dp[i][0] = 1
	else:
		dp[i][0] = dp[i-1][0]

for i in range(1, len(stack1)):
	for j in range(1, len(stack2)):
		if (stack1[i] == stack2[j]):
			if (dp[i-1,j] <= dp[i][j-1]):
				dp[i][j] = max(dp[i-1][j] + 1, dp[i][j-1])
			else:
				dp[i][j] = dp[i-1][j] 
			#else:
			#	dp[i][j] = max(dp[i-1,j], dp[i][j-1])
		else:
			dp[i][j] = max(dp[i-1,j], dp[i][j-1])

print(dp, int(dp[len(stack1)-1][len(stack2)-1]))