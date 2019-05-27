#include "jellyfish.h"

#include <iostream>
#include <fstream>

jellyfish::jellyfish():
    m_size(0),
    m_numberOfVertices(0),
    m_VAO(nullptr),
    m_vertices(),
    m_center(glm::vec3(0.f))
{

}

jellyfish::~jellyfish(){

}

void jellyfish::setVertexData(GLfloat *data, int size, int numVertices){
    m_data = data;
    m_size = size;
    m_numberOfVertices = numVertices;
}

void jellyfish::buildVAO(){
    VBO vbo = VBO(m_data, m_size);
    m_VAO = std::make_unique<VAO>(vbo, m_numberOfVertices);
}

void jellyfish::draw(){
    if(m_VAO != nullptr){
        m_VAO->bind();
        m_VAO->draw();
        m_VAO->unbind();
    }
}

GLfloat* jellyfish::getVertexData(){
    return m_vertices.data();
}

int jellyfish::getVertexNumber(){
    return m_vertices.size()/3;
}

int jellyfish::getVertexSize(){
    return m_vertices.size();
}

void jellyfish::readOBJ(const char *path){
    std::vector<unsigned int> vertexIndices;
    std::vector<unsigned int> normalIndices;
    std::vector<glm::vec3> normals;
    FILE *file = std::fopen(path, "r");
    if (file == NULL){
        std::cerr<< "File not open"<< std::endl;
        return;
    }
    while(1){
        char lineHeader[1000];
        int res = std::fscanf(file, "%s", lineHeader);
        if(res == EOF){
            break;
        }
        if(std::strcmp(lineHeader, "v") == 0){
            glm::vec3 vertex;
            std::fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
            if(vertex.y > m_center.y){
                m_center = vertex;
            }
            m_vert.push_back(vertex);
        }
        else if(std::strcmp(lineHeader, "vn") == 0){
            glm::vec3 normal;
            std::fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
            normals.push_back(normal);
        }
        else if(std::strcmp(lineHeader, "f") == 0){
            unsigned int vert1, vert2, vert3;
            unsigned int norm1, norm2, norm3;
            int matches = std::fscanf(file, "%d//%d %d//%d %d//%d\n", &vert1, &norm1, &vert2, &norm2, &vert3, &norm3);

            vertexIndices.push_back(vert1);
            vertexIndices.push_back(vert2);
            vertexIndices.push_back(vert3);

            normalIndices.push_back(norm1);
            normalIndices.push_back(norm2);
            normalIndices.push_back(norm3);

        }
        else {
            char commentBuffer[1000];
            std::fgets(commentBuffer, 1000, file);
        }
    }
    int normalIndexCount = 0;
    for(unsigned int i=0; i<vertexIndices.size(); i++){
        unsigned int normalIndex = normalIndices[normalIndexCount];
        glm::vec3 normal = normals[normalIndex-1];
        unsigned int vertexIndex = vertexIndices[i];
        glm::vec3 vertex = m_vert[vertexIndex-1];
        m_vertices.push_back(vertex.x);
        m_vertices.push_back(vertex.y);
        m_vertices.push_back(vertex.z);

        m_vertices.push_back(normal.x);
        m_vertices.push_back(normal.y);
        m_vertices.push_back(normal.z);
        normalIndexCount++;

        float y = m_vert[vertexIndex].y/3.f;
        float w0 = glm::max(glm::min(-y+1, 1.f), 0.f);
        float w1 = glm::max(glm::min(y, -y+2.f), 0.f);
        float w2 = glm::max(glm::min(y-1.f, -y+3.f), 0.f);
        float w3 = glm::max(glm::min(y-2.f, 1.f), 0.f);
        m_vertices.push_back(w0);
        m_vertices.push_back(w1);
        m_vertices.push_back(w2);
        m_vertices.push_back(w3);
    }
    std::fclose(file);
}

void jellyfish::initializeShape(){

    readOBJ("/Users/senademir/Desktop/Jellyfish/DV-C/DV-C/Jellyfish/esen.obj");
    readMaterial("/Users/senademir/Desktop/Jellyfish/DV-C/DV-C/Jellyfish/esen.mtl");
}

glm::vec3 jellyfish::getCenter(){
    return m_center;
}

void jellyfish::readMaterial(const char *path){
    FILE *file = std::fopen(path, "r");
    if (file == NULL){
        std::cerr<< "File not open"<< std::endl;
        return;
    }
    while(1){
        char lineHeader[1000];
        int res = std::fscanf(file, "%s", lineHeader);
        if(res == EOF){
            break;
        }
        if(std::strcmp(lineHeader, "Ka") == 0){
            glm::vec3 ambient;
            std::fscanf(file, "%f %f %f\n", &ambient.x, &ambient.y, &ambient.z);
            m_ambient = ambient;
        }
        else if(std::strcmp(lineHeader, "Kd") == 0){
            glm::vec3 diffuse;
            std::fscanf(file, "%f %f %f\n", &diffuse.x, &diffuse.y, &diffuse.z);
            m_diffuse = diffuse;
        }
        else if(std::strcmp(lineHeader, "Ks") == 0){
            glm::vec3 specular;
            std::fscanf(file, "%f %f %f\n", &specular.x, &specular.y, &specular.z);
            m_specular = specular;
        }
        else {
            char commentBuffer[1000];
            std::fgets(commentBuffer, 1000, file);
        }
    }
    std::fclose(file);
}
