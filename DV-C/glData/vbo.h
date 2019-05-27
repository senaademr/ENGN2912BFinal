#ifndef VBO_H
#define VBO_H

#include "GL/glew.h"

class VBO
{
public:
    VBO(const float *data, int size);
    VBO(const VBO&) = delete;
    VBO& operator=(const VBO&) = delete;
    VBO(VBO &&that);
    VBO& operator=(VBO &&);
    ~VBO();

    void bindAndEnable() const;
    int numberOfVertices() const;
    int sizeOfFloats() const;

    void unbind() const;
private:
    void bind() const;
    GLuint m_handle;
    int m_size;
};

#endif // VBO_H
