#include "stdafx.h"
#include "District.h"
#include <iostream>
using namespace std;

/*class District {
public:
    int type;
    bool keyStone;

    District() : type(0), keyStone(false) {};
    District(int a, bool b) : type(a), keyStone(b) {};
};*/

//Prints the district in the console
void District::PrintType() {
    if (type == 0)
        std::cout << '-'; // Uninfected
    else if (type == 1)
        std::cout << 'X'; // Infected
}

