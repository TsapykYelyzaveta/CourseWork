#include "edge.h"

Vertex Edge::getStart() const
{
    return start;
}

void Edge::setStart(const Vertex &value)
{
    start = value;
}

Vertex Edge::getEnd() const
{
    return end;
}

void Edge::setEnd(const Vertex &value)
{
    end = value;
}

double Edge::getLength() const
{
    return length;
}

void Edge::setLength(double value)
{
    length = value;
}

Edge::Edge()
{
    
}

Edge::Edge(int s, int e, double l)
{
    start.setNumber(s);
    end.setNumber(e);
    length = l;
}


