#ifndef VAO_H
#define VAO_H

#include <memory>
#include "GL/glew.h"

#include "vbo.h"

class VAO
{
public:
    VAO(const VBO &vbo, int vertexNumber = 0 );
    VAO(const VAO &that) = delete;
    VAO& operator=(const VAO &that) = delete;
    VAO(VAO &&that);
    VAO& operator=(VAO &&that);
    ~VAO();

    void bind();
    void draw();
    void unbind();
private:
    std::unique_ptr<VBO> m_VBO;
    GLuint m_handle;
    GLuint m_numberOfVertices;
    int m_size;
};

#endif // VAO_H
