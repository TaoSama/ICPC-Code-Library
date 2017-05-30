import sys

def exgcd(a, b):
    d = a; x = 1; y = 0
    if b != 0:
        d, y, x = exgcd(b, a % b)
        y -= (a / b) * x
    return (d, x, y)

def solve(a, b, c):
    if a == 0 and b == 0:
        if c != 0: return -1
        else: return 0
    if a == 0:
        if c % b == 0 and c / b <= 0: return -c / b
        else: return -1
    if b == 0:
        if c % a == 0 and c / a >= 0: return c / a
        else: return -1

    g, x, y = exgcd(a, b)
    if c % g != 0: return -1

    a /= g; b /= g; c /= g
    x *= c; y *= c

    if x > 0:
        k = x / b
        x -= k * b
        y += k * a
    elif x < 0:
        k = (-x + b - 1) / b
        x += k * b
        y -= k * a
    if y > 0:
        k = (y + a - 1) / a
        x += k * b
        y -= k * a
    return x - y

fin = sys.stdin
#fin = open(r'C:\Users\TaoSama\Desktop\in.txt')
fout = sys.stdout

t = int(fin.readline())
for _ in range(t):
    x, y, p, q = map(int, fin.readline().split())
    fout.write("{}\n".format(solve(q - p, p, p * y - q * x)))
