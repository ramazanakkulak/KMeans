#include "Cluster.h"
#include "Edge.h"
#include <vector>
#include <string>
using namespace std;

Cluster::Cluster(int clusterId, Edge centroid)
{
    this->clusterId = clusterId;
    for (int i = 0; i < centroid.getDimensions(); i++)
    {
        this->centroid.push_back(centroid.getVal(i));
    }
    this->addPoint(centroid);
}
void Cluster::addPoint(Edge p)
{
    p.setCluster(this->clusterId);
    points.push_back(p);
}
bool Cluster::removePoint(int pointId)
{
    int size = points.size();

    for (int i = 0; i < size; i++)
    {
        if (points[i].getID() == pointId)
        {
            points.erase(points.begin() + i);
            return true;
        }
    }
    return false;
}
void Cluster::removeAllPoints() 
{ 
    points.clear(); 
}
int Cluster::getId() 
{ 
    return clusterId; 
}

Edge Cluster::getPoint(int pos) 
{ 
    return points[pos]; 
}

int Cluster::getSize() 
{ 
    return points.size(); 
}

double Cluster::getCentroidByPos(int pos) 
{ 
    return centroid[pos]; 
}

void Cluster::setCentroidByPos(int pos, double val) 
{ 
    this->centroid[pos] = val; 
}

