#include "../include/Utils.h"

#include <iostream>

void Utils::write_json_file(std::string filename, std::string json_buffer) {
    std::ofstream json_file(filename.append(".json"));
    if (!json_file.is_open())
    {
        throw std::runtime_error("unable to write/create json file");
    }
    json_file << json_buffer;
    json_file.close();
    std::cout << filename << " created successfully!\n";
}