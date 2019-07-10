# Write up

## The effect of PID component 

After printing out the p, i and d component, I realized that the i component cumulates and overtakes the p effect. As a mitigation, I used a exponential smoothing when cumulate the i_error

## Final hyperparameters

### PID values

The intuition of `Kp`, `Ki` and `Kd` are 

`Kp`: Larger `Kp` means we desire more correction from current deviation from the correct direction`

`Ki`: Larger `Ki` means we desire more correction from the cumulative error 

`Kd`: Larger `Kd` means we desire more correction from driving in the wrong direction

At first, I set Kp and Kd to be equal value at 0.3, and Ki to 0.001 because Ki need to be smaller, and realized that the car oscillated too much. That means Kp is too big with respect to Kd. Intuitively, we don't want the car to steer too much more if we are already on the track to returning.

Then I decreased Kp to 0.1 and increased Kd value to 2.0, that made the car drive more normally but there is one exception when the car need to turn sharply, it fails to turn fast enough.

Finally I scaled up both Kp and Kd by 1.5 to Kp=0.15 and Kd=3.0. Now the car is more stable

### Throttle

For throttle, I added a simple exponential function to make the car drive slower when the absolute value of the total error is large.