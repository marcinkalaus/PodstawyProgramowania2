#include <iostream>
#include "VectoredList.h"
using namespace std;

int main() {
    /*
    cout << endl << "[ TEST 1 ]" << endl;
    VectoredList v;
    for (int i = 0; i < 101; ++i)
        v.push_back(to_string(i));
    for (int i = 0; i < 101; ++i)
    {
        cout<< v[100-i]<<" ";
        if (i % 10 == 0)
            cout << endl;
    }
    cout << endl << "[ TEST 4 ]" << endl;
    VectoredList v2;
    v2.push_back(to_string(2));
    cout << "Size before using = "<<v2.get_size() << endl;
    v2 = v;
    for (int i = 0; i <= v2.get_size(); ++i)
    {
        cout << v2[i] << " ";
        if (i % 10 == 9)
            cout << endl;
    }
    cout << endl << "\n[ TEST begin() i end(), ++, *]" << endl;
    VectoredList::VectoredListIterator it(v2);
    cout << it.get() <<endl;
    ++it;
    cout << it.get() <<endl;
    VectoredList::VectoredListIterator it2(v2,15);
    cout << it2.get() <<endl;
    cout<< "*it2: "<< *it2 << endl;
    cout<< "v2 begin(): "<< v2.begin().get() << endl;
    cout<< "v2 end(): "<< v2.end().get() << endl;
    cout<< "return index it2: "<< it2.return_index(v2) << endl;
    cout << endl << "[TEST ZAKRESOWE FOR]" << endl;;
    for (const auto& element : v2)
    {
        cout << element << endl;
    }

    cout << endl << "[ TEST 3 erase ]" << endl;
    //doadanie 22 elementow
    for(int i =0; i < 22; ++i)
    {
        v2.push_back(to_string(22+i));
    }
    cout <<"Size before erasing: " <<v2.get_size() << endl;
    //usuwanie 3-ego elementu
    VectoredList::VectoredListIterator it3(v2,3);
    v2.erase(it3);
    cout <<"Size after erasing: " <<v2.get_size() << endl;
    for (int i = 0; i < v2.get_size(); ++i)
    {
        cout << v2[i] << " ";
        if (i % 10 == 9)
            cout << endl;
    }
    cout << endl << "[ TEST 3 erase(it1,it2) ]" << endl;
    cout <<"Size before erasing: " <<v2.get_size() << endl;
    VectoredList::VectoredListIterator it4(v2,3);
    VectoredList::VectoredListIterator it5(v2,13);
    v2.erase(it4,it5);
    cout <<"Size after erasing: " <<v2.get_size() << endl;
    for (int i = 0; i < v2.get_size(); ++i)
    {
        cout << v2[i] << " ";
        if (i % 10 == 0)
            cout << endl;
    }
    cout << endl << "[ TEST 5 erase(it1,it2) ]" << endl;
    VectoredList v3;
    for (int i = 0; i < 103; ++i)
        v3.push_back(to_string(i));
    for (int i = 0; i < v3.get_size(); ++i)
    {
        cout << v3[i] << " ";
        if (i % 10 == 9)
            cout << endl;
    }
    cout << endl;
    VectoredList::VectoredListIterator it6(v3,87);
    VectoredList::VectoredListIterator it7(v3,100);
    v3.erase(it6,it7);
    cout<< "AFTER: "<< endl;
    for (int i = 0; i < v3.get_size(); ++i)
    {
        cout << v3[i] << " ";
        if (i % 10 == 9)
            cout << endl;
    } */

    /////////// Lab 12
    // konstruktor przenoszacy
    VectoredList v1;
    std::string tekst1 = "test konstruktora przenoszacego";
    v1.push_back(tekst1);
    v1.printVL();
    std::string tekst2 = "nowy tekst pustego obiektu";
    std::cout << "Przenoszenie" << std::endl;
    VectoredList v2(std::move(v1));
    v2.printVL();
    v1.push_back(tekst2);
    v1.printVL();
    std::cout << std::endl;

    // przypisanie
    VectoredList v3;
    VectoredList v4;
    std::string tekst3 = "test operatora przypisania";
    v3.push_back(tekst3);
    v3.printVL();
    std::cout << "przypisanie" << std::endl;
    v4 = std::move(v3);
    v4.printVL();
    v3.push_back(tekst2);
    v3.printVL();
    std::cout << std::endl;

    // operator+
    VectoredList v5;
    VectoredList v6;
    std::string tekst4 = "tekst operatora 1 ";
    std::string tekst5 = "tekst operatora 2";
    v5.push_back(tekst4);
    v6.push_back(tekst5);
    std::cout << "dodawanie" << std::endl;
    VectoredList v7;
    v7 = v5 + v6;
    v7.printVL();

    return 0;
}