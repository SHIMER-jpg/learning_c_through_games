/\*
Init player 1;
Init player 2;

    do
        PlayGame(player1,player2)
    while(Want to play again)


    Play Game
    ---------
        Setup board player 1
        Setup board player 2

        DrawBoard(currentPlayer)

        do
            do
                Prompt player for guess
                Get Valid Guess

            while InvalidGuess

            updateBoards(guess,currentPlayer,OtherPlayer)
            DrawBoard;

            if(a ship was sunk)
                output player sunk something

            wait for key press
            switchplayers
        while !GameIsOver

    Setup Board
    -----------
        Clear Board

        for all the ships

            drawBoard
            Get current ship form loop
            do
                Get board position for head of ship
                Get the ship orientation

                if placement is invalid
                    prompt user to select a valid placement

            while Invalid Placement

            Place Ship on board

    IsValidPlacement
    ----------------
    If orientation is horizontal
        for all the columns the currentShip would take up
            If overlaps or goes of board then return false
                return false
    If orientation is vertical
        for all the rows that the ship would take up
            If overlaps or goes of board then return false
                return false
    Return true


    PlaceShipOnBoard
    ----------------
    ship.position = position
    ship.orientation = orientation

    If orientation is horizontal
        for all the columns the currentShip would take up
            set ship part on the board  at position.row and current column

    If orientation is vertical
        for all the rows that the ship would take up
            set ship part on the board  at position.row and current column

    Update Boards
    ----------------
        if other players ship board at guess is a ship
            set hit on the current players guess board
            apply damage to the other players shipboard
            return shipType
        else
            set miss on current player guess board
            return ST_NONE

    IsGameOver
    ----------
        return AreAllShipsSunk for both players


    AreAllShipsSunk
    ---------------
    for all the players ships
        if !IsSunk!
            return false
    return true

    IsSunk
    ------
    both for horizontal and vertical orietnations
        for all columns that ship takes up
            if the current position is not hit return false

        return true
    */
