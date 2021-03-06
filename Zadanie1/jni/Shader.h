﻿/**
 *
    Copyright (C) 2012 Łukasz Durlej

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <GLES2/gl2.h>
#include <cstdlib>
#include <fstream>
using namespace std;

#include "Log.h"

namespace PG
{
	/*!
 * Klasa odpowiedzialna za odczyt, kompilacje i obsługę shadera
 */
class Shader
{
public:
	/**
	 * Konstruktor wczytanie pliku z Assetów na Andridzie
	 */

	Shader(const char *vertexFile, const char *fragmentFile, int a);

	/**
	 * Konstruktor wczytuje shader z pliku
	 * @param file ściężka pliku ze shaderem
	 * @param type typ shadera (GL_VERTEX_SHADER, GL_FRAGMENT_SHADER);
	 */
	Shader(const char *file, GLenum type);
	/**
	 * Konstruktor wczytujący Vertex Shader i Fragment/Pixel Shader z pliku
	 * @param vertexFile plik z Vertex Shader
	 * @param fragmentFile plik z Fragment Shader
	 */
	Shader(const char *vertexFile, const char *fragmentFile);
	/*!
	 * Konstruktor wczytujący Vertex Shader, Fragment Shader i Geometry Shader
	 * @param vertexFile plik z Vertex Shader
	 * @param fragmentFile plik z Fragment Shader
	 * @param geometryFile plik z Geometry Shader
	 */
	Shader(const char *vertexFile, const char *fragmentFile, const char *geometryFile);
	/*!
	 * Zwraca program
	 */
	GLuint getProgram();
	/*!
	 * Włącza shader
	 */
	void use();
	/*!
	 * Wyłącza shader
	 */
	void useOff();
	/*!
	 * destruktor usuwa shadery
	 */
	~Shader();
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
	 * ścieżka pliku
	 */
	const char *shaderFile;
	/*!
	 * Metoda odpowiedzialna za wczytanie shadera z pliku
	 */
	void loadShader();

	/*!
	 * Metoda odpowiedzialna za adowanie shadera a assetów - Android
	 */
	void loadAssetShader();
	/*!
	 * Metoda odpowidzialna za powiązanie obiektu shadera z programem
	 */
	inline void attachProgram();
	/*!
	 * Metoda odpowiedzialna za linkowanie i walidację shaderów
	 */
	inline void linkProgram();
	/*!
	 * Metoda pobierająca komunikat o błędzie obsługi shaderów przez OpenGL
	 * @param text tekt błędu
	 * @kod błędu z jakim ma się zakończyć program
	 */
	inline void getError(const char *text, int code);
};
}
