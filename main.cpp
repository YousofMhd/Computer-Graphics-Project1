#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

void display();
void reshape(int w,int h);
void timer(int);

void init(){
    glClearColor(0.6,0.4,0.0,0.0);
}
using ld = long double;
constexpr ld PI = 3.1415926535897932384626433832L;

int main (int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200,0);
    glutInitWindowSize(1200,800);

    glutCreateWindow("20103360");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    init();

    glutMainLoop();
}

void arc(ld r, ld theta, ld phi, ld px = 0, ld py = 0){
    glLineWidth(5.0);
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);


    int len = 20;
    ld dt = (phi - theta) / len;
    for(int i = 0; i <= len; i++){
        glVertex2d(px + r * cosl(i * dt + theta), py + r * sinl(i * dt + theta));
    }

    glEnd();
}
float step=0;

void display()
{
    //color of the shape
    glColor3f(0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    //Top of the House (Triangle)
    glLineWidth(5.0);
    glColor3f(0.7,0.2,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-5.5,9);
    glVertex2f(-2,6);
    glVertex2f(-9,6);
    glEnd();

    //Bottom of the House(Rectangle)
    glBegin(GL_POLYGON);
    glLineWidth(5.0);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(-9,6);
    glVertex2f(-2,6);
    glVertex2f(-2,-1);
    glVertex2f(-9,-1);
    glEnd();

    //Door of the House
    glBegin(GL_POLYGON);
    glLineWidth(5.0);
    glColor3f(0.7,0.2,0.0);
    glVertex2f(-3,4);
    glVertex2f(-3,-1);
    glVertex2f(-5,-1);
    glVertex2f(-5,4);
    glEnd();

    //Bottom window of the House
    glBegin(GL_POLYGON);
    glLineWidth(5.0);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(-7,5);
    glVertex2f(-7,3);
    glVertex2f(-8,3);
    glVertex2f(-8,5);
    glEnd();

    //Cow
    arc(2,0.0,2*3.14, 6, -5);
    arc(1,0.0,2*3.14, 3.7, -3.2);
    arc(0.1,0.0,2*3.14, 3.2, -3);
    arc(0.1,0.0,2*3.14, 3.6, -3);

    //left leg
    glBegin(GL_POLYGON);
    glLineWidth(5.0);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(4.7+step,-6.6);
    glVertex2f(4.7+step,-9);
    glVertex2f(4.9+step,-9);
    glVertex2f(4.9+step,-6.6);
    glEnd();

    //right leg
    glBegin(GL_POLYGON);
    glLineWidth(5.0);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(7.2+step,-6.6);
    glVertex2f(7.2+step,-9);
    glVertex2f(7.4+step,-9);
    glVertex2f(7.4+step,-6.6);
    glEnd();

    //human
    arc(0.8,0.0,2*3.14, -5, -1.8);
    //neak
    glBegin(GL_POLYGON);
    glLineWidth(5.0);
    glColor3f(0.0,1.0,0.6);
    glVertex2f(-4.8,-2.5);
    glVertex2f(-4.8,-3);
    glVertex2f(-5.2,-3);
    glVertex2f(-5.2,-2.5);
    glEnd();

    //right hand
    glBegin(GL_POLYGON);
    glLineWidth(5.0);
    glColor3f(0.0,1.0,0.6);
    glVertex2f(-4+step,-3);
    glVertex2f(-2+step,-5);
    glVertex2f(-2.2+step,-5.2);
    glVertex2f(-4+step,-3.4);
    glEnd();

    //right hand
    glBegin(GL_POLYGON);
    glLineWidth(5.0);
    glColor3f(0.0,1.0,0.6);
    glVertex2f(-6+step,-3);
    glVertex2f(-8+step,-5);
    glVertex2f(-7.8+step,-5.2);
    glVertex2f(-6+step,-3.4);
    glEnd();

    //top
    glBegin(GL_POLYGON);
    glLineWidth(5.0);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(-6,-3);
    glVertex2f(-4,-3);
    glVertex2f(-4,-5);
    glVertex2f(-6,-5);
    glEnd();

    //
    glBegin(GL_POLYGON);
    glLineWidth(5.0);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(-4,-5);
    glVertex2f(-4,-6);
    glVertex2f(-6,-6);
    glVertex2f(-6,-5);
    glEnd();
    //bottom
    glBegin(GL_POLYGON);
    glLineWidth(5.0);
    glColor3f(0.0,1.0,1.0);
    glVertex2f(-4,-6);
    glVertex2f(-4,-9);
    glVertex2f(-4.2,-9);
    glVertex2f(-5,-7.3);
    glVertex2f(-5.8,-9);
    glVertex2f(-6,-9);
    glVertex2f(-6,-6);
    glEnd();

    //car
    //body
    glBegin(GL_POLYGON);
    glLineWidth(5.0);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(1,3);
    glVertex2f(1,5);
    glVertex2f(9,5);
    glVertex2f(9,3);
    glEnd();

    //top
    glBegin(GL_POLYGON);
    glLineWidth(5.0);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(3,5);
    glVertex2f(4,6.5);
    glVertex2f(7,6.5);
    glVertex2f(8,5);
    glEnd();
    //right
    arc(0.8,0.0,2*3.14, 8, 2.8);
    //left
    arc(0.8,0.0,2*3.14, 3, 2.8);


    glFlush();
}

void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
}


void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
    step+=0.2;
}
