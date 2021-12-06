
#version 330

uniform sampler2D baseColor;

in vec2 texCoord;
out vec4 color;

void main()
{
	color = texture(baseColor, texCoord);
	// color = vex4(texCoord.x, texCoord.y, 0.0, 1.0)
	// debug Aktion wenn kein Dreieck angezeigt wird
