#include "pathfinder.h"


PathFinder::PathFinder(){
}
long double PathFinder::toRadians(long double degrees) {
    return degrees * M_PI / 180.0;
}

// function to calculate the distance between two cities
long double PathFinder::calculateDistance(coord coordi1, coord coordi2) {
    // Earth's radius in kilometers
    const long double R = 6371.0;

    // Convert latitude and longitude from degrees to radians
    long double phi1 = toRadians(coordi1.first);
    long double phi2 = toRadians(coordi2.first);
    long double deltaPhi = toRadians(coordi2.first - coordi1.first);
    long double deltaLambda = toRadians(coordi2.second - coordi1.second);

    // Haversine formula
    long double a = std::sin(deltaPhi / 2) * std::sin(deltaPhi / 2) +
               std::cos(phi1) * std::cos(phi2) *
               std::sin(deltaLambda / 2) * std::sin(deltaLambda / 2);
    long double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    long double distance = R * c;

    return distance;
}


//Graph searching using dijkstra algorithm
void PathFinder::dijkstra(int startNode,long double maxaqiAllowed)
{
    // Set all distances to infinity
    for (int i = 0; i <= 99; ++i)
    {
      //so far, the distance from the start node to all other nodes are infinite
        dist[i] = INT_MAX;
      //initialize the array for storing the paths
        pre[i] = -1; 
    }
    // Create a priority queue to hold nodes to be processed
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;

    // Add the start node to the priority queue with distance 0
    pq.push(std::make_pair(0, startNode));
    dist[startNode] = 0;

    while (!pq.empty())
    {
        // Get the node with minimum distance from the priority queue
        int currentNode = pq.top().second;
        pq.pop();

        // Process all adjacent nodes of the current node
        for (int i = 0; i < adjList[currentNode].size(); ++i)
        {
            int adjacentNode = adjList[currentNode][i].second;
            int weight = adjList[currentNode][i].first;
            if (SystemData::IndexToCity[adjacentNode].get_aqi() <= maxaqiAllowed)
            {
                //if the condition fits, relax the edge
                if (dist[currentNode] != INT_MAX &&weight>0&& dist[adjacentNode] > dist[currentNode] + weight)
                {
                    dist[adjacentNode] = dist[currentNode] + weight;
                  //store the path
                    pre[adjacentNode] = currentNode; 
                  //BFS, push the new pair into the priority queue
                    pq.push(std::make_pair(dist[adjacentNode], adjacentNode));
                }
            }
        }
    }
}

// Function to print the shortest path from the start node to a given node
void PathFinder::printShortestPath(int node)
{
    double timetaken = 0;
    if (dist[node] == INT_MAX)
    {
        std::cout << "There does not exist to be path that is safe enough to " << node << std::endl;
        return;
    }

    Stack<int> path;
    int currNode = node;

    // Build the path by backtracking from the target node to the start node
    while (currNode != -1)
    {
        path.push(currNode);
        currNode = pre[currNode];
    }
    std::cout << "The Path to take: " << SystemData::IndexToCity[node].get_name() << ": ";
    while (path.GetSize() != 0)
    {
        //add something to display the time it would take to go from a -> b in whatever measurements you guys want
        std::cout << SystemData::IndexToCity[path.top()].get_name();
		path.pop();
        if (path.GetSize() != 0)
            std::cout << " -> ";
    }
  //display the total length of the path and give the user an approximate time it takes to get to the destination
    std::cout << std::endl;
    std::cout<<"The total distance of this path is "<< dist[node] <<" km.\n";
    std::cout<<"Assuming that you have an average speed of 40 km/h, it would take "<<dist[node]/40.0<<" hours to get to the destination.\n";
}


void PathFinder::CreatePaths(){
	
	long double weight;
	
	for(auto& iterator: SystemData::CityPaths){

		int size = iterator.second.size();
		int fromNode = SystemData::CityNameToIndex[iterator.first];
        int toNode;
		for(int i = 0; i < size; i++){

			toNode = SystemData::CityNameToIndex[iterator.second[i]];
			//for testing purposes
			//std::cout << "\nFromNode: "<< iterator.first << " " << fromNode << " ToNode: " << iterator.second[i] << " " << toNode;
			//calculate the weight of the edge, and use it as the first component of the pair(pii)
			weight = calculateDistance(SystemData::IndexToCity[fromNode].get_coord(), SystemData::IndexToCity[toNode].get_coord());
        	adjList[fromNode].push_back(std::make_pair(weight,toNode));
       		adjList[toNode].push_back(std::make_pair(weight,fromNode));
		}

	}
	
}