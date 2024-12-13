#include <iostream>
#include <mutex>
using namespace std;

class file_parser {
    public:
        virtual ~file_parser() = default;
        virtual void parse(const string& file_path, mutex& stdout_writing) = 0; // virtual method (interface)
};