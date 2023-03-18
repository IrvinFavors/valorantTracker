#include "headers/valorant.hpp"

Valorant::Valorant() {
    cout << "Can Access Valorant Assets" << endl;
}

vector<string> Valorant::getMaps() {
    return maps;
}

vector<string> Valorant::getMatchTypes() {
    return matchtypes;
}

void Valorant::printMaps() {
    cout << "\033[31m\nValorant maps: \033[0m";
    for (string map : this->maps) {
        cout << map << " ";
    }
    cout << endl;
}