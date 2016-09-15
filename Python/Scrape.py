#Elliot Chibe
#September 15th, 2016

import requests
from bs4 import BeautifulSoup

url = raw_input("What is the URL: ")
r = requests.get(url)

soup = BeautifulSoup(r.content, "lxml")

titles = soup.find_all("title")
print("")
print ("-----Title:")

for t in titles:
	print t.text

print("")
print ("-----Description:")
	
desc = soup.find_all("div", {"id": "watch-description-text"})

for d in desc:
	print d.text

print("")
print ("-----User:")
user = soup.find_all("div", {"class": "yt-user-info"})

for u in user:
	print u.text