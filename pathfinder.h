#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include "stack.h"
#include <cmath>
#include <unordered_map>
#include "city.h"
#include "system_data.h"

#pragma once
//Holds the pm level and index of city
typedef std::pair<long double, int> pii;
class PathFinder
{
public:

//Convert Degrees to radians
	long double toRadians(long double);

//Converts the sphereical coordinate values to linear cartesian coordinates
	long double calculateDistance(coord, coord);

//Given a strating point, map out the shortest path to each node
	void dijkstra(int, long double);

//Given a destination point, print out the shortest path from that node to the starting node
	void printShortestPath(int);

//Creates the graph that the algorithm runs on
	void CreatePaths();

//Doesn't do anything
	PathFinder();

private:
	// Why not just use an array?
	// std::unordered_map<std::string,int> roster2;
	std::vector<pii> adjList[100];
	long double dist[100];
	int pre[100];
};