#include "Node.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <ostream>
using namespace std;

int Node::count = 0;
int Node::countXCoordinate = 0;
int Node::countYCoordinate = 0;

int Node::getCount()
{
	return count;
}

int Node::getcountXCoordinate()
{
	return countXCoordinate;
}

int Node::getcountYCoordinate()
{
	return countYCoordinate;
}

Node::Node(const string &fileName):
         txtName(fileName)
{
    readCoordinate(txtName);
    sperateXYCoordinate();
    ++count;
}

void Node::readCoordinate(string n)
{
	double number;
    ifstream input_file(n);
    if (!input_file.is_open()) {
        cout << "Could not open the file - '"
             << n << "'" << endl;
    }
    while (input_file >> number) {
        //cout << number << " " <<endl;
        data.push_back(number);
    }
	input_file.close();  
}
void Node::sperateXYCoordinate()
{
    double array[data.size()][2];
    for(int i=0;i<data.size();++i){
        if(i%2==0){
            setX(data.at(i));
            ++countXCoordinate;
        }      
    }
    for(int i=0;i<data.size();++i){
        if(i%2!=0){
            setY(data.at(i));
            ++countYCoordinate;
        }
    }
}
void Node::setX(double number)
{
    x.push_back(number);
    //cout<<number<<endl;
}
void Node::setY(double number)
{
    y.push_back(number);
}

void Node::print()
{
    cout<<"The points of the "<<getTxtName()<<" are as follows."<<endl;
    for(int i = 0; i<x.size(); i++)
        cout<<"("<<getX(i)<<" , "<<getY(i)<<")"<<endl;
}

double Node::getX(int i)const
{
    return x.at(i);
}
double Node::getY(int i)const
{
    return y.at(i);
}
string Node::getTxtName()const
{
    return txtName;
}

ostream &operator<<(ostream &output ,const Node &nodeObje)
{
    output << "The points of the "<<nodeObje.getTxtName()<<" are as follows."<<endl;
    for(int i = 0; i<nodeObje.x.size(); ++i){
        output<<"("<<nodeObje.x[i]<<" , "<<nodeObje.y[i]<<")"<<endl;
    }
    return output;
}

Node::~Node()
{
	--count;
}
vector<double> Node::getData()const
{
    return data;
}