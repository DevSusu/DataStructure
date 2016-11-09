#ifndef BAG_H
#define BAG_H

template <class T>
class Bag
{
public:
    Bag(int bagCapacity = 10);
    virtual ~Bag();
    virtual int Size() const;
    virtual bool IsEmpty() const;
    virtual int Element() const;
    virtual void Push(const T&);
    virtual void Pop();
    
protected:
    T *array;
    int capacity;
    int top;
};


#endif