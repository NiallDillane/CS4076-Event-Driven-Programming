### Zork clone 
### Written in C++ through Qt Creator
### 13132911 - Niall Dillane

# Rules: 
1. Moving North will hurt
2. Items may heal or hurt you
3. Room H will win the game

# Programming Techniques:
1. Zork is a friend class of Gameplay
2. Food inherits from Item
3. == operator is overloaded to check if 2 rooms are the same
4. Template function in Character.cpp, to check highest health
   boost and sodium content in your inventory.