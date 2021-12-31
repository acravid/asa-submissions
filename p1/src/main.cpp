#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#define P1 1
#define P2 2



class SolutionP1 {
//public:
    
    
};

class SolutionP2 {
//public:
 


};



 int main()
{
    int command;

    std::cin >> command;
    // removes whitespace that follows "command"
    std::cin >> std::ws;

    if(command == P1) {
      
     
      std::string line_to_process;
      std::vector<int> numbers;
  
      // pushes values to the vector 
      while(getline(std::cin, line_to_process, ' ')) {
        numbers.push_back(std::stoi(line_to_process));

      }
    
    } else if(command == P2) {

      std::cout << "Problema 2" << std::endl;
      // do somehing
    } else {
      // error handling 
    }
      
    return 0;
}


