#ifndef SIMPLEOBJVIEWER_OBJMODEL_H
#define SIMPLEOBJVIEWER_OBJMODEL_H

#include <vector>
#include <string>

class ObjModel{
protected:
    std::string filePath;

    std::vector<float> vertices;
    std::vector<float> normals;
    std::vector<float> uvs;

public:
    ObjModel(const std::string &_filePath);

    virtual bool load();

    const std::string &getFilePath() const;

    const std::vector<float> &getVertices() const;

    const std::vector<float> &getNormals() const;

    const std::vector<float> &getUvs() const;
};

#endif //SIMPLEOBJVIEWER_OBJMODEL_H
