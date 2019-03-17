# cuACS  🐶🐱🐰👩‍💻
_cuACS_ is a software system that matches animals to people.

## Make and Launch Instructions
Ensure you are in the same directory as `cuacs.pro`

To Make:
```bash
qmake -o Makefile cuacs.pro && make
```

To Launch (First Time):
```bash
cd app && ./app data-reset && ./app
```

To Launch (Subsequent Times)"
```bash
./app
```

Note that the first launch command above makes use of 3 separate actions:
* `cd app` will move you into the location that the compiled source lives.
* `./app data-reset` will load new data into the database.
* `./app` will launch the application.

## Running Instructions
You can switch between Staff and Client mode by selecting the mode in the top right corner.

The Client mode offers just View Animals and View Animal Details.

The Staff mode offers the same features as Client, as well as Add Animal, Add Client, View Client, and View Client Details.

You can view details of an Animal or Client by double clicking on them.  This will open another window in which you will be able to view the details.

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
