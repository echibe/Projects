numberToBeDivided = 1
divisor = 2
largestDivisor = 1

while(True):
    if(numberToBeDivided==1):
        break
    elif(numberToBeDivided % divisor == 0):
        numberToBeDivided = numberToBeDivided / divisor
        largestDivisor = divisor
    else:
        divisor += 1

print largestDivisor
