#version 100

attribute vec3 position;
attribute vec4 color;
varying vec4 v_color;

void main()
{
	v_color = color;
	gl_Position = vec4(position, 1.0);
}