def is_leap(year):
    leap = False
    
    if(year%4==0):
        leap = True
        if(year%100==0):
            leap = False
            if(year%400==0):
                leap = True
    return leap

def print_years(i, j):
	year = j
	count = 0
	leap = False
	while(count<i):
		leap = False
		if(year%4==0):
			leap = True
			if(year%100==0):
				leap = False
				if(year%400==0):
					leap = True
		if(leap==True):
			print(year)
			count += 1
		year += 1
	

selection = input("What mode? [a]=search a year [b]=print next i leap years: ")
print()

if(selection=='a'):
	year = int(input("What year: "))
	if(is_leap(year)):
		print(year, "is a leap year!")
	else:
		print(year, "is not a leap year.")
else:
	i = int(input("How many leap years?: "))
	j = int(input("What is the current year?: "))
	(print_years(i, j))