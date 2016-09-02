#2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

#What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

numNotFound = True
i = 1
rangeDiv = input("Highest number of divisor: ")
addition = 1
if(rangeDiv>1):
    addition = 2
    i=2
while(numNotFound):
    if(i%2!=0):
        i+=1
    for j in range(1,rangeDiv+1):
        if(i%j!=0):
            break
        elif(j==rangeDiv):
            print "The lowest number is: ", i 
            numNotFound=False
            break

    i+=addition
    
