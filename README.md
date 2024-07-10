## Important:
- To install/run CMocka, refer to the README.md in the main repository (khaws_internship). This also has more general information on the tasks carried out during my internship (May-July 2024).

### How to run a test:
1. Go into the folder where you have your test files. For example, in the GEKI project, this is "test."
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
