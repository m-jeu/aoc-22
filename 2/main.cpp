#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

#include "shape.h"


int main() {

    std::filesystem::path inputPath = std::filesystem::current_path().string() + "/../inp.txt";

    std::fstream file;
    file.open(inputPath, std::ios::in);

    if(file.is_open()){

        std::string line;
        unsigned int totalScore = 0;

        while(std::getline(file, line)){

            Shape own = Shape::fromReadChar(line.at(2));
            Shape ops = Shape::fromReadChar(line.at(0));

            totalScore += own.versus(ops);

        }
        file.close();
        std::cout << "Total score: " << totalScore << std::endl;

    }else{

        std::cout << "Problem opening file" << std::endl;

    }

}
