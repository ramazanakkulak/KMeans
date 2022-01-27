#ifndef CLUSTER_H
#define CLUSTER_H
#include "Edge.h"
#include <vector>
#include <string>
using namespace std;
/** @brief The Cluster class is the class that holds the values of the clustering operations.
    @author RAMAZAN AKKULAK
    @date January 2022
*/
class Cluster
{
private:
    int clusterId;/**<Contains Point clusterId*/
    vector<double> centroid;/**<Contains vector<double> centroid. The more center points it has, the more value it holds.*/
    vector<Edge> points;/**<One object was created from The Edge class. This object will be kept in vector.*/

public:
/** Cluster class constructor.
* @param int-clusterId Point(x,y) get clusterid 
* @param Edge-centroid Takes a center point from "Edge" class.
*/
    Cluster(int clusterId, Edge centroid);
/** This function adds edge node.
*@param Edge-p Add a Point(x,y)
*/
    void addPoint(Edge p);
/** This function ensures the accuracy of the created cluster point operation.
*@param int-pointid: The given cluster changes depending on the input input.
*@return bool: 1 or 0
*/
    bool removePoint(int pointId);
/** This function continuously removes the tested cluster until the correctness is achieved. In other words, a cluster attempt is made, 
*   if the accuracy of the center points is not ensured, the created cluster attempt is deleted. Then it is retried.
*/
    void removeAllPoints();
/** This function returns the order in which the edge node belongs.
*@return int: pointID
*/
    int getId();
/** This function returns the object of the node created from the Edge class.
*@param int Edge Class position 
*@return Edge
*/
    Edge getPoint(int pos);
/** This function returns the total size.
*@return int
*/
    int getSize();
/** This function returns the value entered from the vector where the cluster center points created after the trials are kept.
*@param int-Centroid position value
*@return double
*/
    double getCentroidByPos(int pos);
/** This function allows the user to create a new center point by giving positions and values ​​according to that request.
*@param int-position: A position is entered.
*@param double-val: Center point value is entered.
*@return double
*/
    void setCentroidByPos(int pos, double val);
};
#endif