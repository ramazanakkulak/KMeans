#define _USE_MATH_DEFINES
#include "matplotlibcpp.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include "KMeans.h"
#include "Graph.h"
#include "Edge.h"
#include "Cluster.h"
#include <vector>
#include <cstdio>
#include <climits>
#include <cmath>
#include <algorithm>
#include <iomanip>


namespace plt = matplotlibcpp;
using namespace std;

Graph::Graph(const string n,const vector<Edge> &ohm):
        name(n),
        points(ohm)
{
  readClusterData();
  readCentroidData(); 
}
void Graph::graphKMeansClustering(string N)
{
  setName(N);
  drawCentroid();
  drawCluster();
}
void Graph::setName(string n)
{
  name = n;
}
void Graph::readClusterData()
{
  int number;
  ifstream input_file("Cluster.txt");
  while(input_file >> number)
  {
    setValueCluster(number);
  }
}
void Graph::readCentroidData()
{
  double number;
  vector<double> temp;
  ifstream input_file("Centroid.txt");
  while(input_file >> number)
  {
    temp.push_back(number);
  }
  for(int i=0;i<temp.size();++i)
  {
    if(i%2 == 0)
      setXCentroid(temp.at(i));
    if(i%2 == 1)
      setYCentroid(temp.at(i));  
  } 
}
void Graph::drawCentroid()
{
  vector<double> z;
  vector<double> x;
  plt::plot(getXCentroid(), getYCentroid(),"k*");
  plt::named_plot("o Cultering",x,z);
  plt::named_plot("* Centroid",x,z);
  plt::legend();
}
void Graph::drawCluster()
{
  
  for(int i= 0; i<valueCluster.size();i++)
  {
    choosePlotCluster(i,valueCluster[i]);
  }

  plt::xlabel("Coordinate x");
  plt::ylabel("Coordinate y");
  plt::title(getName());
  plt::save("kmeans_clustering.png"); 
  plt::show();
  
}
void Graph::choosePlotCluster(int i,int number)
{
  vector<double> y;
  vector<double> x;
  switch(number)
  {
    case 1:
      x.push_back(points[i].getVal(0));
      y.push_back(points[i].getVal(1));
      plt::plot(x, y, "bo");
      x.clear();
      y.clear();
      break;
    case 2:
      x.push_back(points[i].getVal(0));
      y.push_back(points[i].getVal(1));
      plt::plot(x, y, "go");
      x.clear();
      y.clear();
      break;
    case 3:
      x.push_back(points[i].getVal(0));
      y.push_back(points[i].getVal(1));
      plt::plot(x, y, "ro");
      x.clear();
      y.clear();
      break;
    case 4:
      x.push_back(points[i].getVal(0));
      y.push_back(points[i].getVal(1));
      plt::plot(x, y, "co");
      x.clear();
      y.clear();
      break;
    case 5:
      x.push_back(points[i].getVal(0));
      y.push_back(points[i].getVal(1));
      plt::plot(x, y, "mo");
      x.clear();
      y.clear();
      break;
    case 6:
      x.push_back(points[i].getVal(0));
      y.push_back(points[i].getVal(1));
      plt::plot(x, y, "yo");
      x.clear();
      y.clear();
      break;
    case 7:
      x.push_back(points[i].getVal(0));
      y.push_back(points[i].getVal(1));
      plt::plot(x, y, "wo");
      x.clear();
      y.clear();
      break;
    default:
      cout<<"Cluster draw not possible."<<endl;
      break;
  }
}
string Graph::getName()const
{
  return name;
}

double Graph::getXCentroid(int i)const
{
  return xCentroid.at(i);
}

double Graph::getYCentroid(int i)const
{
  return yCentroid.at(i);
}

int Graph::getCluster(int value)const
{
  return valueCluster.at(value);
}

vector<double> Graph::getXCentroid()const
{
  return xCentroid;
}

vector<double> Graph::getYCentroid()const
{
  return yCentroid;
}

void Graph::setXCentroid(double value)
{
  xCentroid.push_back(value);
}

void Graph::setYCentroid(double value)
{
  yCentroid.push_back(value);
}

void Graph::setValueCluster(int value)
{
  valueCluster.push_back(value);
}
Graph::~Graph()
{
  //empty body
}
vector<int> Graph::getValueCluster()
{
  return valueCluster;
}


ostream& operator<<(ostream &output ,const Graph &obje)
{
  output << "Grap: "<<obje.getName()<<" are as follows."<<endl;
  for(int i = 0;i<obje.xCentroid.size();++i){
    output<<"Centroid is "<<i+1<<": "<<obje.getXCentroid(i)<<" , "<<obje.getYCentroid(i)<<""<<endl;
  }
  return output;
}