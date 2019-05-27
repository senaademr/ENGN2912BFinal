# DV-C
Modelling Accurate Prolate Jellyfish Movement

Ayse Sena Demir (ayse_demir@brown.edu) and Amber Chevannes (amber_chevannes@gmail.com)

ENGN 2912B Scientific Programming in C++ 12/2018

## Introduction

![Jellyfish Cover Image](https://github.com/ENGN2912B-2018/DV-C/blob/master/jellyfish.png)

### - Project Overview
   This project will create a base work for realistic rendering and animating of the movement of a jellyfish model that can be extended or improved utilizing scientific programming techniques in C++. Providing a visual model of animal behavior has potential to improve the development of soft robots. A more physiologically  and environmentally modular model could provide valuable information for creation of soft robots. Our work provides an opportunity for soft robot developers to understand the animal behavior better in visual form and can provide groundwork for better understanding of animal behavior. 
	Game and animation productions has been improving to become more and more realistic as the technology improves both in software computation time and in hardware capabilities. The producers has been looking for opportunities to create realism especially in video game industry to immerse players into games.

### - Goals and Objectives
The goal of this project is to assemble the base work for creating a realistic model of a prolate jellyfish. By combining the work done to model the movement mathematically as well as analyzing video data of a real jellyfish's movement, we are able to lay the ground work for a true realistic model of the jellyfish movement. First extracting the shape of the head of the jellyfish from the video data as well as adding in multiple tentacles for visual accuracy. An observational model of the head contraction and expansion from Diabiri et al., was used to create the baseline animation of the jellyfish movement. The model changes the radius of the head based on a sine function. The model can be further complicated by consulting the video data, as the movement of the jellyfish head is not as simple as the the visual approximation. The final goal of the project is to utilize the data from research partners at Boston Engineering and Dr. Jack Costello's lab to create a physiologically relevant model. By either extracting the shape of individual frames of the jellyfish and morphing the 3D shapes to create an animation.

## Software Architectural Design (as appropriate)
### - Required External Libraries
This project uses Qt, Glew 1.10 and glm and openGL libraries as well as the standard library. The glew library is already included in the source code repository.
### - Functional Block Diagrams

![functional map diagram](https://github.com/ENGN2912B-2018/DV-C/blob/master/functionalmap.png)

## Interface Descriptions (as appropriate)

### - Graphical Interface
The graphical interface consists of a main window that contains the jellyfish scene. The camera in the scene can be zoomed in and out by middle mouse button wheel. Any mouse button pressed and moved will rotate the scene so the jellyfish can be seen from all angles.
### - Data Visualization
The data consists of the object (.obj) file that was created in blender. The team has written a parser to decode the data that is in the format as a vertex represented as "v xCoord yCoord zCoord", a normal represented as "vn xCoord yCoord zCoord" and a face represented as "f firstVertexNumber//firstVertexNormal secondVertexNumber//secondVertexNormal thirdVertexNumber//thirdVertexNormal". A face represents a triangle on the jellyfish model. This data is parsed by readOBJ file in the jellyfish class and the correct parts are sent to openGL through Vertex Buffer Object (VBO) and Vertex Array Object (VAO) classes so the openGL can draw and animate the shape in the shaders.

![Amplitude](https://github.com/ENGN2912B-2018/DV-C/blob/master/Amplitude.png)

Rudolf, Dave, and David Mould. "Animating Jellyfish through Observational Models of Motion." Department of Computer Science (2004).

### - Communications Protocols
Our program does not deal with the transfer of data between computers, processes or threads so there is not description for communication protocols.
### - Threading and Concurrency
### - Exception Handling
The necessary checks were inserted for errors that can happen in the program. Since the user interaction is limited most errors can happen from portability issues. We have implemented the necessary checks for reading files as well as shader reading, linking and compiling issues.

## Testing and Evaluation
### - Operating system(s) and software compiler/library version(s) tested
The project works on Mac OS.
### - Description of functional testing to date
Most of the testing was done visually since the project is very visual oriented. During the writing of the software cout statements was used to ensure the data is read correctly along with error handling. The testing is done by comparing visual videos of jellyfish moving with the movement of the jellyfish in the software.
### - Instructions for compiling and running the software
The software can be run on qtCreator easily by opening the .pro file in the repository or can be run with the commands in the MakeFile in DV-C as well.
The readOBJ and readMaterial takes in absolute paths so tweaking with that code might be necessary to run the program.

## Conclusions
### - Major Accomplishments
The team was able to reach out to researchers in animal movement and soft robotics to get a better understanding of the work done in the past. The current mathematical modeling efforts of jellyfish were surveyed and an approximation method of the animal motion was created. A graphical user interface was create in as well as a model of the jellyfish hood and tentacle was rendered within the scene. An approximation of the jellyfish movement was implemented into an animation. The jellyfish video data from the research partners was analyzed and obj files of the jellyfish hood over time was created.

### - Results of the software development effort
The team was able to produce a rendered scene of the jellyfish with an approximation of the movement animation.

### - Were you successful in meeting all goals and objectives?  What didn't work?  What would take more time?
The team was not successfull in capturing absolutely accurate movement however the team managed to get a good approximation. Working with video data did not work as well as approximating a sine wave for the movement according to the y coordinate and time for xz expansion and contraction. 

## Future Work
### - Description of potential future software expansions and software features
The project has the potential to be extended by utilzing the extracted head shape from the video files to create an animation and ultimately extract a function of the vertices movement of the outer jellyfish head within space. In addition, many functional equations for the flow of water around the jellyfish along with the propulsion of the water within the jellyfish head. Approximations or incorporations of this data within the model could improve the realism. As well as many anatomical features were omitted from the project, so mapping of anatomically relevant colorings or textures to the rendering would also improve the realism.

![3D model of outline](https://github.com/ENGN2912B-2018/DV-C/blob/master/screen1.png)

## Author Contributions
### - Description of each authors' contributions to software development
Ayse Sena Demir - Ayse has coded the GUI for the program, the openGL code for VAO, VBO and the openGL commands, the jellyfish class and the data parser, the shaders for the program and the animation of the jellyfish and the "esen.obj" blender model.

Amber Chevannes - Amber has contacted research partners, extracted the outlines and base 3D shapes from the video datasets, created 3D models to represent the change in the head shape over time.
