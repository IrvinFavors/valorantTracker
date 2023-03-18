#include "headers/tools.hpp"

string setTextColor(TextColor color) {
    return "\033[" + to_string(static_cast<int>(color)) + "m";
}