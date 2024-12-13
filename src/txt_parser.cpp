#include <iostream>
#include <fstream>
#include <mutex>
#include "file_parser.cpp"
using namespace std;

class txt_parser : public file_parser {
    public:
        void parse(const string& file_path, mutex& stdout_writing) override {
            std::lock_guard<std::mutex> lock(stdout_writing); // lock the stdout with only one thread

            cout << file_path << endl; // filename for the python
            
            ifstream f(file_path);
            if (!f.is_open()) {
                cout << "File not found: " << file_path << endl;
                return;
            }

            string line;
            while(getline(f, line)) { // read the lines of the file
                cout << line << endl; // data for the python
            }
            
            f.close();
        }
};