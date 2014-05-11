
#include"character.h"
#include"squater.h"
#include"bullet.h"
#include"player.h"
#include"platform.h"
#include"pewpew.h"

#include<iostream>
#include<iomanip>
#include<sstream>
using namespace std;
#include<vector>
#ifdef MACOSX
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>





#include "sound.h"

int WIDTH = 1000;
int HEIGHT = 500;
char programName[] = "Jumpy Jumpy Shoot Shoot";
int level, playerright, playerleft, greenball, squatterleft, squatterright, groundtexture, bullet, pewpew, pewpewflip, titleimg, level2, redball, rock, spikes;
int a = 0, w = 0, d = 0, s = 0, space = 0;
FMOD::Sound *Jump_Sound, *Music;
double startTime;
int counter = 0;
int score = 0; 
int screen = 5;
int screencheck = 0;
char start[] = "Start";
char score2[] = "Score: ";

char lose[] = "YOU ARE DEAD MY FRIEND!!!!";


char info[] = "Instructions";
char story[] = "Story";
char credits[] = "Credits";
char Return[] = "Return to Menu";
bool buttonIsPressed = false; 
Player test {playerright, 0, 430, 40, 40};
Character ground1{playerright, 0, 470, 100, 30};
Character ground2{playerright, 100, 470, 100, 30};
Character ground3{playerright, 200, 470, 100, 30};
Character ground4{playerright, 900, 470, 100, 30};
Platform testplat1{playerright, 200, 390, 100, 20};
Platform testplat2{playerright, 70, 310, 100, 20};
Platform testplat3{playerright, 200, 230, 100, 20};
Platform testplat4{playerright, 300, 150, 100, 20};
Platform testplat5{playerright, 400, 230, 100, 20};
Platform testplat6{playerright, 500, 310, 100, 20};
Platform testplat7{playerright, 600, 230, 100, 20};
Platform testplat8{playerright, 700, 310, 100, 20};
Platform testplat9{playerright, 800, 390, 100, 20};
Character ending{playerright, 950, 430, 40, 40};
Squatter testsquat1{100, 260, playerright, 130, 430, 40, 40}; 
Squatter testsquat2{400, 460, playerright, 460, 190, 40, 40};
Squatter testsquat3{600, 660, playerright, 640, 190, 40, 40};
Squatter testsquat4{70, 130, playerright, 100, 270, 40, 40};
Bullet testbullet{playerright, 0, 0, 20, 20};
Bullet pewbullet{playerright, 0, 0, 10, 10};
PewPew testpew{playerright, 830, 350, 40, 40};


Character ground5{playerright, 0, 470, 100, 30};
Character ground6{playerright, 100, 470, 100, 30};
Character ground7{playerright, 900, 470, 100, 30};
Platform testplat10{playerright, 200, 400, 100, 20};
Platform testplat11{playerright, 150, 320, 100, 20};
Platform testplat12{playerright, 50, 240, 100, 20};
Platform testplat13{playerright, 50, 160, 100, 20};
Platform testplat14{playerright, 200, 80, 100, 20};
Platform testplat15{playerright, 360, 300, 160, 20};
Platform testplat16{playerright, 440, 380, 100, 20};
Platform testplat17{playerright, 550, 300, 100, 20};
Platform testplat18{playerright, 550, 220, 105, 20};
Platform testplat19{playerright, 695, 220, 105, 20};
Platform testplat20{playerright, 850, 160, 100, 20};
Character spike1{playerright, 360, 260, 40, 40};
Character spike2{playerright, 480, 260, 40, 40};
Character spike3{playerright, 900, 430, 40, 40};
Character spike4{playerright, 655, 215, 40, 25};





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
void drawNumber(double x, double y, double num)
{
  stringstream oss;
  oss << num; oss.flush();
  drawText(x, y, oss.str().c_str());
}



void drawWindow()
{
  // clear the buffer
  glClear(GL_COLOR_BUFFER_BIT);

  // draw stuff
  if(( screen == 1) && (screencheck == 0)) {
  drawTexture(level,  0,0,    1000, 500); // texID,   x,y,    width, height

glColor3f(1., 1., 1.);
  drawBox( 50, 40,   90, 15 );

glColor3f(0., 0., 0.);


  drawNumber(110, 50, score);

        drawText(50, 50, score2);


   

  testplat1.draw();
  testplat2.draw();
  testplat3.draw();
  testplat4.draw();
  testplat5.draw();
  testplat6.draw();
  testplat7.draw();
  testplat8.draw();
  testplat9.draw();
  ending.draw();
  if ( testsquat1.getshow() == false){
    testsquat1.draw();
  }
  if ( testsquat2.getshow() == false){
    testsquat2.draw();
  }
  if ( testsquat3.getshow() == false){
    testsquat3.draw();
  }
  if ( testsquat4.getshow() == false){
    testsquat4.draw();
  }
  if ( testpew.getshow() == false){
    testpew.draw();
  }
  ground1.draw();
  ground2.draw();
  ground3.draw();
  ground4.draw();
 
  
  if ( testbullet.fired == 1){
    testbullet.draw();
  }
  test.draw();
  if ( pewbullet.fired == 1){
    pewbullet.draw();
  }
  }
  if ( screen == 5){
    drawTexture(level2,  0,0,    1000, 500); // texID,   x,y,    width, height
    ground5.draw();
    ground6.draw();
    ground7.draw();
    testplat10.draw();
    testplat11.draw();
    testplat12.draw();
    testplat13.draw();
    testplat14.draw();
    testplat15.draw();
    testplat16.draw();
    testplat17.draw();
    testplat18.draw();
    testplat19.draw();
    testplat20.draw();
    spike1.draw();
    spike2.draw();
    spike3.draw();
    spike4.draw();
    test.draw();
    if ( testbullet.fired == 1){
      testbullet.draw();
    }
  }
    if( screen == 0){
      glColor3f(0., .5, 0.);
      drawBox( 0, 0,   1000, 500 );
      glColor3f(.75, .75, .75);
      drawBox( 410, 250,  225, 40);
      glColor3f(.75, .75, .75);
      drawBox( 410, 310,  225, 40);
      glColor3f(.75, .75, .75);
      drawBox( 410, 370,  225, 40);
      glColor3f(.75, .75, .75);
      drawBox( 410, 430,  225, 40);
      
      glColor3f(1., 1., 1.);
      drawBox( 415, 255,  215, 30);
      glColor3f(1., 1., 1.);
      drawBox( 415, 315,  215, 30);
      glColor3f(1., 1., 1.);
      drawBox( 415, 375,  215, 30);
      glColor3f(1., 1., 1.);
      drawBox( 415, 435,  215, 30);

      glColor3f(.0, .0, .0);
      drawText(500, 275, start);
      glColor3f(.0, .0, .0);
      drawText(470, 335, info);
      glColor3f(.0, .0, .0);
      drawText(500, 395, story);
      glColor3f(.0, .0, .0);
      drawText(490, 455, credits);
      drawTexture(titleimg, 400, 50, 220, 150);
      screencheck = 0;
      }
      if ((screen == 2) && (screencheck == 0)) {
      glColor3f(0., .5, 0.);
      drawBox( 0, 0,   1000, 500 );
      glColor3f(.75, .75, .75);
      drawBox( 770, 415, 180, 50);
      glColor3f(1, 1, 1);
      drawBox( 775, 420, 170, 40);
      glColor3f(.0, .0, .0);
      drawText(800, 445, Return);
      screencheck = 0;  }
      if ((screen == 3) && (screencheck == 0)) {
      glColor3f(0., .5, 0.);
      drawBox( 0, 0,   1000, 500 );
      glColor3f(.75, .75, .75);
      drawBox( 770, 415, 180, 50);
      glColor3f(1, 1, 1);
      drawBox( 775, 420, 170, 40);
      glColor3f(.0, .0, .0);
      drawText(800, 445, Return); }
      if ((screen == 4) && (screencheck == 0)) {
      glColor3f(0., .5, 0.);
      drawBox( 0, 0,   1000, 500 );
      glColor3f(.75, .75, .75);
      drawBox( 770, 415, 180, 50);
      glColor3f(1, 1, 1);
      drawBox( 775, 420, 170, 40);
      glColor3f(.0, .0, .0);
      drawText(800, 445, Return); }
  // tell the graphics card that we're done-- go ahead and draw!
  //   (technically, we are switching between two color buffers...)
  glutSwapBuffers();
}

bool onButton(int mousex, int mousey, int x, int y, int w, int h)
{
  return mousex >= x  && mousey >= y &&
         mousex <= x + w &&
         mousey <= y + h;
}

void mouse(int mouseButton, int state, int mousex, int mousey)
{
  if ( GLUT_LEFT_BUTTON == mouseButton ) {
    if ( GLUT_DOWN == state ) {
      // the user just pressed down on the mouse-- do something
      if ( onButton(mousex,mousey, 415,255,215,30) ) {buttonIsPressed = true;
	screen = 1; 
	if (USE_SOUND) playSound(Music, 1); }
      if ( onButton(mousex,mousey, 415,315,215,30) ) {buttonIsPressed = true;
	screen = 2; }
      if ( onButton(mousex,mousey, 415,375,215,30) ) {buttonIsPressed = true;
	screen = 3; }
      if ( onButton(mousex,mousey, 775, 420, 170, 40) ) {buttonIsPressed = true;
	screen = 0; }
      if ( onButton(mousex,mousey, 415,435,215,30) ) {buttonIsPressed = true;
	screen = 4; }
      else buttonIsPressed = false; }
      else {
      // the user just let go the mouse-- do something
      buttonIsPressed = false;
    }
  } else if ( GLUT_RIGHT_BUTTON == mouseButton ) {
  }
  glutPostRedisplay();
}

void keyboard( unsigned char c, int x, int y )
{
  int win = glutGetWindow();
  switch(c) {
  case 'a': a = 1;
    break;
  case 'd': d = 1;
    break;
  case 'w': w = 1;
    break;
  case 's': s = 1;
    break;
  case ' ': space = 1;
    break;
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
  case 's': s = 0;
    break;
  case ' ': space = 0;
    break;
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

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   WIDTH = w;  HEIGHT = h;
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0., WIDTH-1, HEIGHT-1, 0., -1.0, 1.0);
}

double getCurrentTime()
{
  struct timeval tv = {0,0};
  struct timezone tz;
  gettimeofday(&tv, &tz);
  // cout << "tv is " << tv.tv_sec << " micro " << tv.tv_usec << endl;
  return tv.tv_sec + tv.tv_usec/(double)1000000.;
}

void resetlevel()
{
  test.updatexposition(0);
  test.updateyposition(430);
  testbullet.fired = 0;
  testsquat1.updateshow(false);
  testsquat2.updateshow(false);
  testsquat3.updateshow(false);
  testsquat4.updateshow(false);
  testpew.updateshow(false);
  testbullet.updatexposition(0);
  testbullet.updateyposition(0);
  pewbullet.fired = 0;
  screen = 1;
}

void idle()
{
  // figure out whether it is time to change the counter.
  //   we want the counter to change once per second, so we want the
  //   elapsed time (since the beginning of the program) to be 
  //   the same as the elapsedTime (rounded down)
  double elapsedTime = getCurrentTime() - startTime;
  elapsedTime = elapsedTime*20;
 if (test.getdirection() == false){
  test.updatetextureID(playerright);
  }
  if (test.getdirection() == true){
    test.updatetextureID(playerleft);
  }
  if ( screen == 1 ){
  if (testsquat1.getdirection() == true){
    testsquat1.updatetextureID(squatterright);
      }
  if(testsquat1.getdirection() == false){
    testsquat1.updatetextureID(squatterleft);
  }
  if (testsquat2.getdirection() == true){
    testsquat2.updatetextureID(squatterright);
      }
  if(testsquat2.getdirection() == false){
    testsquat2.updatetextureID(squatterleft);
  }
  if (testsquat3.getdirection() == true){
    testsquat3.updatetextureID(squatterright);
      }
  if(testsquat3.getdirection() == false){
    testsquat3.updatetextureID(squatterleft);
  }
  if (testsquat4.getdirection() == true){
    testsquat4.updatetextureID(squatterright);
      }
  if(testsquat4.getdirection() == false){
    testsquat4.updatetextureID(squatterleft);
  }
  testpew.checkPlayerPos(test.getxposition());
  if(testpew.getdirection() == false){
      testpew.updatetextureID(pewpewflip);
  }
  if(testpew.getdirection() == true){
      testpew.updatetextureID(pewpew);
  }
  }
  if ( (int)elapsedTime > counter ) {
    // ok, enough time has passed that we should increase the counter
    test.velocity = test.velocity - 1;
    if ( screen == 1){
    if ( ground1.checkcolide(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
      test.onGround = 0;
      test.velocity = 0;
      test.updateyposition(ground1.getyposition() - test.height);
    }
  if ( ground2.checkcolide(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
      test.onGround = 0;
      test.velocity = 0;
      test.updateyposition(ground2.getyposition() - test.height);
    }
  if ( ground3.checkcolide(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
      test.onGround = 0;
      test.velocity = 0;
      test.updateyposition(ground3.getyposition() - test.height);
    }
  if ( ground4.checkcolide(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
      test.onGround = 0;
      test.velocity = 0;
      test.updateyposition(ground4.getyposition() - test.height);
    }
    if ( s == 0 ){
        if ( testplat1.checktouch(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
	  test.onGround = 0;
	  test.velocity = 0;
	  test.updateyposition(testplat1.getyposition() - test.getheight());
	}
        if ( testplat2.checktouch(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
	  test.onGround = 0;
	  test.velocity = 0;
	  test.updateyposition(testplat2.getyposition() - test.getheight());
	}
        if ( testplat3.checktouch(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
	  test.onGround = 0;
	  test.velocity = 0;
	  test.updateyposition(testplat3.getyposition() - test.getheight());
	}
        if ( testplat4.checktouch(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
	  test.onGround = 0;
	  test.velocity = 0;
	  test.updateyposition(testplat4.getyposition() - test.getheight());
	}
        if ( testplat5.checktouch(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
	  test.onGround = 0;
	  test.velocity = 0;
	  test.updateyposition(testplat5.getyposition() - test.getheight());
	}
        if ( testplat6.checktouch(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
	  test.onGround = 0;
	  test.velocity = 0;
	  test.updateyposition(testplat6.getyposition() - test.getheight());
	}
        if ( testplat7.checktouch(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
	  test.onGround = 0;
	  test.velocity = 0;
	  test.updateyposition(testplat7.getyposition() - test.getheight());
	}
        if ( testplat8.checktouch(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
	  test.onGround = 0;
	  test.velocity = 0;
	  test.updateyposition(testplat8.getyposition() - test.getheight());
	}
        if ( testplat9.checktouch(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
	  test.onGround = 0;
	  test.velocity = 0;
	  test.updateyposition(testplat9.getyposition() - test.getheight());
	}
    }
    }
    if ( w == 1 && test.onGround == 0){
      test.onGround = 1;
      test.velocity = test.velocity + 12;
      if (USE_SOUND) playSound(Jump_Sound, 1);
    }
    if ( a == 1){
      test.updatedirection(true);
      test.xposition = test.xposition - 4;
    }
    if ( d == 1){
      test.updatedirection(false);
      test.xposition = test.xposition + 4;
    }
    if ( space == 1){
      if ( testbullet.fired == 0 ){
	testbullet.updatexposition(test.getxposition());
	testbullet.updateyposition(test.getyposition());
	testbullet.updatedirection(test.getdirection());
	testbullet.fired = 1;
      }
    }
    if ( testbullet.fired == 1){
      testbullet.move();
      if (testbullet.checkInMap(WIDTH) == false){
	testbullet.fired = 0;
      }
    }
    if( testpew.getshow() == 0 ){
      if ( pewbullet.fired == 0 ){
	pewbullet.updatexposition(testpew.getxposition());
	pewbullet.updateyposition(testpew.getyposition());
	pewbullet.updatedirection(testpew.getdirection());
	pewbullet.fired = 1;
      }
    }
    if ( pewbullet.fired == 1){
      pewbullet.move();
      if (pewbullet.checkInMap(WIDTH) == false){
	pewbullet.fired = 0;
      }
    }
    test.updateyposition(test.getyposition() - test.velocity);
    if ( screen == 1 ){
    testsquat1.move();
    testsquat2.move();
    testsquat3.move();
    testsquat4.move();
    if ( testsquat1.getshow() == false){
    if ( testsquat1.checkcolide(testbullet.getxposition(), testbullet.getyposition(), testbullet.getwidth(), testbullet.getheight()) == 1){
      testsquat1.updateshow(true);
      testbullet.fired = 0;
      score+=5; 

    
    }
    }
    if ( testsquat2.getshow() == false){
    if ( testsquat2.checkcolide(testbullet.getxposition(), testbullet.getyposition(), testbullet.getwidth(), testbullet.getheight()) == 1){
      testsquat2.updateshow(true);
      testbullet.fired = 0;
            score+=5; 

    }
    }
    if ( testsquat3.getshow() == false){
    if ( testsquat3.checkcolide(testbullet.getxposition(), testbullet.getyposition(), testbullet.getwidth(), testbullet.getheight()) == 1){
      testsquat3.updateshow(true);
      testbullet.fired = 0;
            score+=5; 

    }
    }
    if ( testsquat4.getshow() == false){
    if ( testsquat4.checkcolide(testbullet.getxposition(), testbullet.getyposition(), testbullet.getwidth(), testbullet.getheight()) == 1){
      testsquat4.updateshow(true);
      testbullet.fired = 0;
            score+=5; 

    }
    }
    if ( testpew.getshow() == false){
    if ( testpew.checkcolide(testbullet.getxposition(), testbullet.getyposition(), testbullet.getwidth(), testbullet.getheight()) == 1){
      testpew.updateshow(true);
      testbullet.fired = 0;
            score+=5; 

    }
    }
    if ( testsquat1.getshow() == false){
    if ( testsquat1.checkcolide(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
      drawText(50, 50, lose);

      cout << "You lose" << endl;
      score =0; 
      resetlevel();
    }
    }
    if ( testsquat2.getshow() == false){
    if ( testsquat2.checkcolide(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
      cout << "You lose" << endl;
            drawText(50, 50, lose);

            score =0; 

      resetlevel();
    }
    }
    if ( testsquat3.getshow() == false){
    if ( testsquat3.checkcolide(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
      cout << "You lose" << endl;
            drawText(50, 50, lose);

            score =0; 

      resetlevel();
    }
    }
    if ( testsquat4.getshow() == false){
    if ( testsquat4.checkcolide(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
      cout << "You lose" << endl;
            drawText(50, 50, lose);

            score =0; 

      resetlevel();
    }
    }
    if ( testpew.getshow() == false){
    if ( testpew.checkcolide(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
      cout << "You lose" << endl;
            drawText(50, 50, lose);

            score =0; 

      resetlevel();
    }
    }
    if ( pewbullet.getshow() == false){
    if ( test.checkcolide(pewbullet.getxposition(), pewbullet.getyposition(), pewbullet.getwidth(), pewbullet.getheight()) == 1){
      cout << "You lose" << endl;
            drawText(50, 50, lose);

            score =0; 

      resetlevel();
    }
    }
    if ( ending.checkcolide(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
      cout << "You Win!" << endl;
      screen = 5;
      test.updatexposition(0);
      test.updateyposition(430);
    }
    if ( test.getyposition() > 500 ){
      cout << "You fell to your doom" << endl;
            score =0; 

      resetlevel();
    }
    }

    
    if ( screen == 5 ){
      
      if ( s == 0 ){
       if ( testplat10.checktouch(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
	  test.onGround = 0;
	  test.velocity = 0;
	  test.updateyposition(testplat10.getyposition() - test.getheight());
	}

       if ( testplat11.checktouch(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
	  test.onGround = 0;
	  test.velocity = 0;
	  test.updateyposition(testplat11.getyposition() - test.getheight());
	}

       if ( testplat12.checktouch(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
	  test.onGround = 0;
	  test.velocity = 0;
	  test.updateyposition(testplat12.getyposition() - test.getheight());
	}

       if ( testplat13.checktouch(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
	  test.onGround = 0;
	  test.velocity = 0;
	  test.updateyposition(testplat13.getyposition() - test.getheight());
	}

       if ( testplat14.checktouch(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
	  test.onGround = 0;
	  test.velocity = 0;
	  test.updateyposition(testplat14.getyposition() - test.getheight());
	}

       if ( testplat15.checktouch(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
	  test.onGround = 0;
	  test.velocity = 0;
	  test.updateyposition(testplat15.getyposition() - test.getheight());
	}

       if ( testplat16.checktouch(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
	  test.onGround = 0;
	  test.velocity = 0;
	  test.updateyposition(testplat16.getyposition() - test.getheight());
	}
       
       if ( testplat17.checktouch(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
	  test.onGround = 0;
	  test.velocity = 0;
	  test.updateyposition(testplat17.getyposition() - test.getheight());
	}

       if ( testplat18.checktouch(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
	  test.onGround = 0;
	  test.velocity = 0;
	  test.updateyposition(testplat18.getyposition() - test.getheight());
	}

       if ( testplat19.checktouch(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
	  test.onGround = 0;
	  test.velocity = 0;
	  test.updateyposition(testplat19.getyposition() - test.getheight());
	}

       if ( testplat20.checktouch(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
	  test.onGround = 0;
	  test.velocity = 0;
	  test.updateyposition(testplat20.getyposition() - test.getheight());
	}
      }

      if ( ground5.checkcolide(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
	test.onGround = 0;
	test.velocity = 0;
	test.updateyposition(ground5.getyposition() - test.height);
      }

      if ( ground6.checkcolide(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
	test.onGround = 0;
	test.velocity = 0;
	test.updateyposition(ground6.getyposition() - test.height);
      }

      if ( ground7.checkcolide(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
	test.onGround = 0;
	test.velocity = 0;
	test.updateyposition(ground7.getyposition() - test.height);
      }

      if ( spike1.checkcolide(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
      cout << "You lose" << endl;
            score =0; 

      resetlevel();
      }
      
      if ( spike2.checkcolide(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
      cout << "You lose" << endl;
            score =0; 

      resetlevel();
      }

      if ( spike3.checkcolide(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
      cout << "You lose" << endl;
            score =0; 

      resetlevel();
      }

      if ( spike4.checkcolide(test.getxposition(), test.getyposition(), test.getwidth(), test.getheight()) == 1){
      cout << "You lose" << endl;
            score =0; 

      resetlevel();
      }

      if ( test.getyposition() > 500 ){
	cout << "You fell to your doom" << endl;
        score =0; 

	resetlevel();
      }
    }

  counter++;
    glutPostRedisplay();
}
}


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

  greenball = loadTexture("Green_ball.pam");
  playerright = loadTexture("playeright.pam");
  playerleft = loadTexture("playerleft.pam");
  level = loadTexture("BackGround.pam");
  squatterleft = loadTexture("squatterLeft.pam");
  squatterright = loadTexture("squatterRight.pam");
  groundtexture = loadTexture("Platform.pam");
  bullet = loadTexture("85.pam");
  pewpew = loadTexture("peashooterflip.pam");
  pewpewflip = loadTexture("peashooter.pam");
  titleimg = loadTexture("title.pam");
  level2 = loadTexture("volcano.pam");
  redball = loadTexture("redball.pam");
  rock = loadTexture("rock.pam");
  spikes = loadTexture("spikes.pam");
  testplat1.updatetextureID(groundtexture);
  testplat2.updatetextureID(groundtexture);
  testplat3.updatetextureID(groundtexture);
  testplat4.updatetextureID(groundtexture);
  testplat5.updatetextureID(groundtexture);
  testplat6.updatetextureID(groundtexture);
  testplat7.updatetextureID(groundtexture);
  testplat8.updatetextureID(groundtexture);
  testplat9.updatetextureID(groundtexture);
  ground1.updatetextureID(groundtexture);
  ground2.updatetextureID(groundtexture);
  ground3.updatetextureID(groundtexture);
  ground4.updatetextureID(groundtexture);
  ending.updatetextureID(greenball);
  testbullet.updatetextureID(bullet);
  pewbullet.updatetextureID(greenball);

  ground5.updatetextureID(rock);
  ground6.updatetextureID(rock);
  ground7.updatetextureID(rock);
  testplat10.updatetextureID(rock);
  testplat11.updatetextureID(rock);
  testplat12.updatetextureID(rock);
  testplat13.updatetextureID(rock);
  testplat14.updatetextureID(rock);
  testplat15.updatetextureID(rock);
  testplat16.updatetextureID(rock);
  testplat17.updatetextureID(rock);
  testplat18.updatetextureID(rock);
  testplat19.updatetextureID(rock);
  testplat20.updatetextureID(rock);
  spike1.updatetextureID(spikes);
  spike2.updatetextureID(spikes);
  spike3.updatetextureID(spikes);
  spike4.updatetextureID(spikes);


  

  glutMouseFunc(mouse);
  glutDisplayFunc(drawWindow);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutKeyboardUpFunc(keyboardUp);
  glutIdleFunc(idle);
  glutMainLoop();
}

int main()
{ init_sound_system();
  Jump_Sound = loadSoundFile("Jump_Sound.wav");
  Music = loadSoundFile("music.wav");
  startTime = getCurrentTime();
  init_gl_window();
}
