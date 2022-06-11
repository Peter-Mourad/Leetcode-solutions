# Write your MySQL query statement below
SELECT name AS Employee FROM Employee e
WHERE salary > (SELECT salary FROM Employee WHERE id = e.managerId)