#ifndef PRIM_H
#define PRIM_H
#include <vector>
#include <string>
#include "Cluster.h"
#include "Edge.h"
#include "Graph.h"
using namespace std;
/** This structure has been created to hold the x and y points of each different cluster structure created separately.
*/
struct PrimYapi
{
    double x;/**<PrimYapi x value*/
    double y;/**<PrimYapi y value*/ 
};
/** @brief The Prim class is inherited from the Graph class, which is the class in which the prim graph algorithm results and plots.This class is inherited from the Graph class.
    @author RAMAZAN AKKULAK
    @date January 2022
*/
class Prim:public Graph{
private:
    int number; /**<Cluster value*/
    string primName;/**<Primname string value*/
    struct PrimYapi p[100];/**<100-value array created by the struct*/
    multimap<int,PrimYapi> primMap;/**<Multimap that will hold cluster and x,y points*/
    vector<int> weightData;/**<The value to hold the weights of the required premium calculation*/
    vector<double> x;/**<The x values of the cluster structure*/
    vector<double> y;/**<The y values of the cluster structure*/
/** This function returns the cluster value in which cluster is being processed.
* @return int- const value
*/
    int getNumber()const;
/** This function is the part where Prim graph calculation is made.
*/
    void CalculatePrim();
/** This function is the part where Prim graph calculation is made.
*@param vector-Sequential vector in result of premium graph calculation x value
*@param vector-Sequential vector in result of premium graph calculation y value
*@param vector-Vector for total value size
*/
    void GraphPrim(vector<double>&, vector<double>&, vector<int>&);
public:
/** Prim class constructor.
*@param name-Prim Graph name
*@param n-String name required for Graph class
*@param Edge-vector Edge required for Graph class
*@param int-cluster number 
*/
    Prim(string name,const string n,const vector<Edge> &ohm,int);
/** This function sets cluster and x,y points into multimap.
*/
    void setPrimMap();
/** A utility function to find the vertex with. Minimum key value, from the set of vertices. Not yet included in MST 
*@param double Minimum key value
*@param bool-true or false
*/
    double minKey(double key[], bool mstSet[]);
/** This function calculates the graph matrix of each cluster within itself.
*@param vector-Point x data vector
*@param vector-Point y data vector
*/
    vector<int> calculateWight(vector<double> &, vector<double>&);
/** This function returns point x.
*@param int-position 
*@return int
*/
    double getX(int);
/** This function returns point y.
*@param int-position 
*@return int
*/
    double getY(int);
    
};
#endif