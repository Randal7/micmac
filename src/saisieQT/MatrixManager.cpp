#include "MatrixManager.h"

MatrixManager::MatrixManager()
{
    _mvMatrix   = new GLdouble[16];
    _projMatrix = new GLdouble[16];
    _glViewport = new GLint[4];

    m_glPosition[0] = m_glPosition[1] = 0.f;
}

MatrixManager::~MatrixManager()
{
    delete [] _mvMatrix;
    delete [] _projMatrix;
    delete [] _glViewport;
}

void MatrixManager::doProjection(QPointF point, float zoom)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glPushMatrix();
    glMultMatrixd(_projMatrix);

    if(_projMatrix[0] != zoom)
    {
        GLint recal;
        GLdouble wx, wy, wz;

        recal = _glViewport[3] - (GLint) point.y() - 1.f;

        gluUnProject ((GLdouble) point.x(), (GLdouble) recal, 1.f,
                      _mvMatrix, _projMatrix, _glViewport, &wx, &wy, &wz);

        glTranslatef(wx,wy,0);
        glScalef(zoom/_projMatrix[0], zoom/_projMatrix[0], 1.f);
        glTranslatef(-wx,-wy,0);
    }

    glTranslatef(m_glPosition[0],m_glPosition[1],0.f);

    m_glPosition[0] = m_glPosition[1] = 0.f;

    glGetDoublev (GL_PROJECTION_MATRIX, _projMatrix);
}

void MatrixManager::orthoProjection()
{
    mglOrtho(0,_glViewport[2],_glViewport[3],0,-1,1);
}

void MatrixManager::scaleAndTranslate(float x, float y, float zoom)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glPushMatrix();
    glScalef(zoom, zoom, 1.f);
    glTranslatef(x,y,0.f);
    glGetDoublev (GL_PROJECTION_MATRIX, _projMatrix);
    glPopMatrix();

    m_glPosition[0] = m_glPosition[1] = 0.f;
}

void MatrixManager::setMatrices()
{
    glMatrixMode(GL_MODELVIEW);
    glGetDoublev(GL_MODELVIEW_MATRIX, _mvMatrix);

    glMatrixMode(GL_PROJECTION);
    glGetDoublev(GL_PROJECTION_MATRIX, _projMatrix);

    glGetIntegerv(GL_VIEWPORT, _glViewport);
}

void MatrixManager::importMatrices(selectInfos &infos)
{
    for (int aK=0; aK<4; ++aK)
        _glViewport[aK] = infos.glViewport[aK];
    for (int aK=0; aK<16; ++aK)
    {
        _mvMatrix[aK] = infos.mvmatrix[aK];
        _projMatrix[aK] = infos.projmatrix[aK];
    }
}

void MatrixManager::exportMatrices(selectInfos &infos)
{
    for (int aK=0; aK<4; ++aK)
        infos.glViewport[aK] = _glViewport[aK];
    for (int aK=0; aK<16; ++aK)
    {
        infos.mvmatrix[aK]   = _mvMatrix[aK];
        infos.projmatrix[aK] = _projMatrix[aK];
    }
}

void MatrixManager::getProjection(QPointF &P2D, Pt3dr P)
{
    GLdouble xp,yp,zp;
    gluProject(P.x,P.y,P.z,_mvMatrix,_projMatrix,_glViewport,&xp,&yp,&zp);
    P2D = QPointF(xp,yp);
}

QPointF MatrixManager::WindowToImage(QPointF const &pt, float zoom)
{
    QPointF res( pt.x()         - .5f*_glViewport[2]*(1.f + _projMatrix[12]),
                -pt.y()  -1.f   + .5f*_glViewport[3]*(1.f - _projMatrix[13]));

    res /= zoom;

    return res;
}

QPointF MatrixManager::ImageToWindow(QPointF const &im, float zoom)
{
    return QPointF (im.x()*zoom + .5f*_glViewport[2]*(1.f + _projMatrix[12]),
            - 1.f - im.y()*zoom + .5f*_glViewport[3]*(1.f - _projMatrix[13]));
}

cPolygon MatrixManager::PolygonImageToWindow(cPolygon polygon, float zoom)
{
    cPolygon poly = polygon;
    poly.clearPoints();
    for (int aK = 0;aK < polygon.size(); ++aK)
        poly.add(ImageToWindow(polygon[aK],zoom));

    return poly;
}

void MatrixManager::mglOrtho( GLdouble left, GLdouble right,
               GLdouble bottom, GLdouble top,
               GLdouble near_val, GLdouble far_val )
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(left, right, bottom, top, near_val, far_val);
}
