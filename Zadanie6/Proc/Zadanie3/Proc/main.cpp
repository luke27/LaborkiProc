#include "headers.h"
#include "LRender.h"
LRender *render;

/*!
 * Okno GLUT
 */
int glutWindow;
/*!
 * funkcja inizjalizuj¹ca OpenGL
 * @param x
 * @param y
 */
void initGl(int x, int y);
/*!
 * zmiana romiaru okna
 * @param x
 * @param y
 */
void resize(int x, int y);

/*!
 * funkcja odpowiedzialna za wyœwietlenie obrazu
 */
void display();

/*!
 *obs³uga klawiatury GLUT
 */
void keyboard(unsigned char key, int x, int y);
/*!
 * Funkcja czyszcz¹ca i zamykaj¹ca program
 */
void release();
/*!
 * obs³uga klawiszy specjalnych
 */
void specialKeys(int key, int x, int y);
int buttonState = GLUT_UP; //obs³uga lewego przycisku myszy, stan
int xButton, yButton; //mysz, wpspó³rzêdne kursora
/*!
 * wykrywanie naciœniêcia przycisku myszy
 */
void mouseButton(int button, int state, int x, int y); 
/*!
 * wykrywanie ruchu myszy
 */
void mouseMotion(int x, int y);

/*!
 * main inicjalizacja okna gluta
 */
int main(int argc, char *argv[])
{
	int x = 800;
	int y = 600;
	//pytanie czy w³¹czyæ fullscreen
	int result = IDNO; //MessageBoxA(NULL, "Fullscreen?","GLSLDemo20", MB_YESNO | MB_ICONQUESTION);
	bool fullscreen = false;
	if(result == IDYES)
		fullscreen = true;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA |GLUT_DOUBLE | GLUT_DEPTH );
	glutInitWindowSize(x, y);
	glutInitWindowPosition(0, 0);
	glutWindow = glutCreateWindow("GLSLDemo32");
	glutDisplayFunc(display);
	
	if(fullscreen == true)
		glutFullScreen();
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMotion);
	glutIdleFunc(display);
	glutReshapeFunc(resize);
	initGl(x, y);
	glutMainLoop();
	glutDestroyWindow(glutWindow);


	return 0;
}

void initGl(int x, int y)
{
	OpenGL30();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	render = new LRender(x, y);
}

void resize(int x, int y)
{
  /*if (x == 0)                                
    x = 1;
 
  glViewport(0, 0, x, y);                
 
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
 
  gluPerspective(45.0f,(GLfloat)x/(GLfloat)y,0.1f,100.0f);
  glOrtho( - 2.0, 2.0, - 2.0, 2.0, - 2.0, 2.0 );
  glMatrixMode(GL_MODELVIEW);*/
	render->resize();
}

void display()
{
	glutSetWindow(glutWindow);
	//glClearColor( 1.0, 1.0, 1.0, 1.0 );
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glLoadIdentity();
	//glTranslatef(0.0f, 0.0f, 100.0f);
	
	render->draw();

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		//Ecape wyjœcie z programu
	case 27:
		release();
		break;
	case 'p':
	case 'P':
		render->scaleDown();
		break;
	case 'o':
	case 'O':
		render->scaleUp();
		break;
	case 'n':
	case 'N':
		render->neutralize();
		break;
	case 'm':
	case 'M':
		render->changeState();
		break;
	}
}

void release()
{
	delete render;
	exit(0);
}

void specialKeys(int key, int x, int y)
{
	switch(key)
	{
	case GLUT_KEY_LEFT:
		render->translateLeft();
		break;
	case GLUT_KEY_RIGHT:
		render->translateRight();
		break;
	case GLUT_KEY_UP:
		render->translateUp();
		break;
	case GLUT_KEY_DOWN:
		render->translateDown();
		break;
	case GLUT_KEY_F2:
		break;
	}
}

void mouseButton(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON)
	{
		buttonState = state;
		if(state == GLUT_DOWN)
		{
			xButton = x;
			yButton = y;
		}
	}
}

void mouseMotion(int x, int y)
{
	if(buttonState == GLUT_DOWN)
	{
		/*GLdouble model[16];
		render->getMAtrix(GL_MODELVIEW_MATRIX, model);

		GLdouble proj[16];
		render->getMAtrix(GL_PROJECTION_MATRIX, proj);
		GLint view[4];
		glGetIntegerv(GL_VIEWPORT, view);

		GLdouble prev[3], curr[3];

		gluUnProject(xButton, yButton, 0.0, model, proj, view, prev, prev + 1, prev + 2);
		gluUnProject( x, y, 0.0, model, proj, view, curr + 0, curr + 1, curr + 2 );
		GLfloat xTranslate;
		GLfloat yTranslate;
		render->getRotatexy(&xTranslate, &yTranslate);
		xTranslate += (curr[0] - prev[0]) * 10;
		yTranslate += (prev[1] - curr[1]) * 10;*/

		GLfloat xTranslate;
		GLfloat yTranslate;
		render->getRotatexy(&xTranslate, &yTranslate);
		xTranslate +=  (float)x / 100.0f;
		yTranslate += (float)y / 100.0f;

		render->setRotation(xTranslate, yTranslate);

		xButton = x;
		yButton = y;
	
		glutPostRedisplay();
	}
}