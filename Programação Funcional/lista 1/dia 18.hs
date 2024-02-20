{-
Main> not_logico True
False
Main> not_logico False
True
-}
not_logico :: Bool -> Bool
not_logico x

	|x == False = True
	|otherwise = False
{-
Main> e_logico False True
False
Main> e_logico True True
True
-}
e_logico :: Bool -> Bool -> Bool
e_logico x y 
	|x == False && y == False = False
	|x == False && y == True  = False
	|x == True && y  == False = False
	|otherwise                = True 
