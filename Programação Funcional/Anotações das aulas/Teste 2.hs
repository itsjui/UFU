calcula :: Char -> Float -> Float -> Float
calcula '*' x y = x * y
calcula '/' x y = x / y
calcula '+' x y = x + y
calcula '-' x y = x - y
calcula _ _ _ = error "erro!"

calcula_g :: Char -> Float -> Float -> Float
calcula_g x y z
    |x == '*' = y * z
    |x == '/' = y / z
    |x == '-' = y - z
    |x == '+' = y + z
    |otherwise = error "erro!"