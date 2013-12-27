#ifndef GPUPROG_H
#define GPUPROG_H

#include <Object.h>
#include <Pixel.h>

namespace lime
{

class ColorTransform;

enum GPUProgID
{
   gpuNone = -1,
   gpuSolid,
   gpuColour,
   gpuColourTransform,
   gpuTexture,
   gpuTextureColourArray,
   gpuTextureTransform,
   gpuBitmap,
   gpuBitmapAlpha,
   gpuRadialGradient,
   gpuRadialFocusGradient,
   gpuSIZE,
};

typedef float Trans4x4[4][4];

class GPUProg : public Object
{
public:
   static GPUProg *create(const char *inVertSource, const char *inFragSource);
   static GPUProg *createDefaultShader(GPUProgID inID, AlphaMode inAlphaMode);

   virtual ~GPUProg() {}

   virtual bool bind() = 0;

   virtual void setUniformi(const char *id, int *value, int size) = 0;
   virtual void setUniformf(const char *id, float *value, int size) = 0;

   virtual void setPositionData(const float *inData, bool inIsPerspective) = 0;
   virtual void setTexCoordData(const float *inData) = 0;
   virtual void setColourData(const int *inData) = 0;
   virtual void setColourTransform(const ColorTransform *inTransform) = 0;
   virtual int getTextureSlot() = 0;

   virtual void setTransform(const Trans4x4 &inTrans) = 0;
   virtual void setTint(unsigned int inColour) = 0;
   virtual void setGradientFocus(float inFocus) = 0;
   virtual void finishDrawing() = 0;
};

}

#endif
