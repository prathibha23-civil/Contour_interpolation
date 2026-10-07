# Project 10: Contour Interpolation from Grid Levelling 

## Project Overview

This project is a C program developed for Civil Engineering surveying applications to determine contour interpolation points from Reduced Level (RL) data arranged in a regular grid.

The program uses linear interpolation to determine the approximate position of a specified contour between two grid points having different Reduced Levels.

## Aim

To develop a C program to determine contour interpolation points from grid levelling data using linear interpolation.

## Objectives

- To store Reduced Level (RL) data using a two-dimensional array.
- To determine the minimum and maximum RL values.
- To accept grid spacing in X and Y directions.
- To accept the contour interval.
- To identify the required contour levels.
- To check horizontal and vertical grid edges.
- To calculate contour interpolation points using linear interpolation.
- To determine the X and Y coordinates of interpolation points.
- To avoid storing duplicate contour points.
- To display the final contour interpolation points.
## Civil Engineering Concept

### Grid Levelling

In grid levelling, an area is divided into a regular grid and the Reduced Level (RL) of each grid point is determined.

### Contour

A contour is a line joining points having the same elevation or Reduced Level.

### Contour Interpolation

Contour interpolation is the process of determining the approximate position of a required contour between two points having different RL values.

## Linear Interpolation

The program uses linear interpolation to determine the position of a contour between two grid points.

The fractional position is calculated using:

t = (C - RL1) / (RL2 - RL1)

Where:

- C = Required contour RL
- RL1 = RL of the first grid point
- RL2 = RL of the second grid point
- t = Fractional position between the two points

The coordinates are calculated using:

x = x1 + t(x2 - x1)

y = y1 + t(y2 - y1)

## Programming Concepts Used

- C programming
- Functions
- Function calling
- Two-dimensional arrays
- One-dimensional arrays
- for loops
- if conditions
- printf() and scanf()
- double data type
- Linear interpolation
- Mathematical functions
- Duplicate point checking
- Input validation

## Functions Used

### 1. displayGrid()

Displays the Reduced Level grid in a formatted manner.

### 2. isDuplicate()

Checks whether a contour interpolation point has already been stored.

### 3. addPoint()

Stores a new contour interpolation point if it is not a duplicate.

### 4. interpolate()

Calculates the position of a contour between two grid points using linear interpolation.

### 5. findContours()

Checks the required contour levels and examines horizontal and vertical grid edges to find contour interpolation points.

### 6. main()

Controls the complete execution of the program by accepting input, validating the input, finding minimum and maximum RL values, displaying the grid and calling the contour interpolation function.

## Program Flow

Start  
↓  
Enter number of rows and columns  
↓  
Enter grid spacing  
↓  
Enter RL values  
↓  
Find minimum and maximum RL  
↓  
Enter contour interval  
↓  
Display RL grid  
↓  
Select contour levels  
↓  
Check horizontal grid edges  
↓  
Check vertical grid edges  
↓  
Perform linear interpolation  
↓  
Calculate X and Y coordinates  
↓  
Check for duplicate points  
↓  
Store unique contour points  
↓  
Display contour interpolation points  
↓  
Stop

## Test Input

The program was tested using RL data obtained from surveying observations and arranged as a regular grid.

- Number of rows = 7
- Number of columns = 5
- X spacing = 5 m
- Y spacing = 2 m
- Contour interval = 0.1 m

### RL Grid

```text
99.995   99.830   99.705   99.725   99.935
99.660   99.740   99.780   99.760   99.935
99.550   99.635   99.770   99.800   99.760
99.605   99.665   99.690   99.805   99.830
99.495   99.580   99.775   99.810   99.825
100.055  100.010  99.705   100.000  100.080
100.415  100.280  99.855   100.000  100.430
```

## Output

The program calculates the minimum RL, maximum RL and contour interpolation points for each required contour level.

Example output:

```text
Minimum RL = 99.50 m
Maximum RL = 100.43 m
Contour Interval = 0.10 m

Contour Interpolation Points:
------------------------------------------
Contour 99.50 m : Interpolation Point (...)
Contour 99.60 m : Interpolation Point (...)
Contour 99.70 m : Interpolation Point (...)
Contour 99.80 m : Interpolation Point (...)
Contour 99.90 m : Interpolation Point (...)
Contour 100.00 m : Interpolation Point (...)
Contour 100.10 m : Interpolation Point (...)
Contour 100.20 m : Interpolation Point (...)
Contour 100.30 m : Interpolation Point (...)
Contour 100.40 m : Interpolation Point (...)
```

## Applications

- Topographical surveying
- Terrain mapping
- Site planning
- Road alignment
- Railway alignment
- Canal alignment
- Drainage planning
- Earthwork estimation
- Land development
- Preparation of contour maps

## Limitations

- The program assumes linear variation of RL between two neighbouring grid points.
- Accuracy depends on the accuracy of the input RL values.
- The program works with a regular grid.
- The program determines interpolation points but does not automatically draw the final contour map.
- Complex terrain may require a denser grid and more accurate surveying data.

## Future Improvements

- Automatically connect interpolation points to form contour lines.
- Generate a graphical contour map.
- Add support for irregularly spaced points.
- Export contour coordinates to CSV files.
- Add graphical visualization.
- Develop a user-friendly interface.

## Learning Outcome

Through this project, I learned how C programming can be applied to a practical Civil Engineering surveying problem.

I gained experience in:

- Handling two-dimensional arrays
- Creating and using functions
- Applying mathematical formulas in C
- Performing linear interpolation
- Working with surveying RL data
- Managing floating-point calculations
- Removing duplicate results
- Organizing a complete C project

## Data Source

The RL values used for testing were obtained from surveying observations and calculations. The resulting RL values were arranged as a regular grid based on the station and cross-section spacings and were then used as input for the contour interpolation program.

## Author

**Prathibha Siripurapu**

Civil Engineering Student  
Vasavi College of Engineering, Hyderabad
