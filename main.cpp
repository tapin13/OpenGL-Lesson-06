#include "GL/freeglut.h"
#include "GL/gl.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"

float WinWid = 400.0;
float WinHei = 400.0;

int Angel = 0.0;
float Scale = 1.0;
float x = 0;
float y = 0;

void Draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    Angel%=360;
    //glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    Scale = 1.0 - fabs(sin(3.14*Angel/90.0)/sqrt(3.0)/2);
    glRotatef(Angel, 0.0, 0.0, 1.0);
    glScalef(Scale, Scale, 1.0);
    glBegin(GL_LINES);
    for(float i = 0 + x; i<= WinWid + x; i+=20.0) {
        glVertex2f(i, 0 + y);
        glVertex2f(i, WinHei);
    }
    for(float i = 0 + y; i<= WinHei + y; i+=20.0) {
        glVertex2f(0 + x, i);
        glVertex2f(WinWid  + x, i);
    }
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
}

void MouseMove(int ax, int ay) {
    //glutSetWindowTitle("MouseMove");
    x = ax;
    y = ay;
}

void MouserPressed(int button, int state, int x, int y) {
    /*
    glutSetWindowTitle("MouserPressed");
    switch(button) {
        case GLUT_LEFT_BUTTON:
            glutSetWindowTitle("GLUT_LEFT_BUTTON");
            break;
        case GLUT_MIDDLE_BUTTON:
            glutSetWindowTitle("GLUT_MIDDLE_BUTTON");
            break;
        case GLUT_RIGHT_BUTTON:
            glutSetWindowTitle("GLUT_RIGHT_BUTTON");
            break;
    }
    switch(state) {
        case GLUT_UP:
            glutSetWindowTitle("GLUT_UP");
            break;
        case GLUT_DOWN:
            glutSetWindowTitle("GLUT_DOWN");
            break;
    }
    */
}

void MouserPressedMove(int ax, int ay) {
    //glutSetWindowTitle("MouserPressedMove");
}

void Timer(int value) {
    /*
    switch(value) {
        case 0:
            glColor3f(1.0, 1.0, 1.0);
            break;
        case 1:
            glColor3f(1.0, 0.0, 0.0);
            break;
    }*/
    glColor3f(1.0, 1.0, 1.0);
    //Draw();
    glutPostRedisplay();
    glutTimerFunc(50, Timer, 0);
}

void Initsialaize() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-WinWid/2, WinWid/2, -WinHei/2, WinHei/2, -200.0, 200.0);
    glOrtho(0, WinWid, WinHei, 0, -200.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(WinWid, WinHei);
    glutInitWindowPosition(100, 200);
    glutCreateWindow("Lesson 06");
    
    glutDisplayFunc(Draw);
    glutTimerFunc(50, Timer, 0);
    
    glutMotionFunc(MouserPressedMove);
    glutPassiveMotionFunc(MouseMove);
    glutMouseFunc(MouserPressed);
    
    Initsialaize();
    glutMainLoop();
    
    return 0;
}

