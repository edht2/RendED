#include "loaders/obj_loader.hpp"
#include "object/object.hpp"
#include <bits/stdc++.h>
#include "core/vector3.hpp"
#include <iostream>
#include <fstream>

std::vector<std::string> split(std::string str, char deliminer) {
    std::string s;
    std::stringstream ss(str);
    std::vector<std::string> v;

    while (getline(ss, s, ' ')) {
        v.push_back(s);
    }
    return v;

}

Object* loadObject(std::string file_name) {
    std::ifstream obj_file(file_name);

    if (!obj_file.is_open()) {
        std::cerr << "Error: Could not open file '" << file_name << "'.\n";
    }

    std::vector<Vector3> verticies;
    std::vector<Triangle> triangles;

    if (obj_file.is_open()) {
        std::string line;
        while (std::getline(obj_file, line)) {
            // for every line in the obj file
            auto line_sp = split(line, ' ');

            if (line_sp[0] == "v") {
                // loading vertex
                verticies.push_back(Vector3(std::stof(line_sp[1]), -std::stof(line_sp[2]), std::stof(line_sp[3])));
            } // also include vt, vn and mtl
            else if (line_sp[0] == "f") {
                triangles.push_back(
                    Triangle(
                        verticies[std::stof(split(line_sp[1], '/')[0])-1],
                        verticies[std::stof(split(line_sp[2], '/')[0])-1],
                        verticies[std::stof(split(line_sp[3], '/')[0])-1]
                    )
                );
            }
        }

        obj_file.close();
        // close file

        Object* pObject = new Object(triangles);

        return pObject;
    }
    else {
        std::cerr << "Error opening file!" << std::endl;
    }
    Object* pObject = new Object();
    return pObject;
}