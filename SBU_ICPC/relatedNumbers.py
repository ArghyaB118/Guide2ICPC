def prime_factors(n):
	factors = []
	while (n % 2 == 0):
		n /= 2
		factors.append(2)
	for i in range(3, int(n) + 1, 2):
		while (n % i == 0):
			n /= i
			factors.append(i)
	factors = list(dict.fromkeys(factors))
	return factors

def multiple(n, limit):
	multiples = []; i = 1
	while (n * i < limit):
		multiples.append(n * i)
		i += 1
	return multiples


def related_numbers(factors, n):
	related_numbers = []
	for i in factors:
		related_numbers.extend(multiple(i, n))
	related_numbers = list(dict.fromkeys(related_numbers))
	return related_numbers

n = 20
print(prime_factors(n))
print(related_numbers(prime_factors(n), n), sum(related_numbers(prime_factors(n), n)))
