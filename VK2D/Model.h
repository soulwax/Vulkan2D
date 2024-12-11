/// \file Model.h
/// \author soulwax
/// \brief Declares things related to loading and managing models
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "VK2D/Structs.h"

/// \brief Creates a model from a set of vertices
/// \param vertices List of VK2DVertex3D vertices the model will use
/// \param vertexCount Number of vertices in the list
/// \param indices List of uint16_t indices for the vertex list
/// \param indexCount Number of indices in the list
/// \param tex Texture bound to the texture
/// \return Returns a new VK2DModel or NULL if it fails
/// \warning The input must be triangulated.
VK2DModel vk2dModelCreate(const VK2DVertex3D *vertices, uint32_t vertexCount, const uint16_t *indices, uint32_t indexCount, VK2DTexture tex);

/// \brief Loads a .obj model from a binary buffer
/// \param objFile .obj file binary buffer
/// \param objFileSize Size of the buffer in bytes
/// \param texture Texture the .obj file expects
/// \return Returns a new model or NULL if it fails
/// \warning This function is very taxing as it builds a proper index list from the loaded model to save video memory
VK2DModel vk2dModelFrom(const void *objFile, uint32_t objFileSize, VK2DTexture texture);

/// \brief Loads a model from a .obj file
/// \param objFile Path to the .obj file
/// \param texture Texture the .obj file expects
/// \return Returns a new model or NULL if it fails
/// \warning This function is very taxing as it builds a proper index list from the loaded model to save video memory
VK2DModel vk2dModelLoad(const char *objFile, VK2DTexture texture);

/// \brief The texture stored in the model is not destroyed
/// \param model Model to free from memory
void vk2dModelFree(VK2DModel model);

#ifdef __cplusplus
}
#endif