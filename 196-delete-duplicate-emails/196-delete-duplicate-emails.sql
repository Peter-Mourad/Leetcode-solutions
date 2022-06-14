DELETE p1 FROM person As p1, person AS p2
WHERE p1.email = p2.email AND p1.id > p2.id