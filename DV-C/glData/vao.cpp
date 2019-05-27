#include "vao.h"

#include <iostream>

VAO::VAO(const VBO &vbo, int vertexNumber):
    m_handle(0),
    m_numberOfVertices(vertexNumber),
    m_size(0)
{
    glGenVertexArrays(1, &m_handle);
    bind();
    vbo.bindAndEnable();
    vbo.unbind();
    unbind();
}

VAO::VAO(VAO &&that):
    m_VBO(std::move(that.m_VBO)),
    m_numberOfVertices(that.m_numberOfVertices),
    m_size(that.m_size)
{
    that.m_handle = 0;
}

VAO& VAO::operator=(VAO &&that) {
    this->~VAO();
    m_VBO = std::move(that.m_VBO);
    m_handle = that.m_handle;
    m_numberOfVertices = that.m_numberOfVertices;
    m_size = that.m_size;
    that.m_handle = 0;
    return *this;
}

VAO::~VAO(){
    glDeleteVertexArrays(1, &m_handle);
}

void VAO::draw(){
    glDrawArrays(GL_TRIANGLES, 0, m_numberOfVertices);

}

void VAO::bind(){
    glBindVertexArray(m_handle);
}

void VAO::unbind(){
    glBindVertexArray(0);
}
