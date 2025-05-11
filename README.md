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

* This application can read text files containing multiple numeric arrays, where arrays are delimited by whitespaces or commas

* Prints input arrays

* Sorts arrays using the Quick Sort algorithm.

* Finds intersections between the two longest arrays and among all input arrays

* Identifies unique elements in the input arrays and outputs them in reverse order

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
* Target file that needs to be processed

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
* Finds intersections between the two longest arrays and among all input arrays

#### Unique-reverse
```
-unique-rev
```
* Finding unique elements in all input arrays and outputs them in reverse order

> [!NOTE]
> If only `-target <file>` is specified, all operations (print, sort, intersect, unique-reverse) will be executed sequentially.

## Tests

The `tests` folder contains scripts that execute the application with various argument options. After running a test, check the `output` folder to review the application's output.

> [!IMPORTANT]
> To perform tests, you need to build application first. Also tests depends on `input.txt` to match `expected_output` files.

