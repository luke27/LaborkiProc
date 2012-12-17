/**
 *
    Copyright (C) 2012 £ukasz Durlej

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
