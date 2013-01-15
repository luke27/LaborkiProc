#ifndef __LSHADER_H_
#define __LSHADER_H_

#include "headers.h"
#include <fstream>
using namespace std;
/*!
 * Klasa odpowiedzialna za odczyt, kompilacje i obs³ugê shadera
 */
class LShader
{
public:
	/*!
	 * Konstruktor wczytuje shader z pliku
	 * @param file œciê¿ka pliku ze shaderem
	 * @param type typ shadera (GL_VERTEX_SHADER, GL_FRAGMENT_SHADER);
	 */
	LShader(const char *file, GLenum type);
	/*!
	 * Konstruktor wczytuj¹cy Vertex Shader i Fragment/Pixel Shader z pliku
	 * @param vertexFile plik z Vertex Shader
	 * @param fragmentFile plik z Fragment Shader
	 */
	LShader(const char *vertexFile, const char *fragmentFile);
	/*!
	 * Konstruktor wczytuj¹cy Vertex Shader, Fragment Shader i Geometry Shader
	 * @param vertexFile plik z Vertex Shader
	 * @param fragmentFile plik z Fragment Shader
	 * @param geometryFile plik z Geometry Shader
	 */
	LShader(const char *vertexFile, const char *fragmentFile, const char *geometryFile);
	/*!
	 * Zwraca program
	 */
	GLuint getProgram();
	/*!
	 * W³¹cza shader
	 */
	void use();
	/*!
	 * Wy³¹cza shader
	 */
	void useOff();
	/*!
	 * destruktor usuwa shadery
	 */
	~LShader();
private:
	/*!
	 * identyfikator shadera
	 */
	GLuint shader;
	/*!
	 * typ shadera
	 */
	GLenum type;
	/*!
	 * obiekt programu
	 */
	GLuint program;
	/*!
	 * œcie¿ka pliku
	 */
	const char *shaderFile;
	/*!
	 * Metoda odpowiedzialna za wczytanie shadera z pliku
	 */
	void loadShader();
	/*!
	 * Metoda odpowidzialna za powi¹zanie obiektu shadera z programem
	 */
	inline void attachProgram();
	/*!
	 * Metoda odpowiedzialna za linkowanie i walidacjê shaderów
	 */
	inline void linkProgram();
	/*!
	 * Metoda pobieraj¹ca komunikat o b³êdzie obs³ugi shaderów przez OpenGL
	 * @param text tekt b³êdu
	 * @kod b³êdu z jakim ma siê zakoñczyæ program
	 */
	inline void getError(const char *text, int code);
};



#endif