import heapq
from collections import defaultdict

def contest_trip():
    C = int(input())  
    cities = []
    for i in range(C):
        city = input().strip()  
        cities.append(city)
    
    city_to_idx = {city: i for i, city in enumerate(cities)}
    
    T = int(input())  
    trains = []
    for i in range(T):
        ti = int(input())  
        train = []
        for j in range(ti):
            time, city = input().split()  
            time = int(time)
            city = city.strip() 
            train.append((time, city))
        trains.append(train)
    
    start_time = int(input())  
    start_city = input().strip() 
    end_city = input().strip() 
    
    graph = defaultdict(list)
    
    for train in trains:
        for i in range(len(train) - 1):
            departure_time, departure_city = train[i]
            arrival_time, arrival_city = train[i + 1]
            graph[city_to_idx[departure_city]].append((arrival_time, city_to_idx[arrival_city], departure_time))
    
    pq = []
    heapq.heappush(pq, (start_time, start_time, city_to_idx[start_city], start_time))
    
    num_cities = len(cities)
    best_arrival = [float('inf')] * num_cities
    best_departure = [0] * num_cities
    best_arrival[city_to_idx[start_city]] = start_time
    
    while pq:
        current_arrival, current_departure, city, initial_departure = heapq.heappop(pq)
        
        if cities[city] == end_city:
            print(f"Departure {str(initial_departure).zfill(4)} {start_city}")
            print(f"Arrival {str(current_arrival).zfill(4)} {end_city}")
            return
        
        for arrival_time, next_city, departure_time in graph[city]:
            if departure_time >= current_arrival: 
                if (arrival_time < best_arrival[next_city]) or \
                   (arrival_time == best_arrival[next_city] and departure_time > best_departure[next_city]):
                    best_arrival[next_city] = arrival_time
                    best_departure[next_city] = departure_time
                    heapq.heappush(pq, (arrival_time, departure_time, next_city, initial_departure))
    
    print("No connection")

contest_trip()


