-- Defining the interface
data ShapeOps = ShapeOps {
    area :: Double,
    draw :: String,
    perimeter :: Double
}

-- Defining a constructor for a circle
mkCircle :: Double -> ShapeOps
mkCircle radius = ShapeOps {
    area = pi * radius**2,
    draw = "Drawing a circle with radius " ++ show radius,
    perimeter = 2 * pi * radius
}

-- Defining another constructor for a square
mkSquare :: Double -> ShapeOps
mkSquare side = ShapeOps {
    area = side * side,
    draw = "Drawing a square with side " ++ show side,
    perimeter = 4 * side
}

-- Code can now treat these as a uniform "shape"
main = do
    let shapes = [mkCircle 5.0, mkSquare 2.0]
    mapM_ (putStrLn . draw) shapes