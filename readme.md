## FYS4150 Project 2, Group 66

### NOTE: how to use "Armadillo" library in Visual Studio IDE
1. Download and unzip Armadillo package.
2. Switch project to 'x64'
3. Copy `Armadillo_rootDirectory\include` and `Armadillo_rootDirectory\examples\lib_win64` to project root directory. (Root directory of a VS project is the folder which contain `.vcxproj` file)
4. Copy `Armadillo_rootDirectory\examples\lib_win64\libopenblas.dll` to project root directory.
5. Go to project `properties ==> VC++ directories` in Visual Studio, add `lib_win64;` to `Reference Directories` and `Include Directories`.
6. Go to `properties ==> Linker`, add `lib_win64;` to `Additional Library Directories`.
7. Go to `properties ==> Linker ==> Input` add `libopenblas.lib` to `Additional Dependencies`.
8. Go to `C/C++`, add `include;` to `Additional Include Directories`.
9. Done
