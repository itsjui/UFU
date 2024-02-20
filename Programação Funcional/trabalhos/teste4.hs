replicar ::Int -> Char -> String
replicar 1 x = x :[]
replicar y x = x: replicar (y-1) x