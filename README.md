# Halma-Game-Playing-Agent
Each player starts with 19 game pieces clustered in diagonally opposite corners of the board. To win the game, a player needs to transfer all of their pieces from their starting corner to the opposite corner, into the positions that were initially occupied by the opponent. Note that this original rule of the game is subject to spoiling, as a player may choose to not move some pieces at all, thereby preventing the opponent from occupying those locations. Note that the spoiling player cannot win either (because some pieces remain in their original corner and thus cannot be used to occupy all positions in the opposite corner). Here, to prevent spoiling, we modify the goal of the game to be to occupy all of the opponent’s starting positions which the opponent is not still occupying.

Setup for two players:
- Simple wooden pawn-style playing pieces, often called "Halma pawns."
- The board consists of a grid of 16×16 squares.
- Each player's camp consists of a cluster of adjacent squares in one corner of the board.
These camps are delineated on the board.
- For two-player games, each player's camp is a cluster of 19 squares. The camps are in
opposite corners.
- Each player has a set of pieces in a distinct color, of the same number as squares in each
camp.
- The game starts with each player's camp filled by pieces of their own color.

BBBBB...........

BBBBB...........

BBBB............

BBB.............

BB..............

................

................

................

................

................

................

..............WW

.............WWW

............WWWW

...........WWWWW

...........WWWWW

Here B denotes player one and W denotes player 2

1. Moving pieces: 
a) Players cannot make a move that starts outside their own camp and causes one of their
pieces to end up in their own camp.
b) If a player has at least one piece left in their own camp, they have to move a piece out of their camp (i.e. at the end of the whole move the piece ends up outside of their camp). If that’s not possible, move a piece in their camp further away from the corner of their
own camp ([0,0] or [15,15] respectively). Only if the player does not have any pieces left in their camp or none of the two alternatives
above are possible are they free to move pieces outside of their camp.
Note: To move “further away”, you should simply move so that you either move further away
horizontally (while not moving closer vertically), or vertically (while not moving closer
horizontally), or both.

Each player's turn consists of moving a single piece of one's own color in one of the
following plays:
a) One move to an empty square:
    Move the piece to an empty square that is adjacent to the piece’s original
    position (with 8-adjacency).
    This move ends the play for this player’s turn.
b) One or more jumps over adjacent pieces:
    An adjacent piece of any color can be jumped if there is an empty square
    on the directly opposite side of that piece.
    Place the piece in the empty square on the opposite side of the jumped
    piece.
    The piece that was jumped over is unaffected and remains on the board.
    After any jump, one may make further jumps using the same piece, or end
    the play for this turn.
    In a sequence of jumps, a piece may jump several times over the same
    other piece.
    Once a piece has reached the opposing camp, a play cannot result in that piece leaving
    the camp.
If the current play results in having every square of the opposing camp that is not already
occupied by the opponent to be occupied by one's own pieces, the acting player wins.
Otherwise, play proceeds to the other player.

Input:
First Line: GAME or SINGLE
Second Line: A string BLACK or WHITE indicating which color you play
Third Line: A strictly positive floating point number indicating the amount of total play time
remaining for your agent.
Next 16 lines: Description of the game board, with 16 lines of 16 symbols each

Output:
1 or more lines: Describing your move(s). There are two possible types of moves
1. E FROM_X,FROM_Y TO_X,TO_Y – your agent moves one of your pieces from location
FROM_X, FROM_Y to adjacent empty location TO_X, TO_Y.
2. J FROM_X,FROM_Y TO_X,TO_Y – your agent moves one of your pieces from location
FROM_X,FROM_Y to empty location TO_X,TO_Y by jumping over a piece in between.
