# slvr::Shader
**Overview**

The main way to draw basic shapes on screen in Silver, supporting the slvr::Shader class as input to shade the primitive with. 

> *Author's Note*: Currently does not support draws above 1 triangle, for testing purposes. Support will be added in future.

## Methods
*Primitive()*

Constructor, takes an array of points (vertices) as the first parameter to draw on screen (these should be normalized), the size of the array in bytes, which can be accessed by ```sizeof(points)```, and a Silver shader class to apply to the vertices.

Parameters: (float\* points, int arraySizeBytes, slvr::Shader\* shader)

&nbsp;

**void** *render()*

Renders the primitive in the scene, using ```glDrawArrays```, on 3 points (currently).

Parameters: ()
