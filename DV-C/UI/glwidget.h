#ifndef GLWIDGET_H
#define GLWIDGET_H

#define GLM_FORCE_RADIANS

#include "GL/glew.h"
#include <QGLWidget>
#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Jellyfish/jellyfish.h"
#include <QTimer>


class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    GLWidget(QGLFormat format, QWidget *parent = nullptr);
    ~GLWidget();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void initializeGlew();
    GLuint createShaderProgram(const char *vertFilePath, const char *fragFilePath);
    GLuint createShader(GLenum shaderType, const char *filepath);
    void setCameraMatrices();

    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void wheelEvent(QWheelEvent *e);

protected slots:
    void tick();

private:
    GLuint m_program;
    glm::mat4x4 m_model;
    glm::mat4x4 m_view;
    glm::mat4x4 m_projection;
    std::unique_ptr<jellyfish> m_jelly;

    float m_angleX, m_angleY, m_angleZ;
    QPoint m_prevMPos;

    QTimer m_timer;
    float m_fps;
    float m_tick;
    float m_angle;
    int m_increment;

};

#endif // GLWIDGET_H
