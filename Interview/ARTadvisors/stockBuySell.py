# maximize profit
# by buying and selling a stock
# as many times as possible.
arr = [13, 14, 8, 2, 12, 15, 10, 18, 9]

size = len(arr)
local_minimum = arr[0]
profit = 0

for i in range(1, size):
	if arr[i] <= arr[i - 1]:
		profit += arr[i - 1] - local_minimum
		local_minimum = arr[i]
	print(profit, arr[i])
print(profit)
