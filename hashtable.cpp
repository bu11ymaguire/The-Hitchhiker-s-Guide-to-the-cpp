#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;
const char TWO_SUM = 'T';
const char SYMMETRIC_PAIRS = 'S';

vector<int> readIntegers(int k, string& line) {
  vector<int> arr;
  istringstream liss(line);
  int val;
  for (int i = 0; i < k; ++i) {
    if (!(liss >> val)) {
      cerr<<"Error: invalid input value"<<endl;
      exit(1);
    }
    else {
      arr.push_back(val);
    }
  }
  return arr;
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cerr<<"Correct usage: [program] [input] [output]"<<endl;
    exit(1);
  }
  ifstream inFile(argv[1]);
  ofstream outFile(argv[2]);
  string line;
  while (getline(inFile, line))
  {
    char op = line[0];
    istringstream iss(line.substr(2));
    vector<int> nums;
    vector<pair<int, int>> pairs;
    vector<pair<int, int>> ans;
    vector<pair<int, int>>::iterator it;
    int k, n, a, b;
    bool exist;

    switch(op)
    {
      case TWO_SUM:{
        if (!(iss >> k >> n)) {
          cerr<<"TWO_SUM: invalid input"<<endl;
          exit(1);
        }
        if (!getline(inFile, line)) {
          cerr<<"TWO_SUM: unable to read a line"<<endl;
          exit(1);
        }
        nums = readIntegers(n, line);
        unordered_map<int, int> hello_there;
        for (int i = 0; i < nums.size(); i++)
        {
            hello_there[nums[i]]++;
        }
        exist = false;
        for (int i = 0; i < nums.size(); i++)
        {
            int ampair = k - nums[i];
            if (ampair == nums[i])
            {
                if (hello_there[ampair] >= 2) {
                    exist = true;
                    break;
                }
                else {
                    continue;
                }
            }
            if (hello_there[ampair] != 0)
            {
                exist = true;
                break;
            }
        }
        if(exist){
          outFile<<'T'<<endl;
        }else{
          outFile<<'F'<<endl;
        }
        break;
      }
      case SYMMETRIC_PAIRS:{
        if (!(iss >> n)) {
          cerr<<"SYMMETRIC_PAIRS: invalid input"<<endl;
          exit(1);
        }
        for (int i = 0; i < n; ++i) {
          if (!getline(inFile, line)) {
            cerr<<"SYMMERIC_PAIRS: invalid input"<<endl;
            exit(1);
          }
          istringstream tiss(line);
          if (!(tiss >> a >> b)) {
            cerr<<"SYMMETRIC_PAIRS: invalid input"<<endl;
            exit(1);
          }
          pairs.push_back(make_pair(a, b));
        }
        unordered_map<int,int> hello_world;
        for(int i=0;i<pairs.size();i++)
        {
          int a = pairs[i].first;
          int b = pairs[i].second;
          if(hello_world.count(b)&&hello_world[b]==a)
          {
            outFile<<b<<' '<<a<<endl;
          }else
          {
            hello_world[a] = b;
          }
        }
        break;
      } 
      default:{
        cerr<<"Undefined operator"<<endl;
        exit(1);
      }
    }
  }
  outFile.close();
  inFile.close();
}
