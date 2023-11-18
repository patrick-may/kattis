readInput :: String -> Integer 
readInput inp = read inp

solve :: Integer -> Integer 
solve n = n - 1

main :: IO ()
main = interact (show . solve . readInput)
