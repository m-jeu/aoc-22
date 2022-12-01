#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <queue>


//
// Not very nice-looking yet, but just getting back into C++ after a long break,
// So forgive me
//


int main() {

    // Default file path goes to cmake-build-debug folder
    // Go up one level to properly read file
    std::filesystem::path inputPath = std::filesystem::current_path().string() + "/../inp.txt";

    //
    // 1a.
    //

    std::cout << "1a." << std::endl;

    std::fstream file;
    file.open(inputPath, std::ios::in);

    std::string line;

    // Assume positive integers only
    unsigned int highestMax = 0;  // Highest batch maximum found
    unsigned int currentAmount = 0; // Total of current batch

    if(file.is_open()){
        while(std::getline(file, line)){

            if(line.size() > 0) { // If line is not empty, add number to currentAmount
                currentAmount += std::stoi(line);
            }else{ // If line is empty, compare currentAmount to highestAmount to track maximum and reset currentAmount
                if(currentAmount > highestMax){
                    highestMax = currentAmount;
                }
                currentAmount = 0;
            }

        }
        file.close();
    }else{
        std::cout << "Issue opening file.";
    }

    std::cout << highestMax << std::endl;

    //
    // 1b.
    //

    std::cout << "1b." << std::endl;

    file.open(inputPath, std::ios::in);

    // Assume positive integers only
    currentAmount = 0; // Reset total of current batch
    std::priority_queue<unsigned int> orderedElves; // Ordered queue of batches

    if(file.is_open()){
        while(std::getline(file, line)){

            if(line.size() > 0) { // If line is not empty, add number to currentAmount
                currentAmount += std::stoi(line);
            }else{ // If line is empty, add currentAmount to orderedElves and reset
                orderedElves.push(currentAmount);
                currentAmount = 0;
            }
        }
        file.close();
    }else{
        std::cout << "Issue opening file.";
    }

    unsigned int totalResult = 0;

    // Fetch top 3
    for (unsigned int i = 0; i < 3; i++){
        totalResult += orderedElves.top();
        orderedElves.pop();
    }

    std::cout << totalResult << std::endl;
}
