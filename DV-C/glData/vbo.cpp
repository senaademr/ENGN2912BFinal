#include "vbo.h"

VBO::VBO(const float *data, int size):
    m_handle(-1),
    m_size(size)
{
    glGenBuffers(1, &m_handle);
    glBindBuffer(GL_ARRAY_BUFFER, m_handle);
    glBufferData(GL_ARRAY_BUFFER, m_size*sizeof(GLfloat), &data[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VBO::VBO(VBO &&that) :
    m_handle(that.m_handle),
    m_size(that.m_size)
{
    that.m_handle = 0;
}

VBO& VBO::operator=(VBO &&that) {
    this->~VBO();
    m_handle = that.m_handle;
    m_size = that.m_size;
    that.m_handle = 0;
    return *this;
}

VBO::~VBO(){
    glDeleteBuffers(1, &m_handle);
}

void VBO::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, m_handle);
}

void VBO::bindAndEnable() const {
    bind();
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 10*sizeof(GLfloat), 0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 10*sizeof(GLfloat), reinterpret_cast<GLvoid*>(3*sizeof(GLfloat)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 10*sizeof(GLfloat), reinterpret_cast<GLvoid*>(6*sizeof(GLfloat)));
}

void VBO::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

int VBO::sizeOfFloats() const {
    return m_size;
}

int VBO::numberOfVertices() const {
    return 1;
}
