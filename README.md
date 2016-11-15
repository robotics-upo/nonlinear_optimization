# nonlinear_optimization
Several ROS Packages for nonlinear optimization including levenberg-marquardt, sparse levenberg-marquardt and bundle adjustment.

This package includes the catkinized version of the following well-known nonlinear optimization libraries:

* *levmar* (http://users.ics.forth.gr/~lourakis/levmar/) a levenberg-marquart library for nonlinear optimizaion.
* *sparselm* (http://users.ics.forth.gr/~lourakis/sparseLM/) a sparse levenber-marquart library for nonlinear optimization.
* *cvsba* (https://www.uco.es/investiga/grupos/ava/node/39) a bundle adjutment library with direct integration with openCV

The package also includes three use examples. For details about the API of each library please consult their web.

## General requirements
The source code has been tested in ROS indigo with Ubuntu Lunux 16.04. However, no major requirements are needed except the software packages listed in Dependencies 

## Dependencies
The following linux software packages are required for compilation:
* libsuitesparse-metis-dev
* libsuperlu3-dev
* liblapack-dev
* libblas-dev

They can be easily installed with "sudo apt-get install libsuitesparse-metis-dev libsuperlu3-dev liblapack-dev libblas-dev"

## Compilation
In order to build the package, clone it to the *src* directory of your Catkin workspace and compile it by using *catkin_make* as usual.

