#ifndef EDGE_H
#define EDGE_H
#include <vector>
#include <string>
using namespace std;
/** @brief Edge class is the class that is used to hold the given point information.
    @author RAMAZAN AKKULAK
    @date January 2022
    */
class Edge
{
private:
    int pointId;/**<Contains Point id*/
    int clusterId;/**<Contains cluster value*/
    int dimensions;/**<Contains dimension value*/
    vector<double> values;/**<Contains vector data, it is belong to txt file data.*/
/** This function returns all points (x,y) as vector<double>.
* @return vector<double>
*/
    vector<double> getValue()const;
/** When this function takes any vector, it assigns it to a vector to use its functions.
*@param vector-line
*@return vector<double>
*/
    vector<double> lineToVec(vector<double> &line);
    

public:
/** Edge class constructor.
* @param id: Point(x,y) indicates which edge it belongs to.
* @param vector: It is a vector operation that keeps the points taken by the node class in order.
*/
    Edge(int id, vector<double> &);
/** This function performs the dimension display.
* @return int
*/
    int getDimensions();
/** This function shows which cluster an edge belongs to.
* @return int
*/
    int getCluster();
/** This function returns the cluster id.
* @return int
*/
    int getID();
/** This function can change the cluster of any edge.
* @param int
*/
    void setCluster(int val);
/** This function shows which cluster an edge belongs to.
* @return int-const
*/
    int getDimension()const;
/** This function returns the value of the "Edge(x,y)" point at the desired position.
* @param int-This value can be 0 and 1.A value of 0 represents the x coordinate, while a value of 1 represents the y coordinate value.             
*/
    double getVal(int pos);  
};

#endif