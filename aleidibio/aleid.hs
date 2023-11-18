readInput :: String -> [Integer]
readInput = map read . words -- parse entire input

writeOutput :: Integer -> String
writeOutput = show

solve :: [Integer] -> Integer
solve [t1, t2, full] = full - t1 - t2
solve _ = error "Invalid input"

main :: IO ()
main = interact (writeOutput . solve . readInput)

