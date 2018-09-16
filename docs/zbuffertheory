# Engine Theory - Depth Checking and the ZBuffer
In almost every 3D engine, drawing objects on the screen sequentially or randomly is not going to produce the results you'd expect, nor the results that you would want for a realistic-looking 3D world. See, as objects move further away from our eyes in real life, they get smaller due to *perspective*, and when objects are behind other objects in real life, we cannot see them due to the front object blocking the other one from view. These two key features of real-world geometry need to be emulated in any engine to make the world look like it could realistically exist, otherwise you end up with something horrific like this:

![dx9failedzb](https://i.stack.imgur.com/lrAJw.png)

Definitely not an intended effect; different parts of geometry are rendering over each other, when they should be behind one another. This is characteristic of objects being rendered without the Z-Buffer being consulted first, and **depth checked**. 

Depth checking ensures that objects that are behind others do not draw over more prominent objects, and so forth till all objects have been drawn onto the screen. This is done by determining the Z distance away from the current view the objects are, and where they are in the X and Y space in comparison to other objects. 

*Note: This is why depth checking is also sometimes known as Z-Buffer checking.*

In Silver specifically, the Z-Buffer is created automatically by SDL2, so no manual Z position storage is required. So, the engine simply enables the depth test flag in OpenGL, which turns on depth checking functionality, and makes the world look more like you were seeing it through the lens of a camera.

    glEnable(GL_DEPTH_TEST);

However, this also means that the depth buffer must now be cleared upon a new frame being drawn, otherwise the data from the previous frames' depth buffer will still be stored upon render time, which would cause disastrous effects. So, after render, ```glClear``` is run to remove buffer data.

    glClear(GL_DEPTH_BUFFER_BIT);

A problem still remains, however; the image still appears as if all objects are the same distance away from the camera, due to the projection matrix not being applied before the depth buffer and then rendering. Perspective projection is a difficult mathematical topic, but if you want to know more about it then you can [check out this piece](http://www.songho.ca/opengl/gl_projectionmatrix.html) by Songho.ca about the maths behind it all.

All that is really important is what Silver itself uses to handle projection matrices, which is the projection matrix calculator built into GLM.

    glm::mat4 Model::projMatrix = glm::perspective(glm::radians(camera.field_of_view), (float)win.width/(float)win.height, 0.1f, 100.0f);

After this, the 3D elements of the scene are going to be rendered correctly, and the engine moves onto post processing, lighting and shaders.

*Author's Note: This process is purely for the vertex portion of the OpenGL rendering pipeline, and does not apply when adding shaders etc. to the scene, so they do not need to be distorted by the engine, as this is done automatically with OGL's fragment data.*
