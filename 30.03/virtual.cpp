#include <iostream>
#include <string>
#include <vector>

class Object{

public:
    virtual std::string whatAmI() = 0;
    virtual std::string toString() = 0;
    virtual Object* clone() const= 0;
    virtual ~Object(){}
};

class IntObject : public Object{

private:
    int value;

public:
    int getValue() const { return this->value; }
    void setValue(int value) { this->value = value; }
    std::string whatAmI() override{ return "I am IntObject"; }
    std::string toString() override{ return std::to_string(getValue());  }
    Object* clone() const override { return new IntObject(*this); }
};

class StringObject : public Object{

private:
    char *value;
    size_t size;

public:
    char* getValue() const { return this->value;}
    void setValue(char *value) { this->value = value; }
    std::string whatAmI() override { return "I am StringObject"; }
    std::string toString() override{ return getValue(); }
    Object* clone() const override{return new StringObject(*this); }
};

class DoubleObject : public Object{

private:
    double value;

public:
    double getValue() const { return this->value; }
    void setValue(double value) { this->value = value; }
    std::string whatAmI() override { return "I am DoubleObject"; }
    std::string toString() override{ return std::to_string(getValue()); }
    Object* clone() const override { return new DoubleObject(*this); };
};

double sumDoubleTypeObjects(Object* array[], int arraySize){
    double sum = 0;
    for (int i = 0; i < arraySize; ++i){
        if (array[i]->whatAmI() == "I am DoubleObject"){
            sum += dynamic_cast<DoubleObject *>(array[i])->getValue();
        }
    }
    return sum;
}

int main(){

    IntObject i1;
    StringObject s1;
    DoubleObject d1;

    Object *wsk;

    wsk = &i1;
    i1.setValue(10);
    std::cout << wsk->whatAmI() <<" : " << i1.getValue() <<  std::endl;

    wsk = &s1;
    s1.setValue("xxxxxxx");
    std::cout << wsk->whatAmI() <<" : " << s1.getValue() <<  std::endl;

    wsk = &d1;
    d1.setValue(5.0);
    std::cout << wsk->whatAmI() << " : " << d1.getValue() << std::endl;

    DoubleObject d2, d3;
    d2.setValue(10.0);
    d3.setValue(20.0);

    Object *array[] = {&d1, &d2, &d3};
    const int size = 3;

    std::cout << "Sum of DoubleObject type elements : " << sumDoubleTypeObjects(array, size) << std::endl;

    return 0;
}
