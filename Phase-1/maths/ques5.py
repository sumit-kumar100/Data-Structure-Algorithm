# Program to find prime numbers with in a range (i.e, 2 - 12)
import math
n = 12
is_prime = [0 if i == 1 else 1 for i in range(1,n+1)]

print(is_prime)

for i in range(2,int(math.sqrt(n))+1):
    for j in range(2*i,n+1,i):
        is_prime[j-1] = 0

print(is_prime)