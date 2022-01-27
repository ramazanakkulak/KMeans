#include <vector>
#include <string>
#include <omp.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Cluster.h"
#include "Edge.h"
#include "KMeans.h"
using namespace std;

KMeans::KMeans(vector<Edge> &points,int k, int i):
        all_points(points)
{
    setK(k);
    setIters(i);
    
}

void KMeans::clearClusters()
{
    for (int i = 0; i < K; i++)
    {
        clusters[i].removeAllPoints();
    }
}

int KMeans::getNearestClusterId(Edge point)
{
    double sum = 0.0, min_dist=1e12;
    int NearestClusterId;
    if(dimensions==1) {
    min_dist = abs(clusters[0].getCentroidByPos(0) - point.getVal(0));
    }	
    else 
    {
        for (int i = 0; i < dimensions; i++)
        {
        sum += pow(clusters[0].getCentroidByPos(i) - point.getVal(i), 2.0);
        }
        min_dist = sqrt(sum);
    }
    NearestClusterId = clusters[0].getId();

    for (int i = 1; i < K; i++)
    {
        double dist;
        sum = 0.0;
            
        if(dimensions==1) 
        {
            dist = abs(clusters[i].getCentroidByPos(0) - point.getVal(0));
        } 
        else {
            for (int j = 0; j < dimensions; j++)
            {
            sum += pow(clusters[i].getCentroidByPos(j) - point.getVal(j), 2.0);
            }

        dist = sqrt(sum);
            
        }
        if (dist < min_dist)
        {
            min_dist = dist;
            NearestClusterId = clusters[i].getId();
        }
    }

    return NearestClusterId;
}

void KMeans::run()
{
    total_points = all_points.size();
    dimensions = all_points[0].getDimensions();     
        // Initializing Clusters
    vector<int> used_pointIds;

    for (int i = 1; i <= K; i++)
    {
        
        while (true)
        {
            int index = rand() % total_points;

            if (find(used_pointIds.begin(), used_pointIds.end(), index) ==
                used_pointIds.end())
            {
                used_pointIds.push_back(index);
                all_points[index].setCluster(i);
                Cluster cluster(i, all_points[index]);
                clusters.push_back(cluster);
                break;
            }
        }
    }

    int iter = 1;
    while (true)
    {
        cout << "Iter - " << iter << "/" << iters << endl;
        bool done = true;

        // Add all points to their nearest cluster
        
        for (int i = 0; i < total_points; i++)
        {
            int currentClusterId = all_points[i].getCluster();
            int nearestClusterId = getNearestClusterId(all_points[i]);

            if (currentClusterId != nearestClusterId)
            {
                all_points[i].setCluster(nearestClusterId);
                done = false;
            }
        }

            // clear all existing clusters
        clearClusters();

            // reassign points to their new clusters
        for (int i = 0; i < total_points; i++)
        {
            // cluster index is ID-1
            clusters[all_points[i].getCluster() - 1].addPoint(all_points[i]);
        }

        // Recalculating the center of each cluster
        for (int i = 0; i < K; i++)
        {
            int ClusterSize = clusters[i].getSize();

            for (int j = 0; j < dimensions; j++)
            {
                double sum = 0.0;
                if (ClusterSize > 0)
                {
                    #pragma omp parallel for reduction(+: sum) num_threads(16)
                    for (int p = 0; p < ClusterSize; p++)
                    {
                        sum += clusters[i].getPoint(p).getVal(j);
                    }
                    clusters[i].setCentroidByPos(j, sum / ClusterSize);
                }
            }
        }

        if (iter >= iters)
        {
            break;
        }
        iter++;
    }    
}

void KMeans::printPoints(vector<Edge> &pointsXY)const
{
    for(int i = 0;i<pointsXY.size();++i)
    {
        cout<<"("<<pointsXY[i].getVal(0)<<" , ";
        cout<<pointsXY[i].getVal(1)<<")"<<endl;
    }
}
void KMeans::setK(int k)
{
    K = k;
}
void KMeans::setIters(int i)
{
    this->iters = i;
}
void KMeans::setEdgePoints(vector<Edge> &points)
{
    this->all_points = points;
}

int KMeans::getK()const
{
    return K;
}

int KMeans::getIters()const
{
    return iters;
}

vector<Edge> KMeans::getPoints()const
{
    return all_points;
}

void KMeans::printResult()//sonuç bastırdık.
{
    printClusterResult();
    cout<<endl;
    printCentroidResult();
    writeFileCluster();
    writeFileCentroid();
}

void KMeans::printClusterResult() //cluster sonuçları
{
    for (int i = 0; i < total_points; i++)
    {
        cout<<"Points: (";
        cout << all_points[i].getVal(0)<<" ,"<<  all_points[i].getVal(1)<<") ";
        cout << "Cluster: "<<all_points[i].getCluster()<<endl;
    }
}
void KMeans::printCentroidResult() //centoid sonuçları
{
    for (int i = 0; i < K; i++)
    {
        cout << "Cluster " << clusters[i].getId() << " centroid : ";
        for (int j = 0; j < dimensions; j++)
            {
                cout << clusters[i].getCentroidByPos(j) << " ";    // Output to console
            }
        cout << endl;
    }
}
void KMeans::writeFileCluster()
{
    ofstream file;
    file.open("Cluster.txt");
    
    for (int i = 0; i < total_points; i++)
    {
        file<<all_points[i].getCluster()<<endl;
    }
    file.close();
}
void KMeans::writeFileCentroid()
{
    ofstream file;
    file.open("Centroid.txt");
    
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < dimensions; j++)
            {
                file << clusters[i].getCentroidByPos(j) << " ";    // Output to console
            }
        file << endl;
    }
}




