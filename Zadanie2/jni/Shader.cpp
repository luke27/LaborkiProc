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

#include "Shader.h"
#include "AssetManager.h"

using namespace PG;

Shader::Shader(const char * file, GLenum type)
{
	shader = 0;
	program = 0;
	shaderFile = file;
	this->type = type;
	loadShader();
	attachProgram();
	linkProgram();
}

Shader::Shader(const char *vertexFile, const char *fragmentFile, int a)
{
	shader = 0;
	program = 0;
	shaderFile = vertexFile;
	type = GL_VERTEX_SHADER;
	loadAssetShader();
	attachProgram();
	shader = 0;
	type = GL_FRAGMENT_SHADER;
	shaderFile = fragmentFile;
	loadAssetShader();
	attachProgram();
	linkProgram();
}

Shader::Shader(const char *vertexFile, const char *fragmentFile)
{
	LOGI("Shader::Shader ładowanie Vertex i Fragment Shader");
	shader = 0;
	program = 0;
	//Vertex Shader
	type = GL_VERTEX_SHADER;
	shaderFile = vertexFile;
	loadShader();
	attachProgram();
	shader = 0;
	LOGI("Shader::Shader załadowano Vertex Shader");
	//Fragment Shader
	type = GL_FRAGMENT_SHADER;
	shaderFile = fragmentFile;
	loadShader();
	attachProgram();
	//linkowanie
	linkProgram();
	LOGI("Shader::Shader załadowano Pixel Shader");
}

void Shader::loadShader()
{
	//odczyt pliku
	ifstream file;
	file.open(shaderFile, ios::binary);
	if(file.bad())
	{
		LOGE("Błąd ładowania shadera");
		exit(-20);
	}
	else
		LOGI("Załadowano %s", shaderFile);
	file.seekg(0, ios::end);
	int len = static_cast<int>(file.tellg());
	file.seekg(0, ios::beg);
	GLchar *src = new GLchar[(len + 1) * sizeof(GLchar)];
	file.read(src, len);
	file.close();
	src[len] = '\0';

	LOGI("Shader::loadShader odczytano plik");

	//nowy obiekt shadera
	shader = glCreateShader(type);
	if(shader == 0)
	{
		LOGE("Błąd w tworzeniu shadera");
		exit(-666);
	}
	
	//załadowanie kodu do shadera
	glShaderSource(shader,1, const_cast<const GLchar **>(&src), NULL);
	glesError("glShaderSource");
	LOGI("Treść shadera  %s", src);
	delete[] src;
	LOGI("Usunięcie danych tymczasowych");
	//kompilacja shadera
	glCompileShader(shader);
	glesError("glCompileShader");
	//status kompilacji shadera
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if(status != GL_TRUE)
	{
		//pobranie i wyświetlenie komunikatu błedu o kompilacji
		GLint logLen;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLen);
		char *log = new char[logLen];
		glGetShaderInfoLog(shader, logLen, NULL, log);
		LOGE("Log kompilacji %s", log);
		LOGE("Błąd kompilacji shadera %s", shaderFile);
		delete[] log;
		exit(-21);
	}
	LOGI("Załadowano shader");
}

inline void Shader::attachProgram()
{
	if(!glIsProgram(program))
		program = glCreateProgram();
	glesError("glCreateProgram");
	glAttachShader(program, shader);
	glesError("glAttachProgram");
}

inline void Shader::linkProgram()
{
	//linkowanie shaderów
	glLinkProgram(program);
	glesError("glLinkProgram");
	//sprawdzenie poprawności kompilacji
	GLint status;
	glGetProgramiv(program, GL_LINK_STATUS, &status);
	if(status == GL_FALSE)
	{
		getError("Błąd kompilacji", -22);
	}

	

	//walidacja
	glValidateProgram(program);
	glesError("glValidateProgram");
	//sprawdzenie poprawności walidacji
	glGetProgramiv(program, GL_VALIDATE_STATUS, &status);
	if(status == GL_FALSE)
	{
		getError("Błąd walidacji", -23);
	}
}

inline void Shader::getError(const char *text, int code)
{
	//pobranie komunikatu
		GLint len;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);
		char *log = new char[len];
		glGetProgramInfoLog(program, len, NULL, log);
		LOGE("Shader %s", text);
		delete[] log;
		exit(code);
}

Shader::~Shader()
{
	//usunięcie shaderów
	GLint count; //ilość shaderów
	glGetProgramiv(program, GL_ATTACHED_SHADERS, &count);

	
	//usinięcie shaderów
	if(count != 0)
	{
		GLuint *shaders = new GLuint[count];
		glGetAttachedShaders(program, count, NULL, shaders);
		for(int i = 0; i < count; i++)
			glDeleteShader(shaders[i]);
		delete[] shaders;
		glDeleteProgram(program);
	}
}

GLuint Shader::getProgram()
{
	return program;
}

void Shader::use()
{
	glUseProgram(program);
	glesError("glUseProgram");
	LOGV("Shader::use shader w użyciu program = %d", program);
}

void Shader::useOff()
{
	glUseProgram(0);
}

void PG::Shader::loadAssetShader()
{
	LOGI("Shader loading %s", shaderFile);
	AAsset *asset = AssetManager::getInstance().getAssetFile(shaderFile);
	if(!asset)
	{
		LOGE("Błąd ładowania shadera");
		exit(-20);
	}
	else
		LOGI("Załadowano %s", shaderFile);

	long fileSize = AAsset_getLength(asset);
	GLchar *src = (GLchar *) malloc(fileSize * sizeof(char));
	AAsset_read(asset, (void *)src, fileSize);
	src[fileSize] = '\0';

	AssetManager::getInstance().closeAssetFile(asset);

	LOGI("Shader::loadShader odczytano plik %s", src);

		//nowy obiekt shadera
		shader = glCreateShader(type);
		if(shader == 0)
		{
			LOGE("Błąd w tworzeniu shadera");
			exit(-666);
		}

		//załadowanie kodu do shadera
		glShaderSource(shader,1, const_cast<const GLchar **>(&src), NULL);
		glesError("glShaderSource");
		LOGI("Treść shadera  %s", src);
		//free(src);
		LOGI("Usunięcie danych tymczasowych");
		//kompilacja shadera
		glCompileShader(shader);
		glesError("glCompileShader");
		//status kompilacji shadera
		GLint status;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
		if(status != GL_TRUE)
		{
			//pobranie i wyświetlenie komunikatu błedu o kompilacji
			GLint logLen;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLen);
			char *log = new char[logLen];
			glGetShaderInfoLog(shader, logLen, NULL, log);
			LOGE("Log kompilacji %s", log);
			LOGE("Błąd kompilacji shadera %s", shaderFile);
			delete[] log;
			exit(-21);
		}
		LOGI("Załadowano shader");


	free(src);

}
