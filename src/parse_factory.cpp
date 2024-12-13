#include "txt_parser.cpp"
#include <memory>
using namespace std;

class parse_factory {
    public:
        unique_ptr<file_parser> get_parser(const string& file_extension){
            if (file_extension == "txt") {
                return unique_ptr<file_parser>(new txt_parser); // ensure unique instance of the txt_parser for each thread                                                                 
            } else {
                cout << "Unsupported file extension: " << file_extension << endl;
                return nullptr;
            }
        }
};