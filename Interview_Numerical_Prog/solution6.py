import numpy as np
import random
import math
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
