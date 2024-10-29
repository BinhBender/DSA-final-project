import random

file = open("cityPaths.txt", 'w')

cities = ["San Jose", "San Francisco", "Oakland", "Fremont", "Santa Rosa", "Hayward", "Sunnyvale", "Santa Clara", "Vallejo", "Concord", "Berkeley", "Fairfield", "Richmond", "Antioch", "San Mateo", "Daly City", "Vacaville", "San Leandro", "Livermore", "San Ramon", "Redwood City", "Mountain View", "Milpitas", "Pleasanton", "Napa", "Alameda", "Pittsburg", "Dublin", "Union City", "Walnut Creek", "Palo Alto", "South San Francisco", "Brentwood", "San Rafael", "Cupertino", "Petaluma", "Gilroy", "Novato", "Newark", "Morgan Hill", "Rohnert Park", "Campbell", "San Bruno", "Danville", "Oakley", "Pacifica", "Martinez", "Pleasant Hill", "Foster City", "Menlo Park" ]

tempcities = []

for i in cities:
	tempcities=cities.copy()
	paths = []
	max = 7
	for j in range(max):
		randomcity = random.choice(tempcities)
		tempcities.remove(randomcity)
		if randomcity not in paths and randomcity is not i:
			
			paths.append(randomcity)

	stringout = f"{i}"
	for randompicked in paths:
		stringout = stringout + ',' + randompicked

	
	file.write(f"{stringout}\n")


file.close()