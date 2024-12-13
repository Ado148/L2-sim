// Author: Bc.  Adam Pap
// Description: This program is used to process the input files data and then 
//              give them to the python script

#include <iostream>
#include <vector>
#include <fstream>
#include <future>
#include <mutex>
#include "parse_factory.cpp"
using namespace std;

void process_file(const string& file, parse_factory& parsers, mutex& stdout_writing) {
    string file_extension = file.substr(file.find_last_of(".") + 1);
    auto parser = parsers.get_parser(file_extension); // get the correct parser based on extension

    if (parser) {
        parser->parse(file, stdout_writing);
    } else {
        lock_guard<mutex> lock(stdout_writing); // lock the stdout_writing mutex
        cout << "File extension is not supported: " << file_extension << endl;
        return;
    }
}

int main(int argc, char const *argv[])
{
    vector <string> files(argv + 1, argv + argc); // vector of the cmd. line arguments
    mutex stdout_writing; // mutex to prevent concurrent writing to stdout
    vector<future<void>> futures; // vector of the futures for the threads

    parse_factory parsers;

    for(const auto& file:files) { // process each file in parallel
        futures.push_back(async(launch::async, process_file, file, ref(parsers), ref(stdout_writing))); // process the files in parallel
    }

    for(auto& future : futures) {
        future.get(); // wait for all the threads to finish
    }

    return 0;
}