#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "game.h"



#include <iostream>
#include <fstream>
#include <vector>


std::vector<std::vector<char>> readMapFromFile() {
    std::ifstream file(MAPTXT);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << MAPTXT << std::endl;

        return {};
    }

    std::vector<std::vector<char>> map;
    std::string line;


    while (std::getline(file, line)) {

        std::vector<char> row(line.begin(), line.end());

        map.push_back(row);
    }

    file.close();

    return map;
}


int main()
{
    std::vector<std::vector<char>> map;
    map = readMapFromFile();
    Game game(map);
    game.run();

    return 0;
}
