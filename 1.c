#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>
#define pi 3.142857
float a = 200;

// function to initialize
void myInit(void) {
    // making background color black as first
    // 3 arguments all are 0.0
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // making picture color green (in RGB mode), as middle argument is 1.0
    glColor3f(0.0, 0.0, 0.0);

    // breadth of picture boundary is 1 pixel
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // setting window dimension in X- and Y- direction
    gluOrtho2D(-300, 1100, -20, 880);
}

void drawTriangle() {
        glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0,500);
        glVertex2f(700,500);
        glVertex2f(350,800);
        glEnd();
}

void drawRect() {
        glBegin(GL_POLYGON);
        glColor3f(0.0, 1.0, 1.0);
        glVertex2f(0,0);
        glVertex2f(700,0);
        glVertex2f(700,500);
        glVertex2f(0,500);
        glEnd();
}

void drawDoor() {
        glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(300,0);
        glVertex2f(400,0);
        glVertex2f(400, 300);
        glVertex2f(300,300);
        glEnd();
}

void drawWindow1() {
        glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(100,200);
        glVertex2f(200,200);
        glVertex2f(200, 300);
        glVertex2f(100,300);
        glEnd();
}

void drawWindow2() {
        glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(500,200);
        glVertex2f(600,200);
        glVertex2f(600, 300);
        glVertex2f(500,300);
        glEnd();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    drawTriangle();
    drawRect();
    drawDoor();
    drawWindow1();
    drawWindow2();
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // giving window size in X- and Y- direction
    glutInitWindowSize(1366, 768);
    glutInitWindowPosition(0, 0);

    // Giving name to window
    glutCreateWindow("House Drawing");
    myInit();

    glutDisplayFunc(display);
    glutMainLoop();
}