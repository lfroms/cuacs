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

To Launch (Subsequent Times):
```bash
./app
```

Note that the first launch command will remove all data then load new seed data into the database:
* `cd app` will move you into the location that the compiled source lives.
* `./app data-reset` will load new data into the database.
* `./app` will launch the application.

## Running Instructions
As a user of the program you can authenticate yourself and log into the app by providing your credentials. Test the application experience in the perspective of a shelter staff member by providing the following credentials:
```
username: christinelaurendeau
password: 1234
```
As a shelter staff you can perform the following actions:
* View the list animals at a glance, and double click on the animal profiles to view a detailed version of the profile as well as the ability to edit the currently viewed animal.
* View the list of clients at a glance, and double click on the client profiles to view a detailed version of the profile. Click on the `Matching Preferences` button to see the matching preferences of the client if the client has set their preferences. Staff are not able to edit any of the client profiles.
* Click on the `Add Profiles` dropdown menu to add either an animal or client profile.
  * When you add a new client profile, the client themselves can log in with the credentials `username: <name all lowercase no spaces>` and an empty password text field.
  * If you change the client's name, the username used to log in will be automatically updated to reflect the change.
  * You can only specify the personal information of the client profile. It is the client's job to add and edit their own matching preferences.
* Click on the `Account` dropdown menu to Log Out, which redirects you to the log in screen.
* Click on the `Animal-Client Matching` tab and see a summary of the algorithm results by clicking on the `Run Animal-Client Matching Algorithm` button.
  * Click on an individual match to view a detailed breakdown of how and why the match was computed and chosen.

Otherwise, test the application experience in the perspective of a client by providing the following credentials:
```
username: johnsmith
password: 4321
```
As a client you can perform the following actions:
* View the list animals at a glance, and double click on the animal profiles to view a detailed version of the profile.
* Click on the `Account` dropdown menu to Log Out or edit their own profiles. Click on the `Matching Preferences` tab to edit your own matching preferences.

> Note: double clicking on profiles will open another window in which you will be able to view the details.

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
