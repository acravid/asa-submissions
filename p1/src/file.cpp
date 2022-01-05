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


void lic_p1(std::vector<int> numbers) {
  long unsigned int n = numbers.size();
  
  if(n < 1) { // base case
    std::cout <<  n << " " << n << newline;
    return;
  }
                                                       // stores the count of all LIS that ends at numbers[i]             
  std::vector<int> longest_subsequence_at_index(n,1),  longest_subsequence_counter_at_index(n,1);
  int longest_subsequence = 1, previous_longest, new_longest; 

  // O(N^2) 
  for(std::vector<int>::size_type i = 1; i < n; i++) {
    for(std::vector<int>::size_type j = 0; j < i; j++) {
      if(numbers[i] > numbers[j]) {                                            

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

  // number of longest increasing subsequences
  int num_of_lis = 0;

  for(std::vector<int>::size_type i = 0; i < n; i++) {
    if(longest_subsequence_at_index[i] == longest_subsequence) {
      num_of_lis += longest_subsequence_counter_at_index[i];
    }
  }

  std::cout << longest_subsequence << " " << num_of_lis << newline;
}


void lcis_p2(std::vector<int> first_line, std::vector<int> second_line) {

  long unsigned int len_1 = first_line.size();
  long unsigned int len_2 = second_line.size();


  // a small example to verify the correctness
  // first_line -> <2, 1, 2, 2>
  // second_line -> <2, 2, 1, 2> , during the I/O phase we pushed to the second vector only elements that
  // already exist in the first (1)

  // this vector will store the length of 
  // longest common increasing subsequence known so far at k-th index
  // the longest possible length is given by the second vector, see (1)
  std::vector<int> LCIS(len_2,0);


  // iterate over elements in the first vector
  for(std::vector<int>::size_type i = 0 ; i != len_1; i++) {
    int curr_lcis = 0;
    // for each element in the first vector we iterate through all elements in the second
    for(std::vector<int>::size_type j = 0; j !=  len_2; j++) {
      
      // Check if the common condition is met LC (Longest Common)
      if(first_line[i] == second_line[j]) { // if we have the following vector < 5,5,5,5> we have 4 increasing subsequences of length 1 each
        // if the current length at j-th index is smaller than the current plus 1
        if(curr_lcis + 1 > LCIS[j]) { 
          LCIS[j] = curr_lcis + 1; // we update its length  

        } 
      }
      // Check for a increasing subsequence 
      if(first_line[i] > second_line[j]) {
        if(LCIS[j] > curr_lcis) { // if the LCIS at j-th index is bigger than the current
          // there's previous element in the first subsequence that is common to the second
          curr_lcis = LCIS[j]; // if so update the counter for the length 
        }

      }
    }
  }
  // the maximum value in LCIS is our answer
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

      std::vector<int> first_vector;
      std::vector<int> second_vector;

      process_input(first_vector, second_vector, command);
     // lcis_p2(first_vector,second_vector); 
    } else {
      std::cout << "An error has occurred, try again with different values" << newline;
    }
      
    return 0;
}