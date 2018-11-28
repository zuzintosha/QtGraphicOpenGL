#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include <QGLWidget>

class Widget : public QGLWidget
{
public:
    Widget(QWidget *parent = nullptr);

protected:
   void initializeGL();
   void resizeGL(int nWidth, int nHeight);
   void paintGL();
};

#endif // WIDGET_H
