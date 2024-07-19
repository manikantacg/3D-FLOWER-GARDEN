Butterfly Class:

#ifndef BUTTERFLY_H_INCLUDED
#define BUTTERFLY_H_INCLUDED
#include&lt;windows.h&gt;
#include &lt;iostream&gt;
#include &lt;cstdlib&gt;
#include&lt;cmath&gt;
#include&lt;ctime&gt;
#include &lt;GL/glut.h&gt;
using namespace std;
int FLYING=1;
int SITTING=0;
int DEBUG=1;
float butterfly_body_angle=90;
float angle_wing=2.0f;
float angle_wing_change=2.0f;
GLUquadricObj *quadratic;
int FLOATS =7;
float RAND[7]={-0.05,0.05,-0.05,0.05,-0.05,0.05,0};
float unit=.1f;
int windpaused=0;
class Wind{
public:
float x,y,z;
float speed,max_speed,change;

float threshold;
Wind();
};
Wind::Wind()
{
x=1.0;
y=0.0;
z=0.0;
speed=0.0;
max_speed=1;
change=0.05;
threshold=1.0;
}
Flower Class:
class flower
{
public:
Color petal_color;
Color stalk_color;
int petals;
float petal_radius;
float growth;
int stalk_size;
float stalk_angle;
float x_axis_stalk;
float y_axis_stalk;
float z_axis_stalk;
float x,y,z;
int hasButterfly;
butterfly *b;
flower();

};

//constructor body
butterfly::butterfly(int status)
{
//random variables;
//srand(time(0));
quadratic=gluNewQuadric();
this-&gt;status=status;
this-&gt;baseRadius=0.01*(2+rand()%2);
this-&gt;topRadius=this-&gt;baseRadius;
this-&gt;height=0.1*(2+rand()%2);
this-&gt;slices=15+rand()%15;
this-&gt;stacks=15+rand()%15;
//creating
if(status==FLYING)
{
this-&gt;curx=RAND[rand()%FLOATS]*(rand()%200);
this-&gt;cury=-2+0.01*(rand()%200);
this-&gt;curz=RAND[rand()%FLOATS]*(rand()%200);
this-&gt;destx=this-&gt;curx;
this-&gt;desty=this-&gt;cury;
this-&gt;destz=this-&gt;curz+1;
this-&gt;xaxis=0.01*(rand()%100);
this-&gt;yaxis=0.01*(rand()%100);
this-&gt;zaxis=0.01*(rand()%100);
}
Code of Main Program:
#include&lt;windows.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;stdio.h&gt;

#include &lt;iostream&gt;
#include &lt;cstdlib&gt;
#include &quot;butterfly.h&quot;
//#include &quot;flower.h&quot;
#include&lt;ctime&gt;
#include &lt;GL/glut.h&gt;
using namespace std;
#define MAX_BUTTERFLY 15;
float eyex=0.0,eyey=0.0,eyez=0.0,centerx=0.0,centery=0.0,centerz=-
3.0,upx=0.0,upy=1.0,upz=0.0;
butterfly *butterflies[500];
flower *flowers[1000];
int butterfly_count=0;
int flower_count=0;
int paused=0;
//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y)
{ switch (key) {
case 27: //Escape key
exit(0)
case 66:
case 98:
if(butterfly_count&lt;500)
{
srand(time(0)+butterfly_count*(rand()%20000));

//cout&lt;&lt;&quot;Drawing butterfly &quot;&lt;&lt;butterfly_count&lt;&lt;endl;
butterflies[butterfly_count]=new butterfly(FLYING);
butterfly_count++;
}
break;

float thta=5;
void specialKeyPressed(int key, int x, int y)
{
switch (key) {
case GLUT_KEY_DOWN:
//cout&lt;&lt;&quot;down pressed&quot;&lt;&lt;endl;
eyez+=0.2;
centerz+=0.2;
break;
case GLUT_KEY_UP:
eyez-=0.2;
centerz-=0.2;
break;
case GLUT_KEY_RIGHT:
eyex+=3*sinf(thta*3.1416/180);
eyez+=3*cosf(thta*3.1416/180)-3;
//eyex+=0.2;
//centerx+=0.2;
break;
case GLUT_KEY_LEFT:

eyex-=0.2;
centerx-=0.2;
break;
/*
eyey=centery-sqrt((centerx-eyex)*(centerx-eyex)+(centery-

eyey)*(centery-eyey)-(centerx-eyex+0.2)*(centerx-
eyex+0.2)); eyex-=0.2;
*/
break;
case GLUT_KEY_PAGE_DOWN:
eyey-=0.2;
centery-=0.2;
break;
case GLUT_KEY_PAGE_UP:
eyey+=0.2;
centery+=0.2;
break;
}
}
//Initializes 3D rendering
void initRendering() {
glEnable(GL_DEPTH_TEST);
glEnable(GL_COLOR_MATERIAL);
glEnable(GL_LIGHTING); //Enable lighting
glEnable(GL_LIGHT0); //Enable light #0


glEnable(GL_LIGHT1); //Enable light #1
glEnable(GL_NORMALIZE); //Automatically normalize normals
//glShadeModel(GL_SMOOTH); //Enable smooth shading
}
//Called when the window is resized
void handleResize(int w, int h) {
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}
void drawGarden()
{
float x,y,z;
z=-gardepth/2;
x=-garwidth/2;
glPushMatrix();
glTranslatef(0,garbase,z);
glRotatef(_cameraAngle,0.0,1.0,0.0);
glRotatef(-90,1.0,0.0,0.0);
glColor3f(1.0,0.2,0.2);
for(x=0;x&lt;garwidth;x+=1)
{
glTranslatef(1,0.0,0.0);
gluCylinder(quadratic,0.05,0.05,3.0,2,2);


/*glLineWidth(10);
glBegin(GL_LINE);
glVertex3f(0.0,0.0,0.0);
glVertex3f(0.0,2.0,0.0);
glEnd();
}
glPopMatrix();
glBegin(GL_QUADS);
glVertex3f(-0.7f, -0.5f, 0.0f);
glVertex3f(0.7f, -0.5f, 0.0f);
glVertex3f(0.4f, 0.5f, 0.0f);
glVertex3f(-0.4f, 0.5f, 0.0f);
glEnd();
glBegin(GL_TRIANGLES);
//Pentagon
glVertex3f(-0.5f, -0.5f, 0.0f);
glVertex3f(0.5f, -0.5f, 0.0f);
glVertex3f(-0.5f, 0.0f, 0.0f);
glVertex3f(-0.5f, 0.0f, 0.0f);
glVertex3f(0.5f, -0.5f, 0.0f);
glVertex3f(0.5f, 0.0f, 0.0f);
glVertex3f(-0.5f, 0.0f, 0.0f);
glVertex3f(0.5f, 0.0f, 0.0f);
glVertex3f(0.0f, 0.5f, 0.0f);
glEnd();


int main(int argc, char** argv) {
//Initialize GLUT
glutInit(&amp;argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(1400, 960);
quadratic=gluNewQuadric();
//butterflies[0]=new butterfly(0.1f,0.1f,1.0f,32,32);
//Create the window
glutCreateWindow(&quot;A Garden By Manu&quot;);
initRendering();
glutDisplayFunc(drawScene);
glutKeyboardFunc(handleKeypress);
glutSpecialFunc(specialKeyPressed);
glutReshapeFunc(handleResize);
glutTimerFunc(2000, update, 0); //Add a timer
if(butterfly_count)
glutTimerFunc(300/butterfly_count,update_butterfly_position,0);
glutMainLoop();
return 0;
}
