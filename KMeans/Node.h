#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>
#include <ostream>
using namespace std;
/** @brief Node class is the class that is used to hold the given point information in txtFile.
    @author RAMAZAN AKKULAK
    @date January 2022
    */
class Node{
/**
 * @brief  operator << Performs operator overloading of the cout operation.
 * @param ostream : That is a name for example "output"
 * @param Node: It takes an input value from the node class.
 * @return ostream& 
 */
friend ostream &operator<<(ostream & ,const Node &);
private:
    const string txtName; /**<txt file name*/
    vector<double> data; /**<vector holding x and y pointse*/ 
    vector<double> x; /**<x data*/
    vector<double> y;/**<y data*/
    static int count;/**<static count This is a counter*/
    static int countXCoordinate;/**<static count This is a counter for x coordinates.*/
    static int countYCoordinate;/**<static count This is a counter for y coordinates.*/
    
public:
/** Node class constructor.
 * @param string : const string holding required txt file
        */
    Node(const string &fileName= "txtFileName");
/** This function is reading from the file.
 * @param string : const string holding required txt file
        */
    void readCoordinate(string);
/**
 * @brief  This function shows the result of how many points are in the file.
 * 
 * @return static int
 */
    static int getCount();
/**
 * @brief  This function shows the result of how many x coordinates points are in the file.
 * 
 * @return static int
 */
    static int getcountXCoordinate();
/**
 * @brief  This function shows the result of how many x coordinates points are in the file.
 * 
 * @return static int
 */
    static int getcountYCoordinate();
/**
 * @brief  This function shows the result of how many y coordinates points are in the file.
 *  
 */
    void sperateXYCoordinate();
/**
 * @brief  This function separates the data from the file into x and y.
 *  
 */
    ~Node();
/**
 * @brief  This function is designed according to the user's desire to add data.
 *         For point x only.        
 * @param double
 */
    void setX(double);
/**
 * @brief  This function returns the value of the x point in the desired order in the data.
 * @param int: desired value
 * @return int
 */
    double getX(int)const;
/**
 * @brief  This function is designed according to the user's desire to add data.
 *         For point y only.        
 * @param double
 */
    void setY(double);
/**
 * @brief  This function returns the value of the y point in the desired order in the data.
 * @param int: desired value
 * @return int
 */
    double getY(int)const;
/**
 * @brief  This function displays the filename.
 *
 * @return string: txtFile name
 */
    string getTxtName()const;
/**
 * @brief  This function displays the value of all points to the console.
 *
 * 
 */
    void print();
/**
 * @brief  This function allows all points to be taken in a vector.
 *
 * @return vector<double>
 */
    vector<double>getData()const;
};
#endif