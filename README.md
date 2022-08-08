# Artillery-Project
A C++ Program that creates a visual depiction of a launched artillery shell

Program Description
One of the early uses of computers was to compute ballistic "firing tables" that were published in gunnery manuals. These tables predicted where an artillery shell would land under a given set of firing conditions. Our job over the next several weeks is to simulate the firing of an artillery shell with such a degree of accuracy that we can predict how long it will be in the air and were it will land.

M777 Howitzer
The M777 155mm Ultralightweight Field Howitzer (pronounced the "triple 7") is the most important artillery piece in the US military arsenal.

M777 155mm Ultralightweight Field Howitzer
The M777 howitzer has a muzzle velocity (the speed of the shell when it leaves the howitzer) of 827.0 m/s. Though it can fire at virtually any angle, the most common trajectory is greater than 45°. The main ammunition for the M777 is the M795 projectile.

M795 Projectile
The M795 High Explosive 155mm artillery projectile is the most commonly used ammunition for the M777. It weighs 46.7 kg and has a diameter of 154.89 mm.

M795 155mm High Explosie 155mm artillery projectile
As the projectile flies through the air, it is subject to drag due to wind resistance. There are several equations related to the drag of the projectile:

Name	Equation	Variables
Drag Force Equation	d = ½ c ρ v2 a	
d = force in newtons (N)
c = drag coefficient
ρ = density of the fluid/gas
v = velocity of the projectile
a = surface area
Area of a circle	a = π r 2	
a = area of a circle (m2)
r = radius of a circle
Newton's second law of motion	f = m a	
f = force in newtons (N)
m = mass in kilograms (kg)
a = acceleration (m/s2)
The drag coefficient of the M795 projectile varies quite a bit according to the speed in which it travels. Note that the speed is in Mach or multiples of the speed of sound.

Drag Coefficient of the M795 projectile
The same data in tabular format is the following:

Mach	Drag Coefficient
0.300	0.1629
0.500	0.1659
0.700	0.2031
0.890	0.2597
0.920	0.3010
0.960	0.3287
0.980	0.4002
1.000	0.4258
1.020	0.4335
1.060	0.4483
1.240	0.4064
1.530	0.3663
1.990	0.2897
2.870	0.2297
2.890	0.2306
5.000	0.2656

Environmental Factors
The density of air (ρ) varies according to altitude. Generally speaking, there is less air the greater the altitude:

Density of air according to altitude
The same data in tabular format is the following:

Altitude (m)	Density (kg/m2)
0	1.2250000
1000	1.1120000
2000	1.0070000
3000	0.9093000
4000	0.8194000
5000	0.7364000
6000	0.6601000
7000	0.5900000
8000	0.5258000
9000	0.4671000
10000	0.4135000
15000	0.1948000
20000	0.0889100
25000	0.0400800
30000	0.0184100
40000	0.0039960
50000	0.0010270
60000	0.0003097
70000	0.0000828
80000	0.0000185

The speed of sound also varies with altitude. Recall that the speed of sound is 1.0 Mach.

Speed of sound according to altitude
The same data in tabular format is the following:

Altitude (m)	Speed of Sound (m/s)
0	340
1000	336
2000	332
3000	328
4000	324
5000	320
6000	316
7000	312
8000	308
9000	303
10000	299
15000	295
20000	295
25000	295
30000	305
40000	324

Finally, the force of gravity varies almost linearly according to altitude:

Gravity according to altitude
The same data in tabular format is the following:

Altitude (m)	Gravity (m/s2)
0	9.807
1000	9.804
2000	9.801
3000	9.797
4000	9.794
5000	9.791
6000	9.788
7000	9.785
8000	9.782
9000	9.779
10000	9.776
15000	9.761
20000	9.745
25000	9.730
Geometry
Since we are building a physics simulator, there are few equations we need to know:

Name	Equation	Variables

Degrees and Radians	r / 2 π = d / 360°	

r = angle in radians

π = pi, about 3.14159

d = angle in degrees

Vertical component of speed	dy = s cos(a)	

dy = vertical component of speed (m/s)

s = overall speed (m/s)

a = direction of travel where 0 is pointing up (radians)

Horizontal component of speed	dx = s sin(a)	

dx = vertical component of speed (m/s)

s = overall speed (m/s)

a = direction of travel where 0 is pointing up (radians)

Angle from components	a = atan(dx, dy)	

a = directon of travel where 0 is pointing up (radians)

dx = horizontal component of speed (m/s)

dy = vertical component of speed (m/s)

Pythagorean Theorem	dx2 + dy2 = s2	

dx = horizontal component of speed (m/s)

dy = vertical component of speed (m/s)

s = overall speed (m/s)

Linear Interpolation	
(r - r0)(d - d0) = (r1 - r0)(d1 - d0)
d0,r0 = coordinates of one point
d1,r1 = coordinates of a second point
d,r = coordinates of a point in the middle
This last equation (linear interpolation) is key. Consider the air density table. The following is a short excerpt:

Altitude (m)	Density (kg/m2)
0	1.2250000
1000	1.1120000
If we are trying to find the air density at 200m, it is going to fall somewhere between 1.225 and 1.112. We can find this answer by using linear interpolation:

d0,r0 = 0, 1.225
d1,r1 = 1000, 1.112
d = 200
We plug these values into the linear interpolation equation to get:(r - 1.225)/(d - 0) = (1.112 - 1.225) / (1000 - 0). Using algebra, we can solve for d and get the density of the air at 200m. Thus we can find the drag of the projectile, speed of sound, air temperature, and force of gravity for any altitude. This works even if the altitude we need is not in the provided table.

