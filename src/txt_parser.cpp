// Author: Bc.  Adam Pap
// Description: This class is used to parse the txt (.txt) files          

#include <iostream>
#include <fstream>
#include <mutex>
#include "file_parser.hpp"
using namespace std;

class txt_parser : public file_parser {
    public:
        int parse(const string& file_path, mutex& stdout_writing) override {
            // {
            //     lock_guard<mutex> lock(stdout_writing); // lock the stdout with only one thread
            //     cout << file_path << endl; // filename for the python
            // }
            ifstream f(file_path);
            if (!f.is_open()) {
                //cout << "File not found: " << file_path << endl;
                return 1;
            }

            string line;
            while(getline(f, line)) { // read the lines of the file
                
                { //lock the scope for the stdout - critical section
                    lock_guard<mutex> lock(stdout_writing);
                    cout << file_path << " " << line << endl; // data for the python
                }
            }
            
            f.close();
            return 0;
        }
};