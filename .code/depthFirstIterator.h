#ifndef DEPTHFIRSTITERATOR_H
#define DEPTHFIRSTITERATOR_H

#include "iterator.h"

class depthFirstIterator: public myIterator
{
    private:
        void depthFirstIterator::flattenTree(std::shared_ptr<floorComponent>);
    public:
        depthFirstIterator(std::shared_ptr<floorComponent>);
        std::shared_ptr<floorComponent> first(){};
        void next(){};
        std::shared_ptr<floorComponent> currentItem(){};
        bool hasNext(){};
        ~depthFirstIterator();
};

#endif