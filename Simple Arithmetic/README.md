## Problem Link:
https://open.kattis.com/problems/simplearithmetic

## Thoughts
- back to grinding kattis!
- trying to force myself to learn other syntaxes... attempting this problem in rust

Okay, actual problem thoughts:

In general, really not that complicated. I solved this in python quite quickly with a built in `Decimal` library
In rust, I tried twice but could not get precision high enough for test sets 3/4 or 4/4. There is a similar built in Decimal library in rust (I think it is similar), but it is not in the standard library, so no go for the online judger. 

If I were to revisit this, the main thing would be figuring out a way to do the division and arithmetic with higher precision, likely with integers somewhere (?)

## Primary takeaways
- Floating point precision is hard
- Programming Languages are quirky
- Rust has some extra steps in taking input, in splitting, mapping, casting, etc.
