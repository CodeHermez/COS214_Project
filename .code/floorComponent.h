#ifndef FLOORCOMPONENT_H
#define FLOORCOMPONENT_H

#include <vector>
#include <memory>
#include <string>
#include "visitor.h"

class myIterator;
class depthFirstIterator;
class breadthFirstIterator;
class floorComponent
{
    protected:
        int currentChild;
    public:
        floorComponent(){};
        virtual void add(std::shared_ptr<floorComponent>)=0;
        virtual void remove(std::shared_ptr<floorComponent>)=0;
        virtual std::shared_ptr<floorComponent> getChild(int)=0;
        virtual int getNumChildren()=0;
        virtual std::shared_ptr<myIterator> getDepthIterator()=0;
        virtual std::shared_ptr<myIterator> getBreadthIterator()=0;
        virtual std::string toString()=0;
        virtual int acceptVisitor(std::shared_ptr<visitor>)=0;
        virtual ~floorComponent(){};    
};

#endif