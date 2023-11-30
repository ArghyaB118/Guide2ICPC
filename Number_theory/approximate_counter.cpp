/*
 In order to keep a count of 1023 items,
 we keep the actual count => we need at least 10 bits.

 But, what if we want to count 2^20 = 1048576 ~ 1000000 items instead of 2^10 = 1023 ~ 1000 items?
 However, we only have 10 number of bits. We are happy with an approximate count.
 We can live with a percentage of error.
 
 Probabilistic approach:
 1. Keep a track of constant factor of n:
 To count 2048 with 10 digits, probability to increase the count is p = 0.5.
 => Every time you see the event, toss a fair coin, if it's head, increase the count.
 => Predicted count = value is counter * (1 / 0.5) = (v * 2) AS value in counter, v = n * p
 => Error in predicted count = |predicted count - actual count| = standard deviation
 => standard deviation = std = \sqrt{n * p * (1 - p)} = \sqrt{v / 2}
 => For v = 1000, n * p = 1000, n = 2000, and std = \sqrt{512}.
 
 2. Morris' Algorithm:
 value in counter = v_n = \log_e (1 + n) = \ln (1 + n). HENCE, n_v = e^{v_n} - 1
 probability to increase the counter: d = \frac{1}{n_{v + 1} - n_v}
 To avoid errors from rounding off values, we choose selective values for p.
 
 
 Insight: Instead of using O(\log n) space, we use O(\log \log n) space.
 
 Bibliography:
 1. Morris, R. (1978). Counting large numbers of events in small registers. Communications of the ACM, 21(10), 840–842.
 2. Flajolet, P. (1985). Approximate counting: a detailed analysis. BIT Numerical Mathematics, 25(1), 113–134.
*/
