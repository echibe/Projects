alph = "abcdefghijklmnopqrstuvwxyz"
test = "abcxyz"
key = input("What is the key (1-25): ")
output = []
output2 = []
offset = 0

def cypher(key, test):
	for letter in test:
		offset = key+alph.find(letter)
		if offset > 25:
			offset = offset - 26
		output.append(alph[offset])
	print output

def decypher(key, test):
	for letter in test:
		offset = alph.find(letter)-key
		if offset < 0:
			offset = offset + 26
		output2.append(alph[offset])
	print output2
		
cypher(key, test)
decypher(key, output)

