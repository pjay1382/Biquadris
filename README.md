# Biquadris
The Game of Biquadris
In this project, your group will work together to produce the video game Biquadris, which is a Latinization of the game Tetris, expanded for two player competition.
A game of Biquadris consists of two boards, each 11 columns wide and 15 rows high. Blocks consisting of four cells (tetrominoes) appear at the top of each board,  and you must drop them onto their respective boards so as not to leave any gaps. Once an entire row has been filled, it disappears, and the blocks above move down by one unit.
Biquadris differs from Tetris in one significant way: it is not real-time. You have as much time as you want to decide where to place a block.  Players will take turns dropping blocks,  one at a time. A player’s turn ends when he/she has dropped a block onto the board (unless this triggers a special action; see below). During a player’s turn, the block that the opponent will have to play next is already at the top of the opponent’s board (and if it doesn’t fit, the opponent has lost).
The major components of the system are as follows:

### Blocks
There are seven types of blocks (I, J, L, O, S, Z and T).

### Board
The board should be 11 columns and 15 rows. Reserve three extra rows (total 18) at the top of the board to give room for blocks to rotate, without falling off the board. If a block is at the extreme right-hand side of the board, to the extent that there is no horizontal room to rotate it, it can’t be rotated.
When a block shows up on the board, it appears in the top-left corner, just below the three reserve rows, such that the bottom row of the block occupies the row below the reserve rows (so, for example, a horizontal I block would use none of the reserve rows, while a vertical I block would use all of them). If there is not room for the block in this position, the game is over.
When a block is dropped onto the board, check to see whether any rows have been completely filled as a result of the block having dropped. If so, remove those rows from the board, and the remaining blocks above these rows move down to fill the gap.

### Display
You need to provide both a text-based display and a graphical display of your game board. 
 
### Next Block
Part of your system will encapsulate the decision-making process regarding which block is selected next. The level of difficulty of the game depends on the policy for selecting the next block. You are to support the following difficulty levels:
- Level 0: (Make sure you at least get this  one  working!)  Takes its blocks in sequence from the files biquadris sequence1.txt (for player 1) and biquadris sequence2.txt (for player 2) (samples are provided), or from other files, whose names are supplied on the com- mand line. If you get to the end of one of these files, and the game hasn’t ended yet, begin reading the file again from the beginning. This level is non-random, and can be used to test with a predetermined set of blocks. Make sure that sequence[1-2].txt, and any other sequence files you intend to use  with  your  project,  are  submitted  to  Marmoset along with your code.
-	Level 1: The block selector will randomly choose a block with probabilities skewed such that
S and Z blocks are selected with probability 1 each, and the other blocks are selected with
probability 1 each.
-	Level 2: All blocks are selected with equal probability.
-	Level 3: The block selector will randomly choose a block with probabilities skewed such that
S and Z blocks are selected with probability 2 each, and the other blocks are selected with probability 1 each. Moreover, blocks generated in level 3 are “heavy”: every command to move or rotate the block will be followed immediately and automatically by a downward move of one row (if possible).
-	Level 4: In addition to the rules of Level 3, in Level 4 there is an external constructive force: every time you place 5 (and also 10, 15, etc.) blocks without clearing at least one row, a 1x1 block (indicated by * in text, and by the colour brown in graphics) is dropped onto your game board in the centre column. Once dropped, it acts like any other block: if it completes a row, the row disappears. So if you do not act quickly, these blocks will work to eventually split your screen in two, making the game difficult to play.
Each player is free to choose his/her own level independently. The lower levels produce a greater percentage of “easier” blocks, but the corresponding scores are also lower.

### Special Actions
If a player, upon dropping a block, clears two or more rows simultaneously, a special action is triggered. A special action is a negative influence on the opponent’s game. When a special action is triggered, the game will prompt the player for his/her chosen action. Available actions are as follows:

-	blind: The player’s board, from columns 3-9, and from rows 3-12, is covered with question marks (?), until the player drops a block; then the display reverts to normal. 
-	heavy: Every time a player moves a block left or right, the block automatically falls by two rows, after the horizontal move. If it is not possible for the block to drop two rows, it is considered to be dropped,  and the turn ends.   If the player is already in a level in which blocks are heavy, the effect is cumulative (i.e., the player suffers from both effects).
-	force: Change the opponent’s current block to be one of the player’s choosing. If the block cannot be placed in its initial position, the opponent loses. (E.g., force Z)


### Command Interpreter
You interact with the system by issuing text-based commands. The following commands are to be supported:
-	left: moves the current block one cell to the left. If this is not possible (left edge of the board, or block in the way), the command has no effect.
-	right: as above, but to the right.
-	down: as above, but one cell downward.
-	clockwise: rotates the block 90 degrees clockwise, as described earlier. If the rotation cannot be accomplished without coming into contact with existing blocks, the command has no effect.
-	counterclockwise: as above, but counterclockwise.
-	drop: drops the current block. It is (in one step) moved downward as far as possible until it comes into contact with either the bottom of the board or a block. This command also triggers the next block to appear. Even if a block is already as far down as it can go (as a result of executing the down command), it still needs to be dropped in order to get the next block.
-	levelup: Increases the difficulty level of the game by one.  The block showing as next still comes next, but subsequent blocks are generated using the new level. If there is no higher level, this command has no effect.
-	leveldown: Decreases the difficulty level of the game by one. The block showing as next still comes next, but subsequent blocks are generated using the new level. If there is no lower level, this command has no effect.
-	norandom: file Relevant only during levels 3 and 4, this command makes these levels non- random, instead taking input from the sequence file, starting from the beginning. This is to facilitate testing.
-	random: Relevant only during levels 3 and 4, this command restores randomness in these levels.
-	sequence file: Executes the sequence of commands found in file. This is to facilitate the construction of test cases.
-	I, J, L, etc.: Useful during testing, these commands replace the current undropped block with the stated block. Heaviness is detemined by the level number. Note that, for heavy blocks, these commands do not cause a downward move.
-	restart: Clears the board and starts a new game. End-of-file (EOF) terminates the game.

The board should be redrawn each time a command is issued.

### Scoring
The game is scored as follows: when a line (or multiple lines) is cleared, you score points equal to (your current level, plus number of lines) squared. (For example, clearing a line in level 2 is worth 9 points.) In addition, when a block is completely removed from the screen (i.e., when all of its cells have disappeared) you score points equal to the level you were in when the block was generated, plus one, squared. (For example if you got an O-block while on level 0, and cleared the O-block in level 3, you get 1 point.)
 
You are to track the current score and the hi score.  When the current score exceeds the hi score, the hi score is updated so that it matches the current score. When the game is restarted, the current score reverts to 0, but the hi score persists until the program terminates.

### Command-line Interface
Your program should support the following options on the command line:
-	-text: runs the program in text-only mode. No graphics are displayed. The default behaviour (no -text) is to show both text and graphics.
-	-seed xxx: sets the random number generator’s seed to xxx. If you don’t set the seed, you always get the same random sequence every time you run the program. It’s good for testing, but not much fun.
-	-scriptfile1 xxx: Uses xxx instead of sequence1.txt as a source of blocks for level 0, for player 1.
-	-scriptfile2 xxx: Uses xxx instead of sequence2.txt as a source of blocks for level 0, for player 2.
-	-startlevel n: Starts the game in level n. The game starts in level 0 if this option is not supplied.
