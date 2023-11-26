# Programming Assignments Menu Selection For Professor 
###### Implemented a menu selection for ungraded work to make repo more user friendly since I included have put unnecessary files 


_______________________________
<details>
  <summary>Module 1</summary>

- ##### Assignment 1 Part 1
  > [Pointer Anti-patterns](https://github.com/spnorrington/cs372.norris/tree/main/apps/assignment1PartA)

- ##### Assignment 1 Part 2
  > [Hanoi Files](https://github.com/spnorrington/cs372.norris/tree/main/apps/hanoi)
  > 
  > [CMake File](https://github.com/spnorrington/cs372.norris/blob/main/apps/hanoi/CMakeLists.txt)
  > 
  > [Results](https://github.com/spnorrington/cs372.norris/blob/main/apps/hanoi/results.txt)
</details>

_______________________________
<details>
  <summary>Module 2</summary>

- ##### Assignment 2 Part 1
  > [vector.hpp](https://github.com/spnorrington/cs372.norris/blob/a3b082d36d74d7cd5bf7c78273a63eabb72c884c/include/vector.hpp)
  > 
  > [stlvectest.cpp](https://github.com/spnorrington/cs372.norris/blob/a3b082d36d74d7cd5bf7c78273a63eabb72c884c/apps/stlvectortest/stlvectest.cpp)
  > 
  > [CMakeLists.txt](https://github.com/spnorrington/cs372.norris/blob/a3b082d36d74d7cd5bf7c78273a63eabb72c884c/apps/stlvectortest/CMakeLists.txt)

- ##### Assignment 2 Part 2
  > [Array Class](https://github.com/spnorrington/cs372.norris/blob/main/include/ArrayClass.hpp)
  > 
- ##### Assignment 2 Part 3
  > [vector.hpp](https://github.com/spnorrington/cs372.norris/blob/a3b082d36d74d7cd5bf7c78273a63eabb72c884c/include/vector.hpp)
  > 
  > [bagwithreceipt](https://github.com/spnorrington/cs372.norris/blob/main/include/receiptbag.hpp)
  > 
  > [testbagwithreceipts](https://github.com/spnorrington/cs372.norris/blob/main/apps/BagWithReceipts/testreceiptbagclass.cpp)
  > 
  > [CMake](https://github.com/spnorrington/cs372.norris/blob/main/apps/BagWithReceipts/CMakeLists.txt)
</details>

_______________________________
<details>
  <summary>Module 3</summary>


- ##### Assignment 3 Part 1
  > [List.h](https://github.com/spnorrington/cs372.norris/blob/main/include/List.h)
  > 
  > [listtest.cpp](https://github.com/spnorrington/cs372.norris/blob/main/apps/listtest/listtest.cpp)
  > 
  > [CMake](https://github.com/spnorrington/cs372.norris/blob/main/apps/listtest/CMakeLists.txt)

</details>

_______________________________

<details>
  <summary>Module 4</summary>
  
- ##### Assignment 4 Part 1
> [Hot Potatoe](https://github.com/spnorrington/cs372.norris/blob/main/apps/hotpotato/hotpotato.cpp)
>

- ##### Assignment 4 Part 2
> [Sequential Container](https://github.com/spnorrington/cs372.norris/blob/main/include/SequenceContainer.hpp)
> 

</details>

_____________________________________
  
<details>
  <summary>Module 8</summary>

- ##### Assignment 9 Part 1
> [Quicksortt Test](https://github.com/spnorrington/cs372.norris/blob/main/apps/quicksorttest.cpp)
>
> [QuickSort Template Function Version of Quicksort](https://github.com/spnorrington/cs372.norris/blob/main/include/quicksort.hpp)
>

</details>

_______________________________
CS372 Documents
==================================
This folder is for any documents you need to produce for the class.
For example, some assignments will ask your either theory or
interpretation questions.   You will put documents containing your
answer in this folder.

# Folder Structure

The folders in this repository are organized so that you can use CMake
to build for your favorite platform and IDE. 

The three top-level folders:
- `apps`: Applications go here.  A sample application named `listtest`
  is located in this folder and can be used as a template for
  assignments.
- `include`:  Header files will go here.  The `CMake` sample
  applications in the `apps` folder are setup to get the header files
  from this folder.
- `docs`: Here's where documentation such as this file will live.
  Certain assignments will ask you to collect and report data on the
  programs you've written.  Document that information in this folder.
  
# Working with `CMake`

`CMake` is a command-line utility.  However, it is aware of the common
IDEs such as Visual Studio, Code::Blocks, Xcode, and others.  CMake is
included as part of the extensions for Visual Studio and Visual Studio
Code.  If you're working with the full version of Visual Studio,  use
the links to the PowerShell CLI installed by Visual Studio.  MacOS users
will need to use the HomeBrew package manager to install `CMake`.

## Building with `CMake`

From the command-line, you first need to execute `CMake` to build the
"build system" for your application:

```sh
cmake -S . -B build.windows
```

This command looks for the CMake data files and your source code in the
current folder (the `-S` option on the "dot" folder) and creates the
build files in a folder named "build.windows".   Nothing specific about
this name, just a convention Your Glorious Instructor uses to keep
things organized.

Then you can build your application with the command:

```sh
cmake --build build.windows
```

If you're running on Windows, `Cmake` understands the Microsoft Build
format and will create Visual Studio project files for you.  Just point
Visual Studio at that folder.    

