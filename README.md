# LANPARTY

## Objectives

- Understand the concept of operation and implementation of various data structures (such as lists, stacks, queues, binary search trees)
- Work with these data structures
- Implement a practical functionality using these concepts

## Description

The Faculty of Automation and Computers, through LSAC, organizes a LAN Party every semester, where all students who want to test their skills in a specific game can participate. The goal is to develop a software solution (an executable program) that can automate this process.

## Requirements

1. A list will be created with the information from the file d.in (the list will be formed by adding elements at the beginning - O(1)).
2. Teams with the lowest team score will be removed from the previously created list (information about how this score is calculated is found in the "Technical Details" section), leaving only n teams in the list (where n is the maximum and n is a power of 2). If multiple teams have the same score, the first team found in the list will be removed. After each removal, the list traversal will start again from the beginning.
3. The necessary data structures will be implemented to conduct the matches:
    - A queue will be created to hold the matches between teams.
    - Teams will form matches in the order they appear in the list from the previous step, with the first two teams forming the first match (and so on).
    - Two stacks will be created – one for losers and one for winners – containing the teams that lost and won the previous match, respectively.
    - Teams will be added to the stack based on their match results, and one point will be added to the team score of the winning teams.
    - In the case of a match where both teams have the same score, the first team added to the match will be chosen.
    - The teams in the losers' stack will be deleted (at the end of each round; for example, in a round with 8 teams, the deletion happens after all the teams have been eliminated. In this case, after 4 teams have been eliminated, they will be deleted. In the next round, on this example, 2 teams will be added to the losers' stack, and then it will be emptied again).
    - From the winners' stack, teams will be extracted, and the match queue will be refilled, forming new matches with consecutive teams (the first team extracted from the stack will play the first match with the second team extracted).
    - The enumerated steps will be repeated until the top 8 teams are determined, which will be saved in another list. After identifying the top 8, the matches will continue until the winning team is determined.
## Tehnical details
- The results obtained after executing the requirements from the file c.in will be written to the file r.out.
For requirements 1 and 2, it is enough to write the names of the teams, in the order from the created list, on separate lines in the result file.
- For requirement 3, in each round, the contents of the match queue will be written to the file, along with the contents of the winners' stack.

- The necessary data structures should be deduced to follow good implementation practices. For example, a player has a first name, last name, and experience points, so a data type that characterizes this entity should be used. (The same principle applies to other data types necessary for the application).

## Restrictions

- The implementation must be done using the C programming language.
- The implementation must use lists. It is not allowed to use arrays to implement the stacks, queues, or the list of participating teams. It is recommended to use pointers and free memory.
- Avoid duplicating nodes in the list as much as possible; for serious deviations from this requirement, up to 5 points will be deducted.
- Implementations with statically allocated memory (only local buffer-type variables for temporary storage before allocation are allowed) are not accepted.
- Modularization is mandatory; non-modularized work (functions longer than 40 lines) will be penalized. Operations on data structures like trees, queues, etc., should be handled using functions with descriptive names (e.g., addNode, deleteNode, etc.). All other data manipulations should be done using specialized functions whenever possible.
- Memory must be freed. Failure to do so can result in up to a 10/100-point deduction (this restriction applies from a score of 60 points upwards).
- Maintain at least a minimal level of code formatting and avoid inconsistencies (chaotic indentation, numerous combinations of leading/trailing whitespace, naming variables and functions alphabetically).
- If your solution does not compile, but the idea is good and you submit an implementation attempt, you can receive up to 20/100 points.
- A 15% deduction from the score obtained will be applied for implementations that do not use specific data types for the entities required (e.g., Player).

