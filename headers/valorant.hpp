#ifndef VALORANT_HPP
#define VALORANT_HPP

#include "headers.hpp"

class Valorant {
public:
    vector<string> maps { "Bind", "Haven", "Split", "Ascent", "Icebox", "Breeze", "Fracture", "Pearl", "Lotus" };
    vector<string> matchtypes {"competitive", "Competitive", "unrated", "Unrated", "misc", "Misc", "misc.", "Misc."};
    vector<string> agents = {"Brimstone", "Viper", "Omen", "Killjoy", "Cypher", "Sova", "Sage", "Phoenix", "Jett", 
                            "Reyna", "Raze", "Breach", "Skye", "Yoru", "Astra", "KAY/O", "KAY O", "KAYO", "Chamber", "Neon",
                            "Fade", "Harbor", "Gekko"};

    Valorant();
    vector<string> getMaps();
    vector<string> getMatchTypes();
    void printMaps();


};

#endif