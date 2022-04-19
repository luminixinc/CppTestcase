// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ArrayWrap.hpp"

int main(int argc, const char *argv[])
{
    std::cout << "Check the console output for any assertion failure locations...\n";

    std::vector<ArrayWrap> array;

    /*JsonNode_t n0 = JsonNode_t();
    JsonNode_t n1 = JsonNode_t();
    array.push_back(n0);
    array.push_back(n1);*/

    array.push_back(ArrayWrap());
    array.push_back(ArrayWrap());

    ArrayWrap node(array);
    assert(node._array == array);
    assert(node._array.size() == 2);

    ArrayWrap node2(node);
    assert(node2._array == array);
    assert(node2._array.size() == 2);
    assert(node2._array.size() == 2);
    assert(node2._array.at(0)._array.size() == 0);
    assert(node2._array.at(1)._array.size() == 0);

    ArrayWrap node3;
    assert(node3._array.size() == 0);

    node3 = node2;
    assert(node3._array.size() == 2);
    assert(node3._array == array);
    assert(node3._array.size() == 2);

    ArrayWrap node4;
    assert(node4._array.size() == 0);

    node4 = std::move(node3);
    assert(node4._array.size() == 2);
    assert(node4._array == array);
    assert(node4._array.size() == 2);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
