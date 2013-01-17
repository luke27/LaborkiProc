//////////////////////////////////////////////////////////////////////
// (c > ( Janusz Ganczarski
// http://www.januszg.hg.pl
// JanuszG@enter.net.pl
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <sstream>
#include "extensions3.h"

//////////////////////////////////////////////////////////////////////
// obs≥uga rozszerzeÒ w systemach Windows
//////////////////////////////////////////////////////////////////////
#ifdef WIN32

//////////////////////////////////////////////////////////////////////
// wskaünik funkcji pochodzπcej z rozszerzenia WGL_ARB_create_context
//////////////////////////////////////////////////////////////////////
PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z OpenGL 1.2
//////////////////////////////////////////////////////////////////////
PFNGLBLENDCOLORPROC glBlendColor = NULL;
PFNGLBLENDEQUATIONPROC glBlendEquation = NULL;
PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements = NULL;
PFNGLTEXIMAGE3DPROC glTexImage3D = NULL;
PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D = NULL;
PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z OpenGL 1.3
//////////////////////////////////////////////////////////////////////
PFNGLACTIVETEXTUREPROC glActiveTexture = NULL;
PFNGLSAMPLECOVERAGEPROC glSampleCoverage = NULL;
PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D = NULL;
PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D = NULL;
PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D = NULL;
PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z OpenGL 1.4
//////////////////////////////////////////////////////////////////////
PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate = NULL;
PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays = NULL;
PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements = NULL;
PFNGLPOINTPARAMETERFPROC glPointParameterf = NULL;
PFNGLPOINTPARAMETERFVPROC glPointParameterfv = NULL;
PFNGLPOINTPARAMETERIPROC glPointParameteri = NULL;
PFNGLPOINTPARAMETERIVPROC glPointParameteriv = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z OpenGL 1.5
//////////////////////////////////////////////////////////////////////
PFNGLGENQUERIESPROC glGenQueries = NULL;
PFNGLDELETEQUERIESPROC glDeleteQueries = NULL;
PFNGLISQUERYPROC glIsQuery = NULL;
PFNGLBEGINQUERYPROC glBeginQuery = NULL;
PFNGLENDQUERYPROC glEndQuery = NULL;
PFNGLGETQUERYIVPROC glGetQueryiv = NULL;
PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv = NULL;
PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv = NULL;
PFNGLBINDBUFFERPROC glBindBuffer = NULL;
PFNGLDELETEBUFFERSPROC glDeleteBuffers = NULL;
PFNGLGENBUFFERSPROC glGenBuffers = NULL;
PFNGLISBUFFERPROC glIsBuffer = NULL;
PFNGLBUFFERDATAPROC glBufferData = NULL;
PFNGLBUFFERSUBDATAPROC glBufferSubData = NULL;
PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData = NULL;
PFNGLMAPBUFFERPROC glMapBuffer = NULL;
PFNGLUNMAPBUFFERPROC glUnmapBuffer = NULL;
PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv = NULL;
PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z OpenGL 2.0
//////////////////////////////////////////////////////////////////////
PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate = NULL;
PFNGLDRAWBUFFERSPROC glDrawBuffers = NULL;
PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparate = NULL;
PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparate = NULL;
PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparate = NULL;
PFNGLATTACHSHADERPROC glAttachShader = NULL;
PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation = NULL;
PFNGLCOMPILESHADERPROC glCompileShader = NULL;
PFNGLCREATEPROGRAMPROC glCreateProgram = NULL;
PFNGLCREATESHADERPROC glCreateShader = NULL;
PFNGLDELETEPROGRAMPROC glDeleteProgram = NULL;
PFNGLDELETESHADERPROC glDeleteShader = NULL;
PFNGLDETACHSHADERPROC glDetachShader = NULL;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray = NULL;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray = NULL;
PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib = NULL;
PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform = NULL;
PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders = NULL;
PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation = NULL;
PFNGLGETPROGRAMIVPROC glGetProgramiv = NULL;
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog = NULL;
PFNGLGETSHADERIVPROC glGetShaderiv = NULL;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog = NULL;
PFNGLGETSHADERSOURCEPROC glGetShaderSource = NULL;
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation = NULL;
PFNGLGETUNIFORMFVPROC glGetUniformfv = NULL;
PFNGLGETUNIFORMIVPROC glGetUniformiv = NULL;
PFNGLGETVERTEXATTRIBDVPROC glGetVertexAttribdv = NULL;
PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv = NULL;
PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv = NULL;
PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv = NULL;
PFNGLISPROGRAMPROC glIsProgram = NULL;
PFNGLISSHADERPROC glIsShader = NULL;
PFNGLLINKPROGRAMPROC glLinkProgram = NULL;
PFNGLSHADERSOURCEPROC glShaderSource = NULL;
PFNGLUSEPROGRAMPROC glUseProgram = NULL;
PFNGLUNIFORM1FPROC glUniform1f = NULL;
PFNGLUNIFORM2FPROC glUniform2f = NULL;
PFNGLUNIFORM3FPROC glUniform3f = NULL;
PFNGLUNIFORM4FPROC glUniform4f = NULL;
PFNGLUNIFORM1IPROC glUniform1i = NULL;
PFNGLUNIFORM2IPROC glUniform2i = NULL;
PFNGLUNIFORM3IPROC glUniform3i = NULL;
PFNGLUNIFORM4IPROC glUniform4i = NULL;
PFNGLUNIFORM1FVPROC glUniform1fv = NULL;
PFNGLUNIFORM2FVPROC glUniform2fv = NULL;
PFNGLUNIFORM3FVPROC glUniform3fv = NULL;
PFNGLUNIFORM4FVPROC glUniform4fv = NULL;
PFNGLUNIFORM1IVPROC glUniform1iv = NULL;
PFNGLUNIFORM2IVPROC glUniform2iv = NULL;
PFNGLUNIFORM3IVPROC glUniform3iv = NULL;
PFNGLUNIFORM4IVPROC glUniform4iv = NULL;
PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv = NULL;
PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv = NULL;
PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv = NULL;
PFNGLVALIDATEPROGRAMPROC glValidateProgram = NULL;
PFNGLVERTEXATTRIB1DPROC glVertexAttrib1d = NULL;
PFNGLVERTEXATTRIB1DVPROC glVertexAttrib1dv = NULL;
PFNGLVERTEXATTRIB1FPROC glVertexAttrib1f = NULL;
PFNGLVERTEXATTRIB1FVPROC glVertexAttrib1fv = NULL;
PFNGLVERTEXATTRIB1SPROC glVertexAttrib1s = NULL;
PFNGLVERTEXATTRIB1SVPROC glVertexAttrib1sv = NULL;
PFNGLVERTEXATTRIB2DPROC glVertexAttrib2d = NULL;
PFNGLVERTEXATTRIB2DVPROC glVertexAttrib2dv = NULL;
PFNGLVERTEXATTRIB2FPROC glVertexAttrib2f = NULL;
PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fv = NULL;
PFNGLVERTEXATTRIB2SPROC glVertexAttrib2s = NULL;
PFNGLVERTEXATTRIB2SVPROC glVertexAttrib2sv = NULL;
PFNGLVERTEXATTRIB3DPROC glVertexAttrib3d = NULL;
PFNGLVERTEXATTRIB3DVPROC glVertexAttrib3dv = NULL;
PFNGLVERTEXATTRIB3FPROC glVertexAttrib3f = NULL;
PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fv = NULL;
PFNGLVERTEXATTRIB3SPROC glVertexAttrib3s = NULL;
PFNGLVERTEXATTRIB3SVPROC glVertexAttrib3sv = NULL;
PFNGLVERTEXATTRIB4NBVPROC glVertexAttrib4Nbv = NULL;
PFNGLVERTEXATTRIB4NIVPROC glVertexAttrib4Niv = NULL;
PFNGLVERTEXATTRIB4NSVPROC glVertexAttrib4Nsv = NULL;
PFNGLVERTEXATTRIB4NUBPROC glVertexAttrib4Nub = NULL;
PFNGLVERTEXATTRIB4NUBVPROC glVertexAttrib4Nubv = NULL;
PFNGLVERTEXATTRIB4NUIVPROC glVertexAttrib4Nuiv = NULL;
PFNGLVERTEXATTRIB4NUSVPROC glVertexAttrib4Nusv = NULL;
PFNGLVERTEXATTRIB4BVPROC glVertexAttrib4bv = NULL;
PFNGLVERTEXATTRIB4DPROC glVertexAttrib4d = NULL;
PFNGLVERTEXATTRIB4DVPROC glVertexAttrib4dv = NULL;
PFNGLVERTEXATTRIB4FPROC glVertexAttrib4f = NULL;
PFNGLVERTEXATTRIB4FVPROC glVertexAttrib4fv = NULL;
PFNGLVERTEXATTRIB4IVPROC glVertexAttrib4iv = NULL;
PFNGLVERTEXATTRIB4SPROC glVertexAttrib4s = NULL;
PFNGLVERTEXATTRIB4SVPROC glVertexAttrib4sv = NULL;
PFNGLVERTEXATTRIB4UBVPROC glVertexAttrib4ubv = NULL;
PFNGLVERTEXATTRIB4UIVPROC glVertexAttrib4uiv = NULL;
PFNGLVERTEXATTRIB4USVPROC glVertexAttrib4usv = NULL;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z OpenGL 2.1
//////////////////////////////////////////////////////////////////////
PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv = NULL;
PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv = NULL;
PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv = NULL;
PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv = NULL;
PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv = NULL;
PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z OpenGL 3.0
//////////////////////////////////////////////////////////////////////
PFNGLCOLORMASKIPROC glColorMaski = NULL;
PFNGLGETBOOLEANI_VPROC glGetBooleani_v = NULL;
PFNGLGETINTEGERI_VPROC glGetIntegeri_v = NULL;
PFNGLENABLEIPROC glEnablei = NULL;
PFNGLDISABLEIPROC glDisablei = NULL;
PFNGLISENABLEDIPROC glIsEnabledi = NULL;
PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedback = NULL;
PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedback = NULL;
PFNGLBINDBUFFERRANGEPROC glBindBufferRange = NULL;
PFNGLBINDBUFFERBASEPROC glBindBufferBase = NULL;
PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryings = NULL;
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVarying = NULL;
PFNGLCLAMPCOLORPROC glClampColor = NULL;
PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRender = NULL;
PFNGLENDCONDITIONALRENDERPROC glEndConditionalRender = NULL;
PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer = NULL;
PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIiv = NULL;
PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuiv = NULL;
PFNGLGETUNIFORMUIVPROC glGetUniformuiv = NULL;
PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation = NULL;
PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocation = NULL;
PFNGLUNIFORM1UIPROC glUniform1ui = NULL;
PFNGLUNIFORM2UIPROC glUniform2ui = NULL;
PFNGLUNIFORM3UIPROC glUniform3ui = NULL;
PFNGLUNIFORM4UIPROC glUniform4ui = NULL;
PFNGLUNIFORM1UIVPROC glUniform1uiv = NULL;
PFNGLUNIFORM2UIVPROC glUniform2uiv = NULL;
PFNGLUNIFORM3UIVPROC glUniform3uiv = NULL;
PFNGLUNIFORM4UIVPROC glUniform4uiv = NULL;
PFNGLTEXPARAMETERIIVPROC glTexParameterIiv = NULL;
PFNGLTEXPARAMETERIUIVPROC glTexParameterIuiv = NULL;
PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIiv = NULL;
PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuiv = NULL;
PFNGLCLEARBUFFERIVPROC glClearBufferiv = NULL;
PFNGLCLEARBUFFERUIVPROC glClearBufferuiv = NULL;
PFNGLCLEARBUFFERFVPROC glClearBufferfv = NULL;
PFNGLCLEARBUFFERFIPROC glClearBufferfi = NULL;
PFNGLGETSTRINGIPROC glGetStringi = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z GL_ARB_framebuffer_object (OpenGL 3.0)
//////////////////////////////////////////////////////////////////////
PFNGLISRENDERBUFFERPROC glIsRenderbuffer = NULL;
PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer = NULL;
PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers = NULL;
PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers = NULL;
PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage = NULL;
PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv = NULL;
PFNGLISFRAMEBUFFERPROC glIsFramebuffer = NULL;
PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer = NULL;
PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers = NULL;
PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers = NULL;
PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus = NULL;
PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1D = NULL;
PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D = NULL;
PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3D = NULL;
PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer = NULL;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv = NULL;
PFNGLGENERATEMIPMAPPROC glGenerateMipmap = NULL;
PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer = NULL;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample = NULL;
PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z GL_ARB_map_buffer_range (OpenGL 3.0)
//////////////////////////////////////////////////////////////////////
PFNGLMAPBUFFERRANGEPROC glMapBufferRange = NULL;
PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z GL_ARB_vertex_array_object (OpenGL 3.0)
//////////////////////////////////////////////////////////////////////
PFNGLBINDVERTEXARRAYPROC glBindVertexArray = NULL;
PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays = NULL;
PFNGLGENVERTEXARRAYSPROC glGenVertexArrays = NULL;
PFNGLISVERTEXARRAYPROC glIsVertexArray = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z OpenGL 3.1
//////////////////////////////////////////////////////////////////////
PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced = NULL;
PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced = NULL;
PFNGLTEXBUFFERPROC glTexBuffer = NULL;
PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z GL_ARB_uniform_buffer_object (OpenGL 3.1)
//////////////////////////////////////////////////////////////////////
PFNGLGETUNIFORMINDICESPROC glGetUniformIndices = NULL;
PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv = NULL;
PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName = NULL;
PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex = NULL;
PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv = NULL;
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName = NULL;
PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z GL_ARB_copy_buffer (OpenGL 3.1)
//////////////////////////////////////////////////////////////////////
PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji pochodzπcych z OpenGL 3.2
//////////////////////////////////////////////////////////////////////
PFNGLGETINTEGER64I_VPROC glGetInteger64i_v = NULL;
PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v = NULL;
PFNGLPROGRAMPARAMETERIPROC glProgramParameteri = NULL;
PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_draw_elements_base_vertex (OpenGL 3.2)
//////////////////////////////////////////////////////////////////////
PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex = NULL;
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex = NULL;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex = NULL;
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_provoking_vertex (OpenGL 3.2)
//////////////////////////////////////////////////////////////////////
PFNGLPROVOKINGVERTEXPROC glProvokingVertex = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_sync (OpenGL 3.2)
//////////////////////////////////////////////////////////////////////
PFNGLFENCESYNCPROC glFenceSync = NULL;
PFNGLISSYNCPROC glIsSync = NULL;
PFNGLDELETESYNCPROC glDeleteSync = NULL;
PFNGLCLIENTWAITSYNCPROC glClientWaitSync = NULL;
PFNGLWAITSYNCPROC glWaitSync = NULL;
PFNGLGETINTEGER64VPROC glGetInteger64v = NULL;
PFNGLGETSYNCIVPROC glGetSynciv = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_texture_multisample (OpenGL 3.2)
//////////////////////////////////////////////////////////////////////
PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample = NULL;
PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample = NULL;
PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv = NULL;
PFNGLSAMPLEMASKIPROC glSampleMaski = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_draw_buffers_blend (OpenGL 3.2)
//////////////////////////////////////////////////////////////////////
PFNGLBLENDEQUATIONIPROC glBlendEquationi = NULL;
PFNGLBLENDEQUATIONSEPARATEIPROC glBlendEquationSeparatei = NULL;
PFNGLBLENDFUNCIPROC glBlendFunci = NULL;
PFNGLBLENDFUNCSEPARATEIPROC glBlendFuncSeparatei = NULL;

//////////////////////////////////////////////////////////////////////
// wskaüniki funkcji z rozszerzenia GL_ARB_sample_shading (OpenGL 3.2)
//////////////////////////////////////////////////////////////////////
PFNGLMINSAMPLESHADINGPROC glMinSampleShading = NULL;

//////////////////////////////////////////////////////////////////////
// pobranie wskaünikÛw funkcji z OpenGL 3.0
//////////////////////////////////////////////////////////////////////
bool OpenGL30()
{
    if( OpenGLVersion() < 30 )
        return false;

    // pobranie wskaünikÛw funkcji pochodzπcych z OpenGL 1.2
    glBlendColor = reinterpret_cast < PFNGLBLENDCOLORPROC > ( wglGetProcAddress ( "glBlendColor" ) );
    glBlendEquation = reinterpret_cast < PFNGLBLENDEQUATIONPROC > ( wglGetProcAddress ( "glBlendEquation" ) );
    glDrawRangeElements = reinterpret_cast < PFNGLDRAWRANGEELEMENTSPROC > ( wglGetProcAddress ( "glDrawRangeElements" ) );
    glTexImage3D = reinterpret_cast < PFNGLTEXIMAGE3DPROC > ( wglGetProcAddress ( "glTexImage3D" ) );
    glTexSubImage3D = reinterpret_cast < PFNGLTEXSUBIMAGE3DPROC > ( wglGetProcAddress ( "glTexSubImage3D" ) );
    glCopyTexSubImage3D = reinterpret_cast < PFNGLCOPYTEXSUBIMAGE3DPROC > ( wglGetProcAddress ( "glCopyTexSubImage3D" ) );

    // pobranie wskaünikÛw pochodzπcych z OpenGL 1.3
    glActiveTexture = reinterpret_cast < PFNGLACTIVETEXTUREPROC > ( wglGetProcAddress ( "glActiveTexture" ) );
    glSampleCoverage = reinterpret_cast < PFNGLSAMPLECOVERAGEPROC > ( wglGetProcAddress ( "glSampleCoverage" ) );
    glCompressedTexImage3D = reinterpret_cast < PFNGLCOMPRESSEDTEXIMAGE3DPROC > ( wglGetProcAddress ( "glCompressedTexImage3D" ) );
    glCompressedTexImage2D = reinterpret_cast < PFNGLCOMPRESSEDTEXIMAGE2DPROC > ( wglGetProcAddress ( "glCompressedTexImage2D" ) );
    glCompressedTexImage1D = reinterpret_cast < PFNGLCOMPRESSEDTEXIMAGE1DPROC > ( wglGetProcAddress ( "glCompressedTexImage1D" ) );
    glCompressedTexSubImage3D = reinterpret_cast < PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC > ( wglGetProcAddress ( "glCompressedTexSubImage3D" ) );
    glCompressedTexSubImage2D = reinterpret_cast < PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC > ( wglGetProcAddress ( "glCompressedTexSubImage2D" ) );
    glCompressedTexSubImage1D = reinterpret_cast < PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC > ( wglGetProcAddress ( "glCompressedTexSubImage1D" ) );
    glGetCompressedTexImage = reinterpret_cast < PFNGLGETCOMPRESSEDTEXIMAGEPROC > ( wglGetProcAddress ( "glGetCompressedTexImage" ) );

    // pobranie wskaünikÛw pochodzπcych z OpenGL 1.4
    glBlendFuncSeparate = reinterpret_cast < PFNGLBLENDFUNCSEPARATEPROC > ( wglGetProcAddress ( "glBlendFuncSeparate" ) );
    glMultiDrawArrays = reinterpret_cast < PFNGLMULTIDRAWARRAYSPROC > ( wglGetProcAddress ( "glMultiDrawArrays" ) );
    glMultiDrawElements = reinterpret_cast < PFNGLMULTIDRAWELEMENTSPROC > ( wglGetProcAddress ( "glMultiDrawElements" ) );
    glPointParameterf = reinterpret_cast < PFNGLPOINTPARAMETERFPROC > ( wglGetProcAddress ( "glPointParameterf" ) );
    glPointParameterfv = reinterpret_cast < PFNGLPOINTPARAMETERFVPROC > ( wglGetProcAddress ( "glPointParameterfv" ) );
    glPointParameteri = reinterpret_cast < PFNGLPOINTPARAMETERIPROC > ( wglGetProcAddress ( "glPointParameteri" ) );
    glPointParameteriv = reinterpret_cast < PFNGLPOINTPARAMETERIVPROC > ( wglGetProcAddress ( "glPointParameteriv" ) );

    // pobranie wskaünikÛ wpochodzπcych z OpenGL 1.5
    glGenQueries = reinterpret_cast < PFNGLGENQUERIESPROC > ( wglGetProcAddress ( "glGenQueries" ) );
    glDeleteQueries = reinterpret_cast < PFNGLDELETEQUERIESPROC > ( wglGetProcAddress ( "glDeleteQueries" ) );
    glIsQuery = reinterpret_cast < PFNGLISQUERYPROC > ( wglGetProcAddress ( "glIsQuery" ) );
    glBeginQuery = reinterpret_cast < PFNGLBEGINQUERYPROC > ( wglGetProcAddress ( "glBeginQuery" ) );
    glEndQuery = reinterpret_cast < PFNGLENDQUERYPROC > ( wglGetProcAddress ( "glEndQuery" ) );
    glGetQueryiv = reinterpret_cast < PFNGLGETQUERYIVPROC > ( wglGetProcAddress ( "glGetQueryiv" ) );
    glGetQueryObjectiv = reinterpret_cast < PFNGLGETQUERYOBJECTIVPROC > ( wglGetProcAddress ( "glGetQueryObjectiv" ) );
    glGetQueryObjectuiv = reinterpret_cast < PFNGLGETQUERYOBJECTUIVPROC > ( wglGetProcAddress ( "glGetQueryObjectuiv" ) );
    glBindBuffer = reinterpret_cast < PFNGLBINDBUFFERPROC > ( wglGetProcAddress ( "glBindBuffer" ) );
    glDeleteBuffers = reinterpret_cast < PFNGLDELETEBUFFERSPROC > ( wglGetProcAddress ( "glDeleteBuffers" ) );
    glGenBuffers = reinterpret_cast < PFNGLGENBUFFERSPROC > ( wglGetProcAddress ( "glGenBuffers" ) );
    glIsBuffer = reinterpret_cast < PFNGLISBUFFERPROC > ( wglGetProcAddress ( "glIsBuffer" ) );
    glBufferData = reinterpret_cast < PFNGLBUFFERDATAPROC > ( wglGetProcAddress ( "glBufferData" ) );
    glBufferSubData = reinterpret_cast < PFNGLBUFFERSUBDATAPROC > ( wglGetProcAddress ( "glBufferSubData" ) );
    glGetBufferSubData = reinterpret_cast < PFNGLGETBUFFERSUBDATAPROC > ( wglGetProcAddress ( "glGetBufferSubData" ) );
    glMapBuffer = reinterpret_cast < PFNGLMAPBUFFERPROC > ( wglGetProcAddress ( "glMapBuffer" ) );
    glUnmapBuffer = reinterpret_cast < PFNGLUNMAPBUFFERPROC > ( wglGetProcAddress ( "glUnmapBuffer" ) );
    glGetBufferParameteriv = reinterpret_cast < PFNGLGETBUFFERPARAMETERIVPROC > ( wglGetProcAddress ( "glGetBufferParameteriv" ) );
    glGetBufferPointerv = reinterpret_cast < PFNGLGETBUFFERPOINTERVPROC > ( wglGetProcAddress ( "glGetBufferPointerv" ) );

    // pobranie wskaünikÛw pochodzπcych z OpenGL 2.0
    glBlendEquationSeparate = reinterpret_cast < PFNGLBLENDEQUATIONSEPARATEPROC > ( wglGetProcAddress ( "glBlendEquationSeparate" ) );
    glDrawBuffers = reinterpret_cast < PFNGLDRAWBUFFERSPROC > ( wglGetProcAddress ( "glDrawBuffers" ) );
    glStencilOpSeparate = reinterpret_cast < PFNGLSTENCILOPSEPARATEPROC > ( wglGetProcAddress ( "glStencilOpSeparate" ) );
    glStencilFuncSeparate = reinterpret_cast < PFNGLSTENCILFUNCSEPARATEPROC > ( wglGetProcAddress ( "glStencilFuncSeparate" ) );
    glStencilMaskSeparate = reinterpret_cast < PFNGLSTENCILMASKSEPARATEPROC > ( wglGetProcAddress ( "glStencilMaskSeparate" ) );
    glAttachShader = reinterpret_cast < PFNGLATTACHSHADERPROC > ( wglGetProcAddress ( "glAttachShader" ) );
    glBindAttribLocation = reinterpret_cast < PFNGLBINDATTRIBLOCATIONPROC > ( wglGetProcAddress ( "glBindAttribLocation" ) );
    glCompileShader = reinterpret_cast < PFNGLCOMPILESHADERPROC > ( wglGetProcAddress ( "glCompileShader" ) );
    glCreateProgram = reinterpret_cast < PFNGLCREATEPROGRAMPROC > ( wglGetProcAddress ( "glCreateProgram" ) );
    glCreateShader = reinterpret_cast < PFNGLCREATESHADERPROC > ( wglGetProcAddress ( "glCreateShader" ) );
    glDeleteProgram = reinterpret_cast < PFNGLDELETEPROGRAMPROC > ( wglGetProcAddress ( "glDeleteProgram" ) );
    glDeleteShader = reinterpret_cast < PFNGLDELETESHADERPROC > ( wglGetProcAddress ( "glDeleteShader" ) );
    glDetachShader = reinterpret_cast < PFNGLDETACHSHADERPROC > ( wglGetProcAddress ( "glDetachShader" ) );
    glDisableVertexAttribArray = reinterpret_cast < PFNGLDISABLEVERTEXATTRIBARRAYPROC > ( wglGetProcAddress ( "glDisableVertexAttribArray" ) );
    glEnableVertexAttribArray = reinterpret_cast < PFNGLENABLEVERTEXATTRIBARRAYPROC > ( wglGetProcAddress ( "glEnableVertexAttribArray" ) );
    glGetActiveAttrib = reinterpret_cast < PFNGLGETACTIVEATTRIBPROC > ( wglGetProcAddress ( "glGetActiveAttrib" ) );
    glGetActiveUniform = reinterpret_cast < PFNGLGETACTIVEUNIFORMPROC > ( wglGetProcAddress ( "glGetActiveUniform" ) );
    glGetAttachedShaders = reinterpret_cast < PFNGLGETATTACHEDSHADERSPROC > ( wglGetProcAddress ( "glGetAttachedShaders" ) );
    glGetAttribLocation = reinterpret_cast < PFNGLGETATTRIBLOCATIONPROC > ( wglGetProcAddress ( "glGetAttribLocation" ) );
    glGetProgramiv = reinterpret_cast < PFNGLGETPROGRAMIVPROC > ( wglGetProcAddress ( "glGetProgramiv" ) );
    glGetProgramInfoLog = reinterpret_cast < PFNGLGETPROGRAMINFOLOGPROC > ( wglGetProcAddress ( "glGetProgramInfoLog" ) );
    glGetShaderiv = reinterpret_cast < PFNGLGETSHADERIVPROC > ( wglGetProcAddress ( "glGetShaderiv" ) );
    glGetShaderInfoLog = reinterpret_cast < PFNGLGETSHADERINFOLOGPROC > ( wglGetProcAddress ( "glGetShaderInfoLog" ) );
    glGetShaderSource = reinterpret_cast < PFNGLGETSHADERSOURCEPROC > ( wglGetProcAddress ( "glGetShaderSource" ) );
    glGetUniformLocation = reinterpret_cast < PFNGLGETUNIFORMLOCATIONPROC > ( wglGetProcAddress ( "glGetUniformLocation" ) );
    glGetUniformfv = reinterpret_cast < PFNGLGETUNIFORMFVPROC > ( wglGetProcAddress ( "glGetUniformfv" ) );
    glGetUniformiv = reinterpret_cast < PFNGLGETUNIFORMIVPROC > ( wglGetProcAddress ( "glGetUniformiv" ) );
    glGetVertexAttribdv = reinterpret_cast < PFNGLGETVERTEXATTRIBDVPROC > ( wglGetProcAddress ( "glGetVertexAttribdv" ) );
    glGetVertexAttribfv = reinterpret_cast < PFNGLGETVERTEXATTRIBFVPROC > ( wglGetProcAddress ( "glGetVertexAttribfv" ) );
    glGetVertexAttribiv = reinterpret_cast < PFNGLGETVERTEXATTRIBIVPROC > ( wglGetProcAddress ( "glGetVertexAttribiv" ) );
    glGetVertexAttribPointerv = reinterpret_cast < PFNGLGETVERTEXATTRIBPOINTERVPROC > ( wglGetProcAddress ( "glGetVertexAttribPointerv" ) );
    glIsProgram = reinterpret_cast < PFNGLISPROGRAMPROC > ( wglGetProcAddress ( "glIsProgram" ) );
    glIsShader = reinterpret_cast < PFNGLISSHADERPROC > ( wglGetProcAddress ( "glIsShader" ) );
    glLinkProgram = reinterpret_cast < PFNGLLINKPROGRAMPROC > ( wglGetProcAddress ( "glLinkProgram" ) );
    glShaderSource = reinterpret_cast < PFNGLSHADERSOURCEPROC > ( wglGetProcAddress ( "glShaderSource" ) );
    glUseProgram = reinterpret_cast < PFNGLUSEPROGRAMPROC > ( wglGetProcAddress ( "glUseProgram" ) );
    glUniform1f = reinterpret_cast < PFNGLUNIFORM1FPROC > ( wglGetProcAddress ( "glUniform1f" ) );
    glUniform2f = reinterpret_cast < PFNGLUNIFORM2FPROC > ( wglGetProcAddress ( "glUniform2f" ) );
    glUniform3f = reinterpret_cast < PFNGLUNIFORM3FPROC > ( wglGetProcAddress ( "glUniform3f" ) );
    glUniform4f = reinterpret_cast < PFNGLUNIFORM4FPROC > ( wglGetProcAddress ( "glUniform4f" ) );
    glUniform1i = reinterpret_cast < PFNGLUNIFORM1IPROC > ( wglGetProcAddress ( "glUniform1i" ) );
    glUniform2i = reinterpret_cast < PFNGLUNIFORM2IPROC > ( wglGetProcAddress ( "glUniform2i" ) );
    glUniform3i = reinterpret_cast < PFNGLUNIFORM3IPROC > ( wglGetProcAddress ( "glUniform3i" ) );
    glUniform4i = reinterpret_cast < PFNGLUNIFORM4IPROC > ( wglGetProcAddress ( "glUniform4i" ) );
    glUniform1fv = reinterpret_cast < PFNGLUNIFORM1FVPROC > ( wglGetProcAddress ( "glUniform1fv" ) );
    glUniform2fv = reinterpret_cast < PFNGLUNIFORM2FVPROC > ( wglGetProcAddress ( "glUniform2fv" ) );
    glUniform3fv = reinterpret_cast < PFNGLUNIFORM3FVPROC > ( wglGetProcAddress ( "glUniform3fv" ) );
    glUniform4fv = reinterpret_cast < PFNGLUNIFORM4FVPROC > ( wglGetProcAddress ( "glUniform4fv" ) );
    glUniform1iv = reinterpret_cast < PFNGLUNIFORM1IVPROC > ( wglGetProcAddress ( "glUniform1iv" ) );
    glUniform2iv = reinterpret_cast < PFNGLUNIFORM2IVPROC > ( wglGetProcAddress ( "glUniform2iv" ) );
    glUniform3iv = reinterpret_cast < PFNGLUNIFORM3IVPROC > ( wglGetProcAddress ( "glUniform3iv" ) );
    glUniform4iv = reinterpret_cast < PFNGLUNIFORM4IVPROC > ( wglGetProcAddress ( "glUniform4iv" ) );
    glUniformMatrix2fv = reinterpret_cast < PFNGLUNIFORMMATRIX2FVPROC > ( wglGetProcAddress ( "glUniformMatrix2fv" ) );
    glUniformMatrix3fv = reinterpret_cast < PFNGLUNIFORMMATRIX3FVPROC > ( wglGetProcAddress ( "glUniformMatrix3fv" ) );
    glUniformMatrix4fv = reinterpret_cast < PFNGLUNIFORMMATRIX4FVPROC > ( wglGetProcAddress ( "glUniformMatrix4fv" ) );
    glValidateProgram = reinterpret_cast < PFNGLVALIDATEPROGRAMPROC > ( wglGetProcAddress ( "glValidateProgram" ) );
    glVertexAttrib1d = reinterpret_cast < PFNGLVERTEXATTRIB1DPROC > ( wglGetProcAddress ( "glVertexAttrib1d" ) );
    glVertexAttrib1dv = reinterpret_cast < PFNGLVERTEXATTRIB1DVPROC > ( wglGetProcAddress ( "glVertexAttrib1dv" ) );
    glVertexAttrib1f = reinterpret_cast < PFNGLVERTEXATTRIB1FPROC > ( wglGetProcAddress ( "glVertexAttrib1f" ) );
    glVertexAttrib1fv = reinterpret_cast < PFNGLVERTEXATTRIB1FVPROC > ( wglGetProcAddress ( "glVertexAttrib1fv" ) );
    glVertexAttrib1s = reinterpret_cast < PFNGLVERTEXATTRIB1SPROC > ( wglGetProcAddress ( "glVertexAttrib1s" ) );
    glVertexAttrib1sv = reinterpret_cast < PFNGLVERTEXATTRIB1SVPROC > ( wglGetProcAddress ( "glVertexAttrib1sv" ) );
    glVertexAttrib2d = reinterpret_cast < PFNGLVERTEXATTRIB2DPROC > ( wglGetProcAddress ( "glVertexAttrib2d" ) );
    glVertexAttrib2dv = reinterpret_cast < PFNGLVERTEXATTRIB2DVPROC > ( wglGetProcAddress ( "glVertexAttrib2dv" ) );
    glVertexAttrib2f = reinterpret_cast < PFNGLVERTEXATTRIB2FPROC > ( wglGetProcAddress ( "glVertexAttrib2f" ) );
    glVertexAttrib2fv = reinterpret_cast < PFNGLVERTEXATTRIB2FVPROC > ( wglGetProcAddress ( "glVertexAttrib2fv" ) );
    glVertexAttrib2s = reinterpret_cast < PFNGLVERTEXATTRIB2SPROC > ( wglGetProcAddress ( "glVertexAttrib2s" ) );
    glVertexAttrib2sv = reinterpret_cast < PFNGLVERTEXATTRIB2SVPROC > ( wglGetProcAddress ( "glVertexAttrib2sv" ) );
    glVertexAttrib3d = reinterpret_cast < PFNGLVERTEXATTRIB3DPROC > ( wglGetProcAddress ( "glVertexAttrib3d" ) );
    glVertexAttrib3dv = reinterpret_cast < PFNGLVERTEXATTRIB3DVPROC > ( wglGetProcAddress ( "glVertexAttrib3dv" ) );
    glVertexAttrib3f = reinterpret_cast < PFNGLVERTEXATTRIB3FPROC > ( wglGetProcAddress ( "glVertexAttrib3f" ) );
    glVertexAttrib3fv = reinterpret_cast < PFNGLVERTEXATTRIB3FVPROC > ( wglGetProcAddress ( "glVertexAttrib3fv" ) );
    glVertexAttrib3s = reinterpret_cast < PFNGLVERTEXATTRIB3SPROC > ( wglGetProcAddress ( "glVertexAttrib3s" ) );
    glVertexAttrib3sv = reinterpret_cast < PFNGLVERTEXATTRIB3SVPROC > ( wglGetProcAddress ( "glVertexAttrib3sv" ) );
    glVertexAttrib4Nbv = reinterpret_cast < PFNGLVERTEXATTRIB4NBVPROC > ( wglGetProcAddress ( "glVertexAttrib4Nbv" ) );
    glVertexAttrib4Niv = reinterpret_cast < PFNGLVERTEXATTRIB4NIVPROC > ( wglGetProcAddress ( "glVertexAttrib4Niv" ) );
    glVertexAttrib4Nsv = reinterpret_cast < PFNGLVERTEXATTRIB4NSVPROC > ( wglGetProcAddress ( "glVertexAttrib4Nsv" ) );
    glVertexAttrib4Nub = reinterpret_cast < PFNGLVERTEXATTRIB4NUBPROC > ( wglGetProcAddress ( "glVertexAttrib4Nub" ) );
    glVertexAttrib4Nubv = reinterpret_cast < PFNGLVERTEXATTRIB4NUBVPROC > ( wglGetProcAddress ( "glVertexAttrib4Nubv" ) );
    glVertexAttrib4Nuiv = reinterpret_cast < PFNGLVERTEXATTRIB4NUIVPROC > ( wglGetProcAddress ( "glVertexAttrib4Nuiv" ) );
    glVertexAttrib4Nusv = reinterpret_cast < PFNGLVERTEXATTRIB4NUSVPROC > ( wglGetProcAddress ( "glVertexAttrib4Nusv" ) );
    glVertexAttrib4bv = reinterpret_cast < PFNGLVERTEXATTRIB4BVPROC > ( wglGetProcAddress ( "glVertexAttrib4bv" ) );
    glVertexAttrib4d = reinterpret_cast < PFNGLVERTEXATTRIB4DPROC > ( wglGetProcAddress ( "glVertexAttrib4d" ) );
    glVertexAttrib4dv = reinterpret_cast < PFNGLVERTEXATTRIB4DVPROC > ( wglGetProcAddress ( "glVertexAttrib4dv" ) );
    glVertexAttrib4f = reinterpret_cast < PFNGLVERTEXATTRIB4FPROC > ( wglGetProcAddress ( "glVertexAttrib4f" ) );
    glVertexAttrib4fv = reinterpret_cast < PFNGLVERTEXATTRIB4FVPROC > ( wglGetProcAddress ( "glVertexAttrib4fv" ) );
    glVertexAttrib4iv = reinterpret_cast < PFNGLVERTEXATTRIB4IVPROC > ( wglGetProcAddress ( "glVertexAttrib4iv" ) );
    glVertexAttrib4s = reinterpret_cast < PFNGLVERTEXATTRIB4SPROC > ( wglGetProcAddress ( "glVertexAttrib4s" ) );
    glVertexAttrib4sv = reinterpret_cast < PFNGLVERTEXATTRIB4SVPROC > ( wglGetProcAddress ( "glVertexAttrib4sv" ) );
    glVertexAttrib4ubv = reinterpret_cast < PFNGLVERTEXATTRIB4UBVPROC > ( wglGetProcAddress ( "glVertexAttrib4ubv" ) );
    glVertexAttrib4uiv = reinterpret_cast < PFNGLVERTEXATTRIB4UIVPROC > ( wglGetProcAddress ( "glVertexAttrib4uiv" ) );
    glVertexAttrib4usv = reinterpret_cast < PFNGLVERTEXATTRIB4USVPROC > ( wglGetProcAddress ( "glVertexAttrib4usv" ) );
    glVertexAttribPointer = reinterpret_cast < PFNGLVERTEXATTRIBPOINTERPROC > ( wglGetProcAddress ( "glVertexAttribPointer" ) );

    // pobranie wskaünikÛw pochodzπcych z OpenGL 2.1
    glUniformMatrix2x3fv = reinterpret_cast < PFNGLUNIFORMMATRIX2X3FVPROC > ( wglGetProcAddress ( "glUniformMatrix2x3fv" ) );
    glUniformMatrix3x2fv = reinterpret_cast < PFNGLUNIFORMMATRIX3X2FVPROC > ( wglGetProcAddress ( "glUniformMatrix3x2fv" ) );
    glUniformMatrix2x4fv = reinterpret_cast < PFNGLUNIFORMMATRIX2X4FVPROC > ( wglGetProcAddress ( "glUniformMatrix2x4fv" ) );
    glUniformMatrix4x2fv = reinterpret_cast < PFNGLUNIFORMMATRIX4X2FVPROC > ( wglGetProcAddress ( "glUniformMatrix4x2fv" ) );
    glUniformMatrix3x4fv = reinterpret_cast < PFNGLUNIFORMMATRIX3X4FVPROC > ( wglGetProcAddress ( "glUniformMatrix3x4fv" ) );
    glUniformMatrix4x3fv = reinterpret_cast < PFNGLUNIFORMMATRIX4X3FVPROC > ( wglGetProcAddress ( "glUniformMatrix4x3fv" ) );

    // pobranie wskaünikÛw pochodzπcych z OpenGL 3.0
    glColorMaski = reinterpret_cast < PFNGLCOLORMASKIPROC > ( wglGetProcAddress( "glColorMaski" ) );
    glGetBooleani_v = reinterpret_cast < PFNGLGETBOOLEANI_VPROC > ( wglGetProcAddress( "glGetBooleani_v" ) );
    glGetIntegeri_v = reinterpret_cast < PFNGLGETINTEGERI_VPROC > ( wglGetProcAddress( "glGetIntegeri_v" ) );
    glEnablei = reinterpret_cast < PFNGLENABLEIPROC > ( wglGetProcAddress( "glEnablei" ) );
    glDisablei = reinterpret_cast < PFNGLDISABLEIPROC > ( wglGetProcAddress( "glDisablei" ) );
    glIsEnabledi = reinterpret_cast < PFNGLISENABLEDIPROC > ( wglGetProcAddress( "glIsEnabledi" ) );
    glBeginTransformFeedback = reinterpret_cast < PFNGLBEGINTRANSFORMFEEDBACKPROC > ( wglGetProcAddress( "glBeginTransformFeedback" ) );
    glEndTransformFeedback = reinterpret_cast < PFNGLENDTRANSFORMFEEDBACKPROC > ( wglGetProcAddress( "glEndTransformFeedback" ) );
    glBindBufferRange = reinterpret_cast < PFNGLBINDBUFFERRANGEPROC > ( wglGetProcAddress( "glBindBufferRange" ) );
    glBindBufferBase = reinterpret_cast < PFNGLBINDBUFFERBASEPROC > ( wglGetProcAddress( "glBindBufferBase" ) );
    glTransformFeedbackVaryings = reinterpret_cast < PFNGLTRANSFORMFEEDBACKVARYINGSPROC > ( wglGetProcAddress( "glTransformFeedbackVaryings" ) );
    glGetTransformFeedbackVarying = reinterpret_cast < PFNGLGETTRANSFORMFEEDBACKVARYINGPROC > ( wglGetProcAddress( "glGetTransformFeedbackVarying" ) );
    glClampColor = reinterpret_cast < PFNGLCLAMPCOLORPROC > ( wglGetProcAddress( "glClampColor" ) );
    glBeginConditionalRender = reinterpret_cast < PFNGLBEGINCONDITIONALRENDERPROC > ( wglGetProcAddress( "glBeginConditionalRender" ) );
    glEndConditionalRender = reinterpret_cast < PFNGLENDCONDITIONALRENDERPROC > ( wglGetProcAddress( "glEndConditionalRender" ) );
    glVertexAttribIPointer = reinterpret_cast < PFNGLVERTEXATTRIBIPOINTERPROC > ( wglGetProcAddress( "glVertexAttribIPointer" ) );
    glGetVertexAttribIiv = reinterpret_cast < PFNGLGETVERTEXATTRIBIIVPROC > ( wglGetProcAddress( "glGetVertexAttribIiv" ) );
    glGetVertexAttribIuiv = reinterpret_cast < PFNGLGETVERTEXATTRIBIUIVPROC > ( wglGetProcAddress( "glGetVertexAttribIuiv" ) );
    glGetUniformuiv = reinterpret_cast < PFNGLGETUNIFORMUIVPROC > ( wglGetProcAddress( "glGetUniformuiv" ) );
    glBindFragDataLocation = reinterpret_cast < PFNGLBINDFRAGDATALOCATIONPROC > ( wglGetProcAddress( "glBindFragDataLocation" ) );
    glGetFragDataLocation = reinterpret_cast < PFNGLGETFRAGDATALOCATIONPROC > ( wglGetProcAddress( "glGetFragDataLocation" ) );
    glUniform1ui = reinterpret_cast < PFNGLUNIFORM1UIPROC > ( wglGetProcAddress( "glUniform1ui" ) );
    glUniform2ui = reinterpret_cast < PFNGLUNIFORM2UIPROC > ( wglGetProcAddress( "glUniform2ui" ) );
    glUniform3ui = reinterpret_cast < PFNGLUNIFORM3UIPROC > ( wglGetProcAddress( "glUniform3ui" ) );
    glUniform4ui = reinterpret_cast < PFNGLUNIFORM4UIPROC > ( wglGetProcAddress( "glUniform4ui" ) );
    glUniform1uiv = reinterpret_cast < PFNGLUNIFORM1UIVPROC > ( wglGetProcAddress( "glUniform1uiv" ) );
    glUniform2uiv = reinterpret_cast < PFNGLUNIFORM2UIVPROC > ( wglGetProcAddress( "glUniform2uiv" ) );
    glUniform3uiv = reinterpret_cast < PFNGLUNIFORM3UIVPROC > ( wglGetProcAddress( "glUniform3uiv" ) );
    glUniform4uiv = reinterpret_cast < PFNGLUNIFORM4UIVPROC > ( wglGetProcAddress( "glUniform4uiv" ) );
    glTexParameterIiv = reinterpret_cast < PFNGLTEXPARAMETERIIVPROC > ( wglGetProcAddress( "glTexParameterIiv" ) );
    glTexParameterIuiv = reinterpret_cast < PFNGLTEXPARAMETERIUIVPROC > ( wglGetProcAddress( "glTexParameterIuiv" ) );
    glGetTexParameterIiv = reinterpret_cast < PFNGLGETTEXPARAMETERIIVPROC > ( wglGetProcAddress( "glGetTexParameterIiv" ) );
    glGetTexParameterIuiv = reinterpret_cast < PFNGLGETTEXPARAMETERIUIVPROC > ( wglGetProcAddress( "glGetTexParameterIuiv" ) );
    glClearBufferiv = reinterpret_cast < PFNGLCLEARBUFFERIVPROC > ( wglGetProcAddress( "glClearBufferiv" ) );
    glClearBufferuiv = reinterpret_cast < PFNGLCLEARBUFFERUIVPROC > ( wglGetProcAddress( "glClearBufferuiv" ) );
    glClearBufferfv = reinterpret_cast < PFNGLCLEARBUFFERFVPROC > ( wglGetProcAddress( "glClearBufferfv" ) );
    glClearBufferfi = reinterpret_cast < PFNGLCLEARBUFFERFIPROC > ( wglGetProcAddress( "glClearBufferfi" ) );
    glGetStringi = reinterpret_cast < PFNGLGETSTRINGIPROC > ( wglGetProcAddress( "glGetStringi" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_framebuffer_object
    glIsRenderbuffer = reinterpret_cast < PFNGLISRENDERBUFFERPROC > ( wglGetProcAddress( "glIsRenderbuffer" ) );
    glBindRenderbuffer = reinterpret_cast < PFNGLBINDRENDERBUFFERPROC > ( wglGetProcAddress( "glBindRenderbuffer" ) );
    glDeleteRenderbuffers = reinterpret_cast < PFNGLDELETERENDERBUFFERSPROC > ( wglGetProcAddress( "glDeleteRenderbuffers" ) );
    glGenRenderbuffers = reinterpret_cast < PFNGLGENRENDERBUFFERSPROC > ( wglGetProcAddress( "glGenRenderbuffers" ) );
    glRenderbufferStorage = reinterpret_cast < PFNGLRENDERBUFFERSTORAGEPROC > ( wglGetProcAddress( "glRenderbufferStorage" ) );
    glGetRenderbufferParameteriv = reinterpret_cast < PFNGLGETRENDERBUFFERPARAMETERIVPROC > ( wglGetProcAddress( "glGetRenderbufferParameteriv" ) );
    glIsFramebuffer = reinterpret_cast < PFNGLISFRAMEBUFFERPROC > ( wglGetProcAddress( "glIsFramebuffer" ) );
    glBindFramebuffer = reinterpret_cast < PFNGLBINDFRAMEBUFFERPROC > ( wglGetProcAddress( "glBindFramebuffer" ) );
    glDeleteFramebuffers = reinterpret_cast < PFNGLDELETEFRAMEBUFFERSPROC > ( wglGetProcAddress( "glDeleteFramebuffers" ) );
    glGenFramebuffers = reinterpret_cast < PFNGLGENFRAMEBUFFERSPROC > ( wglGetProcAddress( "glGenFramebuffers" ) );
    glCheckFramebufferStatus = reinterpret_cast < PFNGLCHECKFRAMEBUFFERSTATUSPROC > ( wglGetProcAddress( "glCheckFramebufferStatus" ) );
    glFramebufferTexture1D = reinterpret_cast < PFNGLFRAMEBUFFERTEXTURE1DPROC > ( wglGetProcAddress( "glFramebufferTexture1D" ) );
    glFramebufferTexture2D = reinterpret_cast < PFNGLFRAMEBUFFERTEXTURE2DPROC > ( wglGetProcAddress( "glFramebufferTexture2D" ) );
    glFramebufferTexture3D = reinterpret_cast < PFNGLFRAMEBUFFERTEXTURE3DPROC > ( wglGetProcAddress( "glFramebufferTexture3D" ) );
    glFramebufferRenderbuffer = reinterpret_cast < PFNGLFRAMEBUFFERRENDERBUFFERPROC > ( wglGetProcAddress( "glFramebufferRenderbuffer" ) );
    glGetFramebufferAttachmentParameteriv = reinterpret_cast < PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC > ( wglGetProcAddress( "glGetFramebufferAttachmentParameteriv" ) );
    glGenerateMipmap = reinterpret_cast < PFNGLGENERATEMIPMAPPROC > ( wglGetProcAddress( "glGenerateMipmap" ) );
    glBlitFramebuffer = reinterpret_cast < PFNGLBLITFRAMEBUFFERPROC > ( wglGetProcAddress( "glBlitFramebuffer" ) );
    glRenderbufferStorageMultisample = reinterpret_cast < PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC > ( wglGetProcAddress( "glRenderbufferStorageMultisample" ) );
    glFramebufferTextureLayer = reinterpret_cast < PFNGLFRAMEBUFFERTEXTURELAYERPROC > ( wglGetProcAddress( "glFramebufferTextureLayer" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_map_buffer_range
    glMapBufferRange = reinterpret_cast < PFNGLMAPBUFFERRANGEPROC > ( wglGetProcAddress( "glMapBufferRange" ) );
    glFlushMappedBufferRange = reinterpret_cast < PFNGLFLUSHMAPPEDBUFFERRANGEPROC > ( wglGetProcAddress( "glFlushMappedBufferRange" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_vertex_array_object
    glBindVertexArray = reinterpret_cast < PFNGLBINDVERTEXARRAYPROC > ( wglGetProcAddress( "glBindVertexArray" ) );
    glDeleteVertexArrays = reinterpret_cast < PFNGLDELETEVERTEXARRAYSPROC > ( wglGetProcAddress( "glDeleteVertexArrays" ) );
    glGenVertexArrays = reinterpret_cast < PFNGLGENVERTEXARRAYSPROC > ( wglGetProcAddress( "glGenVertexArrays" ) );
    glIsVertexArray = reinterpret_cast < PFNGLISVERTEXARRAYPROC > ( wglGetProcAddress( "glIsVertexArray" ) );

    // sukces
    return true;
}

//////////////////////////////////////////////////////////////////////
// pobranie wskaünikÛw funkcji z OpenGL 3.1
//////////////////////////////////////////////////////////////////////
bool OpenGL31()
{
    // sprawdzenie numeru wersji
    if( OpenGLVersion() < 31 )
        return false;

    // pobranie wskaünikÛw
    glDrawArraysInstanced = reinterpret_cast < PFNGLDRAWARRAYSINSTANCEDPROC > ( wglGetProcAddress( "glDrawArraysInstanced" ) );
    glDrawElementsInstanced = reinterpret_cast < PFNGLDRAWELEMENTSINSTANCEDPROC > ( wglGetProcAddress( "glDrawElementsInstanced" ) );
    glTexBuffer = reinterpret_cast < PFNGLTEXBUFFERPROC > ( wglGetProcAddress( "glTexBuffer" ) );
    glPrimitiveRestartIndex = reinterpret_cast < PFNGLPRIMITIVERESTARTINDEXPROC > ( wglGetProcAddress( "glPrimitiveRestartIndex" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_uniform_buffer_object
    glGetUniformIndices = reinterpret_cast < PFNGLGETUNIFORMINDICESPROC > ( wglGetProcAddress( "glGetUniformIndices" ) );
    glGetActiveUniformsiv = reinterpret_cast < PFNGLGETACTIVEUNIFORMSIVPROC > ( wglGetProcAddress( "glGetActiveUniformsiv" ) );
    glGetActiveUniformName = reinterpret_cast < PFNGLGETACTIVEUNIFORMNAMEPROC > ( wglGetProcAddress( "glGetActiveUniformName" ) );
    glGetUniformBlockIndex = reinterpret_cast < PFNGLGETUNIFORMBLOCKINDEXPROC > ( wglGetProcAddress( "glGetUniformBlockIndex" ) );
    glGetActiveUniformBlockiv = reinterpret_cast < PFNGLGETACTIVEUNIFORMBLOCKIVPROC > ( wglGetProcAddress( "glGetActiveUniformBlockiv" ) );
    glGetActiveUniformBlockName = reinterpret_cast < PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC > ( wglGetProcAddress( "glGetActiveUniformBlockName" ) );
    glUniformBlockBinding = reinterpret_cast < PFNGLUNIFORMBLOCKBINDINGPROC > ( wglGetProcAddress( "glUniformBlockBinding" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_copy_buffer
    glCopyBufferSubData = reinterpret_cast < PFNGLCOPYBUFFERSUBDATAPROC > ( wglGetProcAddress( "glCopyBufferSubData" ) );

    // sukces
    return true;
}

//////////////////////////////////////////////////////////////////////
// pobranie wskaünikÛw funkcji z OpenGL 3.2
//////////////////////////////////////////////////////////////////////
bool OpenGL32()
{
    // sprawdzenie numeru wersji
    if( OpenGLVersion() < 32 )
        return false;

    // pobranie wskaünikÛw
    glGetInteger64i_v = reinterpret_cast < PFNGLGETINTEGER64I_VPROC > ( wglGetProcAddress( "glGetInteger64i_v" ) );
    glGetBufferParameteri64v = reinterpret_cast < PFNGLGETBUFFERPARAMETERI64VPROC > ( wglGetProcAddress( "glGetBufferParameteri64v" ) );
    glProgramParameteri = reinterpret_cast < PFNGLPROGRAMPARAMETERIPROC > ( wglGetProcAddress( "glProgramParameteri" ) );
    glFramebufferTexture = reinterpret_cast < PFNGLFRAMEBUFFERTEXTUREPROC > ( wglGetProcAddress( "glFramebufferTexture" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_draw_elements_base_vertex
    glDrawElementsBaseVertex = reinterpret_cast < PFNGLDRAWELEMENTSBASEVERTEXPROC > ( wglGetProcAddress( "glDrawElementsBaseVertex" ) );
    glDrawRangeElementsBaseVertex = reinterpret_cast < PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC > ( wglGetProcAddress( "glDrawRangeElementsBaseVertex" ) );
    glDrawElementsInstancedBaseVertex = reinterpret_cast < PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC > ( wglGetProcAddress( "glDrawElementsInstancedBaseVertex" ) );
    glMultiDrawElementsBaseVertex = reinterpret_cast < PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC > ( wglGetProcAddress( "glMultiDrawElementsBaseVertex" ) );

    // pobranie wskaünikÛw -rozszerzenie GL_ARB_provoking_vertex
    glProvokingVertex = reinterpret_cast < PFNGLPROVOKINGVERTEXPROC > ( wglGetProcAddress( "glProvokingVertex" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_sync
    glFenceSync = reinterpret_cast < PFNGLFENCESYNCPROC > ( wglGetProcAddress( "glFenceSync" ) );
    glIsSync = reinterpret_cast < PFNGLISSYNCPROC > ( wglGetProcAddress( "glIsSync" ) );
    glDeleteSync = reinterpret_cast < PFNGLDELETESYNCPROC > ( wglGetProcAddress( "glDeleteSync" ) );
    glClientWaitSync = reinterpret_cast < PFNGLCLIENTWAITSYNCPROC > ( wglGetProcAddress( "glClientWaitSync" ) );
    glWaitSync = reinterpret_cast < PFNGLWAITSYNCPROC > ( wglGetProcAddress( "glWaitSync" ) );
    glGetInteger64v = reinterpret_cast < PFNGLGETINTEGER64VPROC > ( wglGetProcAddress( "glGetInteger64v" ) );
    glGetSynciv = reinterpret_cast < PFNGLGETSYNCIVPROC > ( wglGetProcAddress( "glGetSynciv" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_texture_multisample
    glTexImage2DMultisample = reinterpret_cast < PFNGLTEXIMAGE2DMULTISAMPLEPROC > ( wglGetProcAddress( "glTexImage2DMultisample" ) );
    glTexImage3DMultisample = reinterpret_cast < PFNGLTEXIMAGE3DMULTISAMPLEPROC > ( wglGetProcAddress( "glTexImage3DMultisample" ) );
    glGetMultisamplefv = reinterpret_cast < PFNGLGETMULTISAMPLEFVPROC > ( wglGetProcAddress( "glGetMultisamplefv" ) );
    glSampleMaski = reinterpret_cast < PFNGLSAMPLEMASKIPROC > ( wglGetProcAddress( "glSampleMaski" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_draw_buffers_blend
    glBlendEquationi = reinterpret_cast < PFNGLBLENDEQUATIONIPROC > ( wglGetProcAddress( "glBlendEquationi" ) );
    glBlendEquationSeparatei = reinterpret_cast < PFNGLBLENDEQUATIONSEPARATEIPROC > ( wglGetProcAddress( "glBlendEquationSeparatei" ) );
    glBlendFunci = reinterpret_cast < PFNGLBLENDFUNCIPROC > ( wglGetProcAddress( "glBlendFunci" ) );
    glBlendFuncSeparatei = reinterpret_cast < PFNGLBLENDFUNCSEPARATEIPROC > ( wglGetProcAddress( "glBlendFuncSeparatei" ) );

    // pobranie wskaünikÛw - rozszerzenie GL_ARB_sample_shading
    glMinSampleShading = reinterpret_cast < PFNGLMINSAMPLESHADINGPROC > ( wglGetProcAddress( "glMinSampleShading" ) );

    // sukces
    return true;
}

#endif // WIN32

//////////////////////////////////////////////////////////////////////
// pobranie numeru wersji biblioteki OpenGL
// numer wersji pomnoøony przez 10
//////////////////////////////////////////////////////////////////////
int OpenGLVersion()
{
    int major = 0, minor = 0;
    glGetIntegerv( GL_MAJOR_VERSION, &major );
    glGetIntegerv( GL_MINOR_VERSION, &minor );
    return 10*major + minor;
}

//////////////////////////////////////////////////////////////////////
// sprawdzenie obs≥ugi rozszerzenia biblioteki OpenGL
// extName - nazwa sprawdzanego rozszerzenia OpenGL
//////////////////////////////////////////////////////////////////////
bool OpenGLExtension( const char *extName )
{
    GLint numExt;
    glGetIntegerv( GL_NUM_EXTENSIONS, &numExt );
    for( int i = 0; i < numExt; i++ )
        if( std::string( reinterpret_cast< const char* >( glGetStringi( GL_EXTENSIONS, i ) ) ) == std::string ( extName ) )
            return true;
    return false;
}

//////////////////////////////////////////////////////////////////////
// sprawdzenie wersji jÍzyka GLSL; numer wersji pomnoøony przez 100
//////////////////////////////////////////////////////////////////////
int GLSLVersion()
{
    // pobranie numery wersji GLSL
    std::stringstream version( std::stringstream::in | std::stringstream::out );
    version << reinterpret_cast< const char* >( glGetString( GL_SHADING_LANGUAGE_VERSION ) );
    if( glGetError() != GL_NO_ERROR ) return 0;

    // numer wersji pomnoøony przez 100
    int major = 0, minor = 0;
    char dot;
    version >> major;
    if( version.fail() )return 0;
    version >> dot;
    if( version.fail() || dot != '.' ) return 0;
    version >> minor;
    if( version.fail() ) return 0;
    return 100*major + minor;
}

