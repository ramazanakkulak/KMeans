#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "Edge.h"
#include "Cluster.h"
#include "KMeans.h"

using namespace std;
/** @brief Graph class is the class where plotting operations are made after calculations.
    @author RAMAZAN AKKULAK
    @date January 2022
    */
class Graph{
/**
 * @brief  operator << Performs operator overloading of the cout operation.
 * @param ostream : That is a name for example "output"
 * @param Graph: It takes an input value from the node class.
 * @return ostream& 
 */
friend ostream& operator<<(ostream &output ,const Graph &);
protected:
    vector<Edge> points;/**<It is the vector of the Edge class defined as protected.*/
private:
    vector<int> valueCluster;/**<It is the vector in which the cluster values are kept.*/
    vector<double> xCentroid;/**<It is the vector in which the x values of the center points are held.*/
    vector<double> yCentroid;/**<It is the vector in which the y values of the center points are held.*/
    vector<double> pointsData;/**<pointData */
    string name;/**<It is the string value that will hold the graphic name to be created. */
    vector<Cluster> clusters;/**<It is the cluster vector created to use the values of the cluster object in order.*/
/** This function is the process of plotting the generated cluster values..
*/
    void drawCluster();
/** This function is the process of plotting the generated centroid values.
*/
    void drawCentroid();
/** This function plots the points in different clusters by giving them appropriate colors.
*@param int This value indicates the order.
*@param int The value of the cluster cluster it belongs to
*/
    void choosePlotCluster(int,int);
/** This function plots the center points in the selected color.
*/
    void choosePlotCentroid();
/** It reads the data found with the cluster class and written to the clustered.txt file.
*/
    void readClusterData();
/** It reads the data found with the cluster class and written to the centorid.txt file.
*/
    void readCentroidData();
/** This function returns the entered const string plot object name.
* @return string-name
*/
    string getName()const;
/** This function changes the entered name.
* @param string-name
*/
    void setName(string);
/** This function returns the x value of the center point in the entered order.
* @param int-position
* @return double: position - centorid value
*/
    double getXCentroid(int)const;
/** This function returns the y value of the center point in the entered order.
* @param int-position
* @return double: position - centorid value
*/
    double getYCentroid(int)const;
/** This function returns the x value vector of the center point in the entered order.
* @return const vector: all centorid value
*/
    vector<double> getXCentroid()const;
/** This function returns the y value vector of the center point in the entered order.
* @return const vector: all centorid value
*/
    vector<double> getYCentroid()const;
/** This function allows a y new center point to be given..
* @param double - value
*/
    void setXCentroid(double);
/** This function allows a x new center point to be given..
* @param double - value
*/
    void setYCentroid(double);
/** This function allows a new cluster to be given..
* @param int - value
*/
    void setValueCluster(int);
    
    
public:
/** Graph class constructor.
* @param string: Grap plot name
* @param Edge: Retrieves the object created from the Edge class.
*/
    Graph(const string,const vector<Edge> &);  
/** This function starts plot operations.
* @param string: Grap plot name
*/
    void graphKMeansClustering(string);
/** This function returns cluster values.
* @return vector<int>
*/
    vector<int> getValueCluster();
/** This function returns cluster values.
* @param int-position
* @return int-cluster value
*/
    int getCluster(int)const;
/** Graph class destructor.
*/
    ~Graph();
};
#endif