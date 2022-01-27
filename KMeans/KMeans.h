#ifndef KMEANS_H
#define KMEANS_H
#include <vector>
#include <string>
#include "Cluster.h"
#include "Edge.h"
using namespace std;
/** @brief K Means class performs clustering operations with K Means method using cluster, node, edge classes.
    @author RAMAZAN AKKULAK
    @date January 2022
    */
class KMeans
{
private:
    int K;/**<Number of clusters to be calculated entered from the user*/
    int iters;/**<Number of calculation attempts*/
    int dimensions;/**<Contains dimension value*/
    int total_points;/**<The int value to hold the total number of edges.r*/
    vector<Cluster> clusters;/**<Number of clusters to be calculated entered from the user.This object will be stored in the vector.*/
    vector<Edge> all_points;/**<Number of Edge to be calculated entered from the user.This object will be stored in the vector.*/
/** This function performs the cleaning process of the created cluster attempt.
*   It does this with the remove all Points function in the Cluster class.
*/
    void clearClusters();
/** This function makes Cluster arrangement by making trials to the nearest center position.
* This function returns the closest cluster to the point where it is from the edge class as a result.
*@param Edge-Point set created with edge class
*@return int 
*/
    int getNearestClusterId(Edge point);
/** This function sets the entered cluster K value.
*@param int:K This value is taken from the main function by the user.
*/
    void setK(int);
/** This function sets the entered set itreations
*@param int:iteration This value is taken from the main function by the user.
*/
    void setIters(int);
/** This function assigns the edge to be added by the user to the value vector<Edge> all_points.
*@param Edge:iteration This value is taken from the main function by the user.
*/
    void setEdgePoints(vector<Edge> &);
/** This function returns the entered cluster K value.
*@return int
*/
    int getK()const;
/** This function returns the entered the iteration.
*@return int
*/
    int getIters()const;
/** This function returns the entered the Edge points.
*@return vector<Edge>
*/
    vector<Edge> getPoints()const;
/** This function prints the cluster results.
*/
    void printClusterResult();
/** This function prints the centroid results.
*/
    void printCentroidResult();
/** This function writes the Cluster equivalents to the Cluster.txt file in accordance with the point order.
*/
    void writeFileCluster();
/** This function writes the Cluster centorid equivalents to the Centroid.txt file in accordance with the point order.
*/
    void writeFileCentroid();
    
public:
/** KMeans class constructor.
* @param Edge: Retrieves the object created from the Edge class.
* @param k: Cluster value
* @param i: Iteration number
*/
    KMeans(vector<Edge> &points,int k = 0, int i=0);
/** This function is the main function where cluster calculation and centoid tests are made using all Cluster, Node, Edge, KMeans classes.
*/
    void run();
/** This function prints all edge object values.
*/
    void printPoints(vector<Edge> &)const;
/** This function is printed after cluster calculation and centroid tests are performed using all Cluster, Node, Edge, K Means classes.
*/
    void printResult();
};
#endif