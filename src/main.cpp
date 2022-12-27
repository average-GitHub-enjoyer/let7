#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <sstream>

std::string readFileFromPath(const std::string &path);
std::vector<std::string> stringArray(std::string &someString);
void showVector(std::vector<std::string> &text);
void printPalindromes(std::vector<std::string> someArray);
bool isPalindrome(const std::string &word);
std::vector<std::string> getPalindromeArray(std::vector<std::string> &someArray);

int main() {
  std::string rawString = readFileFromPath("prikol.txt");
  std::vector<std::string> rawArray = stringArray(rawString);
  std::vector<std::string> palindromeArray = getPalindromeArray(rawArray);
  printPalindromes(palindromeArray);
  
  return 0;
}

std::string readFileFromPath(const std::string &path) {
  std::ifstream f(path);
  std::string result;
  if (f) {
    std::ostringstream ss;
    ss << f.rdbuf();
    return ss.str();
  } else {
    return "-1";
  }
}

std::vector<std::string> stringArray(std::string &someString) {
  std::vector<std::string> arr;
  std::string delimiter = "\n";

  size_t pos = 0;
  std::string token;
  while ((pos = someString.find(delimiter)) != std::string::npos) {
    token = someString.substr(0, pos);
    arr.push_back(token);
    someString.erase(0, pos + delimiter.length());
  }
  return arr;
}

void showVector(std::vector<std::string> &text) {
  for (std::string line : text)
    std::cout << line << std::endl;
}

std::vector<std::string> getPalindromeArray(std::vector<std::string> &someArray) {
  std::vector<std::string> palindromeArray;
  for (std::string line : someArray){
    if (isPalindrome(line)){
      palindromeArray.push_back(line);
    }
  }
  return palindromeArray;
}

bool isPalindrome(const std::string &word){
  for (int i=0; i != word.length()/2; i++) {
    if (std::tolower(word[i]) != std::tolower(word[word.length()-i-1])) {
      return false;
    }
  }
  return true;
}

void printPalindromes(std::vector<std::string> palindromeArray){
  printf("{\n\t\"count_palindromes\": %d,\n\t\"palindromes\": [", (int)palindromeArray.size());
  printf("\"%s\"", palindromeArray[0].c_str());
  for (int i=1; i < (int)palindromeArray.size(); i++){
    printf(", \"%s\"", palindromeArray[i].c_str());
  }
  printf("]\n}\n");
}
