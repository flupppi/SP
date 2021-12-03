
class ShaderUtil
{
public:
	static GLuint CreateShaderProgram(cost char* vertexFilename, const char* fragmentFilename);
	
private:
	static std::string LoadFile(const char* fileName);
	static void PrintShaderLog(GLuint shader);
	static void PrintProgramLog(GLuint program);
	static void PrintOGlErrors();
}
