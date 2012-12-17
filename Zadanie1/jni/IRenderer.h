#pragma once
#include "Shader.h"
#include <GLES2/gl2.h>
using namespace PG;

class IRenderer
{
public:
	virtual void render() = 0;
	virtual ~IRenderer()
	{}
protected:
	Shader *shader;
};
