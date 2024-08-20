
---
title: Arduino Line Follower w/ collision detection
author: Tydox
date: 2021-05-08
category: Jekyll
layout: post
---


In my C++ Object Oriented Programming course, our final project was to create a working Monopoly.

# Monopoly in C++ OOP


This project involves creating a console-based game where players navigate a board with various slots that have different effects. The game structure is defined by an input file that specifies the types of slots on the board, and players compete by purchasing properties, managing resources, and making strategic decisions.

## Game Rules

### Gameplay
   - The game is turn-based. At the start of each turn, the player is asked if they want to continue or quit. If a player quits, they are removed from the game.
   - When a player quits, all of their assets are released to the public domain, and any mortgages on their properties are removed.

### Player Setup
   - After loading the board structure, the game prompts the user to enter the number of players and their names.
   - Each player starts with a credit of $350 (this amount can be changed for debugging purposes).

### Player Actions
   - Each player starts at the "Start" slot.
   - The game includes a method to handle debits and credits for a player:
     - If the amount is positive, it is added to the player's balance.
     - If the player has mortgaged properties and the new balance is sufficient, the game will attempt to redeem the properties.
     - If the amount is negative, the player's balance is debited accordingly. If the balance is insufficient, the player's properties will be mortgaged in order of acquisition until the required amount is covered.


### Game Start
   - The game begins by reading the board structure from a file. Each row in the file represents a slot on the board.
   - The structure of a line for an instruction slot (I) in the file is:
     ```
     [slot type = I], [instruction type], [slot name]
     ```
     Example:
     ```
     I,S,start : get $350
     I,T,Get Ticket
     ```
   - The structure of a line for a property slot (P) in the file is:
     ```
     [slot type = P], [city name], [slot name], [price], [rent]
     ```
     Example:
     ```
     P,City1,property1,150,20
     ```



### Game Components

   - `Deck` class manages the collection of cards that players may draw during the game. Each card represents an action or event that impacts the player's status or position on the board.

   - `Player` class represents each participant in the game. It manages the player's current position, balance, properties owned, and other statuses. Players interact with the game board through this class.

   - `Board` class manages the overall structure of the game, including the layout of slots, property ownership, and player positions. It reads from the input file to set up the board and governs the interaction between players and the slots they land on.

   - `Asset` class manages individual properties on the board. It tracks ownership, value, and rental income. This class also handles the mortgaging and redemption of properties when players need to cover debts or sell assets.

   - `GameEngine` class orchestrates the overall flow of the game, controlling the sequence of turns, player interactions, and game logic. It acts as the main controller, ensuring that the rules are followed and that the game progresses smoothly.


   - `Instruction Slot` class, this type of slot provides specific instructions to the player, such as receiving money, moving to another slot, or drawing a card. The `Instruction Slot` class handles the execution of these instructions when a player lands on the slot.

### Other Rules
   - If there is a circular reference (where an asset points to a player and the player has an array of assets), ensure that class declarations are added to the header files to prevent compilation errors.

---


## Screenshots

![]()

---
## Algorithm and flowchats
### Algorithm
![](https://github.com/Tydox/Project7/blob/master/Images/algo-flow.png)
### Class Relationships
![](https://github.com/Tydox/Project7/blob/master/Images/class-relationships.png)
### Simplified workflow
![](https://github.com/Tydox/Project7/blob/master/Images/simple-flow1.png)
![](https://github.com/Tydox/Project7/blob/master/Images/simple-flow2.png)
![](https://github.com/Tydox/Project7/blob/master/Images/simple-flow3.png)


---
