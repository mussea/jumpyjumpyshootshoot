#include<iostream>
#include<fstream>
using namespace std;
#ifdef MACOSX
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include"texture.h"

bool mouseIsDragging = false;

int WIDTH = 490;  
int HEIGHT = 240;
char programName[] = "project-texture";
int menu, level, mario, marioflip, peashooter, peashooterflip, bullet, greenbullet;  // texture IDs

int xposition = 30;
int yposition = 174;
int v = 0;
double startTime;
int counter = 0;
int direction = 1;
int peadirection =0;
int menu1 = 0;
int f =0;
char titletest[] = "Jumpy Jumpy Shoot Shoot";
char start[] = "Start";
char info[] = "Instructions";
bool buttonIsPressed = false;
int a, w, d;

void drawBox(double x, double y, double width, double height)
{
  glBegin(GL_POLYGON);
    glVertex2f(x, y);  // upper left
    glVertex2f(x, y + height);  // lower left
    glVertex2f(x + width, y + height);  // lower right
    glVertex2f(x + width, y);  // upper right
  glEnd();
}

void drawText(double x, double y, const char *text)
{
  glRasterPos2f( x, y );
  int length = strlen(text);
  for (int i = 0; i < length; i++)
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[i]);
}

void drawWindow()
{
  // clear the buffer
  glClear(GL_COLOR_BUFFER_BIT);

  // draw stuff
  if( menu1 == 1){
  drawTexture(level,  0,0,    490, 240); // texID,   x,y,    width, height
  drawTexture(bullet, 150, 175, 20, 20);
  drawTexture(greenbullet, 190, 175, 11, 11);
  if( peadirection == 1){
    drawTexture(peashooterflip, 120,180,  30,30);
  }
  if( peadirection == 0){
    drawTexture(peashooter, 120,180,  30,30);
  }
  if ( direction == 1){
  drawTexture(mario, xposition,yposition, 24,32);
  }
  if ( direction == 0){
    drawTexture(marioflip, xposition,yposition, 24,32);
  }
  }
    if( menu1 == 0){
      glColor3f(0., .5, 0.);
      drawBox( 0, 0,   490, 240 );
      glColor3f(.75, .75, .75);
      drawBox( 123, 120,  240, 30);
      glColor3f(.75, .75, .75);
      drawBox( 123, 180,  240, 30);
      glColor3f(1., 1., 1.);
      drawBox( 127, 124,  232, 22);
      glColor3f(1., 1., 1.);
      drawBox( 127, 184,  232, 22);
      glColor3f(1., 1., 1.);
      drawText(140, 80, titletest);
      glColor3f(.0, .0, .0);
      drawText(220, 140, start);
      glColor3f(.0, .0, .0);
      drawText(190, 200, info);
      }
  // tell the graphics card that we're done-- go ahead and draw!
  //   (technically, we are switching between two color buffers...)
  glutSwapBuffers();
}

bool onButton(int x, int y)
{
  return x >= 123  && y >= 120 &&
         x <= 123 + 232 &&
         y <= 120  + 30;
}

void mouse(int mouseButton, int state, int x, int y)
{
  if ( GLUT_LEFT_BUTTON == mouseButton ) {
    if ( GLUT_DOWN == state ) {
      // the user just pressed down on the mouse-- do something
      if ( onButton(x,y) ) {buttonIsPressed = true;
	menu1 = 1;
      }
      else buttonIsPressed = false;
    } else {
      // the user just let go the mouse-- do something
      buttonIsPressed = false;
    }
  } else if ( GLUT_RIGHT_BUTTON == mouseButton ) {
  }
  glutPostRedisplay();
}

// process keyboard events
void keyboard( unsigned char c, int x, int y )
{

  int win = glutGetWindow();
  switch(c) {
  case 'a': a = 1;
    break;
  case 'd': d = 1;
    break;
  case 'w': w = sqrt(10);
    break;
  case 'b': menu1 = 1;
    break;
    case 'q':
    case 'Q':
    case 27:
      // get rid of the window (as part of shutting down)
      glutDestroyWindow(win);
      exit(0);
      break;
    default:
      break;
  }
  glutPostRedisplay();
}

void keyboardUp( unsigned char c, int x, int y )
{
 

  int win = glutGetWindow();
  switch(c) {
  case 'a': a = 0;
    break;
  case 'd': d = 0;
    break;
  case 'w': w = 0;
    break;
  case 'b': menu1 = 1;
    break;
    case 'q':
    case 'Q':
    case 27:
      // get rid of the window (as part of shutting down)
      glutDestroyWindow(win);
      exit(0);
      break;
    default:
      break;
  }
  glutPostRedisplay();
}

// the reshape function handles the case where the user changes the size
//   of the window.  We need to fix the coordinate
//   system, so that the drawing area is still the unit square.
void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   WIDTH = w;  HEIGHT = h;
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0., WIDTH-1, HEIGHT-1, 0., -1.0, 1.0);
}


// the init function sets up the graphics card to draw properly
void init(void)
{
  // clear the window to black
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // set up the coordinate system:  number of pixels along x and y
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0., WIDTH-1, HEIGHT-1, 0., -1.0, 1.0);

  // allow blending (for transparent textures)
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);

  // welcome message
  cout << "Welcome to " << programName << "." << endl;
}

double getCurrentTime()
{
  struct timeval tv = {0,0};
  struct timezone tz;
  gettimeofday(&tv, &tz);
  // cout << "tv is " << tv.tv_sec << " micro " << tv.tv_usec << endl;
  return tv.tv_sec + tv.tv_usec/(double)1000000.;
}

void idle()
{
  // figure out whether it is time to change the counter.
  //   we want the counter to change once per second, so we want the
  //   elapsed time (since the beginning of the program) to be 
  //   the same as the elapsedTime (rounded down)
  double elapsedTime = getCurrentTime() - startTime;
  elapsedTime = elapsedTime*20;
  if ( (int)elapsedTime > counter ) {
    // ok, enough time has passed that we should increase the counter
    if( w == 1) {
    if (f == 0){
      f = 1;
      v = v + 60;}}
  if( v > 30){
    yposition = yposition -3;
    v--;
    v--;
  }
  if( v <= 30 && yposition < 174){
    yposition = yposition +3;
    v--;
    v--;
  }  
  if ( xposition > 120){
    peadirection = 0;}
  if ( xposition <= 120){
      peadirection = 1;}
  if (yposition == 174){
    f = 0;}
  if( buttonIsPressed == true ){
    menu1 = 1;}
  if( a == 1){ xposition = xposition -3;
    direction = 0;}
  if( d == 1 ){ xposition = xposition + 3;
    direction = 1;}

  counter++;
    glutPostRedisplay();
}
}


// init_gl_window is the function that starts the ball rolling, in
//  terms of getting everything set up and passing control over to the
//  glut library for event handling.  It needs to tell the glut library
//  about all the essential functions:  what function to call if the
//  window changes shape, what to do to redraw, handle the keyboard,
//  etc.
void init_gl_window()
{
  char *argv[] = { programName };
  int argc = sizeof(argv) / sizeof(argv[0]);
  glutInit(&argc, argv);
  glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
  glutInitWindowSize(WIDTH,HEIGHT);
  glutInitWindowPosition(100,100);
  glutCreateWindow(programName);
  init();

  menu = loadTexture("menu.pam");
  level = loadTexture("level.pam");
  mario = loadTexture("Mario.pam");
  marioflip = loadTexture("Mario_Flip.pam");
  peashooter = loadTexture("peashooter.pam");
  peashooterflip = loadTexture("peashooterflip.pam");
  bullet = loadTexture("85.pam");
  greenbullet = loadTexture("Green_ball.pam");

  glutMouseFunc(mouse);
  glutDisplayFunc(drawWindow);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutKeyboardUpFunc(keyboardUp);
  glutIdleFunc(idle);
  glutMainLoop();
}

int main()
{
  startTime = getCurrentTime();
  init_gl_window();
}
