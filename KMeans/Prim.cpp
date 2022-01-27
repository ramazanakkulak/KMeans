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
#include "Prim.h"
#include <vector>
#include <cstdio>
#include <climits>
#include <cmath>
#include <algorithm>
#include <iomanip>

namespace plt = matplotlibcpp;
using namespace std;

static int SIZ = 0;

Prim::Prim(string name,const string n,const vector<Edge> &ohm,int clusterNumber)
          :primName(name),
          Graph(n,ohm),
          number(clusterNumber)
{
  setPrimMap();
  CalculatePrim();
}

void Prim::setPrimMap()
{
  for(int i = 0;i<getValueCluster().size();i++){
    p[i].x = points[i].getVal(0);
    p[i].y = points[i].getVal(1);
    primMap.insert(make_pair(getCluster(i),p[i]));
  }
}

void Prim::CalculatePrim()
{
  for(int i = 1; i<=getNumber();i++){
    std::pair <std::multimap<int,PrimYapi> ::iterator, std::multimap<int,PrimYapi> ::iterator> ret;
    ret = primMap.equal_range(i);
    int sayac = 0;
    cout<<"\n\nCluster data "<<endl;       
    for (std::multimap<int,PrimYapi>::iterator it=ret.first; it!=ret.second; ++it){
      std::cout << ' ' << it->second.x<<" "<<it->second.y<<" "<<endl;
      x.push_back(it->second.x);
      y.push_back(it->second.y);
    }
    weightData = calculateWight(x,y);
    GraphPrim(x,y,weightData);
    x.clear();
    y.clear();
    }
}

double Prim::minKey(double key[], bool mstSet[])
{
  // Initialize minimum value
  int min = INT_MAX, min_index;

  for (int v = 0; v < SIZ; v++)
    if (mstSet[v] == false && key[v] < min)
      min = key[v], min_index = v;
    return min_index;
  }


vector<int> Prim::calculateWight(vector<double>& temp_x,vector<double>& temp_y)
{
  double array[temp_x.size()][temp_y.size()];
  for(int i = 0; i<temp_x.size();i++){
    for(int j=0;j<temp_y.size();j++){
      double dist_x = pow((temp_x[j]- temp_x[j]),2);
      double dist_y = pow((temp_y[i]- temp_y[j]),2);
      double calcu = sqrt(dist_x+dist_y);
      array[i][j] = calcu;
    }
  }
  SIZ = temp_x.size();  
  double graph[SIZ][SIZ];
  cout<<"\n\nPrim Graph Matris\n\n"<<endl;        
  for(int i = 0; i<temp_x.size();i++){
    for(int j = 0; j<temp_y.size();j++){
      cout <<setfill(' ')<<setprecision(4)<<setw(6)<<array[i][j]<<"  ";
      graph[i][j] = array[i][j];
    }
    cout<<endl;
  }

  double parent[SIZ]; // Array to store constructed minimum spanning tree
  double  key[SIZ]; // Key values used to pick minimum weight edge in cut
  bool mstSet[SIZ]; // To represent set of vertices not yet included in minimum spanning tree

                        // Initialize all keys as INFINITE
  for (int i = 0; i < SIZ; i++)
    key[i] = INT_MAX, mstSet[i] = false;

    // Always include first 1st vertex in minimum spanning tree.
    key[0] = 0;	 // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of minimum spanning tree 

                        // The minimum spanning tree will have V vertices
    for (int count = 0; count < SIZ; count++){
    // Pick the minimum key vertex from the set of vertices
    // not yet included in minimum spanning tree
      int u = minKey(key, mstSet);

      // Add the picked vertex to the minimum spanning tree Set
      mstSet[u] = true;

      // Update key value and parent index of the adjacent vertices of
      // the picked vertex. Consider only those vertices which are not yet
      // included in the minimum spanning tree
      for (int v = 0; v < SIZ; v++)
        // graph[u][v] is non zero only for adjacent vertices of m
        // minimum spanning treeSet[v] is false for vertices not yet included in minimum spanning tree
        // Update the key only if graph[u][v] is smaller than key[v]
        if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
          parent[v] = u, key[v] = graph[u][v];
    }
    vector<int> result;
    cout<<"\n\nPrim Result\n\n"<<endl;
    for (int i = 1; i < SIZ; i++){
      int j= parent[i];
      cout<<parent[i]<<" "<<i<<" "<<graph[i][j]<<endl;
      result.push_back(parent[i]);
    }      
    return result;
}

double Prim::getX(int i)
{
  return x[i];
}
double Prim::getY(int i)
{
  return y[i];
}

void Prim::GraphPrim(vector<double>& x_temp, vector<double>& y_temp, vector<int>& w)
{
  int j = 0;
  for(int i = 1; i<w.size()+1;i++){
    vector<double> tempx,tempy;
    tempx.push_back(x_temp[w[j]]);
    tempy.push_back(y_temp[w[j]]);
    tempx.push_back(x_temp[i]);
    tempy.push_back(y_temp[i]);
    plt::plot(tempx,tempy,"k-");
    j++;
    
  }
}
int Prim::getNumber()const
{
  return number;
}