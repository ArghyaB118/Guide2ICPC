/*
A positive integer is considered uniform if all of its digits 
are equal. For example, 222 is uniform, while 223 is not.
Given two positive integers A and B, 
determine the number of uniform integers between 
A and B, inclusive.
*/

int numOfDigits(long long num) {
  int digitsN = 0;
  while (num > 0) {
    digitsN++;
    num /= 10;
  }
  return digitsN;
}

int getUniformIntegerCountInIntervalOld(long long A, long long B) {
  // Write your code here
  int uniformN = 0;
  for (long long i = A; i <= B; i++) {
    int digitsN = numOfDigits(i);
    long long num = 0;
    while (digitsN > 0) {
      num = num * 10 + 1;
      digitsN--;
    }
    if (i % num == 0)
      uniformN++;
  }
  return uniformN;
}

int getUniformIntegerCountInInterval(long long A, long long B) {
  // Write your code here
  int uniformN = 0;
  int digitsA = numOfDigits(A);
  int digitsB = numOfDigits(B);
  for (int i = digitsA; i <= digitsB; i++) {
    long long num = 0;
    int digitsN = i;
    while (digitsN > 0) {
      num = num * 10 + 1;
      digitsN--;
    }
    for (int j = 1; j <= 9; j++) {
      if (num * j >= A && num * j <= B)
        uniformN++;
    }
  }
  return uniformN;
}
