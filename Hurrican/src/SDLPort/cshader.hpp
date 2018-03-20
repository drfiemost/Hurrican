/**
 *
 *  Copyright (C) 2011-2015 Scott R. Smith
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 *
 */
#ifndef CSHADER_H
#define CSHADER_H

#include <string>
#include <vector>
#include "cml/cml.h"
#include "opengl.hpp"

#define CHECK_FLAG(X, Y) ((X & Y) == Y)

enum { SHADER = 0x01, PROGRAM = 0x02 };

struct shader_t {
    std::string path;
    GLenum type;
    GLuint name;

    shader_t() : path("none"), type(GL_INVALID_VALUE), name(GL_INVALID_VALUE){};
};

class CShader {
  public:
    CShader();
    virtual ~CShader();

    void Close();
    int8_t Load(const std::string &path_vertex, const std::string &path_frag);
    void Use();
    GLint GetAttribute(const std::string &attribute);
    GLint GetUniform(const std::string &attribute);

    GLuint NamePos;
    GLuint NameClr;
    GLuint NameTex;
    GLuint NameMvp;
#if defined(USE_ETC1)
    GLuint texUnit0;
    GLuint texUnit1;
#endif

  private:
    int8_t LoadShader(GLenum type, const std::string &path);
    int8_t CreateProgram(void);
    GLuint CompileShader(GLenum type, const std::string &path);
    void FindAttributes(void);
    void FindUniforms(void);
    void PrintLog(uint8_t type, GLuint shader = 0);

    GLuint Program;
    std::vector<shader_t> Shaders;
    std::vector<std::pair<std::string, GLint> > Uniforms;
    std::vector<std::pair<std::string, GLint> > Attributes;
};

extern cml::matrix44f_r g_matView;
extern cml::matrix44f_r g_matModelView;

#endif  // CSHADER_H