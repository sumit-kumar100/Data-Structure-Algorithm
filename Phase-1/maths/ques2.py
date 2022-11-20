'''
    Find the trailing zeros in a factorial of a number
    i.e, input :- 12!  output :- 2 or input :- 30! output :- 7 
'''

n = 30
result = 0
gap = 5
while(gap <= n):
    result += (n//gap)
    gap *= 5

print(result)