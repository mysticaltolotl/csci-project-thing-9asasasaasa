#include "SearchAndRescue.hpp"
#include <vector>
#include <stack>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


SearchAndRescue::SearchAndRescue(string fileName)
{
    terrain = new int*[4];
    string line;
    ifstream infile(fileName);
    if (infile.is_open())
    {
        for(int i = 0; getline(infile, line); i++)
        {   
            terrain[i] = new int[4];
            stringstream ss(line);
            string s;
            for (int j = 0; getline(ss, s, ' '); j++)
            {
                terrain[i][j] = stoi(s);
            }
        }
    }
    path = vector<State*>();
}


SearchAndRescue::~SearchAndRescue()
{
    State* to_del = path.back();
    delete to_del;
    path.pop_back();

    for (int i = 0; i < 4; i++)
    {
        delete terrain[i];
    }
    delete terrain;
}


void SearchAndRescue::possibleActions(State* current)
{
    // TODO
}


State* SearchAndRescue::result(State* current, string action)
{
    // TODO
    State* newState = new State{current->x, current->y, current->saved_people, action, vector<string>()};
    return newState;
}


vector<State*> SearchAndRescue::expand(State* current)
{
    // TODO
    vector<State*> expansion = vector<State*>();
    return expansion;
}


bool SearchAndRescue::iterativeDeepeningWrapper(State* start)
{
    // TODO
    return false;
}


bool SearchAndRescue::iterativeDeepeningSearch(State* current, int depth_limit)
{
    // TODO
    return false;
}


void SearchAndRescue::printPath()
{
    // TODO
}


bool SearchAndRescue::isGoal(State* current)
{
    // TODO
    return false;
}


void SearchAndRescue::printTerrain()
{
    // TODO
}
