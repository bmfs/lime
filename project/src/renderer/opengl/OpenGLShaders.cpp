#include "renderer/opengl/OGL.h"
#include "renderer/opengl/OpenGlShaders.h"
#include "renderer/opengl/OpenGLProgram.h"


namespace lime {
	
		
	GPUProg *GPUProg::create(const char *inVertSource, const char *inFragSource) { 
		return new OpenGLProgram(inVertSource, inFragSource);
	}


	GPUProg *GPUProg::createDefaultShader(GPUProgID inID, AlphaMode inAlphaMode) {
		
		#ifdef ALLOW_OGL2
		switch (inID) {
			
			case gpuSolid:
				return new OpenGLProgram (gSolidVert, gSolidFrag, inAlphaMode);
				
			case gpuColourTransform:
				return new OpenGLProgram (gColourVert, gColourTransFrag, inAlphaMode);
				
			case gpuColour:
				return new OpenGLProgram (gColourVert, gColourFrag, inAlphaMode);
				
			case gpuRadialGradient:
				return new OpenGLProgram (gTextureVert, gRadialTextureFrag, inAlphaMode);
				
			case gpuRadialFocusGradient:
				return new OpenGLProgram (gTextureVert, gRadialFocusTextureFrag, inAlphaMode);
				
			case gpuTexture:
				return new OpenGLProgram (gTextureVert, gTextureFrag, inAlphaMode);
				
			case gpuTextureColourArray:
				if (inAlphaMode == amPremultiplied)
					return new OpenGLProgram (gTextureColourVert, gTextureColourPremultFrag, inAlphaMode);
				else
					return new OpenGLProgram (gTextureColourVert, gTextureColourFrag, inAlphaMode);
				
			case gpuTextureTransform:
				return new OpenGLProgram (gTextureVert, gTextureTransFrag, inAlphaMode);
				
			case gpuBitmap:
				return new OpenGLProgram (gTextureVert, gBitmapFrag, inAlphaMode);
				
			case gpuBitmapAlpha:
				if (inAlphaMode == amPremultiplied)
					return new OpenGLProgram (gTextureVert, gBitmapAlphaPremultFrag, inAlphaMode);
				else
					return new OpenGLProgram (gTextureVert, gBitmapAlphaFrag, inAlphaMode);
				
			default:
				break;
			
		}
		#endif
		
		return 0;
		
	}
	
	
}
