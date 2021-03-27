#include <ObjModel.h>

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include <fstream>
#include <sstream>
#include <iostream>

ObjModel::ObjModel(const std::string &_filePath)
    : filePath(_filePath) { }

bool ObjModel::load() {
    // tmp data
    std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
    std::vector<glm::vec3> tmp_vertices;    // vertices coordinates
    std::vector<glm::vec2> tmp_uvs;         // texture map
    std::vector<glm::vec3> tmp_normals;     // normals vectors

    // open the file
    std::fstream in;
    in.open(filePath, std::ios::in);
    if(!in.is_open()){
        std::cout << "Impossible to open the file" << std::endl;
        return false;
    }

    // while can read, we do it
    while (!in.eof()){
        // read line
        std::string line;
        getline(in, line);

        // parse the line
        std::stringstream lineStream(line);

        // line type
        std::string lineType;
        lineStream >> lineType;

        if(lineType == "v"){    // vertices
            glm::vec3 vertex;
            lineStream >> vertex.x >> vertex.y >> vertex.z;
            tmp_vertices.push_back(vertex);
        }
        else if(lineType == "vn"){  // vertices normal
            glm::vec3 normal;
            lineStream >> normal.x >> normal.y >> normal.z;
            tmp_normals.push_back(normal);
        }
        else if(lineType == "vt"){  // vertices textures
            glm::vec2 uv;
            lineStream >> uv.x >> uv.y;
            tmp_uvs.push_back(uv);
        }
        else if(lineType == "f"){   // faces
            // a face can be a polygon, pares the line and see if we need to triangulate face
            std::vector<unsigned int> tmpVertexIndices, tmpUvIndices, tmpNormalIndices;

            std::string vertexProperties;
            while (!lineStream.eof()){
                lineStream >> vertexProperties;
                unsigned int vertexIndex, uvIndex, normalIndex;
                sscanf(vertexProperties.c_str(), "%u/%u/%u", &vertexIndex, &uvIndex, &normalIndex);
                //obj are indexing from 1
                tmpVertexIndices.push_back(vertexIndex-1);
                tmpUvIndices.push_back(uvIndex-1);
                tmpNormalIndices.push_back(normalIndex-1);
            }

            // hope is a convex polygon
            for (int index = 2; index < tmpVertexIndices.size(); ++index) {
                vertexIndices.push_back(tmpVertexIndices[0]);
                vertexIndices.push_back(tmpVertexIndices[index - 1]);
                vertexIndices.push_back(tmpVertexIndices[index]);

                uvIndices.push_back(tmpUvIndices[0]);
                uvIndices.push_back(tmpUvIndices[index - 1]);
                uvIndices.push_back(tmpUvIndices[index]);

                normalIndices.push_back(tmpNormalIndices[0]);
                normalIndices.push_back(tmpNormalIndices[index - 1]);
                normalIndices.push_back(tmpNormalIndices[index]);
            }
        }
    }

    // reserve size for data
    vertices.clear();
    uvs.clear();
    normals.clear();;

    for(auto&& i : vertexIndices){
        vertices.push_back(tmp_vertices[i].x);
        vertices.push_back(tmp_vertices[i].y);
        vertices.push_back(tmp_vertices[i].z);
    }

    for(auto&& i : uvIndices){
        uvs.push_back(tmp_uvs[i].x);
        uvs.push_back(tmp_uvs[i].y);
    }

    for(auto&& i : normalIndices){
        normals.push_back(tmp_normals[i].x);
        normals.push_back(tmp_normals[i].y);
        normals.push_back(tmp_normals[i].z);
    }

    return true;
}

const std::string &ObjModel::getFilePath() const {
    return filePath;
}

const std::vector<float> &ObjModel::getVertices() const {
    return vertices;
}

const std::vector<float> &ObjModel::getNormals() const {
    return normals;
}

const std::vector<float> &ObjModel::getUvs() const {
    return uvs;
}
