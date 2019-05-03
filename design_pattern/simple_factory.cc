#include <iostream>
#include <string>
using namespace std;
//基类
class Operation
{
public:
    double numberA, numberB;
    virtual double  getResult()
    {
        return 0;
    }
};
//加法
class addOperation :public Operation
{
    double getResult()
    {
        return numberA + numberB;
    }
};
 
//减法
class subOperation :public Operation
{
    double getResult()
    {
        return numberA - numberB;
    }
};
//乘法
class mulOperation :public Operation
{
    double getResult()
    {
        return numberA*numberB;
    }
};
//除法
class divOperation :public Operation
{
    double getResult()
    {
        return numberA / numberB;
    }
};
//工厂类
class operFactory
{
public:
    static Operation *createOperation(char c)
    {
        switch (c)
        {
        case '+':
            return new addOperation;
            break;
 
        case '-':
            return new subOperation;
            break;
 
        case '*':
            return new mulOperation;
            break;
 
        case '/':
            return new divOperation;
            break;
        }
        return NULL;
    }
};
 
int main()
{
    Operation *oper = operFactory::createOperation('+');
    oper->numberA = 9;
    oper->numberB = 99;
    cout << oper->getResult() << endl;
    return 0;
}
