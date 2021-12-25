# Fdf

42 Graphic Project - Minilibx

FdF is a 3D Wireframe Viewer.

In this project you I learn about the basics of graphic programming, and in particular how to place points in space, how to join them with segments and most importantly how to observe the scene from a particular viewpoint. I also discover a graphic library called miniLibX. This library was developed internally and includes the minimum necessary to open a window, light a pixel and deal with events linked to this window: keyboard and mouse. This project also introduces you to “events” programming.

## Approach
To draw the different shapes provided by the school or created by myself, I have implemented the bresenham algorithm, which determines the points of an n-dimensional raster that should be selected in order to form a close approximation to a straight line between two points. It is one of the earliest and easiest algorithms developed in the field of computer graphics.

Here you learn about it:

1. https://es.wikipedia.org/wiki/Algoritmo_de_Bresenham
2. https://programmerclick.com/article/6348855911/

## Maps
This is the map format we have to deal to draw the different figures.

0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0

Each number corresponds to a point in space:

1. The horizontal position corresponds to its axis.
2. The vertical position corresponds to its coordinate axis (Y).
3. The value corresponds to its altitude.

## Usage
There are to makefiles created, each one works for a different operating system, if you work with linux rename Makefile_linux to Makefile, if you work with mac rename the other Makefile.

The run ```make```.

The fdf programs is used as follows:

```c
    ./fdf test_maps/42.fdf
```

## Visualizer
42
![42 map](https://github.com/Gon99/fdf/blob/master/42-fdf.png)

Mars
![mars map](https://github.com/Gon99/fdf/blob/master/mars-fdf.png)

Julia (colored)

![julia map](https://github.com/Gon99/fdf/blob/master/julia-fdf.png)
