fibonacci :: Int -> Int
fibonacci n
  |n == 0 = 0
  |n == 1 = 1
  |n > 1 = fibonacci (n-2) + fibonacci (n-1)

termo_n :: Int -> Int
termo_n n = fibonacci(n-1)
