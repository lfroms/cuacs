# cuACS  🐶🐱🐰👩‍💻
_cuACS_ is a software system that matches animals to people.

## Development
* Ubuntu (64-bit)
* Qt Creator 4.8.1
  * Based on Qt 5.12.0
  
### Opening in Qt Creator
* Open the `cuacs.pro` file in the root directory, _not_ `app.pro`.
  
## Adding a Source File
_File Naming Scheme: `PascalCase`_
1. Create a folder in `/app`.
2. In Qt Creator, right-click `app` and click "Add New".
3. Select "C++ Class".
4. Give it a name, ensuring that the "Header File" and "Source File" boxes match the naming scheme.
5. Set the "Path" to point the the folder you created in 1.
