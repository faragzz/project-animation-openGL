#include<cmath>
#include<GL/freeglut.h>


float step=0;
float move = 0.025;
float edit_turn = 0.001;
float addx = 0;
float addy = 0;
float turn = 0;

using std::pair;
pair<float, float> rotate(float x,float y,float turn) {

    float x2 = (x + 8) * cos(turn) - (y - 8) * sin(turn) - 8;
    float y2 = (x + 8) * sin(turn) + (y - 8) * cos(turn) + 8;

    return { x2,y2 };
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glLineWidth(5);

    // ground
    glColor3f(49.0 / 255, 159.0 / 255, 9.0 / 255);
    glBegin(GL_POLYGON);
    glVertex2d(-12, -2);
    glVertex2d(12, -2);

    glVertex2d(-12, -2);
    glVertex2d(-12, -10);

    glVertex2d(12, -2);
    glVertex2d(12, -10);

    glVertex2d(-12, -10);
    glVertex2d(12, -10);
    glEnd();
    

    //home roof
    glColor3f(192.0/255, 49.0/255, 88.0/255);
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);
    glVertex2d(2,-5);

    glVertex2d(0, 0);
    glVertex2d(-2, -5);

    glVertex2d(-2, -5);
    glVertex2d(2, -5);
    glEnd();

    //home body
    glColor3f(233.0 / 255, 155.0 / 255, 65.0 / 255);
    glBegin(GL_POLYGON); //left side
    glVertex2d(-2, -5);
    glVertex2d(-2,-9);

    glVertex2d(2, -5);
    glVertex2d(2, -9);

    glVertex2d(2, -9);
    glVertex2d(-2, -9);
    glEnd();

    //door
    glColor3f(144.0/255, 77.0/255, 35.0/255);
    glBegin(GL_POLYGON); 
    glVertex2f(0.5, -6);
    glVertex2f(0.5, -9);

    glVertex2f(-0.5, -6);
    glVertex2f(-0.5, -9); 

    glVertex2f(-0.5, -6);
    glVertex2f(0.5, -6);

    glVertex2f(-0.5, -9);
    glVertex2f(0.5, -9);
    glEnd();

    //handle

    glColor3f(68.0 / 255, 47.0 / 255, 16.0 / 255);
    glBegin(GL_POLYGON);
    for (int j = 0; j<= 360; j++) {
        double angles = j * 3.14 / 180;
        glVertex2f((0.1 * cos(angles))+0.3, (0.2 * sin(angles)) -7.5);
    }
    glEnd();

    //chimney
    glColor3f(117.0 / 255, 79.0 / 255, 23.0 / 255);
    glBegin(GL_POLYGON);
    glVertex2f(0.8, 0);
    glVertex2f(1.5, 0);

    glVertex2f(1.5, 0);
    glVertex2f(1.5, -3.8);

    glVertex2f(0.8,0);
    glVertex2f(0.8,-2);

    glVertex2f(0.8, -2);
    glVertex2f(1.5, -3.8);
    glEnd();

    // sun
    glColor3f(240.0 / 255, 148.0 / 255, 11.0 / 255);
    glBegin(GL_POLYGON);
    for (int i = 0; i<=360;i++) {
        double angle = i*3.14/180;
        glVertex2f((3*cos(angle))-8,(5*sin(angle))+8);
    }
    glEnd();

  /*  addx = addx * cos(turn) - addy * sin(turn);
    addy = addx * sin(turn) + addy * cos(turn);*/

        //sun rays1
        glColor3f(240.0 / 255, 148.0 / 255, 11.0 / 255);
        glBegin(GL_LINES);
        auto [x, y] = rotate(-5, 6,turn);
        glVertex2f(x, y);
        auto [x2, y2] = rotate(-3, 4, turn);
        glVertex2f(x2, y2);


        glEnd();
        //sun rays2
        glColor3f(240.0 / 255, 148.0 / 255, 11.0 / 255);
        glBegin(GL_LINES);
        auto [x3, y3] = rotate(-7, 3, turn);
        glVertex2f(x3, y3);
        auto [x4, y4] = rotate(-6.5, 0, turn);
        glVertex2f(x4 , y4);

        //sun rays3 up
        glColor3f(240.0 / 255, 148.0 / 255, 11.0 / 255);
        glBegin(GL_LINES);
        auto [x5, y5] = rotate(-5, 9, turn);
        glVertex2f(x5, y5);
        auto [x6, y6] = rotate(-3, 9, turn);
        glVertex2f(x6, y6);

        //sun rays4 up
        glColor3f(240.0 / 255, 148.0 / 255, 11.0 / 255);
        glBegin(GL_LINES);
        auto [x7, y7] = rotate(-9, 3, turn);
        glVertex2f(x7, y7);
        auto [x8, y8] = rotate(-9.5, 0, turn);
        glVertex2f(x8, y8);
        glEnd();
   
    //cloud
 
        glColor3f(195.0 / 255, 201.0 / 255, 193.0 / 193);
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 360; i++) {
            double angle = i * 3.14 / 180;
            glVertex2f((1 * cos(angle)) - 8 + step, (2 * sin(angle)) + 7);
        }
        glColor3f(195.0 / 255, 201.0 / 255, 193.0 / 193);
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 360; i++) {
            double angle = i * 3.14 / 180;
            glVertex2f((1 * cos(angle)) - 7 + step, (2 * sin(angle)) + 7.5);
        }
        glColor3f(195.0 / 255, 201.0 / 255, 193.0 / 193);
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 360; i++) {
            double angle = i * 3.14 / 180;
            glVertex2f((1 * cos(angle)) - 7 + step, (2 * sin(angle)) + 6.5);
        }
        glColor3f(195.0 / 255, 201.0 / 255, 193.0 / 193);
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 360; i++) {
            double angle = i * 3.14 / 180;
            glVertex2f((1 * cos(angle)) - 6 + step, (2 * sin(angle)) + 7);
        }
    glEnd();
    glFlush();
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
    step += move;
    if (step>14 ||  step<0) {
        move = -move;
    }
    turn += edit_turn;
    if (turn > 0.25 || turn < 0) {
        edit_turn = - edit_turn;
    }
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200, 0);
    glutInitWindowSize(1200, 800);

    glutCreateWindow("Ahmed Khaled Farag 20109481");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);

   glClearColor(102.0/255, 102.0/255, 1.0, 1.0);

    glutMainLoop();
}