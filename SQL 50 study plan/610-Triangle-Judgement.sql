select x, y, z, (
    Case WHEN x + y > z and x + z > y and y + z > x THEN \Yes\
    ELSE \No\
    END) AS triangle
FROM Triangle;