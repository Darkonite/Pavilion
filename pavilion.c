#include "glos.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <glaux.h>
#include <math.h>

void myinit(void);
void CALLBACK display(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);
void CALLBACK MutaStanga(void);
void CALLBACK MutaDreapta(void);
void CALLBACK MutaSus(void);
void CALLBACK MutaJos(void);
//void CALLBACK rot_z_down(void);
//void CALLBACK rot_z_up(void);
void MatriceUmbra(GLfloat puncte[3][3], GLfloat pozSursa[4],
    GLfloat mat[4][4]);
void calcCoeficientiPlan(float P[3][3], float coef[4]);
void plan(void);
static int yRot = 0; 
static int xRot = 0; 
static GLfloat pozSursa[] = { 25.0, 25.0, 25.0, 1.0 };
static GLfloat x1 = -85, y = 0; int z1;

void CALLBACK MutaStanga(void) { x1 = x1 - 10; }
void CALLBACK MutaDreapta(void) { x1= x1 + 10; }
void CALLBACK MutaSus(void) { y = y + 10; }
void CALLBACK MutaJos(void) { y = y - 10; }
//void CALLBACK rot_z_up(void) { z = z + 10; }
//void CALLBACK rot_z_down(void) { z = z - 10; }
 
void FoisorIncolor()
{
   GLfloat more_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
    //partea de jos a foisorului
    glPushMatrix();
    GLUquadricObj* jos = gluNewQuadric();
    glTranslatef(0, 0, 0);
   // glColor3f(0.6, 0.3, 0);
    gluQuadricDrawStyle(jos, GLU_FILL);
    gluDisk(jos, 0, 11.5, 6, 6);
    glPopMatrix();
    //partea de sus a foisorului
    glPushMatrix();
    GLUquadricObj* sus = gluNewQuadric();
    glTranslatef(0, 0, 2.5);
   //glColor3f(0.6, 0.3, 0);
    gluQuadricDrawStyle(sus, GLU_FILL);
    gluDisk(sus, 0, 11.5, 6, 6);
    glPopMatrix();
    //lateralele 
    GLUquadricObj* laterale = gluNewQuadric();
    glPushMatrix();
    glTranslatef(0, 0, 0);
  //  glColor3f(0.6, 0.3, 0);
    gluQuadricDrawStyle(laterale, GLU_FILL);
    gluCylinder(laterale, 11.5, 11.5, 2.5, 6, 6);
    glPopMatrix();
    // picior 1
    GLUquadricObj* picior1 = gluNewQuadric();
    glPushMatrix();
    glTranslatef(-9, 4.5, 2.5);
   // glColor3f(0.7, 0.2, 0);
    gluQuadricDrawStyle(picior1, GLU_FILL);
    gluCylinder(picior1, 1, 1, 15, 4, 4);
    glPopMatrix();
    //picior 2
    GLUquadricObj* picior2 = gluNewQuadric();
    glPushMatrix();
    glTranslatef(-9, -4.5, 2.5);
   // glColor3f(0.7, 0.2, 0);
    gluQuadricDrawStyle(picior2, GLU_FILL);
    gluCylinder(picior2, 1, 1, 15, 4, 4);
    glPopMatrix();
    //picior3
    GLUquadricObj* picior3 = gluNewQuadric();
    glPushMatrix();
    glTranslatef(9, 4.5, 2.5);
   // glColor3f(0.7, 0.2, 0);
    gluQuadricDrawStyle(picior3, GLU_FILL);
    gluCylinder(picior3, 1, 1, 15, 4, 4);
    glPopMatrix();
    //picior4
    GLUquadricObj* picior4 = gluNewQuadric();
    glPushMatrix();
    glTranslatef(9, -4.5, 2.5);
   // glColor3f(0.7, 0.2, 0);
    gluQuadricDrawStyle(picior4, GLU_FILL);
    gluCylinder(picior4, 1, 1, 15, 4, 4);
    glPopMatrix();
    //picior5
    GLUquadricObj* picior5 = gluNewQuadric();
    glPushMatrix();
    glTranslatef(0, 10.5, 2.5);
  //  glColor3f(0.7, 0.2, 0);
    gluQuadricDrawStyle(picior5, GLU_FILL);
    gluCylinder(picior5, 1, 1, 15, 4, 4);
    glPopMatrix();
    //picior6
    GLUquadricObj* picior6 = gluNewQuadric();
    glPushMatrix();
    glTranslatef(0, -10.5, 2.5);
   // glColor3f(0.7, 0.2, 0);
    gluQuadricDrawStyle(picior6, GLU_FILL);
    gluCylinder(picior6, 1, 1, 15, 4, 4);
    glPopMatrix();
    //acoperis
    glMaterialfv(GL_FRONT, GL_AMBIENT, more_ambient);
    GLUquadricObj* acoperis = gluNewQuadric();
    glPushMatrix();
    glTranslatef(0, 0, 17.5);
   // glColor3f(0.7, 0.2, 0);
    gluQuadricDrawStyle(acoperis, GLU_FILL);
    gluCylinder(acoperis, 13, 0, 7.5, 6, 6);
    glPopMatrix();
    // sfera aia din mijloc
    glPushMatrix();
    glTranslatef(0, 0, 16.5);
    auxSolidSphere(1.0);
    glPopMatrix();
}
void FoisorColor()
{
    GLfloat more_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
    //rotatii
    glRotatef(x1, 1, 0, 0);
    // glRotatef(y, 0, 1, 0);
    glRotatef(z1, 0, 0, 1);
    //partea de jos a foisorului
    glPushMatrix();
    GLUquadricObj* jos = gluNewQuadric();
    glTranslatef(0, 0, 0);
    glColor3f(0.6, 0.3, 0);
    gluQuadricDrawStyle(jos, GLU_FILL);
    gluDisk(jos, 0, 11.5, 6, 6);
    glPopMatrix();
    //partea de sus a foisorului
    glPushMatrix();
    GLUquadricObj* sus = gluNewQuadric();
    glTranslatef(0, 0, 2.5);
    glColor3f(0.6, 0.3, 0);
    gluQuadricDrawStyle(sus, GLU_FILL);
    gluDisk(sus, 0, 11.5, 6, 6);
    glPopMatrix();
    //lateralele 
    GLUquadricObj* laterale = gluNewQuadric();
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glColor3f(0.6, 0.3, 0);
    gluQuadricDrawStyle(laterale, GLU_FILL);
    gluCylinder(laterale, 11.5, 11.5, 2.5, 6, 6);
    glPopMatrix();
    // picior 1
    GLUquadricObj* picior1 = gluNewQuadric();
    glPushMatrix();
    glTranslatef(-9, 4.5, 2.5);
    glColor3f(0.7, 0.2, 0);
    gluQuadricDrawStyle(picior1, GLU_FILL);
    gluCylinder(picior1, 1, 1, 15, 4, 4);
    glPopMatrix();
    //picior 2
    GLUquadricObj* picior2 = gluNewQuadric();
    glPushMatrix();
    glTranslatef(-9, -4.5, 2.5);
    glColor3f(0.7, 0.2, 0);
    gluQuadricDrawStyle(picior2, GLU_FILL);
    gluCylinder(picior2, 1, 1, 15, 4, 4);
    glPopMatrix();
    //picior3
    GLUquadricObj* picior3 = gluNewQuadric();
    glPushMatrix();
    glTranslatef(9, 4.5, 2.5);
    glColor3f(0.7, 0.2, 0);
    gluQuadricDrawStyle(picior3, GLU_FILL);
    gluCylinder(picior3, 1, 1, 15, 4, 4);
    glPopMatrix();
    //picior4
    GLUquadricObj* picior4 = gluNewQuadric();
    glPushMatrix();
    glTranslatef(9, -4.5, 2.5);
    glColor3f(0.7, 0.2, 0);
    gluQuadricDrawStyle(picior4, GLU_FILL);
    gluCylinder(picior4, 1, 1, 15, 4, 4);
    glPopMatrix();
    //picior5
    GLUquadricObj* picior5 = gluNewQuadric();
    glPushMatrix();
    glTranslatef(0, 10.5, 2.5);
    glColor3f(0.7, 0.2, 0);
    gluQuadricDrawStyle(picior5, GLU_FILL);
    gluCylinder(picior5, 1, 1, 15, 4, 4);
    glPopMatrix();
    //picior6
    GLUquadricObj* picior6 = gluNewQuadric();
    glPushMatrix();
    glTranslatef(0, -10.5, 2.5);
    glColor3f(0.7, 0.2, 0);
    gluQuadricDrawStyle(picior6, GLU_FILL);
    gluCylinder(picior6, 1, 1, 15, 4, 4);
    glPopMatrix();
    //acoperis
    glMaterialfv(GL_FRONT, GL_AMBIENT, more_ambient);
    GLUquadricObj* acoperis = gluNewQuadric();
    glPushMatrix();
    glTranslatef(0, 0, 17.5);
    glColor3f(0.7, 0.2, 0);
    gluQuadricDrawStyle(acoperis, GLU_FILL);
    gluCylinder(acoperis, 13, 0, 7.5, 6, 6);
    glPopMatrix();
    // sfera aia din mijloc
    GLfloat mat_ambient_color[] = { 0.2, 0.2, 0.2, 0.5 };
    GLfloat mat_diffuse[] = { 0.1, 0.1, 0.1, 0.5 };
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat no_shininess[] = { 0.0 };
    GLfloat mat_emission[] = { 0.3, 0.2, 0.2, 0.0 };

    glPushMatrix();
    // glTranslatef(3.75, -0.0, 0.0);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
    glTranslatef(0, 0, 16.5);
    auxSolidSphere(1.0);
    glPopMatrix();
}
void MatriceUmbra(GLfloat puncte[3][3], GLfloat pozSursa[4], GLfloat mat[4][4])
{
    GLfloat coefPlan[4];
    GLfloat temp;
    //determinã coeficienþii planului
    calcCoeficientiPlan(puncte, coefPlan);
    //determinã si pe D
    coefPlan[3] = -(
        (coefPlan[0] * puncte[2][0]) +
        (coefPlan[1] * puncte[2][1]) +
        (coefPlan[2] * puncte[2][2]));
    //temp=A*xL+B*yL+C*zL+D*w
    temp = coefPlan[0] * pozSursa[0] +
        coefPlan[1] * pozSursa[1] +
        coefPlan[2] * pozSursa[2] +
        coefPlan[3] * pozSursa[3];
    //prima coloanã
    mat[0][0] = temp - pozSursa[0] * coefPlan[0];
    mat[1][0] = 0.0f - pozSursa[0] * coefPlan[1];
    mat[2][0] = 0.0f - pozSursa[0] * coefPlan[2];
    mat[3][0] = 0.0f - pozSursa[0] * coefPlan[3];
    //a doua coloana
    mat[0][1] = 0.0f - pozSursa[1] * coefPlan[0];
    mat[1][1] = temp - pozSursa[1] * coefPlan[1];
    mat[2][1] = 0.0f - pozSursa[1] * coefPlan[2];
    mat[3][1] = 0.0f - pozSursa[1] * coefPlan[3];
    //a treia coloana
    mat[0][2] = 0.0f - pozSursa[2] * coefPlan[0];
    mat[1][2] = 0.0f - pozSursa[2] * coefPlan[1];
    mat[2][2] = temp - pozSursa[2] * coefPlan[2];
    mat[3][2] = 0.0f - pozSursa[2] * coefPlan[3];
    //a patra coloana
    mat[0][3] = 0.0f - pozSursa[3] * coefPlan[0];
    mat[1][3] = 0.0f - pozSursa[3] * coefPlan[1];
    mat[2][3] = 0.0f - pozSursa[3] * coefPlan[2];
    mat[3][3] = temp - pozSursa[3] * coefPlan[3];
}
void plan(void)
{
    glBegin(GL_QUADS);
    glVertex3f(-60.0f, -60.0f, 0.0f);
    glVertex3f(-60.0f, 60.0f, 0.0f);
    glVertex3f(60.0f, 60.0f, 0.0f);
    glVertex3f(60.0f, -60.0f, 0.0f);
    glEnd();
}
void calcCoeficientiPlan(float P[3][3], float coef[4])
{
    float v1[3], v2[3];
    float length;
    static const int x = 0;
    static const int y = 1;
    static const int z = 2;
    //calculeazã doi vectori din trei puncte
    v1[x] = P[0][x] - P[1][x];
    v1[y] = P[0][y] - P[1][y];
    v1[z] = P[0][z] - P[1][z];

    v2[x] = P[1][x] - P[2][x];
    v2[y] = P[1][y] - P[2][y];
    v2[z] = P[1][z] - P[2][z];

    //se cacluleazã produsul vectorial al celor doi vectori
    // care reprezintã un al treilea vector perpendicular pe plan 
    // ale cãrui componente sunt chiar coeficienþii A, B, C din ecuaþia planului
    coef[x] = v1[y] * v2[z] - v1[z] * v2[y];
    coef[y] = v1[z] * v2[x] - v1[x] * v2[z];
    coef[z] = v1[x] * v2[y] - v1[y] * v2[x];
    //normalizeazã vectorul
    length = (float)sqrt((coef[x] * coef[x]) + (coef[y] * coef[y]) + (coef[z] * coef[z]));
    coef[x] /= length;
    coef[y] /= length;
    coef[z] /= length;
}
void CALLBACK IdleAnimation(void)
{
    z1 += 1;
    z1 %= 360;
    display();
    Sleep(1);
}
void myinit(void) {
    GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat position[] = { 0.0, 0.0,16.5, 0.0 };
    GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
    GLfloat local_view[] = { 0.0 };
    glClearColor(0.0, 1.0, 1.0, 1.0);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}
void CALLBACK display (void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    FoisorColor();
    GLfloat matUmbra[4][4];
    GLfloat puncte[3][3] = { {-60.0f, -60.0f, 0.1f},
                            {60.0f, 60.0f, 0.1f},
                            {-60.0f, 60.0f, 0.1f} };	
    MatriceUmbra(puncte, pozSursa, matUmbra); 
    glPushMatrix();
    glLightfv(GL_LIGHT0, GL_POSITION, pozSursa);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0, 1.0, 0.0);
  
    FoisorIncolor();
    glPopMatrix(); 
    glPushAttrib(GL_LIGHTING_BIT);
    glDisable(GL_LIGHTING);
    glPushMatrix();
    glMultMatrixf((GLfloat*)matUmbra);
   
    glColor3f(0.4, 0.4, 0.4);
    FoisorIncolor();
    glPopMatrix(); 

    glPushMatrix();
    glTranslatef(pozSursa[0], pozSursa[1], pozSursa[2]);
    glColor3f(1.0, 1.0, 0.0);
    auxSolidSphere(2);
    glPopMatrix();

    glColor3f(1.0f, 0.3f, 0.3f);
    plan();

    glPopAttrib();
   
  glFlush();
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;			
    glViewport(0, 0, w, h);	
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (-30.0, 30.0, -10.0, 
        30.0, -50.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    auxInitDisplayMode(AUX_SINGLE | AUX_DEPTH16 | AUX_RGB);
    auxInitPosition (0, 0, 600, 400);
    auxInitWindow ("FOISOR");
    myinit ();
    //auxKeyFunc(AUX_LEFT, MutaJos);
    //auxKeyFunc(AUX_RIGHT, MutaSus);
    auxKeyFunc(AUX_DOWN, MutaDreapta);
    auxKeyFunc(AUX_UP, MutaStanga);
    auxIdleFunc(IdleAnimation);
    
    //auxMouseFunc(AUX_LEFTBUTTON, AUX_MOUSEDOWN, rot_z_up);
    //auxMouseFunc(AUX_RIGHTBUTTON, AUX_MOUSEDOWN, rot_z_down);

    auxReshapeFunc (myReshape);
    auxMainLoop(display);
    return(0);
}
