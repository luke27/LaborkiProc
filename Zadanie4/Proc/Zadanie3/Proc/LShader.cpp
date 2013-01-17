#include "LShader.h"

LShader::LShader(const char * file, GLenum type)
{
	shader = 0;
	program = 0;
	shaderFile = file;
	this->type = type;
	loadShader();
	attachProgram();
	linkProgram();
}

LShader::LShader(const char *vertexFile, const char *fragmentFile)
{
	shader = 0;
	program = 0;
	//Vertex Shader
	type = GL_VERTEX_SHADER;
	shaderFile = vertexFile;
	loadShader();
	attachProgram();
	shader = 0;
	//Fragment Shader
	type = GL_FRAGMENT_SHADER;
	shaderFile = fragmentFile;
	loadShader();
	attachProgram();
	//linkowanie
	linkProgram();
}

void LShader::loadShader()
{
	//odczyt pliku
	ifstream file;
	file.open(shaderFile, ios::binary);
	if(file.bad())
	{
		MessageBox(NULL, L"Nie mo�na otworzy� pliku", L"B��d", MB_OK | MB_ICONEXCLAMATION);
		exit(-20);
	}
	file.seekg(0, ios::end);
	int len = static_cast<int>(file.tellg());
	file.seekg(0, ios::beg);
	GLchar *src = new GLchar[(len + 1) * sizeof(GLchar)];
	file.read(src, len);
	file.close();
	src[len] = '\0';

	//nowy obiekt shadera
	shader = glCreateShader(type);
	
	//za�adowanie kodu do shadera
	glShaderSource(shader,1, const_cast<const GLchar **>(&src), NULL);
	
	delete[] src;

	//kompilacja shadera
	glCompileShader(shader);

	//status kompilacji shadera
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if(status != GL_TRUE)
	{
		//pobranie i wy�wietlenie komunikatu b�edu o kompilacji
		GLint logLen;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLen);
		char *log = new char[logLen];
		glGetShaderInfoLog(shader, logLen, NULL, log);
		MessageBoxA(NULL, log, shaderFile, MB_OK | MB_ICONEXCLAMATION);
		delete[] log;
		exit(-21);
	}
}

inline void LShader::attachProgram()
{
	if(!glIsProgram(program))
		program = glCreateProgram();
	glAttachShader(program, shader);
}

inline void LShader::linkProgram()
{
	//linkowanie shader�w
	glLinkProgram(program);

	//sprawdzenie poprawno�ci kompilacji
	GLint status;
	glGetProgramiv(program, GL_LINK_STATUS, &status);
	if(status == GL_FALSE)
	{
		getError("B��d kompilacji", -22);
	}

	//walidacja
	glValidateProgram(program);
	//sprawdzenie poprawno�ci walidacji
	glGetProgramiv(program, GL_VALIDATE_STATUS, &status);
	if(status == GL_FALSE)
	{
		getError("B��d walidacji", -23);
	}
}

inline void LShader::getError(const char *text, int code)
{
	//pobranie komunikatu
		GLint len;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);
		char *log = new char[len];
		glGetProgramInfoLog(program, len, NULL, log);
		MessageBoxA(NULL, log, text, MB_OK | MB_ICONEXCLAMATION);
		delete[] log;
		exit(code);
}

LShader::~LShader()
{
	//usuni�cie shader�w
	GLint count; //ilo�� shader�w
	glGetProgramiv(program, GL_ATTACHED_SHADERS, &count);

	
	//usini�cie shader�w
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

GLuint LShader::getProgram()
{
	return program;
}

void LShader::use()
{
	glUseProgram(program);
}

void LShader::useOff()
{
	glUseProgram(0);
}