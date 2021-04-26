#TestBinaryTrees.py
#05/04/2021

from collections import deque 

# Spain road map tree
graf = {}
graf["Vigo"] = ["A Coruña", "Orense"]
graf["A Coruña"] = []
graf["Orense"] = ["Ponferrada"]
graf["Ponferrada"] = ["Santander", "Madrid"]
graf["Santander"] = ["San Sebastian", "Zaragoza"]
graf["Madrid"] = ["Albacete", "Cordoba"]
graf["Zaragoza"] = ["Tarragona"]
graf["San Sebastian"] = []
graf["Tarragona"] = ["Valencia"]
graf["Valencia"] = ["Alicante"]
graf["Albacete"] = []
graf["Cordoba"] = ["Albacete", "Almeria"]
graf["Almeria"] = ["Alicante"]


def goToDestiny(startCity, endCity) :
	queue = deque()
	queue += graf[startCity]
	checked = []
	while queue :
		city = queue.popleft()
		if not city in checked :
			if city == endCity :
				print("Arrived to " + city)
				print("Checked Cities:")
				print(checked)
				return True
			else :
				queue += graf[city]
				checked.append(city)
	return False

goToDestiny("Vigo", "Madrid")