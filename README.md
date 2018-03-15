# Training Simulator Test

I have found an issue with the collision detection that I need to fix. It seems like SFML uses non-rotating bounding boxes for collision detection which means that rectangles at an angle will not collide correctly. This is very noticable with lines that are not at right angles. 
