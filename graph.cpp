#include "auxiliary.h"
#include "graph.h"

QList<Edge> Graph::getListOfEdges() const
{
    return listOfEdges;
}

void Graph::setListOfEdges(const QList<Edge> &value)
{
    listOfEdges = value;
}

QList<Vertex> Graph::getListOfVertices() const
{
    return listOfVertices;
}

void Graph::setListOfVertices(const QList<Vertex> &value)
{
    listOfVertices = value;
}

int Graph::getNewIndexForVertex()
{
    if(listOfVertices.length() == 0)return 0;
    else{
    int max = listOfVertices[0].getNumber();
    for(int i = 1; i < listOfVertices.length(); i++)
    if(max < listOfVertices[i].getNumber())
        max = listOfVertices[i].getNumber();
    return max + 1;
    }
}

void Graph::addVertex()
{
    Vertex v;
    v.setNumber(getNewIndexForVertex());
    listOfVertices.append(v);
}
void Graph::addVertex(int count)
{
    for(int i = 0; i < count; i++){
        Vertex v;
        v.setNumber(getNewIndexForVertex());
        listOfVertices.append(v);
    }
}

void Graph::addEdge(Edge e)
{
    int i = is(e);
    if(i == -1)
    listOfEdges.append(e);
    else listOfEdges[i] = e;
}

int Graph::is(Edge e)
{
    for(int i = 0; i < listOfEdges.length(); i++){
        if(e.getStart().getNumber() == listOfEdges[i].getStart().getNumber() &&
                e.getEnd().getNumber() == listOfEdges[i].getEnd().getNumber())
            return i;
    }
    return -1;
}
double** Graph::formAdjacencyMatrix(){
    int count = this->listOfVertices.count();
    double** adjacencyMatrix = new double*[count];
    for(int i = 0; i < count; i++)
        adjacencyMatrix[i] = new double[count];
    Auxiliary::fillArrBy(adjacencyMatrix, count, INT_MAX);


foreach(Edge edge, this->listOfEdges){
    if(edge.getDirection() == 1)
    adjacencyMatrix[edge.getStart().getNumber()][edge.getEnd().getNumber()] = edge.getLength();
}
    return adjacencyMatrix;
}
Graph::Graph()
{
    type = 0;
}
