import numpy as np
import random

x = random.randint(1,6)

num = 100
sum = 0
for i in range(num):
	x = random.randint(1,6)
	sum = sum + x

print(sum / num)