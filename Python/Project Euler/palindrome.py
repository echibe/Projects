#A palindromic number reads the same both ways.
#The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

#Find the largest palindrome made from the product of two 3-digit numbers.

maxP = 0
palindrome = False
theUserIsBeingStupid = True
roof = 0

while(theUserIsBeingStupid):
    numOfDig = input("How many digits will we use? : ")
    if(numOfDig>4):
        print("Less than 5 please")
    else:
        #hooray they got smart
        theUserIsBeingStupid = False
    roof = 10**numOfDig-1
    print roof
for i in range(1,roof):
    for n in range(1,roof):
        num = i*n
        check = str(num)
        l = len(str(check))-1
        k=0
        while(1):
            if(k>l):
                if(palindrome == True):
                    if(maxP<num):
                        maxP=num
                        maxI = i
                        maxN = n
                    palindrome = False
                    break
                else:
                    break
            elif(check[k]==check[l]):
                palindrome = True
                k += 1
                l -= 1
            else:
                palindrome = False
                break
print maxP, " = ", maxI," x ", maxN

            
