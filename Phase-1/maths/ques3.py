'''
    Check a number is palindrome or not
'''

N = 125

temp = N

result = 0

while temp > 0:
    mod = temp % 10
    result = (result * 10) + mod
    temp = temp // 10

print(f"IS PALIMDROME : {result == N}")