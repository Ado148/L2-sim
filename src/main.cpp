// Author:      Adam Pap
// Description: This program is used to process the input files data and then 
//              give them to the python script

#include <iostream>
#include <vector>
#include <fstream>
#include <future>
#include <mutex>
#include "parse_factory.cpp"
using namespace std;

int process_file(const string& file, parse_factory& parsers, mutex& stdout_writing) {
    /*
    * This function is used to choose the correct parser based on the file extension
    */

    string file_extension = file.substr(file.find_last_of(".") + 1);
    auto parser = parsers.get_parser(file_extension); // get the correct parser based on extension
    
    if (parser) {
        int parsing_result = parser->parse(file, stdout_writing);
        if (parsing_result != 0) { // if the parsing was not successful
            lock_guard<mutex> lock(stdout_writing);
            cout << "Error occured while parsing file: " << file << endl;
            return parsing_result;
        }
    } else { // if the file extension is not supported
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    vector <string> files(argv + 1, argv + argc); // vector of the cmd. line arguments
    mutex stdout_writing; // mutex to prevent concurrent writing to stdout
    vector<future<int>> futures; // vector of the futures for the threads

    parse_factory parsers;

    for(const auto& file:files) { // process each file in parallel
        futures.push_back(async(launch::async, process_file, file, ref(parsers), ref(stdout_writing))); // process the files in parallel
    }

    for(auto& future : futures) {
        int final_result = future.get(); // wait for all the threads to finish
        if(final_result != 0) {
            cout << "Some files were not processed successfully" << endl;
            return 2;
        }
    }

    return 0;
}