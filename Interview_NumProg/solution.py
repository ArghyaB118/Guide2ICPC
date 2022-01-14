import numpy as np
import random
import math
from matplotlib import pyplot as plt

# solution of question 1
# x_1 + x_2 = 3
# x_n + x_{n + 1} = 3
# x_{i} - x_{i + 1} = 1 for i \in {2, 3, ... n}
def solution1(n):
	A = np.zeros((101,101))
	B = np.zeros(101)

	A[0][0] = 1
	A[0][1] = 1
	A[n][n - 1] = 1
	A[n][n] = 1
	B[0] = 3
	B[n] = 3

	for i in range(n - 1):
		A[i+1][i+1] = 1
		A[i+1][i+2] = -1
		B[i+1] = 1

	X = np.linalg.solve(A,B)
	return X[:-1]

print("The solution of X: " + str(solution1(100)))


# generating n points 
# x and y coordinates are chosen from a uniform distribution
# checking if the point is in the circle
def solution2(n, radius):
	points = []
	for i in range(n):
		x = round(random.uniform(-radius, radius), 3)
		y = round(random.uniform(-radius, radius), 3)
		points.append((x,y))
	count = 0
	while points:
		point = points.pop()
		distance = math.sqrt(point[0] * point[0] + point[1] * point[1])
		if distance < radius:
			count = count + 1
	return count

print("Percentage of points in the circle is: " + str(solution2(100, 10.000)))


# y = number of years
# h = highest rain in cm
def solution3(y, h):
	rain = []
	plot = np.zeros(y * 365)
	for i in range(y * 365):
		rain.append(round(random.uniform(0, h), 2))
	for i in range(y * 365 - 3):
		if (rain[i] > 3 and rain[i + 1] > 3 and rain[i + 2] > 3 and rain[i + 3] > 3):
			plot[i] = 1
			plot[i+1] = 1
			plot[i+2] = 1
			plot[i+3] = 1

	plt.plot(plot)
	plt.show()


solution3(3, 5)


def solution4(day, accident):
	array = np.array([150,100,30,30,30,20,20,10,5,5])
	length = array.size
	answer = np.zeros(length)
	for i in range(day - 1):
		answer[i] = array[i]
	answer[day - 1] = accident
	if (accident < array[day - 1]):
		deficit = array[day - 1] - accident
		for i in range(day, length):
			answer[i] = array[i] + 1.000 * deficit * array[i] / np.sum(array[day:])
	print("Modified pattern: " + str(answer))

solution4(2, 60)


def solution5a(n):
	A = np.random.randint(100, size=n)
	Asub = []
	B = []
	for i, j in enumerate(A[:-199]):
		Asub = A[i:i+200].copy()
		Asub.sort()
		B.append(0.5 * (Asub[99] + Asub[100]))
	fig = plt.figure()
	ax1 = fig.add_subplot(2, 1, 1)
	ax2 = fig.add_subplot(2, 1, 2)
	x = list(range(n - 199))
	ax1.plot(x, B)
	ax1.set_xlabel('Time unit')
	ax1.set_ylabel('B')
	x = list(range(n))
	ax2.plot(x, A)
	ax2.set_xlabel('Time unit')
	ax2.set_ylabel('A')
	plt.show()
	return A	

def solution5b(A, n):
	a = np.random.randint(n)
	while True:
		b = np.random.randint(n)
		if (b != a):
			break
	A[a] = 1000
	A[b] = 1000
	detected = 0
	Asub = []
	for i, j in enumerate(A[:-199]):
		Asub = A[i:i+200].copy()
		Asub.sort()
		if Asub[199] == 1000:
			detected = detected + 1
	print("Number of samples with spike: " + str(detected))

A = solution5a(2000)
solution5b(A, 2000)


# Solution 6
import cvxpy as cp

A_t = [500, 700, -450, 600, 640]
B_t = [300, -200, 350, -400, 100]

# part a
X_t = []
Y_t = []
x = cp.Variable()
y = cp.Variable()
constraints = [150 <= x, x <= 400, 120 <= y, y <= 320]
obj = cp.Maximize(A_t[0] * x + B_t[0] * y - 40000)
prob = cp.Problem(obj, constraints)
prob.solve()
X_t.append(x.value)
Y_t.append(y.value)

for i in range(1, 5):
	x = cp.Variable()
	y = cp.Variable()
	constraints = [150 <= x, x <= 400, 120 <= y, y <= 320, x - X_t[i-1] <= 200, y - Y_t[i-1] <= 100]
	obj = cp.Maximize(A_t[i] * x + B_t[i] * y - 40000)
	prob = cp.Problem(obj, constraints)
	prob.solve()
	X_t.append(x.value)
	Y_t.append(y.value)

print(X_t, Y_t)


# part b
X_t = []
Y_t = []
x = cp.Variable()
y = cp.Variable()
constraints = [150 <= x, x <= 400, 120 <= y, y <= 320, x + y <= 400]
obj = cp.Maximize(A_t[0] * x + B_t[0] * y - 40000)
prob = cp.Problem(obj, constraints)
prob.solve()
X_t.append(x.value)
Y_t.append(y.value)

for i in range(1, 5):
	x = cp.Variable()
	y = cp.Variable()
	constraints = [150 <= x, x <= 400, 120 <= y, y <= 320, x + y <= 400, x - X_t[i-1] <= 200, y - Y_t[i-1] <= 100]
	obj = cp.Maximize(A_t[i] * x + B_t[i] * y - 40000)
	prob = cp.Problem(obj, constraints)
	prob.solve()
	X_t.append(x.value)
	Y_t.append(y.value)

print(X_t, Y_t)

