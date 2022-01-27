#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Node.h"
#include "Edge.h"
#include "Cluster.h"
#include "KMeans.h"
#include "Graph.h"
#include "Prim.h"

using namespace std;

int main()
{
    string txtFileName = "50.txt";
    int pointId = -1;
    int iters = 10;
    int cluster = 4;

    vector<Edge> all_points;

	Node n(txtFileName);

	cout<<"Number of Node after objects is are N(x,y)-->\n-->number of x coordinate: "
			<<Node::getcountXCoordinate()<<"\n-->number of y coordinate: "
			<<Node::getcountYCoordinate()<<endl;

    //cout<<n;
    
    for(int i = 0; i<Node::getcountXCoordinate(); ++i){
        vector<double> temp;
        temp.push_back(n.getX(i));
        temp.push_back(n.getY(i));
        Edge point(pointId, temp);
        all_points.push_back(point);
        pointId++;
    }

    KMeans kmeans(all_points, cluster, iters);
    kmeans.run();
    kmeans.printResult();
    cout <<endl;
    Graph plot("KMeans Clustering",all_points);
    plot.graphKMeansClustering("KMeans Clustering");
    Prim primPlot("PrimCluster","Prims KMeans",all_points,cluster);
    plot.graphKMeansClustering("Prim Graph");
    //cout<<plot;
    
}
