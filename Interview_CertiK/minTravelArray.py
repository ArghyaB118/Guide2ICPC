# Problem: An array and an initial index within the array is given. 
# At each index, you can either go left or right, 
# exactly number of steps equal to the cell value.
# How mnay steps to reach the right end of the array?
# If you cannot reach return -1.

def dfs(arr, index, moves):
    if (index == len(arr) - 1):
        return moves
    elif (index + arr[index] >= len(arr) - 1):
        return moves + 1
    elif (arr[index] == 0):
        return -1
    if (index - arr[index] >= 0):
        if dfs(arr, index + arr[index], moves + 1) != -1 and dfs(arr, index - arr[index], moves + 1) != -1:
            return min (dfs(arr, index + arr[index], moves + 1), dfs(arr, index - arr[index], moves + 1))
        elif dfs(arr, index + arr[index], moves + 1) == -1 and dfs(arr, index - arr[index], moves + 1) == -1:
            return -1
        elif dfs(arr, index + arr[index], moves + 1) != -1 and dfs(arr, index - arr[index], moves + 1) == -1:
            return dfs(arr, index + arr[index], moves + 1)
        elif dfs(arr, index + arr[index], moves + 1) == -1 and dfs(arr, index - arr[index], moves + 1) != -1:
            return dfs(arr, index - arr[index], moves + 1)
    return dfs(arr, index + arr[index], moves + 1)

# This method calls DFS. Hence, allows the pointer to move in both directions in the array.
def minTravelsDFS(arr, index):
    moves = 0
    return dfs(arr, index, moves)

# This method allows traveling only rightward
def minTravels(arr, index):
    moves = 0
    while (index < len(arr) - 1 and arr[index] != 0):
        index = index + arr[index]
        moves = moves + 1
    if (index >= len(arr) - 1):
        return moves
    return -1

arr1 = [1, 3, 1, 2, 2]
arr2 = [5, 4, 0, 1, 0, 0]
index = 2

arr3 = [1]

print(minTravels(arr1, index))
print(minTravelsDFS(arr1, index))
print(minTravelsDFS(arr2, index))
print(minTravelsDFS(arr3, 0))