Designed to be simple tests without many dependencies that help one get started with CMocka, from basic assertions to mocking to wrapping unimplemented functions.

## How to install CMake
1. Download the latest version from https://cmake.org/download/. I used 3.29.5 on Windows, installing the x64 .msi installer under "Binary distributions".
2. Go through the installer and install it in Program Files. Choose the option in the installer that will automatically add CMake to your path.
3. Test whether or not this is correctly installed by running ``cmake --version`` in the command line.
4. Next, download Visual Studio and Visual Studio Build Tools from https://visualstudio.microsoft.com/downloads/ and https://visualstudio.microsoft.com/visual-cpp-build-tools/, respectively. Make sure you opt in to getting the "Desktop Development for C++" build tool.
5. Configure CMake by running ``cmake -G "Visual Studio (version, such as 17) (year, such as 2022)" -DCMAKE_BUILD_TYPE=Debug /path/to/source``, where ``/path/to/source`` is the path to the folder you are in. As for the Visual Studio version/year part, for example mine was `"Visual Studio 17 2022"`. I ran this inside one of my test folders, but I do not think it matters whether or not you do so. This is a one-time run.
6. To configure the unit tests necessary for this repository, run ``cmake -DCMAKE_BUILD_TYPE=Debug -DUNIT_TESTING=ON ..``  . This also a one-time run.

## How to install CMocka
#### What you will need: CMake version >= 3.5.0, a C compiler such as gcc.
1. Download the source code as a zip file from https://github.com/clibs/cmocka.
2. Extract the zip file into a folder, and open/navigate to that folder in command prompt.
3. Run ``mkdir build`` and ``cd build`` while in the folder to create the build directory and navigate into it.
4. Using CMake, generate the Visual Studio solution by running ``cmake -G "Visual Studio (version, such as 17) (year, such as 2022)" ..``  . Again, mine was `"Visual Studio 17 2022"` for this portion.
5. Open the newly created cmocka.sln file found in the build folder of cmocka. It should open up Visual Studio. Next, run this build by selecting Build from the top bar of Visual Studio and selecting Build Solution from the drop down (or by typing `Ctrl + Shift + B`).
6. Now that it has been compiled, open command prompt again but this time as an administrator.
7. Navigate to the build directory inside the cmocka expanded folder again (where you just created cmocka.sln). Run ``cmake --build . --target install`` to fully install cmocka.
8. Lastly, navigate into the Environment Variables section of System Properties. Edit the Path variable, adding `"C:\Program Files (x86)\cmocka\bin"` to the list. Click OK 3 times to apply.

### How to run a test:
1. Go into the main folder of the directory.
2. Ensure you have written a CMakeLists.txt file and that it is in the same folder as your test files. Refer to the ones in this repository as examples: you need, in short, to define the project, add executables based on your test files and their dependencies, add include directories/link libraries for cmocka for every executable, enable testing, and add the tests based off of the given executables.
3. Run ``mkdir build`` and ``cd build`` while still in the test folder to create the build directory and navigate into it.
4. Run ``cmake ..``  . This generates your compilation (`cmake`) based off the CMakeLists file in the previous folder (`..`).
5. Run ``cmake --build .``  . This builds the directory and sets its location.
6. Run ``ctest -C Debug -V``  . This runs the given tests (`ctest`), configures it to output the Debug (`-C Debug`), and gives more information in the view than would be given without this command (`-V`).

### Important: If you edit your CMakeLists.txt file, you need to delete your build folder and run steps 3-6 again. If you simply edit a source/test file, you only need to run steps 5-6 again.

## Files included:
- test_example.c
  - Contains basic cmocka testing to get acclimated with the program. Compares integers to one another using the raw values as well as in variables by using boolean, integer, and range assertions. Includes a very simple mocking function, and asserts that it is correctly implemented.
- file.c
  - Contains a function that correctly uses a mocked function in place of an unimplemented one to return a boolean. Links the two files together to simulate this.
- test_file.c
  - Contains the test functions for the above file. Defines and tests the wrapped/mocked function to ensure correct linking and give an example of how mocked functions can be used regardless of if their real counterpart is implemented or not.
