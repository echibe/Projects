a,b = 1,1
sum = 0
for i in range(4000000):
    a,b = b,a+b
    if(a>4000000):
        break
    if(a%2==0):
        sum += a
print sum
