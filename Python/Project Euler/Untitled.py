sum = 0;
for num in range(1,1000):
    if ((num % 3==0) | (num % 5==0)):
        sum += num
        # print num
        # print sum

print sum