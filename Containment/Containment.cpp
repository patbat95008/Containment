// Containment.cpp : A game about tough choices (TM)
/* Current build abilities: 
* - Builds "city" 
* - Infects it randomly.
*/

/* TODO: 
* - Make maps more than just squares
* - Restrict infection to small # at start
* - Add disease spread
* - have human interaction - AKA inspections mechanic
* - Implement GUI and multiple diseases
*/

// By Patrick Russell

#include "stdafx.h"
#include "District.h"
#include <iostream>
#include <stdlib.h>
#include <time.h> //For the random function
#include <vector>
using namespace std;

// Creates a 2d vector of empty initialized District objects
// ATM creates a rectangle of height and width completly empty
vector<vector <District> > buildCity(int height, int width) {
    vector< vector<District> > city; //City object

    cout << "building city..." << endl;

    //Init vector height
    city.resize(height);

    //Init vector width
    for (int i = 0; i < height; i++) {
        city[i].resize(width);
    }

    //Set the type and other variables to blank
    for (int i = 0; i < city.size(); i++) {
        for (int j = 0; j < city[i].size(); j++) {
            city[i][j].SetType(0);
            city[i][j].SetKeyStone(false);
            //DEBUG: Display city
            city[i][j].PrintType();
        }
        cout << endl;
    }

    return city;
}

// Infects the city with disease
// ATM: Randomly decides where to infect, has a 50/50 chance
void infectCity(vector<vector <District> > city) {
    int limit = 3;
    int numInfected = 0;
    
    //Go through every district
    for (int i = 0; i < city.size(); i++) {
        for (int j = 0; j < city[i].size(); j++) {
            //Randomly assign infection (50% chance) until limit
            if (rand() % 10 < 2 && numInfected < limit) {
                //Infect
                city[i][j].SetInfection(true);
                numInfected++;
            } else {
                //Do not infect
                city[i][j].SetInfection(false);
            }
            
            //DEBUG: Display city
            city[i][j].PrintType();
        }
        cout << endl;
    }
}

/* Game action list:
*   Pre-Game:
*   - Initialize city as empty (Determine shape)
*   - Add infection to specific # of districts in city (Based on size)
*   - Determine disease to fight from random list
*   Gameplay:
*   - Based on disease properties, spread infection across city in real time
*   - Player can enter districts
*   - Upon entering, is given a symptom of the real disease or a false symptom
*   - Player can decide to: 1. Quarantine       (3 strikes)
*                           2. Release          (1 strike)
*                           3. Test             (% chance of telling truth)
*                           4. Look up records  (Give another symptom)
*                           5. Leave            (Do nothing)
*   - Game tracks strikes and player choices (Lock down districts after choice)
*   - STRETCH GOAL: Game will know when infection 'needs' a district, and labels 
*     it a 'keystone' district. These districts play out pre-written story segments.
*/

int main()
{
    //Define the srand for random numbers
    srand(time(NULL));

    // Make the city array
    vector< vector<District> > testArray = buildCity(5, 5);

    cout << "City complete. Infecting..." << endl;
    //Add infection to city
    infectCity(testArray);

    cout << "Infection completed." << endl;

    return 0;
}


