#include <iostream>
#include <string>
using namespace std;
 
class Operation
{
public:
    virtual ~Operation() = 0;
    double numberA, numberB;
    virtual double  getResult()
    {
        return 0;
    }
};
 
Operation::~Operation() {
    std::cout << "base operation." << std::endl; 
}

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
    std::shared_ptr<IFactory> fac(new MulFactory());
    //IFactory *fac = new MulFactory();
    std::shared_ptr<Operation> oper(fac->createOperation());
    //Operation *oper = fac->createOperation();
    oper->numberA = 9;
    oper->numberB = 99;
    cout << oper->getResult() << endl;
    //delete oper;
    //delete fac;
    return 0;
}
