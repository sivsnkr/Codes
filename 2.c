#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>
#define pi 3.142857
float a = 50;

// function to initialize
void myInit(void) {
    // making background color black as first
    // 3 arguments all are 0.0
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // making picture color green (in RGB mode), as middle argument is 1.0
    glColor3f(0.0, 1.0, 0.0);

    // breadth of picture boundary is 1 pixel
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // setting window dimension in X- and Y- direction
    gluOrtho2D(-500, 900, -200, 700);
}


void wheelf() {
    float i = 0.0f;
        
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 1.0);
    float x = 100;
    float y = 0;
    float r = 50;
    glVertex2f(x, y); // Center
    for(i = 0.0f; i <= 360; i++)
            glVertex2f(r*cos(pi * i / 180.0) + x, r*sin(pi * i / 180.0) + y);
    
    glEnd();
}

void wheelb() {
    float i = 0.0f;
        
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 1.0);
    float x = 400;
    float y = 0;
    float r = 50;
    glVertex2f(x, y); // Center
    for(i = 0.0f; i <= 360; i++)
            glVertex2f(r*cos(pi * i / 180.0) + x, r*sin(pi * i / 180.0) + y);
    
    glEnd();
}

void rectangle() {
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0, 0);
    glVertex2f(500, 0);

    glVertex2f(500, 0);
    glVertex2f(500, 100);

    glVertex2f(500, 100);
    glVertex2f(0, 100);

    glVertex2f(0, 100);
    glVertex2f(0, 0);
    glEnd();
}

void ext_box() {
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(100, 100);
    glVertex2f(500, 100);

    glVertex2f(500, 100);
    glVertex2f(450, 220);
    
    glVertex2f(450, 220);
    glVertex2f(200, 220);

    glVertex2f(200, 220);
    glVertex2f(100, 100);

    glEnd();
}

void in_box1() {
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(140, 120);
    glVertex2f(300, 120);

    glVertex2f(300, 120);
    glVertex2f(300, 200);
    
    glVertex2f(300, 200);
    glVertex2f(200, 200);

    glVertex2f(200, 200);
    glVertex2f(140, 120);

    glEnd();
}

void in_box2() {
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);

    glVertex2f(320, 120);
    glVertex2f(460, 120);
    
    glVertex2f(460, 120);
    glVertex2f(430, 200);

    glVertex2f(430, 200);
    glVertex2f(320, 200);

    glVertex2f(320, 200);
    glVertex2f(320, 120);
    

    glEnd();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    rectangle();
    ext_box();
    in_box1();
    in_box2();
    wheelf();
    wheelb();
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // giving window size in X- and Y- direction
    glutInitWindowSize(1366, 768);
    glutInitWindowPosition(0, 0);

    // Giving name to window
    glutCreateWindow("Circle Drawing");
    myInit();

    glutDisplayFunc(display);
    glutMainLoop();
}
