#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const std::string WHITESPACE = " \n\r\t\f\v";
 
std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
std::string trim(const std::string &s) {
    return rtrim(ltrim(s));
}

char asciitolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

void lowercase(std::string &inStr) {
  std::transform(inStr.begin(), inStr.end(), inStr.begin(), asciitolower);

}

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    std::stringstream ss(s);
    std::string item;
    elems.clear();
    while(std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

/* method to compare two pairs based on the second parameter,
   it is used as a comparator function to sort a vector of pairs */
bool sortByVal(const pair<string, int> &a, const pair<string, int> &b){
  return a.second > b.second;
}


int main(int argc, char** argv) {

  string filename;

  if (argc > 1) {
    filename = argv[1];
  }
  else {
    cout << "usage: shakespeare input.txt\n";
    return 1;
  }

  int top = 100;
  if (argc > 2) {
    top = atoi(argv[2]);
  }

  vector<string> words;
  map<string, int> counts;
  
  ifstream file;
  file.open(filename);

  int i;
  
  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      split(line, ' ', words);
      for (i=0; i < words.size(); i++) {
	words[i] = trim(words[i]);
	
	if (words[i].length() == 0)
	  continue;

	lowercase(words[i]);
	
	if (counts.count(words[i]) == 0) {
	  counts[words[i]]=0;
	}
	counts[words[i]]++;
	
      }
    }
    
    file.close();
  }

  vector<pair<string, int> > arr;
  for (const pair<string,int> &item : counts) {
    arr.emplace_back(item);
  }
  
  std::sort(arr.begin(), arr.end(), sortByVal);
  
  cout << "Top " << top << " words in '" << filename << "'." << endl;
  i = 0;
  for (const auto &item : arr) {
    cout << item.first << " : " << item.second << endl;
    if (i++ >= top)
      break;
  }  
  return 0;
}
