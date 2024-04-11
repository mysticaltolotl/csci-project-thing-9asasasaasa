//searchandrescue.cpp

#include "SearchAndRescue.hpp"
#include <vector>
#include <stack>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

bool findPossibleDirection(string dir, vector<string> actions)
{
    for(int i = 0; i < actions.size(); i++)
    {
        if(actions[i] == dir)
        {
            return true;
        }
    }

    return false;
}


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
  	if(current->y < 3) {current->possible_actions.push_back("up");}
  
  	if(current->y > 0) {current->possible_actions.push_back("down");}
    
  	if(current->x > 0) {current->possible_actions.push_back("left");}
    
  	if(current->x < 3) {current->possible_actions.push_back("right");}
}


State* SearchAndRescue::result(State* current, string action)
{   
    State* newState = new State{current->x, current->y, current->saved_people, action, vector<string>()};
  
  	switch(action[0])
    {
        case('u'):
            if(findPossibleDirection("up", current->possible_actions))
            {
        	    newState->y++;
            }
        	break;
        case('d'):
            if(findPossibleDirection("down", current->possible_actions))
            {
        	    newState->y--;
            }
        	break;
        case('l'):
            if(findPossibleDirection("left", current->possible_actions))
            {
        	    newState->x--;
            }
        	break;
        case('r'):
            if(findPossibleDirection("right", current->possible_actions))
            {
        	    newState->x++;
            }
        	break;
    }
  
  	newState->prev_action = action;
  
    return newState;
}


vector<State*> SearchAndRescue::expand(State* current)
{
    vector<State*> expansion = vector<State*>();

    possibleActions(current);

    if(findPossibleDirection("up", current->possible_actions)) {expansion.push_back(result(current, "up"));}
    if(findPossibleDirection("down", current->possible_actions)) {expansion.push_back(result(current, "down"));}
    if(findPossibleDirection("left", current->possible_actions)) {expansion.push_back(result(current, "left"));}
    if(findPossibleDirection("right", current->possible_actions)) {expansion.push_back(result(current, "right"));}

    return expansion;
}


bool SearchAndRescue::iterativeDeepeningWrapper(State* start)
{
    int limit = 0;

    State* current = start;

    bool found = false;

    while(limit <= 4)
    {
        found = iterativeDeepeningSearch(current, limit);

        if(found)
        {
            return true;
        }

        limit++;
    }

    return false;
}


bool SearchAndRescue::iterativeDeepeningSearch(State* current, int depth_limit)
{
    if(depth_limit == 0) {return false;}

    


    return false;
}


void SearchAndRescue::printPath()
{
    // TODO
}


bool SearchAndRescue::isGoal(State* current)
{
    if(current->saved_people == 4)
    {
        return true;
    }
    return false;
}


void SearchAndRescue::printTerrain()
{
    // TODO
}
