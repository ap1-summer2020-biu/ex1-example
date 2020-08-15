# About the code
## ErrorCode
Other than implementing the obvious, I also added some enum values to the ErrorCode enum, 
namely ERROR\_NO\_MEMORY, ERROR\_MATRIX\_SIZE, and a generic ERROR\_FAILURE.

## Matrix
I didn't add anything to Matrix.h.
The implementaion was nothing out of the ordinary - two unsigned ints for the size of the matrix stored, 
and a pointer to the array of elements(array of doubles).


# Compilation
In the project directory, run the following(on linux):

```
mkdir build
cd build
cmake ../src
make
```

You should probably be able to compile it however you want, but this is what I did, and it works.

This will create libmatrix.so inside build.
