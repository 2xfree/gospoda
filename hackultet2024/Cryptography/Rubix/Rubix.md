# Rubix (80 points)

For this task we had to rotate the rubix cube as shown in 
rubix_dokumentacija.pdf file. First rotation was F' 
(front counter-clockwise) and after that the cube looked like this:

![first rotation](challenge_files/first_rotation.png "First rotation")

After that we had to do the L (left side down) rotation:

![second rotation](challenge_files/second_rotation.png "Second rotation")

And finally the U (up to the left) rotation:

![third rotation](challenge_files/third_rotation.png "Third rotation")

Because we had some duplicates we had to switch them with missing
characters (sorted from biggest to smallest) going from left to right.
After that was done we got this square (with normal square to the right):

![final square](challenge_files/final_square.png "Final square")

Now we had to decrypt the flag XIFZNZA[NYZAZAA5TMAM], we know that 
the flag starts with "CTF2024" so we already knew some characters
(X->C, I->T, F->F, Z->2, N->0, A->4) and we had to find the rest.
N->0
Y->8
5->3
T->1
M->6

So the flag is:
CTF2024[082424431646]

No clue how X->C, though.
