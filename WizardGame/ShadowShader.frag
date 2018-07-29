#version 110

uniform sampler2D sampler;

varying vec2 texCoords;

void main() {
	vec4 col = texture2D(sampler, texCoords);
	if (col.r == 1.0) {
		discard;
	}
	gl_FragColor = vec4(0.0, 0.0, 0.0, 0.5);
}