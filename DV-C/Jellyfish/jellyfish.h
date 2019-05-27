#ifndef JELLYFISH_H
#define JELLYFISH_H

#include "GL/glew.h"

#include "glData/vbo.h"

#include "glData/vao.h"

#include "glm/glm.hpp"
#include <vector>
#include <map>

const int NUM_VERTICES = 10;

class jellyfish
{
public:
    jellyfish();
    virtual ~jellyfish();
    void setVertexData(GLfloat *data, int size, int numVertices);
    void buildVAO();
    void draw();
    virtual GLfloat* getVertexData();
    virtual void initializeShape();
    virtual int getVertexNumber();
    virtual int getVertexSize();
    void readOBJ(const char *path);
    void readMaterial(const char *path);
    glm::vec3 getCenter();

protected:
    std::vector<GLfloat> m_vertices;
    std::map<int, glm::vec3> m_vertexMap;
    std::vector<glm::vec3> m_vert;

private:
    GLfloat *m_data;
    GLsizeiptr m_size;
    int m_numberOfVertices;
    std::unique_ptr<VAO> m_VAO;
    glm::vec3 m_center;
    glm::vec3 m_ambient;
    glm::vec3 m_diffuse;
    glm::vec3 m_specular;

};

#endif // JELLYFISH_H
