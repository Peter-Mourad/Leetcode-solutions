DELETE p1 FROM person As p1
INNER JOIN person AS p2
ON p1.email = p2.email AND p1.id > p2.id