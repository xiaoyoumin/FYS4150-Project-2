## FYS4150 Project 2, Group 66

### NOTE: how to use "Armadillo" library in Visual Studio IDE
1. Download and unzip Armadillo package.
2. Cope `Armadillo_rootDirectory\include` and `Armadillo_rootDirectory\examples\lib_win64` to your Visual Studio root directory. (Root directory of a VS project is the folder which contain `.vcxproj` file)
3. Go to project `properties ==> VC++ directories` in Visual Studio, add `include;` to `Include Directories` and add `lib_win64;` to `Library Directories`.
4. Go to `properties ==> Linker`, add `lib_win64;` to `Additional Library Directories`.
5. Go to `properties ==> Linker ==> Input` add `libopenblas.lib` to `Additional Dependencies`.
6. Done
