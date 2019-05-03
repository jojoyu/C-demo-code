#include <iostream>
#include <string>
using namespace std;
 
class Operation
{
public:
    double numberA, numberB;
    virtual double  getResult()
    {
        return 0;
    }
};
 
class addOperation :public Operation
{
    double getResult()
    {
        return numberA + numberB;
    }
};
 
 
class subOperation :public Operation
{
    double getResult()
    {
        return numberA - numberB;
    }
};
 
class mulOperation :public Operation
{
    double getResult()
    {
        return numberA*numberB;
    }
};
 
class divOperation :public Operation
{
    double getResult()
    {
        return numberA / numberB;
    }
};
 
class IFactory
{
public:
    virtual Operation *createOperation() = 0;
    virtual ~IFactory()  = 0;
};

IFactory::~IFactory() {
    std::cout << "base factory." << std::endl; 
}
 
class AddFactory :public IFactory
{
public:
    Operation *createOperation()
    {
        return new addOperation();
    }
};
 
 
class SubFactory :public IFactory
{
public:
    Operation *createOperation()
    {
        return new subOperation();
    }
};
 
class MulFactory :public IFactory
{
public:
    Operation *createOperation()
    {
        return new mulOperation();
    }

    ~MulFactory() {
        std::cout << "mul factory." << std::endl; 
    }
};
 
class DivFactory :public IFactory
{
public:
    Operation *createOperation()
    {
        return new divOperation();
    }
};
 
int main()
{
    IFactory *fac = new MulFactory();
    Operation *oper = fac->createOperation();
    oper->numberA = 9;
    oper->numberB = 99;
    cout << oper->getResult() << endl;
    delete oper;
    delete fac;
    return 0;
}
