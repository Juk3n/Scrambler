A university project we made. Decided to make some improvements. It is a simulator of how scrambling looks like. 
# Scrambler
Scrambler is a device, which encode input data with proper algorithms. This process makes the data more secure from being lost during data transfer.
# Algorithm
In a project we decided to use <b>additive scrambler</b>. This algorithm makes each iteration modulo-two addition. First number is from input data, and the second on is from sync word. The modulo-two sum is the new element of scrambled output.
# Simulation
There are two types of simulation included:
- <i>Simulation with the chance of data loss.</i>
- <i>Simulation with the data loss depended on occurrence.</i><br>

<b>Simulation with the chance of data loss</b> loses bits at randomly, but the probability of losing can be set.<br>
<b>Simulation with the data loss depended on occurrence</b> lose bits when to many same bits are next to each other.
