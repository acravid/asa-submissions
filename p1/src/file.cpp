#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#define P1 1
#define P2 2
#define newline "\n"


void lic_p1(std::vector<int> nums) {
  int n = nums.size();
  
  if(n < 1) { // base case
    std::cout <<  n << " " << n << newline;
    return;
  }

  std::vector<int> longest_subsequence_at_index(n,1),  longest_subsequence_counter_at_index(n,1);
  int longest_subsequence = 1, previous_longest, new_longest; 

  for(int i = 1; i < n; i++) {
    for(int j = 0; j < i; j++) {
      if(nums[i] > nums[j]) {                                            

        previous_longest = longest_subsequence_at_index[i];
        new_longest = longest_subsequence_at_index[j] + 1;

        // Check if the new longest length is equal to a previously seen length
        // if so, add to the counter 
        if (previous_longest == new_longest) { 
          // all indexes were initialized to 1
          longest_subsequence_counter_at_index[i] += longest_subsequence_counter_at_index[j];
         
        } else if(new_longest > previous_longest) {  // we found a newer LIS 
            if(previous_longest == longest_subsequence) {
              longest_subsequence = new_longest;

            }

            longest_subsequence_at_index[i] = new_longest;
            longest_subsequence_counter_at_index[i] = longest_subsequence_counter_at_index[j];
        }
      }
    }
  }

  // number of longest increasing subsequence
  int num_of_lis = 0;

  for(int i = 0; i < n; i++) {
    if(longest_subsequence_at_index[i] == longest_subsequence) {
      num_of_lis += longest_subsequence_counter_at_index[i];
    }
  }

  std::cout << longest_subsequence << " " << num_of_lis << newline;
}


void lcis_p2() {




}

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
      lic_p1(numbers);

    } else if(command == P2) {

      std::cout << "Problema 2" << newline;
      // do somehing
    } else {
      std::cout << "An error has occurred, try again with different values" << newline;
    }
      
    return 0;
}


