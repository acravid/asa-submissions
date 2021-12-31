#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#define P1 1
#define P2 2





class Solution1
{
//public:
  //MyClass(int t_data)
  //  : m_data(t_data)
  //{

  //}

  //int getData() const
  //{
  // return m_data;
  //}

//private:
};


class Solution2
{
//public:
  //MyClass(int t_data)
  //  : m_data(t_data)
  //{

  //}

  //int getData() const
  //{
  // return m_data;
  //}

//private:
};

 int main()
{
    int command;

    std::cin >> command;

    if(command == P1) {
      
      std::string line_to_process;

      std::vector<std::string> numbers;
    

      // removes whitespace that follows "command"
      std::cin >> std::ws;

      // if we're inside the problem 1 
      // we only have 1 line left to process 
      // 
      // line 2 -- a sequence of integers 

      // change std::endl to something else // 
      std::cout << "Problema 1\n" ;


      // pushes values to the string vector 

      // -- I might have to change the vector type later | atoi function
      while(getline(std::cin, line_to_process, ' ')) {
        numbers.push_back(line_to_process);

      }
      

      std::cout << "START LOOP\n";

      for (std::string number : numbers)
      {
        std::cout << number << "\n";
      }
    


      // now the line we'll read next has the sequence of integers, we want to store in the vector




      // if we're inside the problem 1 
      // we only have to deal with 2 lines
      // line 1 -- tells us the problem we're working on 
      // line 2 -- a sequence of integers 



      // do somehting 
    } else if(command == P2) {

      std::cout << "Problema 2" << std::endl;
      // do somehing
    } else {
      // error handling 
    }
  




  
    return 0;
}




