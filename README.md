# Array Sorter (Transformer) Task

## Build (Windows)

1. Download and install [MSYS 2](https://www.msys2.org/).
2. Startup "MSYS2 UCRT64" and execute the following commands:

    #### Update all packages

    ```
    pacman -Syu
    ```

    #### Install dependencies

    ```
    pacman -S "git" "mingw-w64-ucrt-x86_64-cmake"
    ```

3. Clone repo

    Make sure that you have [git](https://git-scm.com/) installed on your system, then use following commands:

    ```
    git clone https://github.com/S0ulM1ke/Array_Sorter_Task.git
    cd Array_Sorter_Task
    ```

4. Build

    #### Configure project

    ```
    cmake -B build -G Ninja -S .
    ```

    #### Build

    ```
    ninja -C build
    ```
When steps done you'll be ready to use application `ArraySorterTask.exe` located in `build` folder.

## Features

* This application is capable of reading text files that contain multiple numeric       arrays delimed by whitespaces and comas

* Prints input arrays

* Sorting arrays by `quick sort`.

* Finding intersections between two longest arrays and between all input arrays

* Finding unique elements in input arrays and place them in reverse order

### Command line arguments

#### Help
    
```
-help
```
* Prints out all available options

#### Target file
```
-target <file> (required)
```

##### Example:

```
ArraySorterTask.exe -target input_arrays.txt
```
* Target file that needs to be proceeded

#### Print
```
-print
```
* Prints parsed arrays from the input document to the output

#### Sort
```
-sort
```
* Sorts input arrays by `quick sort` algorithm

#### Intersection
```
-intersect
```
* Finding intersection between two longest arrays and between all input arrays

#### Unique-reverse
```
-unique-rev
```
* Finding unique elements in all input arrays and reverse it

> [!NOTE]
> If `-target <file>` is specified only, all operations below would be executed

## Tests

In `tests` folder you can find different kind of scripts that executes application within the different argument options. After test completes you can find `output` folder to inspect application output.

> [!IMPORTANT]
> To perform tests, you need to build application first. Also tests depends on `input.txt` to match `expected_output` files.

