# CarND-Controls-PID

## Code Implementation

PID control is implemented in `PID.cpp`

## Reflection

There are 3 parameters `Kp`, `Ki`, and `Kd` in PID control, stands for proportional gain, integral gain and differential gain respectively. A brief explaination of the effects is:

|component|Gain|effect|
|:---:|:---:|:---:|
|P "proportional"|Kp|proportional Kp times to the cross track error. When increasing Kp, it will make overshoot increase, raise time decrease, steady state error decrease and system stability degrade|
|I "integral"|Ki|Ki times the integral of cte. When increasing Ki, it will make overshoot increase, raise time decrease, steady state error eliminated and system stability degrade|
|D "differential"|Kd|Kd times to the cte changing rate. when increasing Kd, it will decrease the overshoot and improve system stability|

And here's a good animation show how these component take effects from wikipedia.

![PID demo](https://en.wikipedia.org/wiki/PID_controller#/media/File:PID_Compensation_Animated.gif)


## Parameter Tuning

I do manual tuning for these 3 parameters. Since the simulator have some limitations, for example, once the car getting oscillation, it may be out of the road and cannot back again. So I tried to tune the parameters on straight start part first, then fine tune the turn. The steering value should be `[-1, 1]`, so there's a truncation when doing calculation. I print out the original steer value as a tuning helper cretiera.

1. I tune Kp parameter first, set `[Kp, Ki, Kd] = [1, 0, 0]` as initial start point. Obviously, it's too large that the car quickly get oscillation. I then try to decrease the Kp value to decrease the overshoot until the original steer angle is in between `[-1, 1]`. Finally, `0.1f` seems to be work.
2. Then I add integral part to tune, set `[Kp, Ki, Kd] = [0.1, 1, 0]`. It is obviousely too large Ki, decrease it and seems `0.00001` is a good value.
3. Finally, I use differential part to minimize the overshoot, set `[Kp, Ki, Kd] = [0.1, 0.00001, 1]`. It still have some overshooting, increase the Kd value, and final value is 4.