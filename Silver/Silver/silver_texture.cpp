//Including basic headers and texture header.
#include "silver_inc.h"
#include "silver_texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "silver_stbimage.h"
//Defining functions for the "slvr::Texture" class.
//ALL DOCUMENTATION IS HERE!

///The class constructor for the Texture class.
///Takes a path, and two optional texture filtering/tiling modes.
///TILING: 0=REPEAT 1=MIRROR 2=CLAMPTOEDGE
///FILTERING: 0=LINEAR 1=NEARESTN
///Parameters: (std::string pathtofile, int wrappingmode, int filtermode)
slvr::Texture::Texture(std::string path, int wrapmode, int filtermode) {
	//Generating texture ID to int.
	glGenTextures(1, &texture);

	//Binding as current texture.
	glBindTexture(GL_TEXTURE_2D, texture);

	//Setting the tiling/filtering options.
	switch (wrapmode) {
	case 0:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		break;
	case 1:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
		break;
	case 2:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		break;
	default:
		std::cout << "WARNING: Could not find wrap mode with ID " << wrapmode << ", using default of GL_REPEAT.\n";
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		break;
	}

	switch (filtermode) {
	case 0:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		break;
	case 1:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		break;
	default:
		std::cout << "WARNING: Could not find filter mode with ID " << filtermode << ", using default of GL_LINEAR.\n";
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		break;
	}

	//Loading in texture from image file path given.
	data = stbi_load(path.c_str(), &width, &height, &channelNumber, 0);
	//Error checking to see if it loaded properly.
	if (data) {
		//Setting texture image data to currently bound texture (this one).
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		//Generating mipmaps for performance.
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "WARNING: Could not load data for file path \"" << path << "\".";
	}

	//Freeing image data, it's now copied into the texture.
	stbi_image_free(data);
}