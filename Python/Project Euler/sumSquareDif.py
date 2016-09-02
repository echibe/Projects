highestNum = input("To what number are we going? : ")
sumOfSquares, sumNum = 0,0
for i in range(1, highestNum+1):
    sumOfSquares += i**2
    sumNum += i

print(sumNum**2-sumOfSquares)
