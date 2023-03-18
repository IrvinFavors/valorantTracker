#include "headers/tracker.hpp"

map<string, string> csvFields;
string username, tag, datastr, input, filename;
fstream file;
Valorant valorant;
    
int main() {
    cout<< setTextColor(TextColor::Cyan) << "\nEnter Username: " << setTextColor(TextColor::Default);
    getline(cin, username);
    while (username.length() > 16 || username.length() == 0){ //May need to exclude special characters
        cout<< setTextColor(TextColor::Cyan) << "Enter Username: " << setTextColor(TextColor::Default);
        getline(cin, username);
    }
    cout<< setTextColor(TextColor::Cyan) << "Enter Tag: " << setTextColor(TextColor::Default);
    getline(cin, tag);
    while (tag.length() > 5 || tag.length() == 0){
        cerr<< setTextColor(TextColor::Red) << "Try Again! Invalid Tag Entered.\n" << setTextColor(TextColor::Cyan) << "Tag: " << setTextColor(TextColor::Default);
        getline(cin, tag);
    }

    cout<<username<<"#"<<tag<<endl<<endl;
    filename = "data/"+username+tag+".csv";

    file.open(filename, fstream::app); //ensure a file is created if it does not exist

    if (count_lines(filename) == 0) {
        file << "nodeID, date, map, agent, kills, deaths, assist, avgCombatScore, econRating, firstBloods, plants, defuses, outcome, roundsWon, roundsLost, mvpStatus\n";
    }
    
    file.close(); //close file for different modes
    file.open(filename); //open file
    
    assignField("nodeID");
    if (csvFields["nodeID"] == "nodeID") csvFields["nodeID"] = "1";
    else csvFields["nodeID"] = to_string(stoi(csvFields["nodeID"])+1);
    
    file.close();
    file.open(filename, fstream::app);
    
    
    file << csvFields["nodeID"] << ", ";
    
    cout<<"**Enter 'exit' to stop logging data.**\n";
    assignField("date");
    assignField("map");
    assignField("compStatus");
    assignField("agent");
    assignField("kills");
    assignField("deaths");
    assignField("assists");
    assignField("avgCombatScore");
    assignField("econRating");
    assignField("firstBloods");
    assignField("plants");
    assignField("defuses");
    assignField("outcome");
    assignField("score");
    assignField("mvpStatus");


    file.close();
    cout << "File " << filename << " written successfully." << endl;
    return 0;
}