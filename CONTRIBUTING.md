# CONTRIBUTION GUIDELINES
SILVER (c) C272 2018

Basic Contribution Rules
---
1. Use four spaces as the indent for **any** file you are creating or editing in the project.
2. Modifying critical engine files (such as silver_core.cpp/h or silver_inc.h) can only be done by moderators.
3. When creating a new feature, please predefine your classes and their functions inside a header, and implement inside a .cpp file. In-header implementations will **not** be committed to any branch, unless it is for a good reason.
4. Document all functions in the .cpp (implementation) where the functions are defined, and use three forward slashes (///) to denote function docs for IntelliSense.
5. Comment code well and keep it readable. No 200-line spaghetti fests, please.

Advanced Contribution Rules
---
*These only apply if you're creating a major new feature or addition to the project.*
1. Follow basic memory management protocol (eg. don't create a 1000 element long array on the stack) and remember to always delete allocated memory before the pointer. Features that do not follow this specific rule will always be declined.
2. Try to make everything as class-based as possible (within reason), by using pointers as function parameters, and having getters/setters for your class variables.
3. Wrap any classes in the "slvr::" namespace. This will stop pollution of the global namespace for projects.
