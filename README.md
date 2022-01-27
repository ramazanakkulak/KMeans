# KMeans and Prim Algorithm

Clustering is the grouping of data showing similar characteristics in a data set. Within the same cluster, the similarities are high, and the similarities between the clusters are low. Known as Unsupervised Learning, the algorithm is not given any prior knowledge. It is the clustering algorithm commonly used in K-Means and Hierarchical Segmentation. K-Means algorithm is an unsupervised learning and clustering algorithm. The K value in K-Means determines the number of clusters and should take this value as a parameter. This is actually a disadvantage. The algorithm has a simple way of working.

**How does the K-Means algorithm work? 

The Kmeans algorithm is an iterative algorithm that tries to divide the dataset into different Kpre-defined non-overlapping subgroups (clusters) where each data point belongs to only one group. It tries to make the within-cluster data points as similar as possible, while trying to keep the clusters as distinct (away) as possible. Assigns data points to a cluster so that the sum of the squared distance between the data points and the cluster's centroid (the arithmetic mean of all data points belonging to that cluster) is minimum. The less variation we have within clusters, the more homogeneous (similar) the data points within the same cluster. 

According to the working mechanism of the K-means algorithm, K objects are randomly selected to represent the center point or mean of each cluster. The remaining objects are included in the clusters with which they are most similar, taking into account their distance from the mean values of the clusters. Then, by calculating the average value of each cluster, new cluster centers are determined and the distances of the objects to the center are examined again. The algorithm continues to repeat until there is no change. 

The algorithm basically consists of 4 stages: 

(1) Determination of cluster centers 

(2) Clustering the data outside the center according to their distance 

(3) Determination of new centers according to the clustering (or shifting of old centers to the new center) 

(4) Repeating steps 2 and 3 until stable state is reached.

![image](https://user-images.githubusercontent.com/78980365/151424006-80ab094b-d1b5-49ae-a5be-cbe5900c0988.png)


**Prim Graph Algorithm

Prim's algorithm is a Greedy algorithm. It starts with an empty spanning tree. The idea is to preserve the two sets of vertices. The first set of Minimum Spanning Tree (MST) contains vertices already found, the other set contains vertices that have not yet been included. At each step, it considers all the edges connecting the two sets and chooses the minimum weight edge from these edges. After selecting the edge, it moves the other endpoint of the edge to the cluster containing the MST. 

A group of edges connecting two vertices in a graph is called a segment in graph theory. So, at each step of Prim's algorithm, we find a cut (one contains the vertices already in the MST and the other contains the remaining vertices), select the minimum weight edge from the cut, and the operations are performed by including this vertex in the MST Set. containing set).

Prim Graph Algorithm

(1) A set of mstSet of the minutes of the peaks already found in the MstSet.

(2) Assign a key value to all vertices in the value in the input. All keys as INFINITE. Assign 0 as the key for the first vertex, select it first.

(3) Although mstSet does not contain all vertices
      (a) A vertex value option u has no mstSet and a minimum key.
      (b) u include for mstSet.
      (c) Update keys of all universal vertices of u. Iterate through all the vertices to update the keys. If v is kilo for each neighbor, UV is older key value v, change UV to           refresh life for now

![image](https://user-images.githubusercontent.com/78980365/151424041-63758a0a-55c1-4646-a3e1-8e6edcff7b97.png)

The Coding Hierarchy and Running

The K Means algorithm I designed consists of five classes and one inherit class. These classes are as follows:

1. Node Class (base)
 
2. Edge Class (base)
 
3. Cluster Class (base)

4. K-Means Class (base)

5. Graph Class (base)

6. Prim Class (inherit)
 
7. MatPlotLib.cpp

The study was developed on VS code ide. There is also the matplotlib.cpp function developed for plotting over the matplotlib library developed for python. The installation of this file is simple. This file can be accessed via github specified in table 2 step 1. The following guidelines should be followed to run this run.

**MatPlotLib setups steps. (1)Github link (2) Python lib setup, (3) Example run
 
**(1) https://github.com/lava/matplotlib-cpp

**(2) sudo apt-get install python-matplotlib pythonX-numpy pythonX.X-dev

**(3) g++ example.cpp -I/usr/include/pythonX.X -lpythonX.X

The above 2 steps are performed. Before this process is performed, the python version installed on the Linux (ubuntu) operating system is important in places marked as X in bold. The work was run on python3.8. Then run one of the examples in the file installed from github to test the accuracy of this process.

After doing this process, you can go to the directory where you are working via the terminal on the visual code or via the ubuntu terminal with the help of the "cd" command. 

After navigating to the required directory: Terminal complier CMake

**g++ main.cpp Node.cpp Edge.cpp Cluster.cpp KMeans.cpp Graph.cpp Prim.cpp -std=c++11 -I/usr/include/python3.8 -lpython3.8**

This command is typed into the terminal to view the results: Output command

**./a.out**


![image](https://user-images.githubusercontent.com/78980365/151424455-8279b5bc-14ff-4de8-aa0a-d3802f69d2a1.png)


![image](https://user-images.githubusercontent.com/78980365/151424521-66d8bee6-e859-4ce3-b16c-74bc3f956c50.png)


Youtube: https://www.youtube.com/watch?v=PxEkcAIync0
