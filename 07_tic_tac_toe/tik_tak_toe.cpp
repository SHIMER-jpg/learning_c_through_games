// Tic Tac Toe
// ------------

// Write the game of Tic Tac Toe. It's a game with a 3 by 3 grid played by 2 players. 
// One player places O markers and the other player places X markers.
//  Each player takes turns placing his/her marker in order to get 3 of their markers to line up on the board.
//  A player wins when 3 or their markers line up either horizontally, vertically or diagonally.
//  If no player has their markers line up in that fashion, and the board is full, then the game is called a "Cat Game".
//  Your program should output the winner of the game or "Cat Game" if there was no winner.
//  The user should be prompted if they would like to play again when the game is over.
//  If they choose to play again, the player who started second last game should go first.


// We've only learned about linear arrays
// But we need a way to have a board that is 3d

// We can make our linear array act like a 2D grid by having a set index pattern as shown above where index 0 of our array would be the top left element on the board, element 1 would be the top middle element and so on.
//  So the numbers in the 2D grid are the indecies of our array.
//  This will act like a 2D grid even though we only have an array.
