// Author: Bc.  Adam Pap
// Description: This class is used to parse the json (.json) files 

#include <iostream>
#include <fstream>
#include <mutex>
#include "file_parser.hpp"

// Using the nlohmann::json library, which is licensed under the MIT License.
// See the LICENSE file in the project root for more information.
#include "third_party_libs/json.hpp"
using json = nlohmann::json;

class json_parser : public file_parser { 
    public: 
        int parse(const string& file_path, mutex& stdout_writing) override {
            ifstream f(file_path);
            if(!f.is_open()) {
                return 1;
            }

            json data = json::parse(f); // data is the json object
            if(data.contains("points") && data["points"].is_array()) {
                for(auto& point : data["points"]) {
                    if(point.contains("group") && point.contains("x") && point.contains("y"))
                    {
                        string group = point["group"];
                        int x = point["x"];
                        int y = point["y"];

                    {
                        lock_guard<mutex> lock(stdout_writing);
                        cout << file_path << " " << group << ":" << x << "," << y << endl;
                    }
                    } else {
                        return 1;
                    }
                }
            } else {
                return 1;
            }

            f.close();
            return 0;
        }
};