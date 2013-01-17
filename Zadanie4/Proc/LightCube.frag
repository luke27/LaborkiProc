#version 150
uniform vec4 lightPos;
uniform vec4 observer;
uniform vec4 ambient;
uniform vec4 diffuse;
uniform vec4 specular;
uniform float shininess;
in vec4 outCol;
//in vec3 normal;
out vec4 outputColor;
in vec3 inoutNormal;
in vec3 outPos;
vec4 lightDiffuse = vec4(1.0, 1.0, 1.0, 1.0);
vec4 lightSpecular = vec4(1.0, 1.0, 1.0, 1.0);
//normal wektoe normalny
//pos pozycja 
vec4 phong(const vec3 normal, const vec3 pos);
//œciana przednia
vec4 farPhong(const vec3 normal, const vec3 pos);
//ty³
vec4 nearPhong(const vec3 normal, const vec3 pos);

void main()
{
	vec3 normal = normalize(inoutNormal); //normalizacja wektpra
	outputColor = phong(normal, outPos);
}

vec4 phong(const vec3 normal, const vec3 pos)
{
	
	if(gl_FrontFacing == true)
		return farPhong(normal, pos);
	else
		return nearPhong(normal, outPos);
	
}


vec4 farPhong(const vec3 normal, const vec3 pos)
{
	vec3 lighVec = lightPos.xyz - pos;
	float distance = length(lighVec);
	vec3 lightVec = normalize(lighVec);
	
	float ndotl = max(dot(normal, lightVec), 0.0);
	if(ndotl > 0.0)
	{
		vec3 reflectVex = -reflect(lightPos.xyz, normal);
		float etdor = max(dot(normalize(observer.xyz - pos), reflectVex), 0.0);
		return ndotl * diffuse * lightDiffuse + specular * lightSpecular * pow(etdor, shininess);
	}
	else
		return vec4(0.0);
	
	/*vec3 lighVec = lightPos - pos;
	float distance = length(lighVec);
	vec3 lightVec = normalize(lighVec);
	float NdoL = max(dot(normal, lightVec), 0.0);
	if(NdoL > 0.0)
	{
		vec3 observer = vec3(0.0, 0.0, 3.0);
		vec3 reflectVec = -reflect(lightPos, normal);
		float EdoR = max(dot(normalize(observer - pos), reflectVec), 0.0);
		return NdoL * diffuse * lightDiffuse + specular * lightSpecular * pow(EdoR, shininess);
	}
	else
		return vec4(0.0);
		*/
}

vec4 nearPhong(const vec3 normal, const vec3 pos)
{
	
	vec3 lighVec = lightPos.xyz - pos;
	float distance = length(lighVec);
	vec3 lightVec = normalize(lighVec);

	float ndotl = max(dot(normal, lightVec), 0.0);
	if(ndotl > 0.0)
	{
		vec3 reflectVex = -reflect(lightPos.xyz, normal);
		float etdor = max(dot(normalize(observer.xyz - pos), reflectVex), 0.0);
		return ndotl * diffuse * lightDiffuse + specular * lightSpecular * pow(etdor, shininess);
	}
	else
		return vec4(0.0);
}