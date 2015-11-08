#pragma once
#ifndef DIST_H
#define DIST_H
class District {
private:
    int type;       //Determine tile type: 0 = uninfected; 1 = infected;
    bool keyStone;  //STRETCH GOAL: look for 'key' story moments, store indicator here
    

public:

    District() : type(0), keyStone(false) {};
    District(int a, bool b) : type(a), keyStone(b) {};

    //Type access functions
    void PrintType();
    void SetType(int x) { type = x; }
    int  GetType() { return type; }

    //Keystone access functions
    void SetKeyStone(bool key) { keyStone = key; }
    bool IsKeyStone() { return keyStone; }

    //Infected access functions
    void SetInfection(bool infect) { if (infect) type = 1; else type = 0; }
    bool IsInfected() { return type==1; }

};
#endif