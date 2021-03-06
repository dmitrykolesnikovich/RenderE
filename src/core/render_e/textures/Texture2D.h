/*
 *  RenderE
 *
 *  Created by Morten Nobel-Jørgensen ( http://www.nobel-joergnesen.com/ ) 
 *  License: LGPL 3.0 ( http://www.gnu.org/licenses/lgpl-3.0.txt )
 */

#ifndef TEXTURE_H
#define	TEXTURE_H

#include "TextureBase.h"
#include "TextureDataSource.h"

namespace render_e {

class Texture2D : public TextureBase {
public:
    Texture2D();
    Texture2D(const char *resourceName);
    virtual ~Texture2D();
    virtual TextureLoadStatus Load();
    /** Create a texture without content */
    void Create(int width, int height, TextureFormat textureFormat);
    int GetInternalFormat(){ return internalFormat; }
    void SetClamp(bool clamp){this->clamp = clamp;}
    bool IsClamp(){ return clamp; }
private:
    Texture2D(const Texture2D& orig); // disallow copy constructor
    Texture2D& operator = (const Texture2D&); // disallow copy constructor
    void GetTextureFormat(unsigned int &format);
    TextureDataSource *textureDataSource;
    bool interpolationLinear;
    bool clamp;
    char *resourceName;
    TextureFormat textureFormat;
    int internalFormat;
	int storageType;
};
}
#endif // TEXTURE_H
