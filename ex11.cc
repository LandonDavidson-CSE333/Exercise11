// Copyright 2025 Landon Davidson
// landond@uw.edu

#include <algorithm>
#include <iostream>
#include <vector>

// A template function to read and return the given type from the given input stream
template <typename T> T ReadValue(std::istream& in);

// Read 6 doubles from cin and then print them back out in order
int main (int argc, char** argv) {
  std::vector<double> vector;

  // Prompt user for 6 doubles
  std::cout << "Enter 6 doubles:\n";

  // Read 6 doubles from cin using ReadValue which handles errors for us, and push onto vector
  for (int i = 0; i < 6; i++) {
    auto input = ReadValue<double>(std::cin);
    vector.push_back(input);
  }

  // Sort the input vector
  std::sort(vector.begin(), vector.end());
  // Print out the sorted input vector
  std::cout << "Your sorted doubles are:\n";
  for (double num : vector) {
    std::cout << num << "\n";
  }

  // Return a success code at the end of execution
  return EXIT_SUCCESS;
}

template<typename T>
T ReadValue(std::istream &in) {
  // If stream isn't good then exit with failure and print the proper error
  if (!in.good()) {
    // Find which error we had and print a relevant message to cerr
    if (in.eof()) {
      std::cerr << "Unexpected EOF";
      exit(EXIT_FAILURE);
    }
    if (in.bad()) {
      std::cerr << "Bad input stream";
      exit(EXIT_FAILURE);
    }
    if (in.fail()) {
      std::cerr << "Logical error, likely incorrect input type";
      exit(EXIT_FAILURE);
    }
  }

  // Extract result from in and return
  T res;
  in >> res;
  return res;
}
