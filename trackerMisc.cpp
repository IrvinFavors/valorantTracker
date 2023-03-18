#include "headers/tracker.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

    
string getNodeID(string filename) {
    if (!file.is_open()) {
        cout << "failed" << endl;
        return "";  // return empty string if file cannot be opened
    }

    string line;
    string lastLine;
    while (getline(file, line)) {
        lastLine = line;  // keep overwriting the variable with the last line until the end of file is reached
    }

    stringstream lastLineStream(lastLine);
    string nodeID;

    getline(lastLineStream, nodeID, ',');  // assuming that nodeID is the first field in the line and is separated by a comma

    return nodeID;
}

bool assignField(string fn) {
    if (fn == "nodeID") {csvFields["nodeID"] = getNodeID(fn); return true;}
    else if (fn == "date"){
        cout << setTextColor(TextColor::Cyan) << "Enter the Date: " << setTextColor(TextColor::Default);
        while(getline(cin, csvFields["date"]))
        {
            if (csvFields["date"].empty()) {
                cerr<<"Unsuccessful Read! Enter the Date: ";
                continue;
            }
            if(isValidDate(csvFields["date"])) {
                file << csvFields["date"] << ", "; 
                return true;
            }
            else {
                cerr<< setTextColor(TextColor::Red) << "Invalid Date! Enter the Date: " << setTextColor(TextColor::Default);
                continue;
            }
        }
        
    }
    else if (fn == "compStatus"){
        cout << setTextColor(TextColor::Cyan) << "Was the match Competitive, Unrated or Misc.: " << setTextColor(TextColor::Default);
        while(getline(cin, csvFields["compStatus"]))
        {
            if (csvFields["compStatus"].empty()) {
                cerr<< setTextColor(TextColor::Red) << "Unsuccessful Read! Was the match Competitive, Unrated or Misc.: " << setTextColor(TextColor::Default);
                continue;
            }
            vector<string>::iterator it = find(valorant.matchtypes.begin(), valorant.matchtypes.end(), csvFields["compStatus"]);
            if(it != valorant.matchtypes.end()) {
                file << csvFields["compStatus"] << ", "; 
                return true;
            }
            else {
                cerr<< setTextColor(TextColor::Red) << "Invalid match type! Enter Competitive, Unrated or Misc: " << setTextColor(TextColor::Default);\
                continue;
            }
        }
    }
    else if (fn == "map"){
        cout << setTextColor(TextColor::Cyan) << "Enter the Map: " << setTextColor(TextColor::Default);
        while(getline(cin, csvFields["map"]))
        {
            if (csvFields["map"].empty()) {
                cerr<< setTextColor(TextColor::Red) << "Unsuccessful Read! Enter the Map: " << setTextColor(TextColor::Default);
                continue;
            }
            vector<string>::iterator it = find(valorant.maps.begin(), valorant.maps.end(), csvFields["map"]);
            if(it != valorant.maps.end()) {
                file << csvFields["map"] << ", "; 
                return true;
            }
            else {
                cerr<< setTextColor(TextColor::Red) << "Invalid match type! Enter the Map: " << setTextColor(TextColor::Default);\
                continue;
            }
        }
    }
    else if (fn == "agent"){
        cout << setTextColor(TextColor::Cyan) << "Enter the Agent used: " << setTextColor(TextColor::Default);
        while(getline(cin, csvFields["agent"]))
        {
            if (csvFields["agent"].empty()) {
                cerr<< setTextColor(TextColor::Red) << "Unsuccessful Read! Enter the Agent used: " << setTextColor(TextColor::Default);
                continue;
            }
            vector<string>::iterator it = find(valorant.agents.begin(), valorant.agents.end(), csvFields["agent"]);
            if(it != valorant.agents.end()) {
                file << csvFields["agent"] << ", "; 
                return true;
            }
            else {
                cerr<< setTextColor(TextColor::Red) << "Invalid match type! Enter the Agent used: " << setTextColor(TextColor::Default);\
                continue;
            }
        }
    }
    else if (fn == "kills"){
        cout << setTextColor(TextColor::Cyan) << "Enter the number of Kills earned: " << setTextColor(TextColor::Default);
        while(getline(cin, csvFields["kills"]))
        {
            if (csvFields["kills"].empty()) {
                cerr<< setTextColor(TextColor::Red) << "Unsuccessful Read! Enter the number of Kills earned: " << setTextColor(TextColor::Default);
                continue;
            }
            if(is_valid_integer(csvFields["kills"])) {
                if (stoi(csvFields["kills"]) >= 0 && stoi(csvFields["kills"]) <= 80){
                    file << csvFields["kills"] << ", "; 
                    return true;
                }
                else {
                    cerr<< setTextColor(TextColor::Red) << "Invalid number of Kills! Enter the number of Kills earned: " << setTextColor(TextColor::Default);\
                    continue;
                }
            }
            else {
                cerr<< setTextColor(TextColor::Red) << "Invalid number of Kills! Enter the number of Kills earned: " << setTextColor(TextColor::Default);\
                continue;
            }
        }
    }
    else if (fn == "deaths"){
        cout << setTextColor(TextColor::Cyan) << "Enter the number of Deaths: " << setTextColor(TextColor::Default);
        while(getline(cin, csvFields["deaths"]))
        {
            if (csvFields["deaths"].empty()) {
                cerr<< setTextColor(TextColor::Red) << "Unsuccessful Read! Enter the number of Deaths: " << setTextColor(TextColor::Default);
                continue;
            }
            if(is_valid_integer(csvFields["deaths"])) {
                if (stoi(csvFields["deaths"]) >= 0 && stoi(csvFields["deaths"]) <= 50){
                    file << csvFields["deaths"] << ", "; 
                    return true;
                }
                else {
                    cerr<< setTextColor(TextColor::Red) << "Invalid number of deaths! Enter the number of Deaths: " << setTextColor(TextColor::Default);\
                    continue;
                }
            }
            else {
                cerr<< setTextColor(TextColor::Red) << "Invalid number of deaths! Enter the number of Deaths: " << setTextColor(TextColor::Default);\
                continue;
            }
        }
    }
    else if (fn == "assists"){
        cout << setTextColor(TextColor::Cyan) << "Enter the number of Assists: " << setTextColor(TextColor::Default);
        while(getline(cin, csvFields["assists"]))
        {
            if (csvFields["assists"].empty()) {
                cerr<< setTextColor(TextColor::Red) << "Unsuccessful Read! Enter the number of Assists: " << setTextColor(TextColor::Default);
                continue;
            }
            if(is_valid_integer(csvFields["assists"])) {
                if (stoi(csvFields["assists"]) >= 0 && stoi(csvFields["assists"]) <= 125){
                    file << csvFields["assists"] << ", "; 
                    return true;
                }
                else {
                    cerr<< setTextColor(TextColor::Red) << "Invalid number of Assists! Enter the number of Assists: " << setTextColor(TextColor::Default);\
                    continue;
                }
            }
            else {
                cerr<< setTextColor(TextColor::Red) << "Invalid number of Assists! Enter the number of Assists: " << setTextColor(TextColor::Default);\
                continue;
            }
        }
    }
    else if (fn == "avgCombatScore"){
        cout << setTextColor(TextColor::Cyan) << "Enter the average combat score: " << setTextColor(TextColor::Default);
        while(getline(cin, csvFields["avgCombatScore"]))
        {
            if (csvFields["avgCombatScore"].empty()) {
                cerr<< setTextColor(TextColor::Red) << "Unsuccessful Read! Enter the average combat score: " << setTextColor(TextColor::Default);
                continue;
            }
            if(is_valid_integer(csvFields["avgCombatScore"])) {
                if (stoi(csvFields["avgCombatScore"]) >= 0 && stoi(csvFields["avgCombatScore"]) <= 400){
                    file << csvFields["avgCombatScore"] << ", "; 
                    return true;
                }
                else {
                    cerr<< setTextColor(TextColor::Red) << "Invalid average combat score! Enter the average combat score: " << setTextColor(TextColor::Default);\
                    continue;
                }
            }
            else {
                cerr<< setTextColor(TextColor::Red) << "Invalid average combat score! Enter the average combat score: " << setTextColor(TextColor::Default);\
                continue;
            }
        }
    }
    else if (fn == "econRating"){
        cout << setTextColor(TextColor::Cyan) << "Enter the EconRating: " << setTextColor(TextColor::Default);
        while(getline(cin, csvFields["econRating"]))
        {
            if (csvFields["econRating"].empty()) {
                cerr<< setTextColor(TextColor::Red) << "Unsuccessful Read! Enter the EconRating: " << setTextColor(TextColor::Default);
                continue;
            }
            if(is_valid_integer(csvFields["econRating"])) {
                if (stoi(csvFields["econRating"]) >= 0 && stoi(csvFields["econRating"]) <= 400){
                    file << csvFields["econRating"] << ", "; 
                    return true;
                }
                else {
                    cerr<< setTextColor(TextColor::Red) << "Invalid EconRating! Enter the EconRating: " << setTextColor(TextColor::Default);\
                    continue;
                }
            }
            else {
                cerr<< setTextColor(TextColor::Red) << "Invalid EconRating! Enter the EconRating: " << setTextColor(TextColor::Default);\
                continue;
            }
        }
    }
    else if (fn == "firstBloods"){
        cout << setTextColor(TextColor::Cyan) << "Enter the number of First Bloods: " << setTextColor(TextColor::Default);
        while(getline(cin, csvFields["firstBloods"]))
        {
            if (csvFields["firstBloods"].empty()) {
                cerr<< setTextColor(TextColor::Red) << "Unsuccessful Read! Enter the number of First Bloods: " << setTextColor(TextColor::Default);
                continue;
            }
            if(is_valid_integer(csvFields["firstBloods"])) {
                if (stoi(csvFields["firstBloods"]) >= 0 && stoi(csvFields["firstBloods"]) <= 50){
                    file << csvFields["firstBloods"] << ", "; 
                    return true;
                }
                else {
                    cerr<< setTextColor(TextColor::Red) << "Invalid number of First Bloods! Enter the number of First Bloods: " << setTextColor(TextColor::Default);\
                    continue;
                }
            }
            else {
                cerr<< setTextColor(TextColor::Red) << "Invalid number of First Bloods! Enter the number of First Bloods: " << setTextColor(TextColor::Default);\
                continue;
            }
        }
    }
    else if (fn == "plants"){
        cout << setTextColor(TextColor::Cyan) << "Enter the number of plants: " << setTextColor(TextColor::Default);
        while(getline(cin, csvFields["plants"]))
        {
            if (csvFields["plants"].empty()) {
                cerr<< setTextColor(TextColor::Red) << "Unsuccessful Read! Enter the number of plants: " << setTextColor(TextColor::Default);
                continue;
            }
            if(is_valid_integer(csvFields["plants"])) {
                if (stoi(csvFields["plants"]) >= 0 && stoi(csvFields["plants"]) <= 26){
                    file << csvFields["plants"] << ", "; 
                    return true;
                }
                else {
                    cerr<< setTextColor(TextColor::Red) << "Invalid number of plants! Enter the number of plants: " << setTextColor(TextColor::Default);\
                    continue;
                }
            }
            else {
                cerr<< setTextColor(TextColor::Red) << "Invalid number of plants! Enter the number of plants: " << setTextColor(TextColor::Default);\
                continue;
            }
        }
    }
    else if (fn == "defuses"){
        cout << setTextColor(TextColor::Cyan) << "Enter the number of defuses: " << setTextColor(TextColor::Default);
        while(getline(cin, csvFields["defuses"]))
        {
            if (csvFields["defuses"].empty()) {
                cerr<< setTextColor(TextColor::Red) << "Unsuccessful Read! Enter the number of defuses: " << setTextColor(TextColor::Default);
                continue;
            }
            if(is_valid_integer(csvFields["defuses"])) {
                if (stoi(csvFields["defuses"]) >= 0 && stoi(csvFields["defuses"]) <= 26){
                    file << csvFields["defuses"] << ", "; 
                    return true;
                }
                else {
                    cerr<< setTextColor(TextColor::Red) << "Invalid number of defuses! Enter the number of defuses: " << setTextColor(TextColor::Default);\
                    continue;
                }
            }
            else {
                cerr<< setTextColor(TextColor::Red) << "Invalid number of defuses! Enter the number of defuses: " << setTextColor(TextColor::Default);\
                continue;
            }
        }
    }
    else if (fn == "outcome"){
        cout << setTextColor(TextColor::Cyan) << "Enter the match result (Victory or Defeat): " << setTextColor(TextColor::Default);
        while(getline(cin, csvFields["outcome"]))
        {
            if (csvFields["outcome"].empty()) {
                cerr<< setTextColor(TextColor::Red) << "Unsuccessful Read! Enter the match result (win or lose): " << setTextColor(TextColor::Default);
                continue;
            }
            if(csvFields["outcome"] == "Victory" || csvFields["outcome"] == "victory" || csvFields["outcome"] == "Defeat" || csvFields["outcome"] == "defeat") {
                file << csvFields["outcome"] << ", ";
                return true;
            }
            else {
                cerr<< setTextColor(TextColor::Red) << "Invalid outcome! Enter the match result (win or lose): " << setTextColor(TextColor::Default);\
                continue;
            }
        }
    }
    else if (fn == "roundsWon"){
        cout << setTextColor(TextColor::Cyan) << "Enter the number of Rounds Won: " << setTextColor(TextColor::Default);
        while(getline(cin, csvFields["defuses"]))
        {
            if (csvFields["roundsWon"].empty()) {
                cerr<< setTextColor(TextColor::Red) << "Unsuccessful Read! Enter the number of Rounds Won: " << setTextColor(TextColor::Default);
                continue;
            }
            if(is_valid_integer(csvFields["roundsWon"])) {
                if (stoi(csvFields["roundsWon"]) >= 0 && stoi(csvFields["roundsWon"]) <= 26){
                    file << csvFields["roundsWon"] << ", "; 
                    return true;
                }
                else {
                    cerr<< setTextColor(TextColor::Red) << "Invalid number of Rounds Won! Enter the number of Rounds Won: " << setTextColor(TextColor::Default);\
                    continue;
                }
            }
            else {
                cerr<< setTextColor(TextColor::Red) << "Invalid number of Rounds Won! Enter the number of Rounds Won: " << setTextColor(TextColor::Default);\
                continue;
            }
        }
    }
    else if (fn == "roundsLost"){
        cout << setTextColor(TextColor::Cyan) << "Enter the number of Rounds Lost: " << setTextColor(TextColor::Default);
        while(getline(cin, csvFields["roundsLost"]))
        {
            if (csvFields["roundsLost"].empty()) {
                cerr<< setTextColor(TextColor::Red) << "Unsuccessful Read! Enter the number of Rounds Lost: " << setTextColor(TextColor::Default);
                continue;
            }
            if(is_valid_integer(csvFields["roundsLost"])) {
                if (stoi(csvFields["roundsLost"]) >= 0 && stoi(csvFields["roundsLost"]) <= 26){
                    file << csvFields["roundsLost"] << ", "; 
                    return true;
                }
                else {
                    cerr<< setTextColor(TextColor::Red) << "Invalid number of Rounds Lost! Enter the number of Rounds Lost: " << setTextColor(TextColor::Default);\
                    continue;
                }
            }
            else {
                cerr<< setTextColor(TextColor::Red) << "Invalid number of Rounds Lost! Enter the number of Rounds Lost: " << setTextColor(TextColor::Default);\
                continue;
            }
        }
    }
    else if (fn == "mvpStatus"){
        cout << setTextColor(TextColor::Cyan) << "Enter the MVP Status (team, match, none): " << setTextColor(TextColor::Default);
        while(getline(cin, csvFields["mvpStatus"]))
        {
            if (csvFields["mvpStatus"].empty()) {
                cerr<< setTextColor(TextColor::Red) << "Unsuccessful Read! Enter the MVP Status (team, match, none): " << setTextColor(TextColor::Default);
                continue;
            }
            if(csvFields["mvpStatus"] == "team" || csvFields["mvpStatus"] == "Team" || csvFields["mvpStatus"] == "match" || csvFields["mvpStatus"] == "Match" || 
               csvFields["mvpStatus"] == "none" || csvFields["mvpStatus"] == "None") {
                file << csvFields["mvpStatus"] << "\n";
                return true;
            }
            else {
                cerr<< setTextColor(TextColor::Red) << "Invalid MVP Status! Enter the MVP Status (team, match, none): " << setTextColor(TextColor::Default);\
                continue;
            }
        }
    }
    return false;
}


bool isValidDate(string dateString) {
    // Check the length of the string
    if (dateString.length() != 10) {
        return false;
    }

    // Check that the separator characters are correct
    if (dateString[2] != '/' || dateString[5] != '/') {
        return false;
    }

    // Extract the month, day, and year components
    int month = stoi(dateString.substr(0, 2));
    int day = stoi(dateString.substr(3, 2));
    int year = stoi(dateString.substr(6, 4));

    // Check that the year, month, and day are valid
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    // Check for valid number of days in each month
    if (month == 2) { // February
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) { // Leap year
            if (day > 29) {
                return false;
            }
        } else {
            if (day > 28) {
                return false;
            }
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) { // April, June, September, November
        if (day > 30) {
            return false;
        }
    }

    return true;
}

bool is_valid_integer(string str) {
    try {
        stoi(str);
        return true;
    }
    catch (invalid_argument&) {
        // The string is not a valid integer
        return false;
    }
    catch (out_of_range&) {
        // The string is too large or too small to be represented as an integer
        return false;
    }
}

int count_lines(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        // File not found or could not be opened
        return -1;
    }

    int count = 0;
    std::string line;
    while (getline(file, line)) {
        count++;
    }

    file.close();
    return count;
}


