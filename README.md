# Toothpick floor
A program that answers the question "If you throw a tooth pick on a hard wood floor, what are the odds that the tooth pick will be touching a line between the hard wood floor boards?"

## Assumptions
To answer this questions we first made the assumption that the width of a floor board (distance between the lines) are the same in length as the tooth pick itself. This made the calculations simpler.

## How I solved the problem

### The first thing I did was simplify the problem. 
- I can represent the tooth pick as 2 points, its end points. We will call one end point the start point and the other the end point. 
- We only need to know the y axis of either end points. Why? Lets start with a representation of the floor, we can represent the floor as a 2d grid, and x and y axis. Lets say the x axis runs parallel to the lines in the floor board and the y axis perpendicular. To answer the question "When does the tooth pick touch a line?" its x axis doesn't affect the answer, only its y axis. To prove this, we will demonstrate it with both cases, when the tooth pick touches a line and when it doesn't. When a tooth pick touches a line we can move it across the x axis (parallel to the line) as much as we want and it won't stop touching the line. The same but reverse is true if it started out not touching a line, if we move it across the x axis only it will never start to touch a line. Given this, we can see that only the y axis matters and thus we can simplify our representation of the problem.
- We only use 2 floor board lines in this problem. That's because to answer the question of if the tooth pick is touching a floor board line, only two lines matter. One line that is at the top of the floor board where the start point landed and the other line that is at the bottom of the floor board where the start point landed. We then just need to determine if the end point crossed either of these two lines.

### My coding solution
Now the problem is simplified we can start to solve it. The first thing I do in my code is I randomly calculate the position and angle of the tooth pick, and from that I can determine if its touching a line in the floor. I then run this experiment a bunch and through statistics I can predict the probability of throwing a tooth pick on the ground will touch a line in the hard wood floor.

- Calculating the start point position: I randomly generate a number between 0 and 1, this gives us the y coordinate of the start point.

- Calculating the angle of the tooth pick: I randomly generate a number between 0 and 2pi. This represents the angle of the tooth pick in radians.

- Calculating the end point position: I use the start point position and the angle that I got in the two previous steps and using the sin() function I'm able to determine the end point position. I do this by getting the adding the start point to the sin(angle) of the end point to determine the end points y coordinate.

- Determining if the tooth pick crosses a line: I then check the coordinate of both the start and end point to determine if its crossed a line. If so I update a counter.

- At the end, when I've collected all my data I can then determine an estimate to answer the question "If you throw a tooth pick on a hard wood floor, what are the odds that the tooth pick will be touching a line between the hard wood floor boards?" Note that this method doesn't find an exact probability but it does get close to the actual probability through lots of samples, in other words it uses statistics to estimate the probability.



