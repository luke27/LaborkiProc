#ifndef __RENDER_H_
#define __RENDER_H_

#include "headers.h"
#include "LShader.h"
#include "LSolid.h"



#include "LPiramid.h"
/*!
 * Klasa odpowiedzialna za rysowanie
 */
class LRender
{
public:
	/*!
	 * Konstruktor domyśny
	 * @param x - rozdzielczość x
	 * @param y - rozdzielczość y
	 */
	LRender(int x, int y);
	/*!
	 * destruktor
	 */
	~LRender();
	/*!
	 * Metoda rysująca
	 */
	void draw();
	/*!
	 * Metoda odrywowująca
	 */
	void resize();
	/*!
	 * skalowanie, zmiejszanie
	 */
	void scaleDown();
	/*!
	 * skalowanie, zwiększanie
	 */
	void scaleUp();
	/*!
	 * przesunięcie w lewo
	 */
	void translateLeft();
	/*!
	 * przesunięcie w prawo
	 */
	void translateRight();
	/*!
	 * przesunięcie w górę
	 */
	void translateUp();
	/*!
	 * przesunięcie w dół
	 */
	void translateDown();
	/*!
	 * usunięcie wszystkich przekształceń
	 */
	void neutralize();
	/*!
	 * zwrócenie xRotate i yRotate
	 */
	void getRotatexy(GLfloat *x, GLfloat *y);
	/*!
	 * zwrócenie macierzy
	 */
	void getMAtrix(GLenum type, GLdouble tab[16]);
	/*!
	 * ustwaienie rotacji
	 * @param x rotacja względem osi x
	 * @param y rotacja względem osi y
	 */
	void setRotation(GLfloat x, GLfloat y);
	/*!
	 * zmiana wyświetlanego obiektu
	 * @param obiekt 
	 */
	void changeSolid(int obiekt);
	/*!
	 * Metoda zmieniająca stan aktualnie wyświetlanego programu
	 */
	void changeState();
private:
	//rozmiar okna
	int x;
	int y;
	/*!
	 * współczynnik skalowania
	 */
	GLfloat scale;
	/*!
	 * współczynnik obrotu x
	 */
	GLfloat xRotate;
	/*!
	 * współczynnik obrotu y
	 */
	GLfloat yRotate;
	/*!
	 * współczynnik przesunięcia x
	 */
	GLfloat xTranslate;
	/*!
	 * współczynnik przesunięcia y
	 */
	GLfloat yTranslate;
	//współrzędne figury obcinania
	GLfloat left;
	GLfloat right;
	GLfloat bottom;
	GLfloat top;
	GLfloat gnear;
	GLfloat gfar;
	/*!
	 * macierz rzutowania
	 */
	matrix4x4<> projectionMatrix;
	/*!
	 * macierz model, widok
	 */
	matrix4x4<> modelViewMatrix;
	/*!
	 * połączenie macierzy rzutowania z macierzą model, widok
	 */
	matrix4x4<> modelViewProjectionMatrix;
	/*!
	 * wskaźnik na rysowany obiekt
	 */
	LSolid *solid;
	/*!
	 * aktualny onbiekt renderowany
	 */
	int actualSolid;

};

#endif
