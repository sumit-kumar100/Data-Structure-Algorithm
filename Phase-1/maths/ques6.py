# Find GCD of two numbers

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


print(gcd(30, 75))


def gcd2(a, b):
    return b if a % b == 0 else gcd2(b, a % b)


print(gcd(30, 75))
