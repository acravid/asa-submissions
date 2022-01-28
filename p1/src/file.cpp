#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>


#define P1 1
#define P2 2
#define newline "\n"

void process_input(std::vector<int> &a, std::vector<int> &b, int lines) {
  
  std::unordered_map<int,int> commom_aux;
  int i = 0;
  while(i < lines) {
    std::string line;
    int input;
    getline(std::cin, line);
    std::istringstream iss(line);
    while( iss >> input){
      if(i == 0) {
        a.push_back(input);
        commom_aux.insert(std::make_pair(input,input));
      } else {
        if((commom_aux.count(input) != 0)) {
            b.push_back(input);
        }
      }
    }
    i++;
  }
}


void lic_p1(std::vector<int> &numbers) {
  long unsigned int n = numbers.size();
  
  if(n < 1) {
    std::cout <<  n << " " << n << newline;
    return;
  }
                                                     
  std::vector<int> longest_subsequence_at_index(n,1),  longest_subsequence_counter_at_index(n,1);
  int longest_subsequence = 1, previous_longest, new_longest; 

  for(std::vector<int>::size_type i = 1; i < n; i++) {
    for(std::vector<int>::size_type j = 0; j < i; j++) {
      if(numbers[i] > numbers[j]) {                                            

        previous_longest = longest_subsequence_at_index[i];
        new_longest = longest_subsequence_at_index[j] + 1;

        if (previous_longest == new_longest) { 
          
          longest_subsequence_counter_at_index[i] += longest_subsequence_counter_at_index[j];
         
        } else if(new_longest > previous_longest) {  
            if(previous_longest == longest_subsequence) {
              longest_subsequence = new_longest;

            }
            longest_subsequence_at_index[i] = new_longest;
            longest_subsequence_counter_at_index[i] = longest_subsequence_counter_at_index[j];
        }
      }
    }
  }

  int num_of_lis = 0;

  for(std::vector<int>::size_type i = 0; i < n; i++) {
    if(longest_subsequence_at_index[i] == longest_subsequence) {
      num_of_lis += longest_subsequence_counter_at_index[i];
    }
  }

  std::cout << longest_subsequence << " " << num_of_lis << newline;
}


void lcis_p2(std::vector<int> &first_line, std::vector<int> &second_line) {

  long unsigned int len_1 = first_line.size();
  long unsigned int len_2 = second_line.size();

  std::vector<int> LCIS(len_2,0);

  for(std::vector<int>::size_type i = 0 ; i != len_1; i++) {
    int curr_lcis = 0;
    for(std::vector<int>::size_type j = 0; j !=  len_2; j++) {
      
      if(first_line[i] == second_line[j]) {
        if(curr_lcis + 1 > LCIS[j]) { 
          LCIS[j] = curr_lcis + 1; 

        } 
      } 
      if(first_line[i] > second_line[j]) {
        if(LCIS[j] > curr_lcis) {
          curr_lcis = LCIS[j];
        }
      }
    }
  }

  int res = 0;
  for(std::vector<int>:: size_type i = 0; i != len_2; i++) {
    if(LCIS[i] > res) {
      res = LCIS[i];
    }
  }

  std::cout << res << newline; 
}


int main() {
    int command;

    std::cin >> command;
    std::cin >> std::ws;

    if(command == P1) {
  
      std::string line_to_process;
      std::vector<int> numbers; 
      while(getline(std::cin, line_to_process, ' ')) {
        numbers.push_back(std::stoi(line_to_process));

      }
      lic_p1(numbers);

    } else if(command == P2) {

      std::vector<int> first_vector;
      std::vector<int> second_vector;

      process_input(first_vector, second_vector, command);
      lcis_p2(first_vector,second_vector); 
    } else {
      std::cout << "An error has occurred, try again with different values" << newline;
    }     
    return 0;
}