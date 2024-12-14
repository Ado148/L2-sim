#include <iostream>
#include <fstream>
#include <mutex>
#include "file_parser.hpp"

using namespace std;

class bin_parser : public file_parser {
    public: 
        int parse(const string& file_path, mutex& stdout_writing) override {   
            ifstream f(file_path, ios::binary);
            if (!f.is_open()) {
                //cout << "File not found: " << file_path << endl;
                return 1;
            } 

            uint32_t plane_point;
            while(f.read(reinterpret_cast<char *>(&plane_point), 4)) { // read 4 bytes
                uint8_t group = (plane_point >> 24) & 0xFF;
                uint16_t x = (plane_point >> 12) & 0xFFF ; // we need to mask it by 0xFFF because of the 12 bits
                uint16_t y = plane_point & 0xFFF;

                { //lock the scope for the stdout - critical section
                    lock_guard<mutex> lock(stdout_writing);
                    cout << file_path << " " << static_cast<int>(group) << ":" << x << "," << y << endl; // data for the python
                }
            }
            
            f.close();
            return 0;
        }
};