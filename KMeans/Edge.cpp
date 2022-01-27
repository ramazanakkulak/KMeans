#include <string>
#include <vector>
#include <iostream>
#include "Edge.h"
#include "Node.h"
using namespace std;

Edge::Edge(int id, vector<double> &p)
{
    pointId = id;
    values = p;
    dimensions = values.size();
    clusterId = 0; // Initially not assigned to any cluster
}

vector<double> Edge::lineToVec(vector<double> &line)
{
    vector<double> values;
    values = line;
    return values;
}

int Edge::getDimensions() 
{
    return dimensions; 
}

int Edge::getCluster()
{ 
    return clusterId; 
}

int Edge::getID() 
{ 
    return pointId; 
}

void Edge::setCluster(int val) 
{ 
    clusterId = val;
}

double Edge::getVal(int pos) 
{ 
    return values[pos]; 
}
vector<double> Edge::getValue()const
{
    return values;
}