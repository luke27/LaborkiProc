/*
 * Zad1Rend.h
 *
 *  Created on: 17-12-2012
 *      Author: Luke
 */

#ifndef ZAD1REND_H_
#define ZAD1REND_H_

#include "IRenderer.h"

namespace PG
{

class Zad1Rend : public IRenderer
{
public:
	Zad1Rend();
	void render();
	virtual ~Zad1Rend();
	GLuint VBO[1];
	GLuint posLoc;
};

} /* namespace PG */
#endif /* ZAD1REND_H_ */
