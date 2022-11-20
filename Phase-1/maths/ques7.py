# Modulo Arithmentic for a numbers i.e, n^m


# Approach 1
def power(a,b):
    res = 1
    for i in range(b):
        res *= a
    return res

print(power(2,5))


# Approach 2
def fastPower(a,b):
    res = 1
    while b > 0:
        if b & 1 != 0:   # b & 1 means b % 2
            res *=  a
        a *= a
        b >>= 1   # b >> 1 means b//2 
    return res

print(fastPower(2,5))