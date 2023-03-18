#ifndef TRACKER_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define TRACKER_H

#include "headers.hpp"
#include "valorant.hpp"

extern string username, tag, datastr, input, filename;
extern fstream file;
extern map<string, string> csvFields;
extern Valorant valorant;


string getNodeID(string filename);
bool assignField(string fieldName);
bool isValidDate(string dateString);
bool is_valid_integer(string str);
int count_lines(string filename);

#endif