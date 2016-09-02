whichPrime = input("What prime number are we looking for? : ")
def findPrime(num):
    i = 2
    n = 0
    while(1):
        for j in range(2,i+1):
            if(j==i):
                n += 1
                break
            elif(i%j == 0):
                break
        if(n==num):
                return i
        i += 1
        
print "The number is: " , findPrime(whichPrime)
