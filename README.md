cpp-starter-project
===================
Different C++ projects can adopt various directory structures, each with its own merits. There's no definitive answer to what's right or wrong. However, certain needs, such as automated documentation generation, integration with testing frameworks, and CI/CD automation, are typical across projects.

This repository can serve as good starting point for a new C++ project. It's structured to accommodate multiple subprojects, (comprising binaries and libraries) within a central project. Documentation is generated using Doxygen, and Google Test serves as the framework for test cases.

A simple TCP/IP based client-server project is used to an example. It generates `client` and `server` binaries along with `SocketLib` static library.

- Cmake option `-DBUILD_DOC=TRUE/FALSE` is used to control doxygen documentation generation
- Cmake option `-DBUILD_TEST=TRUE/FALSE` is used to control test case generation

### Project Directory structure
```text
project
 |-- docs
 |-- src
      |-- Client  
      |-- Server
      |-- CppSocketLib
 |-- test
```

### Features
The following features position this repository as an excellent starting point for a new C++ project:
- Doxygen based documentation and option to switch ON/OFF using cmake option.
- Test case using google test and option to switch ON/OFF using cmake option.
- Independent versioning system for each subproject
- Check for build type, if not specified fallback to release build.
- Tagging git commit hash id with subproject version

### Usage
You can clone this project into your system using 
```BASH
    git clone git@github.com:rishirahul/cpp-starter-project.git
```
After clone, following instructions can be used to generate build. 
```bash
   # go to project directory
   >  cd  cpp-starter-project.
   # run cmake at <build-path>
   > cmake -S . -B <build-path> -DBUILD_DOC=TRUE -DBUILD_TEST=TRUE
   # create build at <build-path>
   >  cmake --build <build-path>
```

