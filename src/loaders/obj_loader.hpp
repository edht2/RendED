#include "object/object.hpp"
#include <string>
#include <vector>

std::vector<std::string> split(std::string str, char deliminer);

Object* loadObject(std::string file_name);