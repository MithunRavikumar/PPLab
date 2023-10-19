
# PP LAB

Basic Instructions to be known while executing the program is given below



## Instructions to execute openmp programs

Compile Instructions 

```bash
  gcc <filename> -fopenmp -o <outputfilename>
```

For math.h
```bash
  gcc <filename> -fopenmp -o <outputfilename> -lm
```
Incase of errors( if it gives c99 is written)

```bash
  gcc <filename> -fopenmp -std=c99
```

FOR OUTPUT
```bash
  ./<outputfilename> <args if any>
```




